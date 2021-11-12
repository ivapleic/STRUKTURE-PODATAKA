#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE 1024

struct _polinom;
typedef struct _polinom *Position;
typedef struct _polinom
{
    int koef;
    int eksp;

    Position next;

}Polinom;

int CitajDatoteku(char* Polinomi,Position head1,Position head2);
void Ispis(Position head);
int ZbrojiPol(Position rezultat,Position head1,Position head2);
Position StvoriElement(int koef,int eksp);
UnesiSortirano(Position head,Position NoviElement);
int PomnoziPol(Position result,Position head1,Position head2);

int main()
{
    Polinom head1={.koef=0,.eksp=0,.next=NULL};
    Polinom head2={.koef=0,.eksp=0,.next=NULL};
    Polinom RezultatMnozenja={.koef=0,.eksp=0,.next=NULL};
    Polinom RezultatZbrajanja={.koef=0,.eksp=0,.next=NULL};

    CitajDatoteku("Polinomi.txt",&head1,&head2);

        printf("Prvi polinom:\n");
        Ispis(&head1),
        printf("Drugi polinom:\n");
        Ispis(&head2);

    PomnoziPol(&RezultatMnozenja,&head1,&head2);

        printf("Rezultat mnozenja:\n");
        Ispis(&RezultatMnozenja);

    ZbrojiPol(&RezultatZbrajanja,&head1,&head2);

    return 0;
}
int CitajDatoteku(char* Polinomi,Position head1,Position head2)
{
    char buffer[MAX_LINE]={0};
    char* p=NULL;
    int n=0;
    int koef=0;
    int eksp=0;
    Position NoviElement=NULL;

    FILE* dat=NULL;
    dat=fopen("Polinomi.txt","r");

    if(!dat)
    {
        perror("Datoteka nije pronadena!n");
        return EXIT_FAILURE;
    }

    fgets(buffer,MAX_LINE,dat);
    p=buffer;

    while(strlen(p)>0) 
    {
        sscanf(p,"%d %d %n",&koef,&eksp,&n);

        NoviElement=StvoriElement(koef,eksp);
        if(!NoviElement)
        {
            perror("Nema memorije!\n");
            return EXIT_FAILURE;
        }
        UnesiSortirano(head1,NoviElement);
        p+=n;
    }
    fgets(buffer,MAX_LINE,dat);
    p = buffer;
    while(strlen(p)>0)
    {
        sscanf(p,"%d %d %n",&koef,&eksp,&n);
        UnesiSortirano(head2,StvoriElement(koef,eksp));
        p+=n;
    }
    fclose(dat);
    return EXIT_SUCCESS;
}
Position StvoriElement(int koef,int eksp)
{
    Position element=NULL;
    element=(Position)malloc(sizeof(Polinom));
    if(!element)
    {
        perror("Greska pri alociranju memorije!\n");
        return EXIT_FAILURE;
    }
    element->koef=koef;
    element->eksp=eksp;
    element->next=NULL;

    return element;
}
UnesiSortirano(Position head,Position NoviElement)
{
    Position temp=NULL;

    if(head==NULL||head->eksp>NoviElement->eksp)
    {
            NoviElement->next=head;
            head=NoviElement;
    }
    else
    {
        temp=head;
        while(temp->next !=NULL && temp->next->eksp>NoviElement->eksp)
            temp=temp->next;
        NoviElement->next=temp->next;
        temp->next=NoviElement;
    }
    return EXIT_SUCCESS;
}
void Ispis(Position head)
{
    Position temp=head->next;

    while(temp!=NULL)
    {
        printf(" %dx^(%d)",temp->koef,temp->eksp);
        temp=temp->next;
    }
    printf("\n");
}
int ZbrojiPol(Position RezultatZbrajanja,Position head1,Position head2)
{
    Position rezultat=RezultatZbrajanja;
    Position p1=head1->next;
    Position p2=head2->next;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->eksp==p2->eksp) 
            {
                UnesiSortirano(rezultat,StvoriElement(p1->koef+p2->koef,p1->eksp));
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1->eksp>p2->eksp)
            {
                UnesiSortirano(rezultat,StvoriElement(p1->koef,p1->eksp));
                p1=p1->next;
            }
            else if(p1->eksp<p2->eksp)
            {
                UnesiSortirano(rezultat,StvoriElement(p2->koef,p2->eksp));
                p2=p2->next;
            }
    }
    while(p1!=NULL)
    {
        UnesiSortirano(rezultat,head2);
        p2=p2->next;
    }
    while(p2!=NULL)
    {
        UnesiSortirano(rezultat,head2);
        p2=p2->next;
    }
    printf("Zbroj polinoma:\n");
    Ispis(rezultat);

    return EXIT_SUCCESS;
}
int PomnoziPol(Position rezultat,Position head1,Position head2)
{
    Position i=NULL;
    Position j=NULL;
    Position NoviElement=NULL;

    NoviElement=(Position)malloc(sizeof(Polinom));

    if (!NoviElement)
    {
        perror("Nije moguce alocirati memoriju!\n");
        return EXIT_FAILURE;
    }
    for(i=head1->next;i!=NULL;i=i->next)
    {
        for(j=head2->next;j!=NULL;j=j->next)
        {
            NoviElement=StvoriElement(i->koef*j->koef,i->eksp+j->eksp);

            UnesiSortirano(rezultat,NoviElement);
        }
    }
    return EXIT_SUCCESS;
}
