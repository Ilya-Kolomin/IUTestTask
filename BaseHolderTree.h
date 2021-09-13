//
// Created by Илья Коломин on 10.09.2021.
//
#include <vector>
#include "BaseHolder.h"

#ifndef IUTESTTASK_BASEHOLDERTREE_H
#define IUTESTTASK_BASEHOLDERTREE_H


class BaseHolderTree {
public:
    class Node {
    private:
        std::pair<size_t, int> dfs() const;
    public:
        BaseHolder* value;
        std::vector<Node*> childNodes;

        friend char* serialize(const BaseHolderTree&);

        explicit Node(BaseHolder*);
        ~Node();
    };

    Node* rootNode;

    explicit BaseHolderTree(BaseHolder* value);
    explicit BaseHolderTree(Node* rootNode);
    ~BaseHolderTree();
};

char * serialize(const BaseHolderTree& tree);
BaseHolderTree deserialize(const char * data);


#endif //IUTESTTASK_BASEHOLDERTREE_H
