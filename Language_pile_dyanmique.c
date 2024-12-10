#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noeud {
    char *info  ; 
    struct noeud *precedent ; 
}Noeud ;

typedef struct pile {
    int Taille ;
    Noeud *Sommet ;
}Pile ;

Pile *p1 , *p2 ;


void initialisation (Pile *p) {
    p->Sommet = NULL ;
    p -> Taille = 0 ;
}

Noeud *empiler (char *valeur , Pile *p){
    Noeud *nouveau ;
    if ((nouveau = (Noeud *)malloc(sizeof(Noeud))) == NULL){
        return NULL ;
    }
    if ((nouveau -> info = (char *)malloc(sizeof(char) * (strlen(valeur) + 1))) == NULL){
        free(nouveau) ;
        return NULL ;
    }
    strcpy (nouveau -> info , valeur) ;
    nouveau->precedent = p->Sommet ;
    p-> Sommet = nouveau ;
    p->Taille ++ ;
    return nouveau ;
}

int depiler (Pile *p){
    if (p->Taille == 0){
        return -1 ;
    }
    Noeud *Supp_element = p->Sommet ; 
    p->Sommet = p->Sommet->precedent ;
    free(Supp_element -> info); 
    free(Supp_element);
    p->Taille -- ;
    return 0 ;
}

void affich (Pile *p){
    Noeud *temp = p-> Sommet ;
    while (temp != NULL){
        printf("%s",temp-> info);
        if (temp -> precedent != NULL){
            printf("->");
        }
        temp = temp -> precedent ;
    } 
    printf("\n");
}

int vidage (Pile *p){
    if (p->Taille == 0){
        return -1 ;
    }
    while (p->Taille > 0){
        depiler(p) ;
    }
    return 0 ;
}

void insertion_mot (char *mot,Pile *p){
    for (int i=0 ; i<strlen(mot) ; i++){
        char temp[2] ;
        temp[0] = mot[i] ;
        temp[1] = '\0' ;
        empiler(temp , p) ;
    }
}

void Language_verif (char *mot){
    insertion_mot(mot ,p1); 
    Noeud *temp = p1->Sommet ;
    while (temp != NULL){
        empiler(temp->info ,p2) ; 
        temp = temp -> precedent ;
    }
    int count = 1 ;
    Noeud *temp_autre ;
    if ((temp_autre = (Noeud *)malloc(sizeof(Noeud))) == NULL){
        printf("l'allocation de memoire a echoue\n") ;
        
    }
    if ((temp_autre -> info = (char *)malloc(sizeof(char) * (strlen(mot) + 1))) == NULL){
        printf("l'allocation de memoire a echoue\n") ;
        free(temp_autre);
       
    }
    strcpy(temp_autre->info , mot) ;
    for (int i=0 ; i<((int)(p1->Taille/2)) ; i++){ 
        if (temp_autre->info[i] == 'c'){
            count = 1 ;
            break; 
        }
        else {
            count = 0 ;
        }
    }
    Noeud *temp_new = p1 -> Sommet ;
    for (int i=0 ; i<(int)((p1->Taille)/2) ; i++){
        temp_new = temp_new -> precedent ;
    }
    if (temp_new-> info[0] != 'c'){
        count = 0 ;
    }
    else {
        Noeud *Temp_1 = p1->Sommet ; 
        Noeud *Temp_2 = p2->Sommet ;
        while (Temp_1 != NULL && Temp_2 != NULL){
            if (Temp_1->info[0] != Temp_2->info[0]) {
                count = 0 ; break ; 
            }
            else{
                Temp_1 = Temp_1 -> precedent ;
                Temp_2 = Temp_2 -> precedent ;
            }
        }
    }
    if (count == 1){
        printf("la chaine : \"%s\" de l alphabet { a, b, c } est un element de language L\n",mot);
    }
    else{
        printf("la chaine : \"%s\" de l alphabet { a, b, c } n'est pas un element de language L\n",mot); 
    }
} 

int main (){
    p1 = (Pile *)malloc(sizeof(Pile)) ;
    p2 = (Pile *)malloc(sizeof(Pile)) ; 
    initialisation(p1) ;
    initialisation(p2) ;
    Language_verif("abcba"); 
    vidage(p1); 
    vidage(p2);
    free(p1);
    free(p2) ;
    return 0 ;
}