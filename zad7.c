#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//STRUKTURA STABLO
    typedef struct _stablo* Position;
    typedef struct _stablo
    {
        char ime[50];
        Position sibling;
        Position child;
    }Stablo;

//STRUKTURA STOG
    typedef struct _stog* Position2;
    typedef struct _stog {
        Position2 Direktorij;
        Position2 next;
    }Stog;

//POPIS FUNKCIJA    
    Position KreirajCvor();  //kreiraj root stabla
    Position2 KreirajCvor2();  //kreiraj pocetak stoga
    int PopisNaredbi();  //popis naredbi za izvrsit nad stablom
    int NapraviDirektorij(Position Stablo,char* imeDirektorija);   //napravit stablo
    int IspisiDirektorij(Position S,char* imeDirektorija);   //ispisat stablo
    Position PromijeniDirektorij(Position S,char*imeDirektorija,Position2 P);   //   
    int PushStog(Position2 P,Position S);
//MAIN FUNKCIJA
    int main()
        {
            Position S=NULL;
            Position2 P=NULL;
            int izbor=0;

            P=KreirajCvor2();
            if(p==NULL) {
                printf("Greska pri alociranju memorije!");
                return NULL;
            }
            p->next=NULL;
            p->element=NULL;

            S=KreirajCvor();
            if(S==NULL)
                {
                printf("Greska pri alociranju memorije!\n");
                return NULL;
                }

            S->next=NULL;
            S->child=NULL;

            printf("Unesite ime vaseg osnovnog direktorija\n");
            scanf("%s",S->ime);

            izbor=PopisNaredbi();

            while(izbor!=1 && izbor!=2 && izbor!=3)
                {
                    printf("Niste unijeli dobar izbor,pokušajte ponovno\n");
                    scanf("%d",&izbor);
                }
            switch(izbor) {
            case 1: 
                {
                    printf("Upisite ime novog direktorija:");
                    scanf("%s",&Ime);
                    NapraviDirektorij(S,Ime);
                    izbor=PopisNaredbi();
                    break;
                }
            case 2:
                {
                    IspisiDirektorij(S,S->ime);
                    izbor=PopisNaredbi();
                    break; 
                }
            case 3:
                {   
                    printf("Napisite ime poddirektorija u kojeg zelite uci?\n");
                    scanf(" %s",Ime);
                    S=PromijeniDirektorij(S,Ime,P);
                    izbor=PopisNaredbi();
                    break;
                }
            default:
                {
                    printf("Niste unijeli ispravnu naredbu!Pokušajte ponovno!");
                    break;
                }

            return 0;
        }

//DEKLARACIJA FUNKCIJA
int PopisNaredbi()
    { 
        int izbor;
        printf("Unesite odredeni broj za naredbu koju zelite izvrsiti:\n");

        printf("\n1---- za stvaranje novog direktorija\n");
        printf("\n2-----za ispis direktorija\n");
        printf("\n3-----za stvaranje poddirektorija\n");

        scanf("%d", &izbor);
        return izbor;
    }
Position KreirajCvor()
    { 
        Position q;
        q=(Position)malloc(sizeof(Stablo));

        if(q==NULL)
            return NULL;

        return q;
    }

Position2 KreirajCvor2()
    { 
        Position2 q;
        q=(Position2)malloc(sizeof(Stog));

        if(q==NULL)
            return NULL;

        return q;
    }

Position PronadiPosljednjeg(Position P)
    {
        while(P->next!=NULL)
        P=P->next;

    return P;
    }

int NapraviDirektorij(Position S,char* Ime)
    {  
        Position q;
        Position temp;
        Position Zadnji;

        q=KreirajCvor();

        if(q==NULL)
            return NULL;

        q->sibling=NULL;
        q->child=NULL;

        temp=S->child;
        while(temp!=NULL && strcmp(Ime,temp->ime)!=0)
            temp=temp->next;

        if(strcmp(Ime,temp->ime)==0)
        {   
            printf("Ne mozete unijeti direktorij s imenom koje vec postoji!\n");
            return NULL;
        }

        strcpy(q->ime,Ime);  //kopiram Ime u q poddstablo

    	if(S->child==NULL)
        S->child=q;

        else    //ako ima elemenata onda moramo pronaci zadnjeg i tu unijeti q
            {   
            Zadnji=PronadiPosljednjeg(S->child);
            q->sibling=Zadnji->sibling; 
            Zadnji->sibling=q; 
            }
        return 0;
    }

int IspisiDirektorij(Position S,char*imeDirektorija)
    {   
        printf("Vas direktorij %s:\n",imeDirektorija);
        S=S->child;

        while(S!=NULL)
            {
                printf("%s\t",S->ime);
                S=S->sibling;
            }
        return 0;
    }
Position PromijeniDirektorij(Position S,char* imeDirektorija,Position2 P)
    {
        Position temp;
        temp=S->child;

        while(temp!=NULL && strcmp(temp->ime,Ime)!=0)
        temp=temp->next;

        if(temp==NULL)
            {   
                printf("Ne postoji poddirektorij s tim imenom!\n");
                return S;
            }

        PushStog(P,S);

        return temp;

        return 0;
    }       

int PushStog(Position2 P,Position S)
    { 
        Position2 q;
        q=KreirajCvor2();

        if(q==NULL)
            {
                printf("Neuspjesno alocirana memorija\n");
                return NULL;
            }

        q->next=NULL;
        q->el=S;

        q->next=P->next;
        P->next=q;

        return 0;
    }