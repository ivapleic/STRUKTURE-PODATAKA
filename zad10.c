#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct _cvorListe;
struct _cvorStabla;

typedef struct _cvorListe* PositionL;
typedef struct _cvorStabla* PositionS;

typedef struct _cvorListe
{
    char imeDrz[50]; 
    PositionS stablo; 
    PositionL next; 
}cvorListe;

typedef struct _cvorStabla
{
    char imeGr[50];
    int br;
    PositionS L;
    PositionS D;
} cvorStabla;

int IspisDrzavaIzDat(char* dat,PositionL head);
int UnesiDrzavu(PositionL head,PositionL noviEl, char* datGradovi);
int StvoriIIspisiStablo(char* datGradovi,PositionL drzava);
PositionS UnesiGrad(PositionS root,PositionS noviEl);
PositionL StvoriDrzavu(char* ime);
PositionS StvoriGrad(char* ime,int br);

int main()
    {
        PositionL head;

        int IspisDrzavaIzDat("drzave.txt",&head);

        return 0;
    }

int IspisDrzavaIzDat(char* dat,PositionL head)
    {
        FILE* dat = NULL;
        char buffer[MAX_SIZE]={0};
        char imeDr[MAX_SIZE]={0};
        char imeDat[MAX_SIZE]={0};
        PositionS root=NULL;

        dat=fopen(dat,"r");

        if(dat==NULL)
            {
            printf("Greska pri otvaranju datoteke.\n");
            return 1;
        }

        while(!feof)
        {
            fgets(buffer,MAX_SIZE,dat);
            sscanf(buffer," %s %s",imeDr,imeDat); 
            UnesiDrzavu(head,StvoriDrzavu(imeDr));
        }

        fclose(dat);

        return 0;
    }

int UnesiDrzavu(PositionL head,PositionL noviEl,char* datGradovi) 
    {
        PositionL p=head;

        while(p->next!=NULL)
        {
            p=p->next;
        }

        p->next=noviEl;
        noviEl->next=NULL;

        StvoriIIspisiStablo(datGradovi,noviEl);

    return 0;
    }

int StvoriIIspisiStablo(char* datGradovi,PositionL drzava)  
    {
        FILE* dat=NULL;

        dat=fopen(datGradovi,"r");
    }

PositionS UnesiGrad(PositionS root,PositionS noviEl) 
    {
        if(root==NULL)
            return noviEl;
        else if(noviEl->br>root->br) 
            root->D=UnesiGrad(root->D,noviEl);
        else if(noviEl->br<root->br)
            root->L=UnesiGrad(root->L,noviEl);
        else if(noviEl->br==root->br) 
            {
                if(strcmp(noviEl->imeGr,root->imeGr)<0)
                    root->L=UnesiGrad(root->L,noviEl);
                else
                    root->D=UnesiGrad(root->D,noviEl);
            }

        return root;
    }

PositionL StvoriDrzavu(char* ime)
    {
        PositionL drzava=NULL;

        drzava=(PositionL)malloc(sizeof(cvorListe));

        if(drzava==NULL)
            {
                printf("Greska pri alokaciji elementa liste.\n");
                return NULL;
            }

            strcpy(drzava->imeDrz,ime);
            drzava->next = NULL;
            drzava->stablo = NULL;

            return drzava;
    }

PositionS StvoriGrad(char* ime,int br)  
    {
        PositionS grad=NULL;

        grad=(PositionS)malloc(sizeof(cvorStabla));

        if(grad==NULL)
            {
                printf("Greska pri alokaciji elementa stabla.\n");
                return NULL;
            }

        strcpy(grad->imeGr,ime);
        grad->br=br;
        grad->D=NULL;
        grad->L=NULL;

        return grad;
    }
