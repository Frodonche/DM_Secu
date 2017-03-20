#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"

llist ajouter(llist liste, int valeur){
    llist nouvel_element = malloc(sizeof(struct liste_s)); // On crée un nouvel élément

    nouvel_element->elem = valeur; // On assigne la valeur au nouvel élément

    nouvel_element->next = liste; // On assigne l'adresse de l'élément suivant au nouvel élément

    return nouvel_element; // On retourne la nouvelle liste, i.e. le pointeur sur le premier élément
}

llist init_liste_aleatoire(llist liste, int taille){
    int i;
    int nombre;
    for(i = 0; i < taille; i++){
        nombre = rand() % 2; // [0,2[

    }

}

lsfr init_lsfr(lsfr ls, int b1, int b2, int b3, int taille, llist li){ // pour initialiser un lsfr
    ls -> b1 = b1;
    ls -> b2 = b2;
    ls -> b3 = b3;
    ls -> taille = taille;
    ls -> liste = init_liste_aleatoire(ls->liste, ls->taille);
    return ls;
}
