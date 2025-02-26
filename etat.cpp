#include "etat.h"
#include "symbole.h"
#include "automate.h"

Etat::Etat() {}
Etat::~Etat() {}
Etat::Etat(string nom) { this->nom = nom; }

bool Etat0::transition(Automate &automate, Symbole *s) {
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.transitionSimple(s, new Etat1);
            break;    
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool Etat1::transition(Automate &automate, Symbole *s) {
    switch(*s){
        case PLUS:
            automate.decalage(s, new Etat4);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case FIN:
            automate.accepter();
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool Etat2::transition(Automate &automate, Symbole *s) {
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.transitionSimple(s, new Etat6);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool Etat3::transition(Automate &automate, Symbole *s) {
    switch(*s){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.reduction(1, new Symbole(EXPR));
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool Etat4::transition(Automate &automate, Symbole *s) {
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.transitionSimple(s, new Etat7);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool Etat5::transition(Automate &automate, Symbole *s) {
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.transitionSimple(s, new Etat8);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
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
