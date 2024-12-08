#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fake_List {
    char * info ;
    struct fake_List *suivant ; 
    struct fake_List *precedent ; 
}Element ;

int Taille ; 
Element *Debut , *Fin ; 

void initialisation(){
    Debut = Fin = NULL ; 
    Taille = 0 ;
}

Element *insert_liste_vide (char *valeur){
    Element *nouveau = (Element *) malloc(sizeof(Element)) ;
    if (nouveau == NULL){
        printf("l'allocation de memoire a ehoue\n") ; 
        return NULL ; 
    }
    if((nouveau -> info = (char *)malloc(sizeof(char)*50)) ==NULL ){
        printf("l'allocation de memoire a ehoue\n") ; 
        free(nouveau) ;
        return NULL ; 
    } 
    strcpy(nouveau->info , valeur) ; 
    nouveau -> suivant = nouveau -> precedent = NULL ; 
    Debut = nouveau ; 
    Fin = nouveau ;
    Taille ++ ;
    return nouveau ; 
}  

Element *insert_debut (char *valeur){
    Element *nouveau = (Element *)malloc(sizeof(Element)) ;
    if (nouveau == NULL){
        printf("l allocation de memoire a echoue\n") ; 
        return NULL ; 
    }
    if ((nouveau->info = (char *)malloc(sizeof(char) * 50)) == NULL){
         printf("l allocation de memoire a echoue\n") ; 
         free(nouveau) ; 
        return NULL ; 
    }
    strcpy(nouveau->info , valeur) ; 
    nouveau -> suivant = Debut  ; 
    nouveau -> precedent = NULL ; 
    Debut -> precedent = nouveau ; 
    Debut = nouveau ; 
    Taille ++ ;
    return nouveau ;
}

Element *insert_fin_liste (char *valeur){
    Element *nouveau = (Element *)malloc(sizeof(Element)) ;
    if (nouveau == NULL){
        printf("l allocation de memoire a echoue\n") ; 
        return NULL ; 
    }
    if ((nouveau->info = (char *)malloc(sizeof(char) * 50)) == NULL){
         printf("l allocation de memoire a echoue\n") ; 
         free(nouveau) ; 
        return NULL ; 
}
    strcpy (nouveau->info , valeur) ; 
    Fin -> suivant = nouveau ; 
    nouveau -> precedent = Fin ;
    nouveau -> suivant = NULL ;
    Fin = nouveau ; 
    Taille ++ ;
    return nouveau ; 
}

Element *insert_avant (int pos , char *valeur){
    Element *nouveau ; 
    if (((nouveau = (Element *)malloc(sizeof(Element))) == NULL)){ 
        printf("l'allocation de memoire a echoue\n") ; 
        return NULL ;
    }
    if ((nouveau->info =(char *)malloc(sizeof(char) * 100)) == NULL){
        printf("l allocation de memoire a echoue\n") ; 
        free(nouveau) ; 
        return NULL ; 
    }  
    strcpy(nouveau -> info , valeur) ;
    Element *prochain = Debut; 
    if (pos == 1){
        Debut -> precedent = nouveau ; 
        nouveau -> suivant = Debut ; 
        nouveau -> precedent = NULL ; 
        Debut = nouveau ;
        Taille ++ ;
        return nouveau ; 
    }
    for (int i = 1 ; i<pos ; i++){
        prochain = prochain -> suivant ; 
    }
    nouveau -> suivant = prochain ; 
    nouveau -> precedent = prochain -> precedent ; 
    prochain -> precedent -> suivant = nouveau ;  
    prochain -> precedent = nouveau ; 
    Taille ++ ;
    return nouveau ; 

}

Element *insert_apres(int pos , char *valeur){
    Element *nouveau ; 
    if (((nouveau = (Element *)malloc(sizeof(Element))) == NULL)){ 
        printf("l'allocation de memoire a echoue\n") ; 
        return NULL ;
    }
    if ((nouveau->info =(char *)malloc(sizeof(char) * 100)) == NULL){
        printf("l allocation de memoire a echoue\n") ; 
        free(nouveau) ; 
        return NULL ; 
    }  
    strcpy(nouveau -> info , valeur) ;
    Element *Avant = Debut; 
    for (int i = 1 ; i<pos ; i++){
        Avant = Avant -> suivant ; 
    }
    if (Avant == Fin){
        nouveau -> precedent = Avant ; 
        nouveau -> suivant = NULL ; 
        Avant -> suivant = nouveau ;
        Fin = nouveau ; 
        Taille ++ ;
        return nouveau ;
    }
    nouveau -> suivant = Avant -> suivant ;
    nouveau -> precedent = Avant  ; 
    Avant -> suivant -> precedent = nouveau ;
    Avant -> suivant = nouveau ;
    Taille ++ ;
    return nouveau ;
}

int suppression (int pos){
    Element *supp_element ;
    if (pos == 1 ){
        supp_element = Debut ;
        if (supp_element -> suivant == NULL) {
            Debut = NULL ; 
            Fin = NULL ; 
            Taille = 0 ;
            free(supp_element) ; 
            return 0 ;
        }
        else {
            Debut = Debut -> suivant ; 
            Debut -> precedent = NULL ;
            Taille -- ;
            free(supp_element) ;
            return 0 ;
        }
    }
    else if (pos == Taille){
        supp_element = Fin ;
        if (supp_element -> precedent == NULL){
            Taille = 0 ; 
            Fin = Debut = NULL ; 
            free(supp_element) ; 
            return 0 ; 
        }
        else {
            supp_element -> precedent -> suivant = NULL ; 
            Fin = Fin -> precedent ;
            free(supp_element) ;
            Taille -- ;
            return 0 ;
        }

    }
    else {
        supp_element = Debut ;
        for (int i=1 ; i<pos ; i++){
            supp_element = supp_element -> suivant ;
        }
        supp_element -> precedent -> suivant = supp_element -> suivant ;
        supp_element -> suivant -> precedent = supp_element -> precedent ; 
        free(supp_element) ;
        Taille -- ;
        return 0 ;
    }
}

void affichage(){
    Element *temp = Debut  ;
    while(temp != NULL){
        printf("%s",temp->info) ; 
        if (temp->suivant != NULL){
            printf("->") ; 
        }
        temp = temp->suivant ; 
    }
    printf("\n") ; 
}

void destruct (){
    while (Taille > 0) {
        suppression(1) ;
    }
}

int main (){
    insert_liste_vide("test");
    insert_debut("Aboubakr") ; 
    insert_debut("Tahir") ; 
    insert_fin_liste("Valid") ; 
    affichage() ;
    insert_apres(2,"pas") ; 
    affichage() ; 
    insert_apres(5 , "error") ;
    affichage() ;
    suppression(6);
    affichage(); 
    printf("la fin est : %s\n" , Fin->info) ; 
    printf("le debut est : %s\n" , Debut->info) ; 
    destruct();
    affichage();
    return 0 ;
}