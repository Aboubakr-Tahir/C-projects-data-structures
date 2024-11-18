#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define MAX 5

typedef struct {
int arr[MAX];
int front , rear ; 
}circular_queue;


void init_queue (circular_queue *q){
    q->front = -1 ; q->rear = -1 ; 
}
 
int is_empty (circular_queue *q){
    return q->front == -1 ; 
}

int is_Full (circular_queue *q){
    return (q->rear+1) % MAX == q->front ; 
}

void enqueue (circular_queue *q, int value){
    if (is_Full(q)) {
        printf("Queue est saturee impossible d'ajouter un aliment\n");
    } 
    else {
        if (q->front == -1){
        q->front = 0 ;
        } 
        q-> rear = (q ->rear+1) % MAX ;
        q->arr[q->rear] = value ;  
        printf("Element ajoutee %d\n" , q->arr[q->rear]);
    }
}

int dequeue (circular_queue *q) {
    if (is_empty(q)) {
        printf("queue est deja vide , impossible d'extraire ");
        return -1 ; 
    } 
    else {
        int value = q->arr[q->front] ;
        if (q->front == q->rear){
            q->front = q->rear = -1 ;
            printf("la file a devenue vide , l'element extrait est : %d\n" , value);   
        } 
        else { 
                q->front = (q->front + 1 ) % MAX ; 
                printf("l element extrait est %d\n" , value);
        }  
          return value ; 
    } 
}

int peek (circular_queue *q){
    if (is_empty(q)) {
        printf("queue est vide\n");
        return 1 ; 
    }
    else  {
        printf("la tete de la file est : %d\n" ,q->arr[q->front]) ;
        return q->arr[q->front] ; 
    }
}

void display (circular_queue *q) {
    if (is_empty(q)) { 
        printf("la file est vide\n") ; 
    }
    else {
        int i = q->front ; 
        printf("les elements de la file sont : ") ; 
        while (i!= q->rear){
            printf("%d " , q-> arr[i]);
            i = (i+1) % MAX ; 
        }
        printf("%d\n", q->arr[q->rear]);   
    }

}

int main (){ 
    circular_queue *q = (circular_queue*) malloc(sizeof(circular_queue));     
    init_queue (q);
    enqueue (q, 10);
    enqueue (q, 20);
    enqueue (q, 30);
    enqueue (q, 40);
    enqueue (q, 50);
    enqueue (q, 60); 
    peek(q) ;  
    display(q);
    return 0 ; 
}