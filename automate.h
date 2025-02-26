#pragma once
#include <stack>
#include "lexer.h"
#include "etat.h"
using namespace std;

class Automate {
public:
    Automate(Lexer& lex) ; 
    ~Automate() ;
    Symbole *getSymbole();
    bool isAccepted();
    // int parse();
    void lecture();

    void accept();
    void pushEtat(Etat* e);
    void pushSymbole(Symbole* s);
    Symbole *popSymbole();
    void popAndDestroySymbole();
    void popEtat(int n);
    Etat* currentEtat();

    Etat * getEtat(int i) ;

    void decalage(Symbole* s, Etat* e);

    void transitionSimple(Symbole* s, Etat* e);

    void reduction(int n, Symbole* s);

    void pushVal(int v);
    int popVal();

private : 
    Lexer& lexer ; 
    stack<Etat*> stackEtats;
    stack<int> stackVals;
    stack<Symbole*> stackSymboles;
    bool accepter = false;
};
