#include <stdio.h>
#include <stdlib.h>
#include "tests.h"

int main()
{
    //test(l1, l2, l3, l4);
    //test_convertisseurs();
    fsm f = malloc(sizeof(struct fsm_s));
    f = init_fsm(f);

    printf("t  LFSR1     LFSR2     LFSR3     LFSR4     X1  X2  X3  X4  z  ct  ct-1\n");

    afficher_fsm(f);

    return 0;
}

/*int main ()
{
Vecteurs de test pour votre impl´ementation de E0
Pour chacun des 3 g´en´erateurs
Pour i variant de 1 `a 20 faire
G´en´erer une s´equence de 1024 blocs initialis´e les g´en´erateurs via par exemple la fonction srand(sdtsc()) qui permet de g´en´erer des nombres al´eatoires diff´erents `a chaque appel
Test de fr´equence monobits // sortie dans un fichier
Test des Runs // sortie dans le mˆeme fichier
}*/
