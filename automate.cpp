#include "automate.h"
#include <iostream>
using namespace std; 

Automate :: Automate(Lexer * l){
    lexer = l;
    statestack.push(new E0());  
    isAccepted = false;

}



void Automate :: decalage(Symbole * s, Etat * e){
    symbolstack.push(s);
    statestack.push(e);
    if(s->isTerminal()) {
        lexer->Avancer();
    }
}

void Automate :: transitionSimple (Symbole * s, Etat * e){
    symbolstack.push(s);
    statestack.push(e);

}

void Automate :: reduction(int n, Symbole * s){
    cout <<"reduction s =";
    s->Affiche();
    cout << endl;
    try{
        cout << "val = " << ((Entier*)s)->getValue() << endl;
    } catch (const std::exception& e) {
    }

    cout<<endl;
    for(int i = 0; i<n; i++){
        delete(statestack.top());
        statestack.pop();
    }
    cout <<"Haut de la pile Etat : "<< statestack.top()->print()<<endl;
    statestack.top()->transition(*this, s);
    
}

void Automate :: dequeueAll(){
    while(!statestack.empty()){
        statestack.pop(); 
    }
}


Symbole* Automate :: popSymbole(){
    Symbole * s = symbolstack.top();
    symbolstack.pop();
    return s;
}

void Automate :: popAndSupprSymbol(){
    delete(statestack.top());
    symbolstack.pop();
}

void Automate :: accepter(){
    isAccepted= true;
    cout<<"Analyse finie."<<endl; 

}

Etat* Automate::getCurrentState() {
	return statestack.top();
}
Symbole * Automate::getCurrentSymbole(){
    return symbolstack.top();
}

void Automate::exec() {
	
	Symbole* s;
    bool fin = false;
	while(this->isAccepted != true ) {
		s=lexer->Consulter();
		cout<<"test current state " <<this->getCurrentState()->print()<<endl;
		this->getCurrentState()->transition(*this, s);
	}
	cout << endl; cout << "Result : " << ((Entier*)symbolstack.top())->getValue() << endl; cout << endl; 
}
