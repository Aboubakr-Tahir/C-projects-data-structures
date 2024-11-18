#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define N 5

typedef struct {
    int tab[N];
    int front , rear ;
}circular_file ; 

void fileVide (circular_file *p){
    p->front = p->rear = -1 ;
}

int emfiler (circular_file *p , int value){
    if ((p->rear +1)%N == p->front){
        printf("la file est pleine impossible d' emfiler\n");
        return -1;
    }
    else {
        if (p->front == -1){
            p->front = 0;
        }
    
        p->rear = (p->rear +1) % N ; 
        p->tab[p->rear] = value ; 
    }
        return p->tab[p->rear];
}

int defiler (circular_file *p){
    int value ; 
    if (p->front == -1){
        printf("la file est vide impossible de defiler\n");
        return -1;
    }
    else {
        if (p->front == p->rear){
            value = p->tab[p->front];
            p->front = p->rear = -1 ;
            return value ;
        }
        else {
            value = p->tab[p->front];
            p->front = (p->front + 1) % N ; 
            return value ; 
        }
    }
}
void defilerEnfiler(circular_file *p1 , circular_file *p2) {
    emfiler(p2,defiler(p1));
}

int comparer(circular_file *p1 , circular_file *p2){
    if (p1 ->front == -1 || p2->front == -1){
        printf("une pile est vide impossible de comparer\n");
        return -1 ;
    }
    else {
        if (p1->tab[p1->front] >= p2->tab[p2->front]){
            return 1 ;
        } 
        else {
            return 0 ;
        }  
    }
}

void affich(circular_file *p){
    if (p->front == -1){
        printf("rien d'afficher la pile est vide\n");
    }
    else{
        int i = p->front ;
        while (i!= p->rear){
            printf("%d-", p->tab[i]);
            i = (i+1)%N;
        }
        printf("%d\n", p->tab[p->rear]);
    }
} 

void triage (circular_file *f1 , circular_file *f2 , circular_file *f3){
    while (f1 -> front != -1){
        defilerEnfiler(f1,f3) ; 
        while (f1 -> front != -1){
            if (!comparer(f1,f3)){
                defilerEnfiler(f3,f1);
                defilerEnfiler(f1,f3);
            } 
            else {
                defilerEnfiler(f1 , f2);
            }
        }
        while (f2 -> front != -1){
            defilerEnfiler(f2 , f1);
        }

        defilerEnfiler(f3,f2);
        
    }
}



int main(){
    circular_file *p1 = (circular_file *) malloc(sizeof(circular_file));
    circular_file *p2 = (circular_file *) malloc(sizeof(circular_file));
    circular_file *p3 = (circular_file *) malloc(sizeof(circular_file));
    fileVide(p1);
    fileVide(p2);
    fileVide(p3);
    emfiler(p1,108); 
    emfiler(p1,27);
    emfiler(p1,99);
    emfiler(p1,55);
    affich(p1);
    
    affich(p1);
    affich(p2);
    affich(p3);
    return 0; 
}