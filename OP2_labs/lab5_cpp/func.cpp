#include "Header.h"

void unpackFormula(std::string& formula)
{
	remove(formula.begin(), formula.end(), ' ');
	size_t formulaLen = formula.size();
	if ((formula[0] == '(') && (formula[formulaLen - 1] == ')'))
	{
		formula = formula.substr(1, formulaLen - 2);
	}
}

char divideFormula(std::string& formula)
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