#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Frequency(int n, int tab[]){ // avec tab le tableau de valeur à tester et n sa longueur
    int i;
    int sn = 0;
    for(i=0; i<n; i++){
        sn += (2*tab[i])-1;
    }

    double sobs = (fabs(sn)) / sqrt(n); // = valeur abs / racine de n
    double pValeur = erfc(sobs/sqrt(2));

    return pValeur;
}

double runs(int n, int tab[]){
    // pre test : proportion de 1
    double pValeur = 0.0;
    int i;
    int nb1 = 0;
    for(i=0; i<n; i++){
        if(tab[i]==1){
            i++;
        }
    }
    double pi = nb1 / n;

    if(fabs(pi)-(1/2) >= 2/sqrt(n)){
        return pValeur;
    }

    int Vobs = 0;
    int k, rk;
    for(k = 0; k<n-1; k++){
        if(tab[k]==tab[k+1]){
            rk = 0;
        }else{
            rk = 1;
        }
        Vobs += rk+1;
    }

    pValeur = erfc(fabs(Vobs - 2*n*pi*(1-pi)) / 2*sqrt(2*n)*pi*(1-pi));
    return pValeur;
}

double exponentielle(double lambda){
    double res = (1-exp(-lambda));
    return res;
}

int main()
{
    int  test[31] = {0,1,0,1,1,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,1,0,1,0,1,1,1,0,0,0,1};
    int taille = 31;
   // double res = Frequency(taille, test);
    double res = runs(taille, test);
    printf("Resultat : %f\n", res);

    double i;
    for(i = 0.0; i<1024; i=i+1){
        printf("%f\n", exponentielle(i));
    }

    return 0;
}
