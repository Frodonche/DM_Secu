struct liste_s{
    int elem;
    struct liste_s *next;
};
typedef struct liste_s* llist;

struct lsfr_s{
    int b1; // les 3 bits a extraire
    int b2;
    int b3;
    int taille;
    int next_value;
    llist liste;
};
typedef struct lsfr_s* lsfr;

llist ajouter(llist liste, int valeur);

llist init_liste_aleatoire(llist liste, int taille);

lsfr init_lsfr(lsfr ls, int b1, int b2, int b3, int taille, llist li); // pour initialiser un lsfr

