#include "etat.h"
#include "symbole.h"

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
