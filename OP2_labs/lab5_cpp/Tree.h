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
public:
    Node* root;

    Tree(std::string, size_t& height);
    Node *newNode(std::string, size_t& height, size_t currHeight);
};