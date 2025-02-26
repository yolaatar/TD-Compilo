#include "automate.h"
#include "etat.h"
#include <iostream>
using namespace std;
Automate::Automate(Lexer& lex) : lexer(lex) {
    // Pour initialiser 
}

Automate::~Automate() {
    // Pour libérer la mémoire
    while (!stackEtats.empty()) {
        delete stackEtats.top();
        stackEtats.pop();
    }
}

void Automate::pushEtat(Etat* e) {
    stackEtats.push(e);
}

void Automate::popEtat(int n) {
    for (int i = 0; i < n; i++) {
        if (!stackEtats.empty()) {
            delete stackEtats.top();
            stackEtats.pop();
        }
    }
}

Etat* Automate::currentEtat() {
    return stackEtats.top();
}

void Automate::pushVal(int v) {
    stackVals.push(v);
}

int Automate::popVal() {
    int v = stackVals.top();
    stackVals.pop();
    return v;
}

int Automate::parse() {
    Symbole* s = lexer.Consulter();
    while (true) {
        Etat* etat = currentEtat();
        Action action = etat->transition(*this, s);
        switch (action.ac) {
            case DECALER:
                lexer.Avancer();
                s = lexer.Consulter();
                break;
            case REDUIRE:

                break;
            case ACCEPTER:
                return popVal();
            case ERR:
                cerr << "Erreur de syntaxe" << endl;
                return -1;
        }
    }
}

