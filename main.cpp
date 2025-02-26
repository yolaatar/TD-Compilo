#include <iostream>
#include "lexer.h"
#include "automate.h"
#include <thread>
#include <chrono>
#include <vector>
#include <map>
using namespace std;

int main() {
    // Liste de cas de test (expressions)
    vector<string> testCases = {
        "45",                // Simple entier
        "(45)",              // Entier entre parenthèses
        "45+34",             // Addition simple
        "(45+34)",           // Addition entre parenthèses
        "45+34*2",           // Addition et multiplication
        "(45+34)*123+62*3",  // Expression complexe valide
        "45++34",            // Erreur : double '+'
        "45+*34",            // Erreur : séquence d'opérateurs invalide
        "((1+2)*3)",         // Parenthèses imbriquées, valide
        "(1+2",              // Erreur : parenthèses déséquilibrées (ouvrante non fermée)
        "1+2)",              // Erreur : parenthèse fermante en trop
        "(45+34)*(62-3)"     // Erreur potentielle si l'opérateur '-' n'est pas géré
    };

    for (const auto& expr : testCases) {
        cout << "-------------------------------------------------" << endl;
        cout << "Test expression: " << expr << endl;

        // Créez un Lexer et un Automate pour l'expression en cours
        Lexer lexer(expr);
        Automate automate(lexer);
        
        // Lancement de l'analyse syntaxique
        automate.lecture();

        // Vérification du résultat
        if (automate.isAccepted()) {
            // Récupérer le symbole final (on suppose qu'il s'agit d'une Expression)
            Symbole* s = automate.getSymbole();
            // Tentative de conversion dynamique en Expression*
            Expression* e = dynamic_cast<Expression*>(s);
            if (e) {
                double valeur = e->eval(map<string, double>());
                cout << "Result: " << valeur << endl;
            } else {
                cout << "Error: Type mismatch or invalid expression result." << endl;
            }
        } else {
            cout << "Expression not accepted." << endl;
        }
        
        // Petite pause pour observer la sortie et, le cas échéant, pour utiliser 'leaks'
        cout << "Waiting 2 seconds before next test..." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << endl;
    }

    return 0;
}
