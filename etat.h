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
    void Affiche() const { cout << "Etat : " << nom << endl;};
    virtual bool transition(Automate & automate, Symbole* s) = 0;

protected:
    string nom;
};

class Etat0 : public Etat {
public:
    Etat0() : Etat("E0") {}
    bool transition(Automate & automate, Symbole* s) override;
};

class Etat1 : public Etat {
public:
    Etat1() : Etat("E1") {}
    bool transition(Automate & automate, Symbole* s) override;
};

class Etat2 : public Etat {
public:
    Etat2() : Etat("E2") {}
    bool transition(Automate & automate, Symbole* s) override;
};

class Etat3 : public Etat {
public:
    Etat3() : Etat("E3") {}
    bool transition(Automate & automate, Symbole* s) override;
};

class Etat4 : public Etat {
public:
    Etat4() : Etat("E4") {}
    bool transition(Automate & automate, Symbole* s) override;
};

class Etat5 : public Etat {
public:
    Etat5() : Etat("E5") {}
    bool transition(Automate & automate, Symbole* s) override;
};

class Etat6 : public Etat {
public:
    Etat6() : Etat("E6") {}
    bool transition(Automate & automate, Symbole* s) override;
};

class Etat7 : public Etat {
public:
    Etat7() : Etat("E7") {}
    bool transition(Automate & automate, Symbole* s) override;
};

class Etat8 : public Etat {
public:
    Etat8() : Etat("E8") {}
    bool transition(Automate & automate, Symbole* s) override;
};

class Etat9 : public Etat {
public:
    Etat9() : Etat("E9") {}
    bool transition(Automate & automate, Symbole* s) override;
};



