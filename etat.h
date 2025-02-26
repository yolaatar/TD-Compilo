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
    Etat(string name);
    virtual ~Etat();
    void Affiche() const;
    virtual Action transition(Automate & automate, Symbole* s) = 0;

protected:
    string nom;
};

