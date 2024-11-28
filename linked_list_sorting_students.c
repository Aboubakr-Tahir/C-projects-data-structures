#include <stdio.h>
#include <stdlib.h>

typedef struct etudiant {
    char *nom_prenom;
    float   note ;
    struct etudiant *suivant;
}Etudiant ; 

Etudiant *Debut ;
int Nb_etudiants;
Etudiant *admis , *non_admis ; 

void init_lsc(){
    Debut = NULL ; 
    Nb_etudiants = 0 ;
}

Etudiant *creation_nv_noeud (char *Fullname, float mark){
    Etudiant *nouveau = (Etudiant *)malloc(sizeof(Etudiant));
    if (nouveau == NULL){
        printf("NULL\n");
        return NULL  ;
    }
    else {
        nouveau -> note = mark ;
        nouveau -> nom_prenom = Fullname ;
        nouveau -> suivant = NULL ;
        return nouveau ;
    }
}

Etudiant *debut_insertion (Etudiant *nouveau){
    if (nouveau == NULL){
        printf("l'insertion au debut de la liste est impossible , la noeud est vide\n");
        return NULL ; 
    }
    else{
        if (Debut == NULL){
            Debut = nouveau ; 
            nouveau -> suivant = NULL ; 
            Nb_etudiants++;
            return Debut ; 
        }
        else {
        nouveau -> suivant = Debut ; 
        Debut = nouveau ; 
        Nb_etudiants ++; 
        return Debut ; 
    }
}
}

Etudiant *fin_insertion (Etudiant *nouveau){
    if (nouveau == NULL){
        printf("l'insertion a la fin de la liste est impossible , la noeud est vide\n");
        return NULL ; 
    }
    else {
        Etudiant *temp = Debut ; 
        while (temp ->suivant != NULL){
            temp = temp -> suivant ;
        }
        temp -> suivant = nouveau ; 
        Nb_etudiants ++ ;
        return nouveau ; 
    }
}

void liber_memo (){
    Etudiant *temp = Debut ; 
    Etudiant *Courant ;
    while (temp != NULL){
        Courant = temp ; 
        temp = temp -> suivant ; 
        free(Courant) ; 
    }
    Nb_etudiants = 0 ; 
    Debut = NULL ; 
}

void afficher (){
    Etudiant *courant = Debut ;
    while (courant != NULL){
        printf("[%s:%.2f]",courant -> nom_prenom , courant -> note);
        if (courant -> suivant != NULL){
            printf("->");
        }
        courant = courant -> suivant ;
    }
}

void divise (){
    Etudiant *courant = Debut ;
    admis = NULL , non_admis = NULL ; 
    while(courant != NULL){
        Etudiant *nouveau ;
        nouveau = creation_nv_noeud(courant -> nom_prenom , courant -> note);
        if (nouveau -> note >= 10){
            nouveau -> suivant = admis ; 
            admis = nouveau ; 
        }
        else if (nouveau -> note < 10){
            nouveau -> suivant = non_admis ;
            non_admis = nouveau ; 
        }
        courant = courant -> suivant ; 
    }
}

void afficher_grps (){
    Etudiant *temp = admis ;
    printf("les eleves admis sont :\n") ;
    while (temp != NULL){
        printf("le nom et prenom : %s , la note : %.2f\n",temp->nom_prenom,temp->note);
        temp=temp->suivant ; 
    }
    temp = non_admis ;
    printf("les eleves non admis sont:\n");
    while(temp!=NULL){
        printf("le nom et prenom : %s , la note : %.2f\n",temp->nom_prenom,temp->note) ; 
        temp = temp -> suivant ;
    }

}

Etudiant *MIN (){
    Etudiant *courant = Debut ; 
    Etudiant *min = courant ; 
    if (Debut == NULL){
        return NULL ; 
    }
    else {
        while (courant != NULL){
            if (courant -> note < min -> note){
                min = courant ; 
            }
            courant = courant -> suivant ; 
        }
        return min ; 
    }
}


Etudiant *Tri = NULL ; 

void Triage (){
    
    while (Debut != NULL){
       
        Etudiant *min = MIN();
        if (min == Debut){
            Debut = Debut -> suivant ; 
        }
        else {
            Etudiant *precedent  = Debut ; 
            while (precedent-> suivant != min){ 
            precedent = precedent -> suivant ; 
        }
        precedent -> suivant = min -> suivant ; 
        }
        min -> suivant = Tri ; 
        Tri = min ; 
    }
    
}

void affich_Tri (){
    Etudiant *courant = Tri ; 
    printf("la liste apres triage est :\n");
    while (courant != NULL){
        printf("[%s : %.2f]",courant -> nom_prenom , courant -> note);
        if (courant -> suivant != NULL){
            printf("->");
        }
        courant = courant -> suivant ;
    }
    printf("\n");
}


int main(){
    init_lsc();
    Etudiant *E1 , *E2 , *E3 , *E4 , *E5 , *E6 , *min ; 
    E1 = creation_nv_noeud("Aboubakr_Tahir",10);
    E2 = creation_nv_noeud("mojtahid_1",18);
    E3 = creation_nv_noeud("kassoul_1",5) ; 
    E4= creation_nv_noeud("Kassoul_2",2);
    E5 = creation_nv_noeud("kasoula_1",3.75);
    E6 = creation_nv_noeud("mojtahid",20);
    debut_insertion(E1);
    fin_insertion(E2);
    fin_insertion(E3) ;
    debut_insertion(E4);
    debut_insertion(E5);
    fin_insertion(E6) ; 
    Triage();
    affich_Tri();
return 0 ;
}