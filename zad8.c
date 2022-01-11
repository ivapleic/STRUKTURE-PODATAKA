#include<stdio.h>
#include<stdlib.h>

//DEKLARACIJA STRUKTURE
    struct _cvor* Position;
    typedef struct _cvor  
        {
            int broj;    //broj 
            Position L;   //pokazivac na lijevo podstablo
            Position D;    //pokazivac na desno podstablo
        }Cvor;

//POPIS FUNKCIJA
    void Meni();
    Position Umetni(Position root,int Broj);
    Position StvoriCvor(int Broj);
    Position Trazi(Position root,int Broj);
    int Inorder(Position root);
    int Preorder(Position root);
    int Postorder(Positio root);
    Position Izbrisi(Position root,int Broj);
    Position PronadiMin(Position root);


//MAIN FUNKCIJA
    int main()
        {
            int Broj;
            Position root=NULL;
            int izbor=0;

            izbor=Meni();

            switch(izbor) {
                case'1':
                    //Unos clanova u stablo
                    printf("Unesite broj koji zelite unijeti:");
                    scanf("%d",&Broj);
                    Umetni(S,Broj);
                    break;
                case '2':
                    //ispis inorder
                    Inorder(root);
                    break;
                case '3':
                    //ispis preorder
                    Preorder(root);
                    break;
                case'4':
                    //ispis postorder
                    Postorder(root);
                    break;
                case'5':
                    //brisanje elementa
                    printf("Koji broj zelite izbrisati?");
                    scanf("%d",&Broj),
                    root=Izbrisi(root,Broj);
                    break;
                case'6':
                // trazenje elementa
                    printf("Koji element trazite?");
                    scanf(" %d",&Broj);
                    root=Trazi(root,Broj);
                    break;
            }
            return 0;
        }

int Meni()
    {
        int izbor=0;
        printf("Unesite operaciju koju zelite izvrsiti nad binarnim stablom pretrazivanja");
        printf("\nTipka 1-------Unos");
        printf("\nTipka 2-------Ispis(inorder)");
        printf("\nTipka 3-------Ispis(preorder)");
        printf("\nTipka 4-------Ispis(levelorder)");
        printf("\nTipka 5-------Brisanje");
        printf("\nTipka 6-------Pronalazenje");

        scanf("%d",&izbor);

        return izbor;
    }

int Inorder(Position root) 
    {
        if(root!=NULL) 
        {
            Inorder(root->L);
            printf("%d",root->broj);
            Inorder(root->D);
        }
        return 0;
    }
int Postorder(Position root)
    {
        if(root!=NULL)
        {
            Postorder(root->L);
            Postorder(root->D);
            printf("%d ",root->broj);
        }
        return 0;
    }
int Preorder(Position root)
    {	
        if(root!=NULL)
        {
            printf("%d ",root->broj);
            Preorder(root->L);
            Preorder(root->D);
        }
        return 0;
    }
Position Umetni(Position root,int Broj) 
    {
        if(root==NULL) 
        {
            root=StvoriCvor(Broj);
        }
        else if(Broj<root->broj)
        {
            root->L=Umetni(root->L,Broj);
        }
        else 
        {
            root->D=Umetni(root->D,Broj);
        }
        return root;
    }
Position StvoriCvor(int Broj)
    {
        Position NoviCvor=NULL;

        NoviCvor=(Position)malloc(sizeof(Cvor));

        if(!NoviCvor) 
        {
            perror("Nije moguce alocirati memoriju!");
            return EXIT_FAILURE;
        }
        NoviCvor->broj=Broj;
        NoviCvor->L=NULL;
        NoviCvor->D=NULL;

        return NoviCvor;
    }
Position Trazi(Position root,int Broj) 
    {
        if(root==NULL)
        {
            printf("Element nepostoji!");
            return root;
        }
        else if(Broj<root->broj)
        {
            root=Trazi(root->L,Broj);
        }
        else if(Broj>root->broj)
        {
            root=Trazi(root->D,Broj);
        }
        return root;
    }
Position Izbrisi(Position root,int Broj) 
    {
        Position temp=NULL;
        
        if(root==NULL) 
            return  NULL;

        else if(Broj<root->broj)
            root->L=Izbrisi(root->L,Broj);

        else if(Broj>root->broj)
            root->D=Izbrisi(root->D,Broj);

        else 
            {
                if(root->L==NULL && root->D==NULL)
                {
                    free(root);
                    root==NULL;
                }
                else if(root->L==NULL)
                    {
                        temp=root;
                        root=root->D;
                        free(temp);     
                    }
                else if(root->D==NULL)
                    {
                        temp=root;
                        root=root->L;
                        free(temp);
                    }
                else {             
                    temp=PronadiMin(root->D);
                    root->broj=temp->broj;
                    root->D=Izbrisi(root->D,temp->broj);
                   }
            } 
            return root;
    }

Position PronadiMin(Position root)
    {
        while(root->L!=NULL)
            root=root->L;
        return root;
    }