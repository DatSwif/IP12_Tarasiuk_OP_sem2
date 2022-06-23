#include "Header.h"

Tree::Tree(std::string formula) 
{
	treeHeight = 0;
	levels = new bool[treeHeight + 1];
	for (size_t i = 0; i < treeHeight; i++)
	{
		levels[i] = false;
	}
	root = newNode(formula, treeHeight, 0);
}

Node* Tree::newNode(std::string formula, size_t& height, size_t currHeight)
{
	if (currHeight > height) { height = currHeight; }

	Node* thisNode = new Node;
	size_t formulaLen = formula.size();

	if (formulaLen == 1)
	{
		thisNode->symbol = formula[0];
		thisNode->left = NULL;
		thisNode->right = NULL;
	}
	else
	{
		thisNode->symbol = divideFormula(formula);
		size_t gapPos = formula.find(' ');
		std::string leftFormula = formula.substr(0, gapPos);
		thisNode->left = newNode(leftFormula, height, currHeight + 1);
		std::string rightFormula = formula.substr(gapPos + 1, formulaLen - gapPos - 1);
		thisNode->right = newNode(rightFormula, height, currHeight + 1);
	}
	return thisNode;
}

void Tree::outDirect(Node* node, int level, bool*& levels)
{
	if (node != NULL)
	{
		for (int i = 0; i < level; i++)
		{
			if (levels[i] == true)
			{
				std::cout << "| ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		levels[level + 1] = true;
		std::cout << "|'" << node->symbol << "'\n";
		outDirect(node->left, level + 1, levels);
		levels[level + 1] = false;
		outDirect(node->right, level + 1, levels);
	}
}

void Tree::outSymm(Node* node, int level, bool*& levels, bool left = false, bool right = false)
{
	if (node != NULL)
	{
		outSymm(node->left, level + 1, levels, true, false);
		if (left == true) { levels[level] = true; }
		if (right == true) { levels[level] = false; }
		for (int i = 0; i < level; i++)
		{
			if (levels[i] == true)
			{
				std::cout << "| ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << "|'" << node->symbol << "'\n";
		outSymm(node->right, level + 1, levels, false, true);
	}
}

void Tree::outRev(Node* node, int level, bool*& levels)
{
	if (node != NULL)
	{
		outRev(node->left, level + 1, levels);
		levels[level + 1] = true;
		outRev(node->right, level + 1, levels);
		for (int i = 0; i < level; i++)
		{
			if (levels[i] == true)
			{
				std::cout << "| ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		levels[level + 1] = false;
		std::cout << "|'" << node->symbol << "'\n";
	}
}

void Tree::outPrefExpr(Node* node)
{
	if (node != NULL)
	{
		std::cout << node->symbol << ' ';
		outPrefExpr(node->left);
		outPrefExpr(node->right);
	}
}

void Tree::outInfExpr(Node* node)
{
	if (node != NULL)
	{
		outInfExpr(node->left);
		std::cout << node->symbol << ' ';
		outInfExpr(node->right);
	}
}

void Tree::outPostfExpr(Node* node)
{
	if (node != NULL)
	{
		outPostfExpr(node->left);
		outPostfExpr(node->right);
		std::cout << node->symbol << ' ';
	}
}

void Tree::startOutDirect()
{
	outDirect(this->root, 0, this->levels);
}

void Tree::startOutPrefExpr()
{
	outPrefExpr(this->root);
}

void Tree::startOutSymm()
{
	outSymm(this->root, 0, this->levels);
}

void Tree::startOutInfExpr()
{
	outInfExpr(this->root);
}

void Tree::startOutRev()
{
	outRev(this->root, 0, this->levels);
}

void Tree::startOutPostfExpr()
{
	outPostfExpr(this->root);
}