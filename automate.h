#pragma once
#include <stack>
#include "lexer.h"
#include "etat.h"
using namespace std;

class Automate {
public:
    Automate(Lexer& lex) ; 
    ~Automate() ;
    int parse(); 

    void pushEtat(Etat* e);
    void popEtat(int n);
    Etat* currentEtat();

    void pushVal(int v);
    int popVal();

private : 
    Lexer& lexer ; 
    stack<Etat*> stackEtats;
    stack<int> stackVals;
};
