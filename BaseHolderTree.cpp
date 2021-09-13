//
// Created by Илья Коломин on 10.09.2021.
//

#include "BaseHolderTree.h"
#include <vector>
#include <cstring>

BaseHolderTree::BaseHolderTree(BaseHolder* value) {
    rootNode = new Node(value);
}

BaseHolderTree::~BaseHolderTree() {
    delete rootNode;
}

BaseHolderTree::Node::~Node() {
    for (auto& childNode : childNodes) {
        delete childNode;
    }
}

BaseHolderTree::Node::Node(BaseHolder * value_) : value(const_cast<BaseHolder *>(value_)), childNodes() { }

//Deep first search to compute the tree's size
std::pair<size_t, int> BaseHolderTree::Node::dfs() const {
    std::pair<size_t, int> res = {value->size(), 1};
    for (const auto& child : childNodes) {
        auto res_child = child->dfs();
        res.first += res_child.first;
        res.second += res_child.second;
    }
    return res;
}

char * serialize(const BaseHolderTree& tree) {
    //Deep first search to compute the size of the BaseHolders in the tree in bytes and to compute the number of nodes
    auto size = tree.rootNode->dfs();
    //The result char[]
    //Allocating memory for one int with number of nodes, computed size of BaseHolders, and for storing parents of nodes
    char * result = new char[sizeof(int) + size.first + size.second * (sizeof(int) + 1)];

    //Writing the number of nodes into the first 4 bytes
    memcpy(result, &size.second, sizeof(int));

    //counters for indexes for storing parents of nodes and the node's data
    size_t last_for_parents = sizeof(int) + size.first + size.second, last_for_holders = sizeof(int);
    int current_node = 0;

    //Deep first search to serialize the nodes
    std::function<void(BaseHolderTree::Node*,int)> result_dfs;
    result_dfs = [&](BaseHolderTree::Node* node, int parent) -> void {
        int this_node_number = current_node++;
        char node_size = (char)node->value->size();

        // Writing the index of parent for this node
        memcpy(result + last_for_parents, &parent, sizeof(int));
        last_for_parents += sizeof(int);

        //Writing the actual node's data (its size in first byte and then the actual data)
        memcpy(result + last_for_holders++, &node_size, 1);
        memcpy(result + last_for_holders, (void*)node->value, node_size);

        last_for_holders += node_size;

        //Running from the children
        for (const auto& child : node->childNodes) {
            result_dfs(child, this_node_number);
        }
    };

    //Running from root node
    result_dfs(tree.rootNode, -1);
    return result;
}

BaseHolderTree::BaseHolderTree(BaseHolderTree::Node *rootNode) {
    this->rootNode = rootNode;
}

BaseHolderTree deserialize(const char * data) {
    size_t last_read = 0;

    //Obtaining number of nodes
    int number_of_nodes = *(int*)data;
    last_read += sizeof(int);

    std::vector<BaseHolderTree::Node*> nodes;

    for (int i = 0; i < number_of_nodes; ++i) {
        //Obtaining BaseHolder's size
        auto node_size = (size_t)(unsigned char)data[last_read++];
        auto* baseHolder = (BaseHolder*)new char[node_size];

        memcpy((void*)baseHolder, data + last_read, node_size);

        nodes.push_back(new BaseHolderTree::Node(baseHolder));
        last_read += node_size;
    }

    //Skipping the root node
    last_read += sizeof(int);

    for(int i = 1; i < number_of_nodes; ++i) {
        //Adding child nodes to its parents
        int parent_node = *(int*)(data + last_read);
        nodes[parent_node]->childNodes.push_back(nodes[i]);
        last_read += sizeof(int);
    }

    return BaseHolderTree(nodes[0]);
}