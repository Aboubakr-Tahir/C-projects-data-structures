#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define N 5

typedef struct {
    int tab[N];
    int sommet ; 
}pile ; 
 
pile * Creer_InitialiserPile() {
    pile *p = (pile *)malloc(sizeof(pile)) ;
    p->sommet = -1 ; 
    return p ; 
}
int pileVide(pile p ){
    if (p.sommet == -1 ){
        return 1 ;
    }
    else {
        return 0 ; 
    }
}
int depiler(pile *p){
    if (p->sommet == -1){
        printf("la pile est deja vide impossible de depiler\n") ;
        return 0;
    }
    else {
        int value = p->tab[p->sommet] ; 
        p->sommet -- ; 
        printf("la valeur %d a ete depile\n",value);
        return value ;
    }
}
void empiler(pile *p , int elt){
    if (p->sommet >= N-1){
        printf("la pile est pleine , impossible d'empiler\n") ;
    }
    else {
        p->sommet ++ ;
        p->tab[p->sommet] = elt ; 
        printf("%d a ete ajoute avec succes dans la pile\n",p->tab[p->sommet]); 
    } 
}



int SommetPile(pile p){
    return p.tab[p.sommet] ;
}

void transfert_piles_pairs_impairs (pile *p1 , pile *p2){
    int temp ; 
    temp = p1->sommet ; 
    while(temp >= 0){
        if (p1->tab[temp]%2 != 0){
            empiler(p2 , p1->tab[temp]) ;
        }
        temp -- ;
    }
    temp = p1->sommet ;
    while(temp >= 0){
        if (p1->tab[temp]%2 == 0){
            empiler(p2 , p1->tab[temp]) ;
        }
        temp -- ;
    }

}

void transfert_pairs_seulement (pile *p1 , pile *p2){ 
    int i = 0; 
    while(i<=p1->sommet){ 
        if (p1 -> tab[i] % 2 == 0){
            empiler(p2  , p1->tab[i]) ;
        }
        i ++ ;
    }
} 


void affiche(pile *p){
    if (p->sommet == -1){
        printf("la file est vide aucune possibilite , rien d'afficher\n") ; 
    }
    else {
        printf("la pile est : \n") ;
        int temp = p->sommet ; 
        for (int i=0 ; i<= p->sommet ; i++){
            printf("%d\n" , p->tab[temp]) ;
            temp -- ; 
        }
    }
}

int main(){
    pile *P1 , *P2 , *P3 ;
    P1 = Creer_InitialiserPile() ;
    P2 = Creer_InitialiserPile() ;
    P3 = Creer_InitialiserPile() ; 
    for (int i=0 ; i<N ; i++){
        empiler(P1 , i+2) ;
    } 
    transfert_piles_pairs_impairs(P1 , P2) ; 
    affiche(P1);
    affiche(P2) ;  
    return 0 ;
}