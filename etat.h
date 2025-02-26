#pragma once
#include "symbole.h"
#include "lexer.h"
#include <memory>

class Parser ; 

enum ActionType {DECALER, REDUIRE, ACCEPTER, ERREUR};

struct Action {
    ActionType ac;
    int nombreProduction;
    int idEtatSuivant;
};

class Etat {
public : 
    virtual ~Etat() {}
    virtual Action transition(Parser* parser, Symbole* s) = 0;
};

