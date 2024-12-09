#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_dynamique {
    char *info ;
    struct file_dynamique *suivant ;
}File ;

File *Debut , *Fin ;
int Taille ;

void initialisation (){
    Taille = 0 ;
    Debut = Fin = NULL ; 
}

File *empiler (char *valeur){
    File *nouveau ;
    if ((nouveau = malloc(sizeof(File))) == NULL){
        printf("l allocation est impossible\n") ;
        return NULL ;
    }
    if ((nouveau -> info = malloc(sizeof(char) * (strlen(valeur)+1))) == NULL){
        printf("l allocation est impossible\n") ;
        free(nouveau) ;
        return NULL ;
    }
    strcpy (nouveau -> info , valeur) ;
    nouveau -> suivant = NULL ; 
    if (Debut == NULL){
        Debut = Fin = nouveau ;
    }
    else {
        Fin -> suivant = nouveau ;
        Fin = nouveau ;
    }
    Taille ++ ;
    return nouveau ;
}

int defiler (){
    if (Taille == 0){
        printf("rien a defiler\n") ;
        return -1 ;
    }
    File *Supp_elemnt = Debut ;
    if (Debut == Fin){
        Debut = Fin = NULL ; 
        Taille = 0 ;
    }
    else {
        Debut = Debut -> suivant ;
        Taille -- ;
    }
    free(Supp_elemnt -> info) ;
    free(Supp_elemnt); 
    return 0 ;
}

void affichage (){
    File *Courant = Debut ;
    while (Courant != NULL) {
        printf("%s" , Courant -> info) ;
        if (Courant -> suivant != NULL){
            printf("->") ;
        }
        Courant = Courant -> suivant ;
    }
}

void vider (){
    while(Taille > 0){
        defiler() ;
    }
}

int main (){
    empiler("Aboubakr") ;
    empiler("Tahir") ;
    empiler("kYs");
    defiler(); 
    vider();
    affichage();
    return 0 ;
}