#pragma once
#include <string>
#include <iostream>

struct Node
{
    char symbol;
    Node *left, *right;
};

class Tree
{
private:
    Node* root;
    bool* levels;
    size_t treeHeight;

    void outDirect(Node* node, int level, bool*& levels);
    void outPrefExpr(Node* node);

    void outSymm(Node* node, int level, bool*& levels, bool left, bool right);
    void outInfExpr(Node* node);

    void outRev(Node* node, int level, bool*& levels);
    void outPostfExpr(Node* node);

public:
    Tree(std::string);
    Node *newNode(std::string, size_t& height, size_t currHeight);

    void startOutDirect();
    void startOutPrefExpr();

    void startOutSymm();
    void startOutInfExpr();

    void startOutRev();
    void startOutPostfExpr();
};