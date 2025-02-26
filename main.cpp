#include <iostream>
#include "lexer.h"
#include "automate.h"



int main(void) {
   string chaine("(45+34)*123+62*3");
   Lexer l(chaine);
   Automate automate(l);
   automate.lecture();

   if (automate.isAccepted()) {
       Symbole *s = automate.getSymbole();

      Expression *e = dynamic_cast<Expression *>(s);
      if (e) {
         double valeur = e->eval(map<string, double>());
         cout << "Valeur de l'expression : " << valeur << endl;
      } else {
         cout << "Erreur de typage" << endl;
      }
   } else {
       cout << "Expression incorrecte" << endl;
   }

   
   // while(*(s=l.Consulter())!=FIN) {
   //    s->Affiche();
   //    cout<<endl;
   //    l.Avancer();
   // }
   
   return 0;
}

