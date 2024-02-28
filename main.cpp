#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(int argc, char *argv[]) {
   string chaine(argv[1]);

   Lexer l(chaine);
   Automate* a = new Automate(&l);
	
	
   a->exec();

   /*Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }*/
   return 0;
}

