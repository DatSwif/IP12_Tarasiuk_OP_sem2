#include "Header.h"

Tree::Tree(string formula, size_t& height) 
{
	root = newNode(formula, height, 0);
}

Node* Tree::newNode(string formula, size_t& height, size_t currHeight)
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
		string leftFormula = formula.substr(0, gapPos);
		thisNode->left = newNode(leftFormula, height, currHeight + 1);
		string rightFormula = formula.substr(gapPos + 1, formulaLen - gapPos - 1);
		thisNode->right = newNode(rightFormula, height, currHeight + 1);
	}
	return thisNode;
}