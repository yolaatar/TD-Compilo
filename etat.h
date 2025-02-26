#pragma once
#include "symbole.h"
#include "lexer.h"
#include <memory>
#include <iostream>

using namespace std;

class Automate ; 



class Etat {
public : 
    Etat(string name);
    Etat();
    virtual ~Etat();
    void Affiche() const { cout << "Etat : " << nom << endl; };
    virtual bool transition(Automate & automate, Symbole* s) = 0;

protected:
    string nom;
};


