#include "symbole.h"
#include <iostream>
#include <map>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

class Expr : public Symbole {
   public:
      Expr(int i) : Symbole(i) { }
      virtual ~Expr() { }
      virtual double eval(const map<string,double> & valeurs) const = 0;
};
