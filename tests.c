#include <stdio.h>
#include <stdlib.h>
#include "tests.h"

void test(lfsr l1, lfsr l2, lfsr l3, lfsr l4){
    printf("\nLFSR 1\n");
    afficher_lfsr(l1);
    printf("Le dernier element de la liste : %d\n", get_element(l1->liste, l1->taille-1)->elem);
    printf("Maintenant, on shift un coup\n");
    shift(l1);
    afficher_lfsr(l1);

    printf("\nLFSR 2\n");
    afficher_lfsr(l2);
    printf("Le dernier element de la liste : %d\n", get_element(l2->liste, l2->taille-1)->elem);
    printf("Maintenant, on shift un coup\n");
    shift(l2);
    afficher_lfsr(l2);

    printf("\nLFSR 3\n");
    afficher_lfsr(l3);
    printf("Le dernier element de la liste : %d\n", get_element(l3->liste, l3->taille-1)->elem);
    printf("Maintenant, on shift un coup\n");
    shift(l3);
    afficher_lfsr(l3);

    printf("\nLFSR 4\n");
    afficher_lfsr(l4);
    printf("Le dernier element de la liste : %d\n", get_element(l4->liste, l4->taille-1)->elem);
    printf("Maintenant, on shift un coup\n");
    shift(l4);
    afficher_lfsr(l4);
}

void test_convertisseurs(){
    char * hex = "8";
    int dec = hex_to_dec(hex);
    printf("Dec : %d\n", dec);
    llist bin = NULL;
    bin = dec_to_bin(dec, bin, 10);
    afficher_liste(bin);


}
