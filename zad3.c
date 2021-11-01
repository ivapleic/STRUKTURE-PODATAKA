#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

struct _osoba;
typedef struct _osoba* Position;

typedef struct _osoba
{
    char ime[MAX];
    char prezime[MAX];
    int godina;

    Position next;
}osoba;


//POPIS FUNKCIJA
int Izbornik();
int UnosPocetni(char* Ime,char* Prezime,int Godina,Position head); //dodaje element na pocetak liste
Position IzradiOsobu(char* Ime,char *Prezime,int Godina);
void UnesiNakon(Position P,Position NovaOsoba);   //dodaje element nakon nekog elementa
int Ispis(Position first);  //ispisuje listu
int UnosKrajnji(char* Ime,char* Prezime,int Godina,Position head);   //dodaje element na kraj liste
Position NadiZadnjeg(Position head);
int PronadiPrezime(char* Prezime,Position first);
int BrisiNakon(char* Prezime,Position head); //brise odredeni element iz liste
int UnesiIza(char* Ime,char* Prezime,int Godina,char* PrezimeI,Position first);  //dodaje element iza odredenog elementa
int UnesiIspred(char* Ime,char* Prezime,int Godina,char *PrezimeI,Position first);  //dodaje el ispred odredenog el
Position NadiMjesto(int n,Position first);  
int UpisiDat(char* Upis,Position first);   //upisuje listu  udatotekz
int Sortiraj(Position head);    //sortiranje po prezimenu


int main(int argc,char** argv)
{
    char izbor= "";
    char unos= "";
    char Ime[MAX],Prezime[MAX];
    int Godina;
    char PrezimeI[MAX];
    char zadnji="";
    int upisan=0;

    osoba Head={ .next=NULL, .ime={0}, .prezime={0}, .godina=0 };
    Position p=&Head;

    char* Upis=NULL;
    Upis=malloc(sizeof(char)*10);

    Izbornik();

    while(izbor!='I')
    {
        printf("\nOdaberite zeljeni unos:");
        scanf("%c",&izbor);

        switch(izbor)
        {
            case 'A':
                    Izbornik();
                    break;
            case 'B':
                    printf("Unesite ime:");
                    scanf("%s",Ime);

                    printf("Unesite prezime:");
                    scanf("%s",Prezime);

                    printf("Unesite godinu:");
                    scanf("%d",&Godina);

                    unos=IzradiOsobu(Ime,Prezime,Godina);
                    UnosPocetni(Ime,Prezime,Godina,&Head);

                    printf("\nStudent je uspjesno dodan na pocetak.\n");
                    break;
            case 'C':
                    Ispis(&Head);
                    break;
            case 'D':
                    printf("Unesite ime:");
                    scanf("%s",Ime);

                    printf("Unesite prezime:");
                    scanf("%s",Prezime);

                    printf("Unesite godinu:");
                    scanf("%d",&Godina);

                    unos=IzradiOsobu(Ime,Prezime,Godina);
                    UnosKrajnji(Ime,Prezime,Godina,&Head);

                    printf("Student je uspjesno dodan na kraj.\n");
                    break;
            case 'E':
                    printf("Unesite prezime studenta kojeg trazite:");
                    scanf("%s",Prezime);

                    PronadiPrezime(Prezime,p);
                    break;
            case 'F':
                    printf("Unesite prezime studenta kojeg zelite izbrisati");
                    scanf("%s",Prezime);

                    BrisiNakon(Prezime,p);
                    break;
            case 'G':
                    printf("Unesite prezime studenta nakon kojeg zelite dodati clan: ");
                    scanf("%s",PrezimeI);

                    while(p->next!=NULL) {
                        if(strcmp(p->next->prezime,PrezimeI)==0) {
                            printf("Unesite ime: ");
					        scanf("%s",Ime);

					        printf("Unesite prezime: ");
					        scanf("%s",Prezime);

					        printf("Unesite godinu: ");
					        scanf("%d",&Godina);

                            UnesiIza(Ime,Prezime,Godina,PrezimeI,&Head);
                            printf("Novi clan je dodan nakon studenta %s",PrezimeI);
                            upisan=1;
                            break;
                        }
                        p=p->next;
                    }
                    if(!upisan)
                    printf("Clan nije pronaden.\n");

                    p=&Head;
                    upisan=0;
                    break;
            case 'H':
                    printf("Unesite prezime studenta prije kojeg zelite dodati clan:");
                    scanf("%s",PrezimeI);

                    while(p->next!=NULL) {
                        if(strcmp(p->next->prezime,PrezimeI)==0) {
                            printf("Unesite ime:");
					        scanf("%s",Ime);

					        printf("Unesite prezime:");
					        scanf("%s",Prezime);

					        printf("Unesite godinu:");
					        scanf("%d",&Godina);

					        UnesiIspred(Ime,Prezime,Godina,PrezimeI,&Head);
					        printf("Novi clan je dodan nakon studenta/ice %s.\n",PrezimeI);
					        upisan=1;
					        break;
				        }
				    p=p->next;
			        }
                    if(!upisan)
                        printf("Clan nije pronaden.\n");
                        p=&Head;
                        upisan=0;
                        break;
            case 'J':
                    printf("Upisite proizvoljno ime datoteke u koju zelite pohraniti svoju listu:");
                    scanf("%s",Upis);
                    UpisiDat(Upis,&Head);
                    break;
            case 'K':
                    printf("Upisite ime datoteke u koju zelize ucitati svoju listu:");
                    scanf("%s",Upis);
                    UpisiDat(Upis,&Head);
                    break;
            case 'L':
                    Sortiraj(&Head);
                    break;
        }
            return EXIT_SUCCESS;
    }
}

int Izbornik()
{
    printf("\nIZBORNIK:\n");

    printf("Za ponovni prikaz izbornika unesite-------->A\n");
    printf("Za unos prvog clana unesite-------->B\n");
    printf("Za ispis svih clanova unesite-------->C\n");
    printf("Za unos clana na kraju unesite-------->D\n");
    printf("Za pronalazak nekog clana po prezimenu unesite-------->E\n");
    printf("Za brisanje nekog clana unesite-------->F\n");
    printf("Za unos clana nakon nekog clana unesite--------->G\n");
    printf("Za unos clana prije nekog clana---------->H\n");
    printf("Za prekid programa unesite--------->I\n");
    printf("Za ispis liste u datoteku unesite-------->J\n");
    printf("Za upis datoteke u listu unesite--------->K\n");
    printf("Za sortiranje liste unesite------->L\n");

    return EXIT_SUCCESS;    
}

int UnosPocetni(char* Ime,char* Prezime,int Godina,Position head)
{
    Position NovaOsoba=NULL;

    NovaOsoba=IzradiOsobu(Ime,Prezime,Godina);
    if(!NovaOsoba)
        return -1;

    UnesiNakon(head,NovaOsoba);
    return EXIT_SUCCESS;
}
Position IzradiOsobu(char* Ime,char*Prezime,int Godina)
{
    Position NovaOsoba=NULL;
    NovaOsoba=(Position)malloc(sizeof(osoba));

    if(!NovaOsoba) {
        perror("Greska!Memoriju nije moguce alocirati!");
        return -1;
    }

    strcpy(NovaOsoba->ime,Ime);
    strcpy(NovaOsoba->prezime,Prezime);
    NovaOsoba->godina=Godina;
    NovaOsoba->next=NULL;

    return NovaOsoba;
}
void UnesiNakon(Position P,Position NovaOsoba)
{
    NovaOsoba->next=P->next;
    P->next=NovaOsoba;
}
int Ispis(Position first)
{
    Position q=first->next;

    printf("\nVasa lista izgleda ovako:\n");
    printf("|Ime      ||Prezime        ||Godina rodenja     \n");
    for(q=first->next;q!=NULL;q=q->next)
    {
        printf("|%-15s || %-19s  || %d\n",q->ime,q->prezime,q->godina);
    }
    return EXIT_SUCCESS;
}
int UnosKrajnji(char* Ime,char* Prezime,int Godina,Position head)
{
        Position NovaOsoba=NULL;
        Position last=NULL;

        NovaOsoba=IzradiOsobu(Ime,Prezime,Godina);
        if(!NovaOsoba) 
            return -1;

        last=NadiZadnjeg(head);
        UnesiNakon(last,NovaOsoba);

    return EXIT_SUCCESS;
}
Position NadiZadnjeg(Position head)
{
    Position q=head;
    while(q->next)
    q=q->next;
    return q;
}
int PronadiPrezime(char* Prezime,Position first)
{
    Position q=first;
    int tester=0;

    for(q=first->next;q!=NULL;q=q->next) {
        if(strcmp(q->prezime,Prezime)==0) {
            printf("\nTrazite osobu:\n");
            printf("|Ime    ||Prezime       ||Godina rodenja \n");
            printf("|%-15s ||%-19s  ||%d\n",q->ime,q->prezime,q->godina);
            tester=1;
        }
    }
    if(!tester) {
        printf("Osoba ne postoji!");
        return EXIT_FAILURE;
    }
}
int BrisiNakon(char* Prezime,Position head)
{
    Position prosli=head;
    Position trenutni=NULL;
    int tester=0;

    for(prosli=head;prosli->next!=NULL;prosli=prosli->next) {
        if(strcmp(prosli->next->prezime,Prezime)==0) {
            trenutni=prosli->next;
            prosli->next=prosli->next->next;
            free(trenutni);

            printf("Izbrisali ste osobu %s.\n",Prezime);
            tester=1;
            break;
        }
    }
    if(!tester) {
        printf("Osoba ne postoji!\n");
    }
    return EXIT_SUCCESS;
}
int UnesiIza(char* Ime,char* Prezime,int Godina,char* PrezimeI,Position first)
{
    Position NovaOsoba=NULL;
    first=first->next;

    while(first!=NULL && strcmp(first->prezime,PrezimeI)!=NULL)
        first=first->next;

    if(first!=NULL) {
        NovaOsoba=IzradiOsobu(Ime,Prezime,Godina);
        if(!NovaOsoba)
            return -1;
        UnesiNakon(first,NovaOsoba);

        return EXIT_SUCCESS;
    }
    else {
        printf("\nGreska!Clan kojeg trazite ne postoji!");
        return EXIT_FAILURE;
    }
}
int UnesiIspred(char* Ime,char* Prezime,int Godina,char* PrezimeI,Position first)
{
    Position NovaOsoba=NULL;

    while(first->next!=NULL && strcmp(first->next->prezime,PrezimeI)!=NULL)
        first=first->next;

    if(first->next!=NULL) {
        NovaOsoba=IzradiOsobu(Ime,Prezime,Godina);
        if(!NovaOsoba)
            return -1;

        UnesiNakon(first,NovaOsoba);

        return EXIT_SUCCESS;
    }
    else {
        printf("Greska!Clan kojeg trazite ne postoji!");
        return EXIT_FAILURE;
    }
}
Position NadiMjesto(int n,Position first)
{
    while(first->next!=NULL && n>first->next->prezime) {
        first=first->next;
    }
    return first;
}
int UpisiDat(char* Upis,Position first)
{
    FILE*dat=NULL;
    dat=fopen(Upis,"w");

    Position clan=NULL;

    if(!dat) {
        printf("Datoteka nije pronadena!");
        return -1;
    }
    for(clan=first->next;clan!=NULL;clan=clan->next) {
        fprintf(dat,"%s %s %d",clan->ime,clan->prezime,clan->godina);
    }
    printf("Lista je upisana u datoteku!");
    fclose(dat);

    return EXIT_SUCCESS;
}
int UcitajDat(char* Upis,Position first)
{
    FILE* dat=NULL;
    dat=fopen(Upis,"r");
    Position clan=NULL;
    char Ime[MAX]={0};
    char Prezime[MAX]={0};
    int Godina=0;

    if(!dat) {
        printf("Datoteku nije moguce pronaci.\n");
        return -1;
    }
    while(!feof(dat)) {
        fscanf(dat,"%s %s %d",Ime,Prezime,&Godina);
        UnosKrajnji(Ime,Prezime,Godina,first);
    }
    printf("Datoteka je ucitana na pocetak liste.\n");
    fclose(dat);
    return EXIT_SUCCESS;
}
int Sortiraj(Position head) 
{
    Position first=NULL;
    Position trenutni=NULL;
    Position sljedeci=NULL;
    Position temp=NULL;
    Position empty=NULL;

    if(head->next==NULL) {
        printf("Nema clanova za sortiranje");
        return -1;
    }
    while(head->next!=empty) {
        trenutni=head;
        sljedeci=head->next;

        while(sljedeci->next!=empty) {
            if(strcmp(sljedeci->prezime,sljedeci->next->prezime)>0) {
                temp=sljedeci->next;
                trenutni->next=temp;
                sljedeci->next=temp->next;
                temp->next=sljedeci;
                sljedeci=temp;
            }
        trenutni=sljedeci;
        sljedeci=sljedeci->next;
    }
    empty=sljedeci;
    }
    printf("Lista je uspjesno sortirana.\n");
    return EXIT_SUCCESS;
}
