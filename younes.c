#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define N 5
typedef char Pile[N];
Pile p ;
int sommet=-1;
int empty (){
    if (sommet == -1)
    {
    printf("La pile est vide\n");
    return 1;
    }  else
    return 0;
} 
char push(char c){
    if (sommet == N-1){
        printf("La pile est pleine\n");
        return '\0';
    }else{
    sommet++;
    p[sommet] = c;
    return c;}
}
char pop(){
    if (empty()){ printf("La pile est vide\n");
    return '\0';
    }
     else{
     char oldchar=p[sommet];
      sommet--;
      return oldchar;
    }
}
int main(){
    int i,j,a=1;
    char *mot;
    mot=malloc(sizeof(char) *100);
    printf("Entrer votre chaine:");
    scanf("%s",mot);
    for(i=0,j=strlen(mot);i>strlen(mot),j<0;i++,j--){
       if(mot[i]!=mot[j]){
        a=0;
    
    }
    if(a==1)
    {printf("la chaine est palindrome\n");}
    else
    {printf("la chaine n'est pas palindrome\n");}
    free(mot);

    return 0 ;
    }
    } 