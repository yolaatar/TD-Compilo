#include "automate.h"
#include "etat.h"
#include <iostream>
using namespace std;
Automate::Automate(Lexer &lex) : lexer(lex)
{
    pushEtat(new Etat0) ;
}

Automate::~Automate()
{
    // Pour libérer la mémoire
    while (!stackEtats.empty())
    {
        delete stackEtats.top();
        stackEtats.pop();
    }
}

void Automate::pushEtat(Etat *e)
{
    stackEtats.push(e);
}

void Automate::popEtat(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!stackEtats.empty())
        {
            delete stackEtats.top();
            stackEtats.pop();
        }
    }
}

void Automate::decalage(Symbole *s, Etat *e)
{
    pushSymbole(s);
    pushEtat(e);
    lexer.Avancer();
}

void Automate::transitionSimple(Symbole *s, Etat *e)
{
    pushSymbole(s);
    pushEtat(e);
}

void Automate::reduction(int n, Symbole *s)
{
    for (int i = 0; i < n; i++)
    {
        delete stackEtats.top();
        stackEtats.pop();
    }
    Etat *e = currentEtat();
    e->transition(*this, s);
}

Etat *Automate::currentEtat()
{
    return stackEtats.top();
}

void Automate::pushSymbole(Symbole* s) {
    stackSymboles.push(s);
}

Symbole *Automate::popSymbole()
{
    cout << "[PopSymbol] Popping symbol: ";
    stackSymboles.top()->Affiche();
    cout << endl;
    Symbole *s = stackSymboles.top();
    stackSymboles.pop();
    return s;
}

void Automate::popAndDestroySymbole()
{
    cout << "[PopSymbol] Popping symbol: ";
    stackSymboles.top()->Affiche();
    cout << endl;
    delete stackSymboles.top();
    stackSymboles.pop();
}

void Automate::pushVal(int v)
{
    stackVals.push(v);
}

int Automate::popVal()
{
    int v = stackVals.top();
    stackVals.pop();
    return v;
}

void Automate::accept()
{
    this->accepter = true;
}   

Symbole *Automate::getSymbole()
{
    return stackSymboles.top();
}

bool Automate::isAccepted()
{
    return this->accepter;
}
void Automate::lecture()
{
    //cout << "Automate starting lecture..." << endl;

    // Démarrage avec l'état initial, ici Etat0 (assurez-vous que la classe Etat0 est correctement déclarée et définie)
    pushEtat(new Etat0());

    Symbole* s = lexer.Consulter();

    while (!this->accepter)
    {
        if (!currentEtat()->transition(*this, s))
        {
            cout << "Error: No valid transition for symbol ";
            s->Affiche();
            cout << endl;
            break;
        }
        currentEtat()->Affiche();
        // cout << "Current Symbol: ";
        //s->Affiche();
        //cout << endl;

        s = lexer.Consulter();
    }
    
    // Vérification de la fin de l'entrée pour décider de l'acceptation.
    if (this->accepter)
        cout << "Input accepted!" << endl;
    else
        cout << "Input not accepted!" << endl;
}


// int Automate::parse() {
//     Symbole* s = lexer.Consulter();
//     while (true) {
//         Etat* etat = currentEtat();
//         Action action = etat->transition(*this, s);
//         switch (action.ac) {
//             case DECALER:
//                 lexer.Avancer();
//                 s = lexer.Consulter();
//                 break;
//             case REDUIRE:

//                 break;
//             case ACCEPTER:
//                 return popVal();
//             case ERR:
//                 cerr << "Erreur de syntaxe" << endl;
//                 return -1;
//         }
//     }
// }

