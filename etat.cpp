#include "etat.h"
#include "automate.h"
#include <iostream>

Etat :: Etat(string n) {
    name = n;
}

E0 :: E0(): Etat("E0"){}

bool E0 :: transition(Automate & automate, Symbole * s){
    switch(*s){
        case INT :
            cout<< "Etape 1 E0 int"<<endl;
            automate.decalage(s, new E3);
            break;

        case PLUS :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case MULT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case OPENPAR :
            cout<<"etape 0 : E0 OPENPAR"<<endl;
            automate.decalage(s, new E2);
            break;

        case CLOSEPAR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case FIN : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case EXPR : 
          
            cout<<"3eme etape : E0 EXPR"<<endl;
            automate.decalage(s, new E1);
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E0." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break; 

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E0." << endl; 
            cout << endl; 
    }
    return false; 
}

E1 :: E1(): Etat("E1"){}

bool E1 :: transition(Automate & automate, Symbole * s){
    switch(*s){
        case INT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case PLUS :
            automate.decalage(s, new E4);
            break;

        case MULT :
            automate.decalage(s, new E5);
            break;

        case OPENPAR :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case CLOSEPAR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case FIN : 
        cout<<endl;
            s->Affiche();
            automate.accepter();
            return true;
            

        case EXPR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E1." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break;

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E1." << endl; 
            cout << endl; 
    }

    return false; 
}

E2 :: E2(): Etat("E2"){}

bool E2 :: transition(Automate & automate, Symbole * s){
    switch(*s){
        case INT :
            automate.decalage(s, new E3);
            break;

        case PLUS :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case MULT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case OPENPAR :
            automate.decalage(s, new E2);
            break;

        case CLOSEPAR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case FIN : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case EXPR : 
            automate.decalage(s, new E6);
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E2." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break; 

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E2." << endl; 
            cout << endl; 
    }

    return false; 
}

E3 :: E3(): Etat("E3"){}

bool E3 :: transition(Automate & automate, Symbole * s){
    Entier * gauche; 
    switch(*s){
        case INT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case PLUS :
            cout<<"2ème étape : E3 PLUS" <<endl;
            
            gauche = ((Entier*) automate.popSymbole());
            automate.reduction(1, new ExprConstante(gauche->getValue()));     

            break;

        case MULT :
            gauche = ((Entier*) automate.popSymbole());
            automate.reduction(1, new ExprConstante(gauche->getValue()));
            break;

        case OPENPAR :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case CLOSEPAR : 
            gauche = ((Entier*) automate.popSymbole());
            automate.reduction(1, new ExprConstante(gauche->getValue()));
            break;

        case FIN : 
            gauche = ((Entier*) automate.popSymbole());
            automate.reduction(1, new ExprConstante(gauche->getValue()));
            break;

        case EXPR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E3." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break; 

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E3." << endl; 
            cout << endl; 
    }
    return false; 
}

E4 :: E4(): Etat("E4"){}

bool E4 :: transition(Automate & automate, Symbole * s){
    switch(*s){
        case INT :
         
           
            automate.decalage(s, new E3);
            break;

        case PLUS :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case MULT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case OPENPAR :
            automate.decalage(s, new E2);
            break;

        case CLOSEPAR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case FIN : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case EXPR : 
            automate.decalage(s, new E7);
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E4." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break; 

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E4." << endl; 
            cout << endl; 
    }
    return false; 
}

E5 :: E5(): Etat("E5"){}

bool E5 :: transition(Automate & automate, Symbole * s){
    switch(*s){
        case INT :
            automate.decalage(s, new E3);
            break;

        case PLUS :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case MULT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case OPENPAR :
            automate.decalage(s, new E2);
            break;

        case CLOSEPAR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case FIN : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case EXPR : 
            automate.decalage(s, new E8);
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E5." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break; 

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E5." << endl; 
            cout << endl; 
    }
    return false; 
}

E6 :: E6(): Etat("E6"){}

bool E6 :: transition(Automate & automate, Symbole * s){
    switch(*s){
        case INT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case PLUS :
            automate.decalage(s, new E4);
            break;

        case MULT :
            automate.decalage(s, new E5);
            break;

        case OPENPAR :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case CLOSEPAR : 
            automate.decalage(s, new E9);
            break;

        case FIN : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case EXPR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E6." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break; 

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E6." << endl; 
            cout << endl; 
    }
    return false; 
}

E7 :: E7(): Etat("E7"){}

bool E7 :: transition(Automate & automate, Symbole * s){
    Expr* gauche;
    Expr* droite;
    switch(*s){
        case INT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case PLUS :
            gauche = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.popAndSupprSymbol(); 
            droite = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.reduction(3, new ExprPlus(gauche, droite));
            break;

        case MULT :
            automate.decalage(s, new E5);
            break;

        case OPENPAR :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case CLOSEPAR : 
            gauche = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.popAndSupprSymbol(); 
            droite = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.reduction(3, new ExprPlus(gauche, droite));
            break;

        case FIN : 
            gauche = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.popAndSupprSymbol(); 
            droite = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.reduction(3, new ExprPlus(gauche, droite));
            break;

        case EXPR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E7." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break; 

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E7." << endl; 
            cout << endl; 
    }
    return false; 
}

E8 :: E8(): Etat("E8"){}

bool E8 :: transition(Automate & automate, Symbole * s){
    Expr* gauche;
    Expr* droite;
    switch(*s){
        case INT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case PLUS :
            gauche = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.popAndSupprSymbol(); 
            droite = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.reduction(3, new ExprMult(gauche, droite));
            break;

        case MULT :
            gauche = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.popAndSupprSymbol(); 
            droite = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.reduction(3, new ExprMult(gauche, droite));
            break;

        case OPENPAR :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case CLOSEPAR : 
            gauche = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.popAndSupprSymbol(); 
            droite = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.reduction(3, new ExprMult(gauche, droite));
            break;

        case FIN : 
            gauche = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.popAndSupprSymbol(); 
            droite = new ExprConstante(((Entier*) automate.popSymbole())->getValue());
            automate.reduction(3, new ExprMult(gauche, droite));
            break;

        case EXPR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E8." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break; 

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E8." << endl; 
            cout << endl; 
    }
    return false; 
}

E9 :: E9(): Etat("E9"){}

bool E9 :: transition(Automate & automate, Symbole * s){
    Entier * gauche;
    switch(*s){
        case INT :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case PLUS :
            automate.popSymbole();
            gauche = ((Entier*) automate.popSymbole());
            automate.popSymbole();
            automate.reduction(3, new ExprConstante(gauche->getValue()));           
            break;
            
        case MULT :
            automate.popSymbole();
            gauche = ((Entier*) automate.popSymbole());
            automate.popSymbole();
            automate.reduction(3, new ExprConstante(gauche->getValue()));  
            break;

        case OPENPAR :
            transition(automate, new Symbole(ERREUR, false));
            break;

        case CLOSEPAR : 
            automate.popSymbole();
            gauche = ((Entier*) automate.popSymbole());
            automate.popSymbole();
            automate.reduction(3, new ExprConstante(gauche->getValue()));  
            break;

        case FIN : 
            automate.popSymbole();
            gauche = ((Entier*) automate.popSymbole());
            automate.popSymbole();
            automate.reduction(3, new ExprConstante(gauche->getValue()));  
            break;

        case EXPR : 
            transition(automate, new Symbole(ERREUR, false));
            break;

        case ERREUR : 
            cout << endl; 
            cout << "Erreur, nous sommes dans le case ERREUR du switch sur E9." << endl; 
            cout << endl; 
            automate.dequeueAll();
            break; 

        default :
            cout << endl; 
            cout << "Erreur, nous sommes dans le default du switch sur E9." << endl; 
            cout << endl; 
    }
    return false; 
}