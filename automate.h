#pragma once
#include "symbole.h"
#include "etat.h"
#include <stack>
#include "lexer.h"
using namespace std;

class Automate{
    public:
        Automate(Lexer * lexer);
        void decalage(Symbole * s, Etat * e);
        void transitionSimple (Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        virtual ~Automate(){};
        void dequeueAll(); 
        Symbole* popSymbole(); 
        void popAndSupprSymbol(); 
        void accepter();
        void exec();
        Etat* getCurrentState();
        Symbole * getCurrentSymbole();

    protected:
        stack <Etat*> statestack;
        stack <Symbole*> symbolstack; 
        Lexer * lexer;
        bool isAccepted;
};