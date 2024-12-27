#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/// la structure de donnees utilisee
typedef struct contact {
    char *Nom_Prenom;
    char *numero;
    struct contact *suivant;
} Contact;

Contact *Debut = NULL; /// pointeur vers le premier element
int taille = 0; /// nombre total de contacts

/// fonction d'ajout de contact
Contact *addContact (){
    char *Nv_nom_prenom = (char *)malloc(sizeof(char) *100) , *Nv_num = (char *)malloc(sizeof(char) *100)  ;
    if (Nv_nom_prenom == NULL || Nv_num == NULL){
        printf("L'allocation de memoire est echouee \n") ;
        return NULL ;
    }
    printf("Entrer le Nom et Prenom du contact que vous voulez ajouter :\n") ;
    fgets(Nv_nom_prenom , 100 , stdin) ;
    printf("Entrer Le numero de telephone de ce Contact :\n") ;
    fgets(Nv_num , 100 , stdin) ;

    Contact *nouveau = (Contact *)malloc(sizeof(Contact)) ;
    if (nouveau == NULL){
        printf("L'allocation de memoire est echouee\n");
        return NULL ;
    }
    nouveau -> Nom_Prenom = (char *)malloc(sizeof(char) *100) ;
    if (nouveau -> Nom_Prenom == NULL){
        printf("L'allocation de memoire est echouee \n") ;
        free(nouveau) ;
        return NULL ;
    }
    strcpy(nouveau -> Nom_Prenom , Nv_nom_prenom) ;
    free(Nv_nom_prenom); 
    nouveau -> numero = (char *)malloc(sizeof(char)*100) ;
    if (nouveau -> numero == NULL){
        printf("L'allocation de memoire est echouee \n") ;
        free(nouveau) ;
        free(nouveau->Nom_Prenom);
    }
    strcpy(nouveau->numero , Nv_num) ;
    free(Nv_num); 
    nouveau -> Nom_Prenom [strcspn(nouveau->Nom_Prenom,"\n")] = '\0' ;
    nouveau -> numero [strcspn(nouveau->numero , "\n")] ='\0' ;
    if (Debut == NULL ) {
        Debut = nouveau ;
        nouveau -> suivant = NULL ;
        taille++;
        printf("le Contact %s : %s a ete ajoute avec success\n",nouveau ->Nom_Prenom , nouveau->numero) ;
        return nouveau ;
    }
    else {
        Contact *prochain = Debut ;
        Contact *precedent  ;
        if (strcmp(nouveau->Nom_Prenom , prochain->Nom_Prenom) < 0){
            nouveau -> suivant = Debut ;
            Debut = nouveau ;
            printf("le Contact %s : %s a ete ajoute avec success\n",nouveau ->Nom_Prenom , nouveau->numero) ;
            taille++; 
            return nouveau ;
        }
        while ( prochain != NULL && strcmp(nouveau->Nom_Prenom , prochain ->Nom_Prenom) > 0 ){
            precedent = prochain ;
            prochain = prochain -> suivant ;
        }
        precedent -> suivant = nouveau ;
        nouveau -> suivant = prochain ;
        printf("le Contact %s : %s a ete ajoute avec success\n",nouveau ->Nom_Prenom , nouveau->numero) ;
        taille++;
        return nouveau ;
    }

}

///fonction de recherche
Contact *searchContact (){
    if (Debut==NULL){
        printf("la liste est vide");
        return NULL;
    };
    Contact *Courant = Debut ;
    char *str = (char *)malloc(sizeof(char)* 100) ;
    if (str == NULL){
        printf("L'allocation de memoire a echouee\n");
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
    free(str);
    if (Courant != NULL){
        printf("Le contact trouve est : \nNom et Prenom : %s , Numero de telephone : %s\n",Courant-> Nom_Prenom , Courant->numero);
        return Courant ;
    }
    else if (Courant == NULL) {
        printf("le Contact n a pas ete trouvee s il vous plait entrer le Nom et Prenom exacte\n");
        return NULL ;
    }
}


///fonction de suppression de contact
void DeleteContact() {
    if (Debut == NULL) {
        printf("La liste des contacts est vide.\n");
        return;
    }

    char *str = (char *)malloc(sizeof(char) * 100);
    if (str == NULL) {
        printf("L allocation de memoire est echouee\n");
        return;
    }

    printf("Entrer le Nom et Prenom du contact que vous voulez supprimer :\n");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    Contact *courant = Debut;
    Contact *precedent = NULL;


    while (courant != NULL && strcmp(courant->Nom_Prenom, str) != 0) {
        precedent = courant;
        courant = courant->suivant;
    }

    free(str);

    if (courant == NULL) {
        printf("Le contact n existe pas.\n");
        return;
    }

    if (precedent == NULL) {
        Debut = courant->suivant;
    } else {
        precedent->suivant = courant->suivant;
    }

    free(courant->Nom_Prenom);
    free(courant->numero);
    free(courant);
    taille--;
    printf("Contact supprime avec succes.\n");
}

/// fonction d'affichage des contacts
void affichage() {
    if (Debut == NULL) {
        printf("La liste des contacts est vide.\n");
        return;
    }

    printf("Liste des contacts :\n");
    Contact *courant = Debut;
    while (courant != NULL) {
        printf("%s : %s\n", courant->Nom_Prenom, courant->numero);
        courant = courant->suivant;
    }
}
/// fonction de mise à jour de contact
void updateContact() {
    if (Debut == NULL) {
        printf("La liste des contacts est vide.\n");
        return;
    }

    char *str = (char *)malloc(sizeof(char) * 100);
    if (str == NULL) {
        printf("L allocation de memoire a echoue\n");
        return;
    }

    printf("Entrer le Nom et Prenom du contact que vous voulez mettre a jour :\n");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    Contact *courant = Debut;
    while (courant != NULL && strcmp(courant->Nom_Prenom, str) != 0) {
        courant = courant->suivant;
    }

    if (courant == NULL) {
        printf("Le contact n existe pas.\n");
        free(str);
        return;
    }

    printf("Contact trouve : %s : %s\n", courant->Nom_Prenom, courant->numero);
    printf("Que voulez-vous mettre a jour ?\n");
    printf("1. Mettre a jour le nom\n2. Mettre a jour le numero de telephone\n");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n'); 

    if (choice == 1) {
        char *Nv_nom = (char *)malloc(sizeof(char) * 100);
        if (Nv_nom == NULL) {
            printf("L allocation de memoire pour le nouveau nom a echoue\n");
            free(str);
            return;
        }
        printf("Entrer le nouveau nom et prenom :\n");
        fgets(Nv_nom, 100, stdin);
        Nv_nom[strcspn(Nv_nom, "\n")] = '\0'; 
        
        free(courant->Nom_Prenom);
        courant->Nom_Prenom = (char *)malloc(sizeof(char) * 100);
        if (courant->Nom_Prenom == NULL) {
            printf("L allocation de memoire a echoue\n");
            free(Nv_nom);
            free(str);
            return;
        }
        strcpy(courant->Nom_Prenom, Nv_nom);
        free(Nv_nom);
        printf("Nom mis a jour avec succes.\n");
    } else if (choice == 2) {
        char *Nv_num = (char *)malloc(sizeof(char) * 100);
        if (Nv_num == NULL) {
            printf("L allocation de memoire pour le nouveau numero a echoue\n");
            free(str);
            return;
        }
        printf("Entrer le nouveau numero de telephone :\n");
        fgets(Nv_num, 100, stdin);
        Nv_num[strcspn(Nv_num, "\n")] = '\0';

        free(courant->numero);
        courant->numero = (char *)malloc(sizeof(char) * 100);
        if (courant->numero == NULL) {
            printf("L allocation de memoire echouee\n");
            free(Nv_num);
            free(str);
            return;
        }
        strcpy(courant->numero, Nv_num);
        free(Nv_num);
        printf("Numero mis a jour avec succes.\n");
    } else {
        printf("Choix invalide.\n");
    }

    free(str);
}


/// fonction operation
void contact(int number) {
    switch (number) {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            DeleteContact();
            break;
        case 4:
            affichage();
            break;
        case 5:
            updateContact();
            break;
        default:
            printf("Choix invalide.\n");
    }
}

int main() {
    int number;
    while (1) {
        printf("1. Ajouter un contact\n2. Rechercher un contact\n3. Supprimer un contact\n4. Afficher tous les contacts\n5. mis a jour \n6. Quitter\n");
        scanf("%d", &number);
        while (getchar() != '\n'); 

        if (number == 6) {break;}

        contact(number);
        number=0;
    }
    return 0;
}
