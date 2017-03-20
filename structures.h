struct liste_s{
    int elem;
    struct liste_s *next;
};
typedef struct liste_s* llist;

struct lfsr_s{
    int b1; // les 3 bits a extraire
    int b2;
    int b3;
    int taille;
    llist liste;
};
typedef struct lfsr_s* lfsr;

llist ajouter(llist liste, int valeur);

llist init_liste_aleatoire(llist liste, int taille);

lfsr init_lfsr(lfsr ls, int b1, int b2, int b3, int taille); // pour initialiser un lfsr

void afficher_liste(llist liste);

void afficher_lfsr(lfsr ls);

llist get_element(llist liste, int indice);

lfsr shift(lfsr ls);
