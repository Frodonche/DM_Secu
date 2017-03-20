#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"

llist ajouter(llist liste, int valeur){
    llist nouvel_element = malloc(sizeof(struct liste_s)); // On cr�e un nouvel �l�ment

    nouvel_element->elem = valeur; // On assigne la valeur au nouvel �l�ment

    nouvel_element->next = liste; // On assigne l'adresse de l'�l�ment suivant au nouvel �l�ment

    return nouvel_element; // On retourne la nouvelle liste, i.e. le pointeur sur le premier �l�ment
}

llist init_liste_aleatoire(llist liste, int taille){ // on initialise la liste "al�atoirement" pour l'instant
    int i;
    int nombre;
    for(i = 0; i < taille; i++){
        nombre = rand() % 2; // [0,2[
        liste = ajouter(liste, nombre);
    }
    return liste;
}

void afficher_liste(llist liste){
    printf("Affichage de la liste : [ ");
    llist tmp = liste;
    while(tmp != NULL){
        printf("%d ", tmp->elem);
        tmp = tmp->next;
    }
    printf("]\n");
}

llist get_element(llist liste, int indice){
    int i;
    for(i=0; i<indice && liste != NULL; i++){ //tant qu'on n'a pas atteint la case ou le bout de la liste
        liste = liste->next;
    }

    if(liste == NULL){ // Si l'�l�ment est NULL, c'est que la liste contient moins de i �l�ments
        return NULL;
    }
    else{ // Sinon on renvoie l'adresse de l'�l�ment i
        return liste;
    }
}

llist supprimerDernierElement(llist liste){
    if(liste == NULL) // Si la liste est vide, on retourne NULL
        return NULL;

    if(liste->next == NULL){ // Si la liste contient un seul �l�ment
        free(liste); // On le lib�re et on retourne NULL (la liste est maintenant vide)
        return NULL;
    }

    // Si la liste contient au moins deux �l�ments
    llist tmp = liste;
    llist ptmp = liste;

    while(tmp->next != NULL){ // Tant qu'on n'est pas au dernier �l�ment
        ptmp = tmp; // ptmp stock l'adresse de tmp
        tmp = tmp->next; // On d�place tmp (mais ptmp garde l'ancienne valeur de tmp
    }

    /* A la sortie de la boucle, tmp pointe sur le dernier �l�ment, et ptmp sur
    l'avant-dernier. On indique que l'avant-dernier devient la fin de la liste
    et on supprime le dernier �l�ment */
    ptmp->next = NULL;
    free(tmp);
    return liste;
}



// FONCTIONS MANIPULATION LISTES (AU DESSUS)

// FONCTIONS MANIPULATION LSFR

lfsr init_lfsr(lfsr ls, int b1, int b2, int b3, int taille){ // pour initialiser un lsfr
    ls -> b1 = b1;
    ls -> b2 = b2;
    ls -> b3 = b3;
    ls -> taille = taille;
    ls -> liste = NULL;
    ls -> liste = init_liste_aleatoire(ls->liste, ls->taille);
    return ls;
}

void afficher_lfsr(lfsr ls){
    printf("Affichage du lsfr\n");
    printf("b1 : %d\n", ls->b1);
    printf("b2 : %d\n", ls->b2);
    printf("b3 : %d\n", ls->b3);
    printf("Taille : %d\n", ls->taille);
    afficher_liste(ls->liste);
}

lfsr shift(lfsr ls){ // Pour shift :
    // On calcule d'abord la valeur � mettre au d�but
    // C�d (dernier element) XOR (bit n� b3) XOR (bit n� b2) XOR (bit n� b1)
    int last = get_element(ls->liste, ls->taille-1)->elem;

    int b3 = get_element(ls->liste, ls->b3)->elem;

    int b2 = get_element(ls->liste, ls->b2)->elem;

    int b1 = get_element(ls->liste, ls->b1)->elem;

    int nouveau = last^b3^b2^b1;
    //int nouveau = (get_element(ls->liste, ls->taille-1)->elem) ^ (ls->b3) ^ (ls->b2) ^ (ls->b1);

    // On l'ajoute � la liste
    ls->liste = ajouter(ls->liste, nouveau);

    // Et enfin, on supprime le dernier �l�ment de la liste
    ls->liste = supprimerDernierElement(ls->liste);

    return NULL;
}
