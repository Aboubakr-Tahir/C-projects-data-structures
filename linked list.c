#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct Element {
char *mot ;
struct Element *suivant ; } noeud;

noeud *debut = NULL , *fin = NULL ;
int taille = 0 ;
noeud *creat_first_new_node(char *mot){
    noeud *result = malloc(sizeof(noeud));
    result -> mot = mot ; 
    result -> suivant = NULL ; 
    debut = result ; 
    fin = result ;
    taille ++ ; 
    return result ; 
}

noeud *insert_fin_node (char *mot){
    noeud *result = malloc (sizeof (noeud)) ; 
    result -> mot = mot ; 
    result -> suivant = NULL ; 
    if ( fin != NULL ){
        fin -> suivant = result ; 
    } 
    fin = result ;   
    taille ++ ;  
    return result ;  
    }


void affiche (){
    noeud *courant ;
    courant = debut ; 
    while ( courant != NULL ){
        printf("%s" , courant -> mot) ; 
        if (courant -> suivant != NULL){
            printf(" -> ");
        }
        courant =  courant -> suivant ;  
    }
} 

void affiche_inverse(noeud *courant ){
if (courant == NULL){
    return ; 
}
affiche_inverse(courant -> suivant) ;
printf("%s", courant-> mot);
if (courant != debut){
    printf("<-");
}

}


int main () {
//  Réaliser les opérations suivantes :
//  Créer la liste chaînée (initialisation du premier élément)
//  Insérer de nouveaux noeuds (à la fin)
//  Parcourir la liste en affichant le texte
//  Afficher les nœuds (mots) dans le sens inverse.
creat_first_new_node("aboubakr");
insert_fin_node("Tahir"); 
insert_fin_node("ISIBID") ; 
insert_fin_node("Cycle"); 
affiche(); 
printf("\n");
affiche_inverse(debut);
    return 0;
} 