#pragma once
#include <stack>
#include "lexer.h"
#include "etat.h"*
using namespace std;

class Automate {
public:
    Automate(Lexer& lex) ; 
    ~Automate() ;
    int parse(); 

    void pushEtat(Etat* e);
    void pushSymbole(Symbole* s);
    void popEtat(int n);
    Etat* currentEtat();

    Etat * getEtat(int i) {
        return stackEtats.top();
    }

    void decalage(Symbole* s, Etat* e) {
        pushSymbole(s);
        pushEtat(e);
        lexer.Avancer();
    }

    void transitionSimple(Symbole* s, Etat* e) {
        pushSymbole(s);
        pushEtat(e);
    }

    void reduction(int n, Symbole* s) {
        for (int i = 0; i < n; i++) {
            delete stackEtats.top();
            stackEtats.pop();
        }
        Etat* e = currentEtat();
        e->transition(*this, s);
    }

    
    void pushVal(int v);
    int popVal();

private : 
    Lexer& lexer ; 
    stack<Etat*> stackEtats;
    stack<int> stackVals;
    stack<Symbole*> stackSymboles;
};
