#include <stdio.h>
#include <stdlib.h> 
#define MAX 5

typedef char element ; 
typedef element Pile[MAX] ;
int sommet = -1 ;   Pile p ; 


int push (int value ){
    if (sommet >= MAX - 1 ){
        printf("la pile est pleine\n") ; 
        return -1 ; 
    }
    else {
        sommet ++ ; 
        p[sommet] = value ; 
        printf("l'element ajoute est %d\n", p[sommet]) ; 
    }
}  

int pop(){
    if (sommet < 0 ){
        printf("la file est deja vide impossible de supprimer un element\n") ; 
        return -1 ; 
    }
    else {
        int value = p[sommet] ; 
        sommet -- ;
        return value ;
    }
}

void affiche() {
    printf("la pile est sous la forme de  :\n");
    for (int i = sommet ; i>=0 ; i--){
        printf("%d\n", p[i]);
    }
}

int main(){
push(5);
push(7);
push(10);
affiche() ; 
pop();
affiche();
pop();
affiche();
push(17);
affiche();
    return 0 ; 
}