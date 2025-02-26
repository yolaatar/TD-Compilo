#include "etat.h"
#include "symbole.h"
#include "automate.h"

Etat::Etat() {}
Etat::~Etat() {}
Etat::Etat(string nom) { this->nom = nom; }

bool Etat0::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
    {
        automate.decalage(s, new Etat3);
        break;
    }
    case OPENPAR:
    {
        automate.decalage(s, new Etat2);
        break;
    }
    case EXPR:
    {
        automate.transitionSimple(s, new Etat1);
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
    }
    return true;
}

bool Etat1::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    {
        automate.decalage(s, new Etat4);
        break;
    }
    case MULT:
    {
        automate.decalage(s, new Etat5);
        break;
    }
    case FIN:
    {
        automate.accept();
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
    }
    return true;
}

bool Etat2::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
    {
        automate.decalage(s, new Etat3);
        break;
    }
    case OPENPAR:
    {
        automate.decalage(s, new Etat2);
        break;
    }
    case EXPR:
    {
        automate.transitionSimple(s, new Etat6);
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
    }
    return true;
}

bool Etat3::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    {
        Entier *e = (Entier *)automate.popSymbole();
        automate.reduction(1, new ExprVal(e));
        break;
    }
    case MULT:
    {
        Entier *e = (Entier *)automate.popSymbole();
        automate.reduction(1, new ExprVal(e));
        break;
    }
    case CLOSEPAR:
    {
        Entier *e = (Entier *)automate.popSymbole();
        automate.reduction(1, new ExprVal(e));
        break;
    }
    case FIN:
    {
        Entier *e = (Entier *)automate.popSymbole();
        automate.reduction(1, new ExprVal(e));
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
    }
    return true;
}

bool Etat4::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
    {
        automate.decalage(s, new Etat3);
        break;
    }
    case OPENPAR:
    {
        automate.decalage(s, new Etat2);
        break;
    }
    case EXPR:
    {
        automate.transitionSimple(s, new Etat7);
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
    }
    return true;
}

bool Etat5::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
    {
        automate.decalage(s, new Etat3);
        break;
    }
    case OPENPAR:
    {
        automate.decalage(s, new Etat2);
        break;
    }
    case EXPR:
    {
        automate.transitionSimple(s, new Etat8);
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
    }
    return true;
}

bool Etat6::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    {
        automate.decalage(s, new Etat4);
        break;
    }
    case MULT:
    {
        automate.decalage(s, new Etat5);
        break;
    }
    case CLOSEPAR:
    {
        automate.decalage(s, new Etat9);
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    
    }
    }
    return true;
}

bool Etat7::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    {
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        Expression *e2 = (Expression *)automate.popSymbole();
        automate.reduction(3, new ExprPlus(e1, e2));
    }
    break;
    case MULT:
    {
        automate.decalage(s, new Etat5);
        break;
    }
    case CLOSEPAR:
    {
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        Expression *e2 = (Expression *)automate.popSymbole();
        automate.reduction(3, new ExprPlus(e1, e2));
        break;
    }
    case FIN:
    {
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        Expression *e2 = (Expression *)automate.popSymbole();
        automate.reduction(3, new ExprPlus(e1, e2));
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
    }
    }
    return true;
}

bool Etat8::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    {
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        Expression *e2 = (Expression *)automate.popSymbole();
        automate.reduction(3, new ExprMult(e1, e2));
        break;
    }
    case MULT:
    {
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        Expression *e2 = (Expression *)automate.popSymbole();
        automate.reduction(3, new ExprMult(e1, e2));
        break;
    }
    case CLOSEPAR:
    {
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        Expression *e2 = (Expression *)automate.popSymbole();
        automate.reduction(3, new ExprMult(e1, e2));
        break;
    }
    case FIN:
    {
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        Expression *e2 = (Expression *)automate.popSymbole();
        automate.reduction(3, new ExprMult(e1, e2));
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
    }
    }
    return true;
}

bool Etat9::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    {
        automate.popAndDestroySymbole();
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        automate.reduction(3, new ExprPar(e1));
        break;
    }
    case MULT:
    {
        automate.popAndDestroySymbole();
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        automate.reduction(3, new ExprPar(e1));
        break;
    }
    case CLOSEPAR:
    {
        automate.popAndDestroySymbole();
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        automate.reduction(3, new ExprPar(e1));
        break;
    }
    case FIN:
    {
        automate.popAndDestroySymbole();
        Expression *e1 = (Expression *)automate.popSymbole();
        automate.popAndDestroySymbole();
        automate.reduction(3, new ExprPar(e1));
        break;
    }
    default:
    {
        automate.decalage(new Symbole(ERREUR), NULL);
    }
    }
    return true;
}
