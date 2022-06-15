#pragma once
#include "Tree.h"

void unpackFormula(std::string&);
char divideFormula(std::string&);

void outDirect(Node*, int level, bool*& levels);
void outSymm(Node*, int level, bool*& levels, bool left, bool right);
void outRev(Node*, int level, bool*& levels);

void outPrefExpr(Node*);
void outInfExpr(Node*);
void outPostfExpr(Node*);