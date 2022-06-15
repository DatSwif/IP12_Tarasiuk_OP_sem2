#pragma once
#include <string>
#include <iostream>

using std::string;

struct Node
{
    char symbol;
    Node *left, *right;
};

class Tree
{
public:
    Node* root;

    Tree(string, size_t& height);
    Node *newNode(string, size_t& height, size_t currHeight);
};