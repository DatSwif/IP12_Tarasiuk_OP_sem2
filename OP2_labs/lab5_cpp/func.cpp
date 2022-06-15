#include "Header.h"

void unpackFormula(string& formula)
{
	remove(formula.begin(), formula.end(), ' ');
	size_t formulaLen = formula.size();
	if ((formula[0] == '(') && (formula[formulaLen - 1] == ')'))
	{
		formula = formula.substr(1, formulaLen - 2);
	}
}

char divideFormula(string& formula)
{
	unpackFormula(formula);
	size_t formulaLen = formula.size();
	int bracketLevel = 0;
	
	char sign = ' ';
	int signPos = -1;
	bool plusMinusFound = false;

	for (size_t pos = 0; pos < formulaLen; pos++) // searching for the last operation to be executed
	{
		if (formula[pos] == '(') { bracketLevel++; }
		else if (formula[pos] == ')') {bracketLevel--; }
		
		else if (bracketLevel == 0)
		{
			if ((formula[pos] == '+') || (formula[pos] == '-'))
			{
				plusMinusFound = true;
				signPos = pos;
				sign = formula[pos];
			}
			else if ((formula[pos] == '*') && (plusMinusFound == false))
			{
				signPos = pos;
				sign = formula[pos];
			}
		}
	}
	if (sign != ' ')
	{
		formula.replace(signPos, 1, 1, ' ');
	}
	return sign;
}

void outDirect(Node* node, int level, bool*& levels)
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

void outSymm(Node* node, int level, bool*& levels, bool left, bool right)
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

void outRev(Node* node, int level, bool*& levels)
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

void outPrefExpr(Node* node)
{
	if (node != NULL)
	{
		std::cout << node->symbol << ' ';
		outPrefExpr(node->left);
		outPrefExpr(node->right);
	}
}

void outInfExpr(Node* node)
{
	if (node != NULL)
	{
		outInfExpr(node->left);
		std::cout << node->symbol << ' ';
		outInfExpr(node->right);
	}
}

void outPostfExpr(Node* node)
{
	if (node != NULL)
	{
		outPostfExpr(node->left);
		outPostfExpr(node->right);
		std::cout << node->symbol << ' ';
	}
}