#include "automate.h"
#include <iostream>
using namespace std; 

Automate :: Automate(Lexer * l){
    lexer = l;
    statestack.push(new E0());  
    symbolstack.push(new Symbole(0));
}



void Automate :: decalage(Symbole * s, Etat * e){
    symbolstack.push(s);
    statestack.push(e);
    lexer->Avancer();

}

void Automate :: transitionSimple (Symbole * s, Etat * e){
    symbolstack.push(s);
    statestack.push(e);

}

void Automate :: reduction(int n, Symbole * s){
   cout<<"reduction s =" ;
   s->Affiche();
    cout<<endl;
    for(int i = 0; i<n; i++){
        delete(statestack.top());
        statestack.pop();
    }
    cout <<"Haut de la pile Etat"<< statestack.top()->print()<<endl;
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
	while(*(s=lexer->Consulter())!=FIN) {
		
		cout<<"test current state " <<this->getCurrentState()->print()<<endl;
		if(this->getCurrentState()->transition(*this, s)) { fin = true ;break; }
	}
	cout << endl; cout << "Result : " << ((Entier*)symbolstack.top())->getValue() << endl; cout << endl; 
}
