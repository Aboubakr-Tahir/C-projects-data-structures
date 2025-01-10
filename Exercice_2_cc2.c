#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (){
    int *Tab , N , i = 0 ; 
    printf("Entrer le nombre d'elements :");
    scanf("%d",&N);
    Tab = (int *)malloc(N * sizeof(int)) ;
    while (i<N){
        printf("T[%d]=",i+1) ;
        scanf("%d", &Tab[i]);
        printf("\n");
        i++;
    }
    int current_lenght = 1 , min_lenght = N ;
    for (i=1 ; i<N ; i++){
        if (Tab[i] == Tab[i-1]){
            current_lenght ++ ;
        }
        else {
            if (current_lenght < min_lenght){
                min_lenght = current_lenght ;
            }
            else {
                current_lenght = 1 ;
            }
        }
    }
    if (current_lenght < min_lenght){
        min_lenght = current_lenght ;
    }
    printf("le plus petit plateu dans le tableau est de longueur : %d\n",min_lenght);
    free(Tab);
    return 0 ;
}