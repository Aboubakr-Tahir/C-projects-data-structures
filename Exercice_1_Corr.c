#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int N ;
int Max (int *Tab){
    int val_max = Tab[0] ;
    for (int i = 1 ; i<N ; i++){
        if (val_max < Tab[i]){
            val_max = Tab[i] ;
        }
    }
    return val_max ;
}

int main (){
    printf("Entrer combien de nombre vous voulez saisir:\n") ;
    scanf("%d",&N);
    int Tab[N] ;
     printf("Entrer :\n") ;
    for (int i =0 ; i<N ; i++){
        printf("Tab[%d] = ",i+1,Tab[i]) ;
        scanf("%d",&Tab[i]) ;
    }
    printf("la valeur maximal est : %d",Max(Tab));
    return 0 ;
}