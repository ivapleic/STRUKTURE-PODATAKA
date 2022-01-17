#include <stdio.h>
#include <stdlib.h>
#define space 5

struct _cvor;
typedef struct _cvor* Position;

typedef struct _cvor{
    int broj;
    Position L;
    Position D;
}Cvor;
Position StvoriCvor(int Broj);
Position Unesi(Position root,int Broj);
int Inorder(Position root);
int Zamijeni(Position root);
//void draw_tree_hor2(TreeNodePtr root, int distance);
//void draw_tree_hor(TreeNodePtr root);

int main(){
    Position root = NULL;
    //TreeNodePtr temp = NULL;
    int A[10] = {2,5,7,8,11,1,4,2,3,7};
    int n=10;
    int i=0;
    int izbor=1;

    for(i=0;i<n;i++){
        root=Unesi(root,A[i]);
    }
        printf("Unesite radnju koju zelite izvrsiti?");
        printf("\n1-----za ispis stabla\n");
        printf("\n2-----za izmjenu stabla\n");
        scanf("%d",&izbor);

        switch(izbor){
            case 0:
                printf("Prekid programa\n");
                break;
            case 1:
                if (root==NULL){
                    printf("Stablo je prazno!\n");
                    return EXIT_SUCCESS;
                }
                Inorder(root);
                break;

            case 2:
                if (root==NULL){
                    printf("Stablo je prazno!\n");
                    return EXIT_SUCCESS;
                }  
                printf("Ispis\n");
                Zamijeni(root);
               // root = Insert(root, root->data);
                Inorder(root);
                break;

            default:
            printf("Unijeli ste pogresnu radnju!");    
        }
    return 0;
}

Position StvoriCvor(int Broj)
    {   
        Positon NoviCvor=NULL;

        NoviCvor=(Position)malloc(sizeof(Cvor));

        if(!NoviCvor)
            {
                printf("Nije moguce alocirati memoriju!\n");
                return NULL;
            }

        NoviCvor->broj=Broj;
        NoviCvor->L=NULL;
        NoviCvor->D=NULL;

        return NoviCvor;
    }

Position Unesi(Position root,int Broj)
    {   
        if(root== NULL)
            {
                root=StvoriCvor(Broj);
            }
        else if(Broj>root->broj)
            {
                root->L=Unesi(root->L,Broj);
            }
        else if(Broj<=root->broj)
            {
                root->D=Unesi(root->D,Broj);
            }
        return root;
    }

int Inorder(Position root)
    {   
        if(root!=NULL){
        Inorder(root->L);
        printf("%d",root->broj);
        Inorder(root->D);
        }
        return EXIT_SUCCESS;
    }
int Zamijeni(Position root)
    {   
        int prev=0;
        if (root==NULL) 
            {
                return 0;
            }
        if(root->L==NULL && root->D==NULL) 
            {
                prev=root->broj;
                root->broj=0;
                return prev;
            }

        int Lijevo=Zamijeni(root->L);
        int Desno=Zamijeni(root->D);

        root->broj=Lijevo+Desno;

        return root->broj;
    }
