#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
typedef struct contact {
    char *Nom_Prenom  ; 
    char *numero ; 
    struct contact *suivant ;
}Contact ;

Contact *Debut = NULL ; 

Contact *creation_nv_contact (char *nv_nom , char *nv_num){
    Contact *nouveau = (Contact *)malloc(sizeof(Contact)) ;
    if (nouveau == NULL){
        printf("allocation de memoire du nouveau contact est impossible\n") ;
        return NULL ; 
    }
    else { 
        nouveau -> Nom_Prenom = (char *)malloc((strlen(nv_nom)+1)*sizeof(char));
         if (nouveau -> Nom_Prenom == NULL){
            printf("allocation de memoire du nom est impossible\n");
            free(nouveau);
            return NULL ;
        }
        strcpy(nouveau->Nom_Prenom , nv_nom); 
        nouveau -> numero = nv_num ;
        nouveau -> suivant = NULL ; 
        return nouveau ;
    }
} 

Contact *addContact (){
    char *Nv_nom_prenom = (char *)malloc(sizeof(char) *100) , *Nv_num = (char *)malloc(sizeof(char) *100)  ; 
    if (Nv_nom_prenom == NULL || Nv_num == NULL){
        printf("L'allocation de memoire est impossible \n") ; 
        return NULL ; 
    }
    printf("Entrer le Nom et Prenom du contact que vous voulez ajouter :\n") ;
    fgets(Nv_nom_prenom , 100 , stdin) ; 
    printf("Entrer Le numero de telephone de ce Contact :\n") ;
    fgets(Nv_num , 100 , stdin) ;

    Contact *nouveau = (Contact *)malloc(sizeof(Contact)) ;
    if (nouveau == NULL){
        printf("l allocation de memoire n a pas ete alloue \n");
        return NULL ; 
    } 
    nouveau -> Nom_Prenom = (char *)malloc(sizeof(char) *100) ; 
    if (nouveau -> Nom_Prenom == NULL){
        printf("l allocation de memoire n a pas ete alloue \n") ; 
        free(nouveau) ; 
        return NULL ; 
    }
    strcpy(nouveau -> Nom_Prenom , Nv_nom_prenom) ; 
    nouveau -> numero = (char *)malloc(sizeof(char)*100) ; 
    if (nouveau -> numero == NULL){
        printf("l allocation de memoire n a pas ete alloue \n") ; 
        free(nouveau) ; 
        free(nouveau->Nom_Prenom);
    }
    strcpy(nouveau->numero , Nv_num) ; 
    nouveau -> Nom_Prenom [strcspn(nouveau->Nom_Prenom,"\n")] = '\0' ; 
    nouveau -> numero [strcspn(nouveau->numero , "\n")] ='\0' ;
    if (Debut == NULL ) {
        Debut = nouveau ;
        nouveau -> suivant = NULL ; 
        return nouveau ;
    }
    else {
        Contact *prochain = Debut ;
        Contact *precedent  ; 
        if (strcmp(nouveau->Nom_Prenom , prochain->Nom_Prenom) < 0){
            nouveau -> suivant = Debut ;
            Debut = nouveau ;
            return nouveau ;
        }
        while ( prochain != NULL && strcmp(nouveau->Nom_Prenom , prochain ->Nom_Prenom) > 0 ){
            precedent = prochain ; 
            prochain = prochain -> suivant ; 
        }
        precedent -> suivant = nouveau ;
        nouveau -> suivant = prochain ;
        return nouveau ;
    }
    free(Nv_nom_prenom) ; 
    free(Nv_num) ; 
}

Contact *searchContact (){
    Contact *Courant = Debut ; 
    char *str = (char *)malloc(sizeof(char)* 100) ;
    if (str == NULL){
        printf("l allocation de memoire pour la chaine de caractere a echoue\n");
        return NULL ;
    }
    printf("Entrer le Nom et Prenom du contact que vous voulez chercher :\n") ;
    fgets(str , 100 , stdin); 
    str[strcspn(str, "\n")] = '\0';
    if(strcmp(str , Courant->Nom_Prenom) == 0){
        printf("Le contact trouve est : \nNom et Prenom : %s , Numero de telephone : %s\n",Courant -> Nom_Prenom , Courant->numero) ; 
        return Courant ; 
    }  
    while ( Courant != NULL && strcmp(str , Courant -> Nom_Prenom) != 0 ){
        Courant = Courant -> suivant  ;
    }
    if (Courant != NULL){
        printf("Le contact trouve est : \nNom et Prenom : %s , Numero de telephone : %s\n",Courant-> Nom_Prenom , Courant->numero);
        return Courant ;
    }
    else if (Courant == NULL) {
        printf("le Contact n'a pas ete trouvee s'il vous plait entrer le Nom et Prenom exacte\n");
        return NULL ; 
    }
}

void affichage (){
    Contact *courant = Debut ;
    printf("la liste des contacts :\n") ; 
    while (courant != NULL){
        printf("%s : %s\n",courant->Nom_Prenom , courant->numero);
        courant = courant -> suivant ;
    }
}

int main (){
    addContact() ;  
    addContact() ; 
    addContact() ; 
    affichage() ; 
    searchContact() ; 
    return 0 ; 
}