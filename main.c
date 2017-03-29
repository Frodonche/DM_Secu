#include <stdio.h>
#include <stdlib.h>
#include "tests.h"

int main()
{
    printf("Implementation de l'algorithme E0\n");

    lfsr l1 = malloc(sizeof(struct lfsr_s));
    init_lfsr_hexa(l1, 8, 12, 20, 25, 23, "04B583D");


    lfsr l2 = malloc(sizeof(struct lfsr_s));
    init_lfsr_hexa(l2, 12, 16, 24, 31, 23, "208E1EC1");

    lfsr l3 = malloc(sizeof(struct lfsr_s));
    init_lfsr_hexa(l3, 4, 24, 28, 33, 31, "063C142F0");

    lfsr l4 = malloc(sizeof(struct lfsr_s));
    init_lfsr_hexa(l4, 4, 28, 36, 39, 37, "0F7A2A42BB");

    //test(l1, l2, l3, l4);
    //test_convertisseurs();
    fsm f = malloc(sizeof(struct fsm_s));
    f = init_fsm(f);

    return 0;
}

/*int main ()
{
Vecteurs de test pour votre impl�ementation de E0
Pour chacun des 3 g�en�erateurs
Pour i variant de 1 `a 20 faire
G�en�erer une s�equence de 1024 blocs initialis�e les g�en�erateurs via par exemple la fonction srand(sdtsc()) qui permet de g�en�erer des nombres al�eatoires diff�erents `a chaque appel
Test de fr�equence monobits // sortie dans un fichier
Test des Runs // sortie dans le m�eme fichier
}*/
