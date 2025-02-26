#pragma once
#include "symbole.h"
#include "lexer.h"
#include <memory>

class automate ; 

enum ActionType {DECALER, REDUIRE, ACCEPTER, ERREUR};

struct Action {
    ActionType ac;
    int nombreProduction;
    int idEtatSuivant;
};

class Etat {
public : 
    virtual ~Etat() {}
    virtual Action transition(automate* automate, Symbole* s) = 0;
};

