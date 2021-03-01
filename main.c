#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"
#include "navigal.h"
#include "regisztracio.h"
#include "bejelentkezes.h"
///#include "ismerosrendszer.h"
///typedef struct Datum{
///    int ev;
///    int honap;
///    int nap;
///}Datum;
int accid=0;
///typedef struct Lista{
///    int Id;
///    char* Felhasznalonev;
///    char* Jelszo;
///    char* Nev;
///    int Nem;//0 anõ 1 a férfi
///    char* Lakohely;
///    char* Munkahely;
///    char* Hobbi;
///    Datum Szuletesi;
///    struct Lista* kov;
///}Lista;
int fiokidinit(char* alakitani)
{
    return atoi(alakitani);
}
void Listanvegig(Lista *elso)
{
    Lista* mozgo;
    for(mozgo=elso;mozgo!=NULL;mozgo=mozgo->kov)
    printf("%s;%s;%d\n",mozgo->Nev,mozgo->Felhasznalonev,mozgo->Id);
}
Lista* Listauccso(Lista *elso)
{
    Lista* mozgo;
    for(mozgo=elso;mozgo->kov!=NULL;mozgo=mozgo->kov)
    {

    }
    return mozgo;
}
void Filebair(Lista* eleje)
{
    FILE* fp;
    fp=fopen("adatok.csv","wt");
    Lista* mozgo=eleje;
    while(mozgo!=NULL)
    {
        Lista *next_one = mozgo->kov;
        fprintf(fp,"%d;%s;%s;%s;%d;%s;%s;%s;%d.%d.%d;\n",mozgo->Id,mozgo->Felhasznalonev,mozgo->Jelszo,mozgo->Nev,mozgo->Nem,mozgo->Lakohely,mozgo->Munkahely,mozgo->Hobbi,mozgo->Szuletesi.ev,mozgo->Szuletesi.honap,mozgo->Szuletesi.nap);
        free(mozgo->Felhasznalonev);
        free(mozgo->Jelszo);
        free(mozgo->Nev);
        free(mozgo->Lakohely);
        free(mozgo->Hobbi);
        free(mozgo);
        mozgo=next_one;
    }
    fclose(fp);
}
Lista* Filebololvas(Lista* eleje) //mukodik
{
    //0;login;pw;Somogyi Bence;1;Mosonmagyarovar;BME VIK;labdarugas;1999.11.6;
    FILE* fp;
    char ures[200];
    //temp=(Lista*)malloc(sizeof(Lista));
    fp=fopen("adatok.csv","rt");
    if(fp!=NULL){
        if(fgets(ures,200,fp)==NULL||strstr(ures,";")==0)
        {
                //printf("az elejen terek egybol vissza\n");
                fclose(fp);
                return eleje;
        }
    }
    else
        perror("Nem sikerult megnyitni az adatok.csv nevu filet");
    fclose(fp);
    fp=fopen("adatok.csv","rt");

    Lista* temp;
    char beolvas[200];

///nev;date;place;note;
    while(fgets(beolvas,200,fp)!=NULL)
    {
        temp=(Lista*)malloc(sizeof(Lista));
        //printf("%s\n",beolvas);
        char* token=strtok(beolvas,";");
        sscanf(token,"%d",&temp->Id);
        accid=fiokidinit(token);
        //printf("%s id\n", token);

        token = strtok(NULL, ";");
        temp->Felhasznalonev=(char*)malloc(strlen(token)*sizeof(char));
        strcpy(temp->Felhasznalonev, token);
        //printf("%s login\n", token);

        token = strtok(NULL, ";");
        temp->Jelszo=(char*)malloc(strlen(token)*sizeof(char));
        strcpy(temp->Jelszo, token);
        //printf("%s pw\n", token);


        token = strtok(NULL, ";");
        temp->Nev=(char*)malloc(strlen(token)*sizeof(char));
        strcpy(temp->Nev, token);
        //printf("%s name\n", token);

        token=strtok(NULL,";");
        sscanf(token,"%d;",&temp->Nem);
        //printf("%s sex\n", token);

        token = strtok(NULL, ";");
        temp->Lakohely=(char*)malloc(strlen(token)*sizeof(char));
        strcpy(temp->Lakohely, token);
        //printf("%s hometown\n", token);

        token = strtok(NULL, ";");
        temp->Munkahely=(char*)malloc(strlen(token)*sizeof(char));
        strcpy(temp->Munkahely, token);
        //printf("%s munka\n", token);


        token = strtok(NULL, ";");
        temp->Hobbi=(char*)malloc(strlen(token)+1*sizeof(char));
        strcpy(temp->Hobbi, token);
        //printf("%s hobbi\n", token);

        token=strtok(NULL,";");
        sscanf(token,"%d.%d.%d",&temp->Szuletesi.ev,&temp->Szuletesi.honap,&temp->Szuletesi.nap);
        //printf("%d.%d.%d bd\n",temp->Szuletesi.ev,temp->Szuletesi.honap,temp->Szuletesi.nap);
        if(eleje==NULL)
            eleje=temp;
        else
        {
            Lista* mozgo=eleje;
            while(mozgo->kov!=NULL)
                mozgo=mozgo->kov;
            mozgo->kov=temp;
        }
    }

    fclose(fp);
    return eleje;
}
int main()
{

    //vabool volteleje=false;
    Lista* eleje=NULL;
    //eleje->kov=NULL;
    //printf("Mi a budos faszomez");
    //eleje=(Lista*)malloc(sizeof(Lista));
    eleje=Filebololvas(eleje);
//    Lista* utolso;
  //  utolso=Listauccso(eleje);
    printf("\n\n\n");
    printf("Udvozlom!Jelentkezzen be vagy regisztraljon!\n\n\n");
    int beolvas;
    while(beolvas!=3)
    {
        printf("Bejelentkezeshez nyomjon 1-et!\nRegisztraciohoz nyomjon 2-t!\nKilepeshez nyomjon 3-t!\n");
        scanf("%d",&beolvas);
        while(beolvas!=1 && beolvas!=2&&beolvas!=3)
        {
            printf("Irja be ujra! : ");
            scanf("%d",&beolvas);
        }
        if(beolvas==2)
        {
            printf("Regisztracio:\n");
            //Lista *utolso;
            if(eleje==NULL)
            {
                //printf("csak az elso ciklusba lep be\n");
                eleje=Regisztracio();
            }
            else
            {
              Lista* mozgo=eleje;
              while(mozgo->kov!=NULL)
                mozgo=mozgo->kov;
              mozgo->kov=Regisztracio();
            }
            system("cls");
            printf("Sikeres regisztracio!\n\n\n");
        }
        else if(beolvas==1&&eleje!=NULL)
            {
            printf("Bejelentkezes:\n");
            Bejelentkezes(eleje);

            }
        else if(beolvas==3)
            break;
    }
    system("cls");
    printf("Koszonjuk hogy hasznalta a programot!\n\n");
    //Listanvegig(eleje);
    Filebair(eleje);
    return 0;
}
