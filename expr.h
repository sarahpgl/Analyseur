#pragma once

#include <string>
#include "symbole.h"

class Expr : public Symbole {
    public:
        Expr():Symbole(EXPR, false){}
        virtual ~Expr(){}
        virtual double eval() = 0;
        void affiche();
};

class ExprMult : public Expr {
    public : 
        ExprMult(Expr* expr1, Expr* expr2) : exprGauche(expr1), exprDroite(expr2){}
        virtual ~ExprMult() {}
        double eval(){return ((exprGauche->eval())*(exprDroite->eval()));}
    protected :
        Expr* exprGauche;
        Expr* exprDroite;

};

class ExprPlus : public Expr {
    public : 
        ExprPlus(Expr* expr1, Expr* expr2)  : exprGauche(expr1), exprDroite(expr2) {}
        virtual ~ExprPlus() {}
        double eval(){return ((exprGauche->eval())+(exprDroite->eval()));}
    protected :
        Expr* exprGauche;
        Expr* exprDroite;
};

class ExprConstante : public Expr {
    public :
        ExprConstante(int val) : valeur(val){}
        virtual ~ExprConstante() {}
        double eval(){return valeur;}
    protected :
        int valeur; 
};