
struct liste_s{
    int elem;
    struct liste_s *next;
};
typedef struct liste_s* llist;

struct lfsr_s{
    int b1; // le numéro des 3 bits a extraire
    int b2;
    int b3;
    int x; // le numéro du bit à extraire pour la FSM
    int taille;
    llist liste;
};
typedef struct lfsr_s* lfsr;

int hex_to_dec(char * hex);

llist dec_to_bin(int dec, llist liste, int taille);

llist hex_to_bin(char * hex, llist liste, int taille);

int rdtsc();

llist ajouter(llist liste, int valeur);

llist init_liste_aleatoire(llist liste, int taille);

llist init_liste_hexa(llist liste, int taille, char* hexa);

lfsr init_lfsr_hexa(lfsr ls, int b1, int b2, int b3, int taille, int x, char* hexa);

lfsr init_lfsr_alea(lfsr ls, int b1, int b2, int b3, int taille, int x); // pour initialiser un lfsr aleatoirement

void afficher_liste(llist liste);

void afficher_lfsr(lfsr ls);

llist get_element(llist liste, int indice);

lfsr shift(lfsr ls);
