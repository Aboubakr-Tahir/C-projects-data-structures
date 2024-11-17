#include <stdio.h> 
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 20

typedef char element ;
typedef element Pile[MAX] ; 
Pile p ; 
int sommet  ;
 

void init (){
     sommet = -1 ; 
}

int push (element alphabet){
    if (sommet == MAX-1) {
        printf("la pile est pleine impossible d'ajouter un element\n") ; 
        return 0 ; 
    }
    else {
        sommet ++ ;
        p[sommet] = alphabet ;   
        printf("l'alphabet \"%c\" a ete ajoute a la pile\n",alphabet) ; 
        return 1 ; 
    }
}

char pop (){
    if (sommet == -1 ){
        printf("la pile est vide\n") ; 
        return '\0' ;  
    }
    else {
        char c  = p[sommet] ; 
        sommet -- ; 
        printf("l'element %c a ete retire\n", c);
        return c ; 
    } 
}

int affiche(){
    int temp ;
    temp = sommet ; 
    if (temp == -1){
        printf("la pile est vide rien d'afficher\n") ; 
        return -1 ; 
    }
    else {
        printf("La pile cree est sous la forme :\n") ;
        while (temp >= 0){
            printf("%c\n", p[temp]) ; 
            temp -- ;
        }
    }

}
int main(){
    char *Nom ; 
    element c ;
    int i=0 , value=1 , temp ; 
    Nom = (char * )malloc(MAX*sizeof(char));
    printf("Entrer le nom : ");
    scanf("%s",Nom);
    init();
    for (int i=0 ; i<strlen(Nom) ; i++){
        c = Nom[i] ; 
        push(c) ; 
    }
    affiche();

    temp = sommet ; 
    if (strlen(Nom) == 1){
        printf("le nom constitue d'un seul caractere est palindrome\n");
    }
    else {
        while (i<temp){ 
            if (p[temp] == p[i]){
                value = 1 ; 
            }
            else {
                value = 0 ; 
            }
            i ++ ;
            temp -- ;
        }
    }
    if (value == 0){
        printf("le nom n'est pas un palindrome\n") ; 
    }
    else {
        printf("le nom est palindrome\n") ;
    } 
    return 0 ; 
}
