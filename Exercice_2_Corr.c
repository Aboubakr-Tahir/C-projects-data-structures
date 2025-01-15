#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//normalment dans l'exercice il faut toujours entré 20 étudiants donc cette N est juste là pour avoir des petits tests de code , et guarantir qu'il marche.
int N ;

//voici la structure demandé dans l'exercice 
typedef struct info {
    char *nom_etudiant ;
    char *annee_naissance ; 
    int module1_note; 
    int module2_note;
    int module3_note;
    int module4_note;
    float Moyenne ; // j ai ajouté cette moyenne pour faciliter la fonction de tri (fonction admis) pas nécessaire si vous avez autre méthode
}Info ;

Info Tab[20] ;



void affiche_resultat (){
    float Moy ; 
    for (int i = 0 ; i<N ; i++){
        Moy = (float)(Tab[i].module1_note + Tab[i].module2_note + Tab[i].module3_note + Tab[i].module4_note) / 4.0 ;
            if (Tab[i].module1_note < 7 || Tab[i].module2_note < 7 || Tab[i].module3_note < 7 || Tab[i].module4_note < 7  ){
                printf("l'eleve : %s a obtenu la moyenne : %.2f , status : Ajourne\n",Tab[i].nom_etudiant,Moy); 
            } 
            else if (Moy >= 12 && !(Tab[i].module1_note < 7 || Tab[i].module2_note < 7 || Tab[i].module3_note < 7 || Tab[i].module4_note < 7 )){
                printf("l'eleve : %s a obtenu la moyenne : %.2f , status : admis\n",Tab[i].nom_etudiant,Moy) ;
            }
            else if (Moy >= 12 && (Tab[i].module1_note < 7 || Tab[i].module2_note < 7 || Tab[i].module3_note < 7 || Tab[i].module4_note < 7)){
                printf("l'eleve : %s a obtenu la moyenne : %.2f , status : Ajourne\n",Tab[i].nom_etudiant,Moy); 
            }
    }
}

    void eleves_admis(){

        // ici une petite boucle afin de remplir le tableau admis par les étudiants admis ( 2incha2allah tkoun mnhom :) )
        Info admis[20] ;
        float Moy ;
        int admis_count = 0 ;
        for (int i =0 ; i<N ; i++){
            Moy = (float)(Tab[i].module1_note + Tab[i].module2_note + Tab[i].module3_note + Tab[i].module4_note) / 4.0 ;
            if (Moy >= 12 && !(Tab[i].module1_note < 7 || Tab[i].module2_note < 7 || Tab[i].module3_note < 7 || Tab[i].module4_note < 7 )){
                admis[admis_count] = Tab[i] ;
                admis[admis_count].Moyenne = Moy ;
                admis_count ++ ;
            }
        }

        // maintenant il faut trier le tableau admis par odre de mérite 
        //je vais utiliser l'algorithme de bublle , c est une algorithme de tri (vous pouvez la chercher dans youtube pour bien la comprendre)
        for (int i=0 ; i<admis_count -1 ; i++){
            for (int j=0 ; j<admis_count -i -1 ; j++){
                if (admis[j].Moyenne < admis[j+1].Moyenne){
                    Info temp = admis[j] ;
                    admis[j] = admis [j+1] ;
                    admis[j+1] = temp ;
                }
            }
        }

        //maintenant on affiche tout simplement 
        printf("la liste des eleves admis par ordre de mérite : : \n") ;
        for (int i =0 ; i<admis_count ; i++){
            printf("%d - %s avec la Moyenne %.2f\n",i+1,admis[i].nom_etudiant,admis[i].Moyenne) ;
        }
}

int main(){
    printf("Entrer le nombre d'eleves que vous voulez entree (Max entre 20): \n") ;// comme j'ai déjà dit , il faut entrer 20 étudiant normalement , ça et seulement pour la pratique.
    scanf("%d",&N) ;
    while (getchar() != '\n'); //apres chaque scanf il reste un \n dans le tampon , il faut juste le vider par cette boucle (C moment :/)
    for (int i=0 ; i<N ; i++){
        Tab[i].annee_naissance = (char *)malloc(sizeof(char) * 100);
        Tab[i].nom_etudiant = (char *)malloc(sizeof(char) * 100) ;
        printf("le nom de l'etudiant numero %d : " , i+1);
        scanf("%s" , Tab[i].nom_etudiant) ;
        while (getchar() != '\n');
        printf("l anne de naissance de l etudiant %d : ",i+1);
        scanf("%s", Tab[i].annee_naissance) ;
        while (getchar() != '\n');
        printf("sa note du module numero 1 : ");
        scanf("%d",&Tab[i].module1_note) ;
        while (getchar() != '\n');
        printf("sa note du module numero 2 : ");
        scanf("%d",&Tab[i].module2_note) ;
        while (getchar() != '\n');
        printf("sa note du module numero 3 : ");
        scanf("%d",&Tab[i].module3_note) ;
        while (getchar() != '\n');
        printf("sa note du module numero 4 : ");
        scanf("%d",&Tab[i].module4_note) ;
        while (getchar() != '\n');
        printf("\n") ;
    } 
    eleves_admis() ;
    for (int i = 0; i < N; i++) {
        free(Tab[i].nom_etudiant);
        free(Tab[i].annee_naissance);
    }
    return 0 ;
}