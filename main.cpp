#include <iostream>
#include "IntHolder.h"
#include "CharArrayHolder.h"
#include "DoubleHolder.h"
#include "BaseHolderTree.h"

int main() {
    //Populating tree in code
    BaseHolderTree tree(new IntHolder(1));
    tree.rootNode->childNodes.push_back(new BaseHolderTree::Node(new IntHolder(2011)));
    tree.rootNode->childNodes.push_back(new BaseHolderTree::Node(new CharArrayHolder("C++")));
    tree.rootNode->childNodes.push_back(new BaseHolderTree::Node(new DoubleHolder(3.14)));
    tree.rootNode->childNodes[0]->childNodes.push_back(new BaseHolderTree::Node(new CharArrayHolder("FULCRUM")));
    tree.rootNode->childNodes[0]->childNodes[0]->childNodes.push_back(new BaseHolderTree::Node(new CharArrayHolder("LINUX")));
    tree.rootNode->childNodes[0]->childNodes[0]->childNodes.push_back(new BaseHolderTree::Node(new IntHolder(7)));
    tree.rootNode->childNodes[2]->childNodes.push_back(new BaseHolderTree::Node(new CharArrayHolder("TEST")));
    tree.rootNode->childNodes[2]->childNodes.push_back(new BaseHolderTree::Node(new IntHolder(9)));
    tree.rootNode->childNodes[2]->childNodes.push_back(new BaseHolderTree::Node(new IntHolder(6)));

    //Serializing tree to char[]
    char* serialized_data = serialize(tree);
    //Deserializing it into new tree
    BaseHolderTree new_tree = deserialize(serialized_data);

    //Output the tree
    std::cout << new_tree.rootNode->value->toString() << std::endl;
    std::cout << new_tree.rootNode->childNodes[0]->value->toString() << std::endl;
    std::cout << new_tree.rootNode->childNodes[1]->value->toString() << std::endl;
    std::cout << new_tree.rootNode->childNodes[2]->value->toString() << std::endl;
    std::cout << new_tree.rootNode->childNodes[0]->childNodes[0]->value->toString() << std::endl;
    std::cout << new_tree.rootNode->childNodes[0]->childNodes[0]->childNodes[0]->value->toString() << std::endl;
    std::cout << new_tree.rootNode->childNodes[0]->childNodes[0]->childNodes[1]->value->toString() << std::endl;
    std::cout << new_tree.rootNode->childNodes[2]->childNodes[0]->value->toString() << std::endl;
    std::cout << new_tree.rootNode->childNodes[2]->childNodes[1]->value->toString() << std::endl;
    std::cout << new_tree.rootNode->childNodes[2]->childNodes[2]->value->toString() << std::endl;

    delete[] serialized_data;

    return 0;
}
