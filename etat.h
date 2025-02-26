#pragma once
#include "symbole.h"
#include "lexer.h"
#include <memory>

class Automate ; 

enum ActionType {DECALER, REDUIRE, ACCEPTER, ERR};

struct Action {
    ActionType ac;
    int nombreProduction;
    int idEtatSuivant;
};

class Etat {
public : 
    virtual ~Etat() {}
    virtual Action transition(Automate* automate, Symbole* s) = 0;
};

