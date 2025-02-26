#include "etat.h"
#include "symbole.h"
#include "automate.h"

Etat::Etat() {}
Etat::~Etat() {}
Etat::Etat(string nom) { this->nom = nom; }

Etat0::Etat0() : Etat("E0") {}
Etat1::Etat1() : Etat("E1") {}
Etat2::Etat2() : Etat("E2") {}
Etat3::Etat3() : Etat("E3") {}
Etat4::Etat4() : Etat("E4") {}
Etat5::Etat5() : Etat("E5") {}
Etat6::Etat6() : Etat("E6") {}
Etat7::Etat7() : Etat("E7") {}
Etat8::Etat8() : Etat("E8") {}
Etat9::Etat9() : Etat("E9") {}

bool Etat0::transition(Automate &automate, Symbole *s) {
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.decalage(s, new Etat1);
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
            return false;
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
            automate.decalage(s, new Etat6);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool Etat3::transition(Automate &automate, Symbole *s) {
    switch(*s){
        case INT:
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
            automate.decalage(s, new Etat7);
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
            automate.decalage(s, new Etat8);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool Etat6::transition(Automate &automate, Symbole *s) {
    return true;
}

bool Etat7::transition(Automate &automate, Symbole *s) {
    return true;
}

bool Etat8::transition(Automate &automate, Symbole *s) {
    return true;
}

bool Etat9::transition(Automate &automate, Symbole *s) {
    return true;
}
