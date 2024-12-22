#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noeud {
    int valeur ; 
    struct noeud *gauche ;
    struct noeud *droite ;
}Noeud ;

typedef struct{
    Noeud *racine ;
}arbre ; 

void initialier(arbre *a){
    a->racine = NULL ;
}

Noeud *preparerNoeud (int val){
    Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud)) ;
    if (nouveau == NULL){
        printf("allocation de memoire a echoue \n");
        return NULL ;
    }
    nouveau ->valeur = val ;
    nouveau -> gauche = NULL ;
    nouveau -> droite = NULL ;
    return nouveau ;
}

void inserer (arbre *a , int val){
    if(a->racine == NULL){
        a->racine = preparerNoeud(val) ;
    } 
    else {
        Noeud *courant = a->racine ; 
        Noeud *parent = NULL ;
        while (courant != NULL){
            parent = courant ;
            if (val < courant -> valeur){
                courant = courant -> gauche ;
            }
            else if (val > courant -> valeur){
                courant = courant -> droite ;
            }
            else {
                 printf("Valeur %d deja dans l'arbre.\n", val);
                 return ;
                } 
        }
        if (val > parent -> valeur){
            parent -> droite = preparerNoeud(val) ;
        }
        else if (val < parent -> valeur){
            parent -> gauche = preparerNoeud(val);
        }
    }
}

void Parcours_prefix (Noeud *racine){
    if (racine == NULL){
        printf("racine est nulle\n");
        return ;
    }
    printf("%d ",racine->valeur) ;
    if (racine->gauche != NULL){
        Parcours_prefix(racine->gauche) ; 
    } 
    if (racine->droite != NULL){
        Parcours_prefix(racine->droite) ; 
    }
}

Noeud *min_sous_arbre(Noeud *racine){
    Noeud *temp = racine ; 
    while (temp && temp->gauche){
        temp = temp -> gauche ;
    }
    return temp ;
}

void Supprimer (arbre *a , int val){
    Noeud * courant = a-> racine ;
    Noeud *parent = NULL ; 

    if (a == NULL || a->racine == NULL){
        printf("l'arbre est vide\n");
        return ;
    }

    while (courant != NULL && courant -> valeur != val){
        parent = courant ;
        if (val < courant -> valeur){
            courant = courant -> gauche ;
        }
        if (val > courant -> valeur){
            courant = courant -> droite ;
        }
    }
    if (courant == NULL){
        printf("la valeur ne se trouve pas dans l'arbre\n");
        return ;
    }

    if (!courant -> gauche && !courant->droite){
        if (courant == a->racine){
            a->racine = NULL ;
        }
        else {
            if (parent -> gauche == courant){
                parent -> gauche = NULL ;
            }
            if (parent -> droite == courant){
                parent -> droite = NULL ;
            }
        }
        free(courant);
    }

    else if (courant -> gauche == NULL || courant -> droite == NULL){
        Noeud *enfant ;
        if (courant ->droite){
            enfant = courant -> droite ;
        }
        else if (courant ->gauche){
            enfant = courant -> gauche ;
        }
        if (courant == a->racine){
            a->racine = enfant ; 
        }
        else {
            if (parent -> gauche == courant){
                parent -> gauche = enfant ;
            }
            else if (parent -> droite == courant){
                parent -> droite = enfant ;
            }
        }
        free(courant) ;
    }

    else if (courant -> gauche && courant -> droite){
        Noeud *min = min_sous_arbre(courant->droite) ;
        int temp = min -> valeur ;
        Supprimer(a , min -> valeur);
        courant -> valeur = temp ;
    }
}



int main(){
    arbre *a = (arbre *)malloc(sizeof(arbre)); 
    initialier(a);
    inserer(a,5);
    inserer(a,7) ;
    inserer(a,4) ;
    inserer(a,8) ;
    inserer(a,6);
    inserer(a,3); 
    Parcours_prefix(a->racine);
    Supprimer(a,2);
    printf("\n");
    Parcours_prefix(a->racine);
    return 0;
}