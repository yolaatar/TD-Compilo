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

void Automate::lecture()
{
    cout << "Automate starting lecture..." << endl;

    // Démarrage avec l'état initial, ici Etat0 (assurez-vous que la classe Etat0 est correctement déclarée et définie)
    pushEtat(new Etat0());
    // Vous pouvez appeler ici une fonction d'affichage de la pile si vous l'avez implémentée, par exemple afficherStack();

    // Récupération du premier symbole depuis le Lexer.
    // Notez que lexer est un objet (référence) et non un pointeur, donc on utilise le point.
    Symbole* s = lexer.Consulter();

    // Boucle tant que le symbole lu n'est pas FIN.
    // Ici, j'utilise s->getType() pour comparer le type du symbole. Si vous avez surchargé l'opérateur==, vous pouvez écrire :
    //    while (*s != FIN)
    while (*s != FIN)
    {
        cout << "Current Symbol: ";
        s->Affiche();
        cout << endl;
        
        // Déclenchement de la transition dans l'état courant.
        // Utilisation de currentEtat() qui renvoie le sommet de stackEtats.
        if (!currentEtat()->transition(*this, s))
        {
            cout << "Error: No valid transition for symbol ";
            s->Affiche();
            cout << endl;
            break;
        }
        
        // (Optionnel) Affichage de la pile d'états pour le debug.
        // afficherStack();

        // Récupération du symbole suivant à traiter
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

void Automate::accepter()
{
    this->accepter = true;
}   