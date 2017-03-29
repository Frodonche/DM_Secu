#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"

int hex_to_dec(char * hex){
    return strtoul(hex, NULL, 16);
}

llist dec_to_bin(int dec, llist liste, int taille){
    int r;
    int n = dec;
    int i = 0;
    while(n!=0 || i < taille){ // on rajoute taille histoire d'avoir le binaire de la taille que l'on veut
        if(n!=0){ // si le nombre n'est pas encore totalement traite
            r=n%2;
            liste = ajouter(liste, r);
            n=(n-r)/2;
        }else{ // si on a fini de traiter le nombre, on rajoute des 0
            liste = ajouter(liste, 0);
        }
        i++;
    }
    return liste;
}

int bin_to_dec(llist bin, int taille){
    int temp = 1;
    int res = 0;
    int i;
    for(i = 0; i < taille; i++){
        res = res + temp*get_element(bin, taille-i-1)->elem; // si le bit = 0, ça rajoute rien, sinon ça rajoute la valeur de la case
        temp = temp *2; // on decalle d'une case a gauche
    }
    return res;
}

llist hex_to_bin(char * hex, llist liste, int taille){
    int dec = hex_to_dec(hex);
    return dec_to_bin(dec, liste, taille);
}

void dec_to_hex(int dec){ // a n'utiliser que pour de l'affichage car crade
    long int decimalNumber = dec;
    long int quotient, temp;
	int i=1,j;
	char hexadecimalNumber[100];
	quotient = decimalNumber;
	while(quotient!=0) {
		temp = quotient % 16;
		//To convert integer into character
        if( temp < 10)
            temp =temp + 48;
        else
            temp = temp + 55;
		hexadecimalNumber[i++]= temp;
		quotient = quotient / 16;
	}
	for (j = i -1 ;j> 0;j--){
        printf("%c",hexadecimalNumber[j]);
	}
}

int rdtsc(){
    __asm__ __volatile__("rdtsc"); // pour un nombre aléatoire plus efficace
}

///////////////////////// PARTIE CONVERSION /////////////////////////////////
///////////////////////// PARTIE LISTES /////////////////////////////////////

llist ajouter(llist liste, int valeur){
    llist nouvel_element = malloc(sizeof(struct liste_s)); // On crée un nouvel élément

    nouvel_element->elem = valeur; // On assigne la valeur au nouvel élément

    nouvel_element->next = liste; // On assigne l'adresse de l'élément suivant au nouvel élément

    return nouvel_element; // On retourne la nouvelle liste, i.e. le pointeur sur le premier élément
}

llist init_liste_aleatoire(llist liste, int taille){ // on initialise la liste aléatoirement pour l'instant
    int i;
    int nombre;
    for(i = 0; i < taille; i++){
        srand(rdtsc());
        nombre = rand() % 2; // [0,2[
        liste = ajouter(liste, nombre);
    }
    return liste;
}

llist init_liste_hexa(llist liste, int taille, char* hexa){
    int i;
    llist bin = hex_to_bin(hexa, bin, taille);
    for(i = 0; i < taille; i++){
        liste = ajouter(liste, get_element(bin, taille-i-1)->elem); // on prend taille -i pour récupérer les bits de poids faible d'abord
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

    if(liste == NULL){ // Si l'élément est NULL, c'est que la liste contient moins de i éléments
        return NULL;
    }
    else{ // Sinon on renvoie l'adresse de l'élément i
        return liste;
    }
}

llist supprimerDernierElement(llist liste){
    if(liste == NULL) // Si la liste est vide, on retourne NULL
        return NULL;

    if(liste->next == NULL){ // Si la liste contient un seul élément
        free(liste); // On le libère et on retourne NULL (la liste est maintenant vide)
        return NULL;
    }

    // Si la liste contient au moins deux éléments
    llist tmp = liste;
    llist ptmp = liste;

    while(tmp->next != NULL){ // Tant qu'on n'est pas au dernier élément
        ptmp = tmp; // ptmp stock l'adresse de tmp
        tmp = tmp->next; // On déplace tmp (mais ptmp garde l'ancienne valeur de tmp
    }

    /* A la sortie de la boucle, tmp pointe sur le dernier élément, et ptmp sur
    l'avant-dernier. On indique que l'avant-dernier devient la fin de la liste
    et on supprime le dernier élément */
    ptmp->next = NULL;
    free(tmp);
    return liste;
}



// FONCTIONS MANIPULATION LISTES (AU DESSUS)

// FONCTIONS MANIPULATION LFSR

lfsr init_lfsr_alea(lfsr ls, int b1, int b2, int b3, int taille, int x){ // pour initialiser un lsfr aleatoirement
    ls -> b1 = b1;
    ls -> b2 = b2;
    ls -> b3 = b3;
    ls -> x = x;
    ls -> taille = taille;
    ls -> liste = NULL;
    ls -> liste = init_liste_aleatoire(ls->liste, ls->taille);
    return ls;
}

lfsr init_lfsr_hexa(lfsr ls, int b1, int b2, int b3, int taille, int x, char* hexa){
    ls -> b1 = b1;
    ls -> b2 = b2;
    ls -> b3 = b3;
    ls -> x = x;
    ls -> taille = taille;
    ls -> liste = NULL;
    ls -> liste = init_liste_hexa(ls->liste, taille, hexa);
    return ls;
}

void afficher_lfsr(lfsr ls){
    printf("Affichage du lsfr\n");
    printf("b1 : %d\n", ls->b1);
    printf("b2 : %d\n", ls->b2);
    printf("b3 : %d\n", ls->b3);
    printf("x : %d\n", ls->x);
    printf("Taille : %d\n", ls->taille);
    afficher_liste(ls->liste);
}

lfsr shift(lfsr ls){ // Pour shift :
    // On calcule d'abord la valeur à mettre au début
    // Càd (dernier element) XOR (bit n° b3) XOR (bit n° b2) XOR (bit n° b1)
    int last = get_element(ls->liste, ls->taille-1)->elem;

    int b3 = get_element(ls->liste, ls->b3)->elem;

    int b2 = get_element(ls->liste, ls->b2)->elem;

    int b1 = get_element(ls->liste, ls->b1)->elem;

    int nouveau = last^b3^b2^b1;
    //int nouveau = (get_element(ls->liste, ls->taille-1)->elem) ^ (ls->b3) ^ (ls->b2) ^ (ls->b1);

    // On l'ajoute à la liste
    ls->liste = ajouter(ls->liste, nouveau);

    // Et enfin, on supprime le dernier élément de la liste
    ls->liste = supprimerDernierElement(ls->liste);

    return NULL;
}

//////////// PARTIE LFSR ////////////
//////////// PARTIE FSM /////////////

fsm init_fsm(fsm f){
    f -> t = 1;

    f -> lfsr_1 = malloc(sizeof(struct lfsr_s));
    init_lfsr_hexa(f -> lfsr_1, 8, 12, 20, 25, 23, "04B583D");

    f -> lfsr_2 = malloc(sizeof(struct lfsr_s));
    init_lfsr_hexa(f -> lfsr_2, 12, 16, 24, 31, 23, "208E1EC1");

    f -> lfsr_3 = malloc(sizeof(struct lfsr_s));
    init_lfsr_hexa(f -> lfsr_3, 4, 24, 28, 33, 31, "063C142F0");

    f -> lfsr_4 = malloc(sizeof(struct lfsr_s));
    init_lfsr_hexa(f -> lfsr_4, 4, 28, 36, 39, 37, "0F7A2A42BB");

    f -> x1 = get_element(f->lfsr_1->liste, f->lfsr_1->x)->elem;
    f -> x2 = get_element(f->lfsr_2->liste, f->lfsr_2->x)->elem;
    f -> x3 = get_element(f->lfsr_3->liste, f->lfsr_3->x)->elem;
    f -> x4 = get_element(f->lfsr_4->liste, f->lfsr_4->x)->elem;

    // on initalise ct a 11
    f -> ct = NULL;
    f -> ct = ajouter(f->ct, 1);
    f -> ct = ajouter(f->ct, 1);

    //calcul de y en decimal, puis stockage en binaire
    int temp = f->x1 + f->x2 + f->x3 + f->x4 + bin_to_dec(f->ct, 2); // 2 car ct sur 2 bits
    f -> yt = NULL;
    f -> yt = dec_to_bin(temp, f->yt, 3); // car y est sur 3 bits

    f -> z = get_element(f->yt, 2)->elem; // 2 pour récupérer le bit 0 car yt sur 3 bits
    // on initialise ct-1 a 01
    f -> ctmoins = NULL;
    f -> ctmoins = ajouter(f->ctmoins, 1);
    f -> ctmoins = ajouter(f->ctmoins, 0);
}

void afficher_fsm(fsm f){
    printf("\n%d  ", f->t);
    dec_to_hex(bin_to_dec(f->lfsr_1->liste, f->lfsr_1->taille)); printf("    ");
    dec_to_hex(bin_to_dec(f->lfsr_2->liste, f->lfsr_2->taille)); printf("  ");
    dec_to_hex(bin_to_dec(f->lfsr_3->liste, f->lfsr_3->taille)); printf("  ");
    dec_to_hex(bin_to_dec(f->lfsr_4->liste, f->lfsr_4->taille)); printf("         ");
    printf("%d   ", f->x1);
    printf("%d   ", f->x2);
    printf("%d   ", f->x3);
    printf("%d   ", f->x4);
    printf("%d  ", f->z);
    printf("%d", f->ct->elem);
    printf("%d   ", f->ct->next->elem);
    printf("%d", f->ctmoins->elem);
    printf("%d   ", f->ctmoins->next->elem);
}
