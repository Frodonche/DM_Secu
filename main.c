#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int main()
{
    printf("Implementation de l'algorithme E0\n");

    lsfr l1 = malloc(sizeof(struct lsfr_s));

    lsfr l2 = malloc(sizeof(struct lsfr_s));

    lsfr l3 = malloc(sizeof(struct lsfr_s));

    lsfr l4 = malloc(sizeof(struct lsfr_s));

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
