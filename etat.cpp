#include "etat.h"
#include "symbole.h"
#include "automate.h"

Etat::Etat() {}
Etat::~Etat() {}
Etat::Etat(string nom) { this->nom = nom; }

bool Etat0::transition(Automate &automate, Symbole *s) {
    return true;
}

bool Etat1::transition(Automate &automate, Symbole *s) {
    return true;
}

bool Etat2::transition(Automate &automate, Symbole *s) {
    return true;
}

bool Etat3::transition(Automate &automate, Symbole *s) {
    return true;
}

bool Etat4::transition(Automate &automate, Symbole *s) {
    return true;
}

bool Etat5::transition(Automate &automate, Symbole *s) {
    return true;
}

bool Etat6::transition(Automate &automate, Symbole *s) {
    switch(*s) {
        case PLUS :
            automate.decalage(s, new Etat4) ;
            break;
        case MULT :
            automate.decalage(s, new Etat5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new Etat9);
            break;
    }
    return true;
}

bool Etat7::transition(Automate &automate, Symbole *s) {
    switch(*s) {
        case PLUS:
            automate.reduction(3, new Symbole(EXPR));
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case CLOSEPAR:
            automate.reduction(3, new Symbole(EXPR));
            break;
        case FIN:
            automate.reduction(3, new Symbole(EXPR));
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
    }
    return true;
}

bool Etat8::transition(Automate &automate, Symbole *s) {
    switch(*s) {
        case PLUS:
            automate.reduction(3, new Symbole(EXPR));
            break;
        case MULT:
            automate.reduction(3, new Symbole(EXPR));
            break;
        case CLOSEPAR:
            automate.reduction(3, new Symbole(EXPR));
            break;
        case FIN:
            automate.reduction(3, new Symbole(EXPR));
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
    }
    return true;
}

bool Etat9::transition(Automate &automate, Symbole *s) {
    switch(*s) {
        case PLUS:
            automate.reduction(3, new Symbole(EXPR));
            break;
        case MULT:
            automate.reduction(3, new Symbole(EXPR));
            break;
        case CLOSEPAR:
            automate.reduction(3, new Symbole(EXPR));
            break;
        case FIN:
            automate.reduction(3, new Symbole(EXPR));
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
    }
    return true;
}
