#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "navigal.h"
int fiokoslista(Lista* listaeleje){
    Lista* mozgo=listaeleje;
    int megszamol=0;
    while(mozgo!=NULL)
    {
        mozgo=mozgo->kov;
        megszamol+=1;
    }

    return megszamol;
}
Uzenet* Uzenetuccso(Uzenet *uzenetelso)
{
    Uzenet* mozgo;
    for(mozgo=uzenetelso;mozgo->kov!=NULL;mozgo=mozgo->kov)
    {

    }
    return mozgo;
}
Ismerosok* Ismuccso(Ismerosok* elso)
{
    Ismerosok* mozgo;
    for(mozgo=elso;mozgo->kov!=NULL;mozgo=mozgo->kov)
    {

    }
    return mozgo;
}
Ismerosok* Filebeolvas(Ismerosok* eleje)
{
    FILE* fp;
    char ures[20];
    //temp=(Lista*)malloc(sizeof(Lista));
    fp=fopen("ismerosok.csv","rt");
    if(fp!=NULL){
        if(fgets(ures,200,fp)==NULL||strstr(ures,";")==0)
        {
        printf("az elejen terek egybol vissza\n");
        fclose(fp);
                return NULL;
        }
    }
    else
        perror("Nem sikerult megnyitni az ismerosok.csv filet");
    fp=fopen("ismerosok.csv","rt");

    Ismerosok* temp;
    char beolvas[20];
    while(fgets(beolvas,20,fp)!=NULL)
    {
        //printf("\n%s\n",beolvas);
        temp=(Ismerosok*)malloc(sizeof(Ismerosok));
        char* token=strtok(beolvas,";");
        sscanf(token,"%d",&temp->egyikId);
        //printf("%d %s id\n", temp->egyikId,token);


        token=strtok(NULL,";");
        sscanf(token,"%d",&temp->masikId);
        //printf("%d %s id\n", temp->masikId,token);


        token=strtok(NULL,";");
        sscanf(token,"%d",&temp->igenvnem);

        token=strtok(NULL,";");
        sscanf(token,"%d",&temp->lattam);
        //printf("%d %s id\n", temp->igenvnem,token);
        ///temp->kov=eleje;eleje=temp;
        temp->kov=eleje;
        eleje=temp;
//        temp->kov=NULL;
//        if(eleje==NULL)
//            eleje=temp;
//        else
//        {
//            printf("eddig jo");
//            Ismerosok* mozgo=eleje;
//            while(mozgo->kov!=NULL)
//                mozgo=mozgo->kov;
//            mozgo->kov=temp;
//        }
    }
    fclose(fp);
    return eleje;
}
void Filebair_ism(Lista* fiok,Ismerosok* eleje)
{
    FILE* fp;
    fp=fopen("ismerosok.csv","wt");
    Ismerosok* mozgo=eleje;
    while(mozgo!=NULL)
    {
        Ismerosok *next_one = mozgo->kov;
        fprintf(fp,"%d;%d;%d;%d;\n",mozgo->egyikId,mozgo->masikId,mozgo->igenvnem,mozgo->lattam);
        free(mozgo);
        mozgo=next_one;
    }
    fclose(fp);
}
int felkeresek_szama(Ismerosok* eleje,Lista* en)
{
    Ismerosok* mozgo;
    mozgo=eleje;
    int i=0;
    while(mozgo!=NULL)
    {
        //printf("%d;%d\n",mozgo->egyikId,mozgo->masikId);
        if(mozgo->masikId==en->Id&&mozgo->lattam==0)
            i++;
        mozgo=mozgo->kov;
    }
    return i;
}
bool ismerosom_e(Ismerosok* ismereleje,Lista* listaeleje,Lista* en,Lista* szemely)
{
    Ismerosok* mozgoismer=ismereleje;
    while(mozgoismer!=NULL)
    {
            //printf("ismeregy  %d  enid  %d  &&   ismerket  %d  szemely  %d  &&  mozgoismer  %d \n",mozgoismer->egyikId,en->Id,mozgoismer->masikId,szemely->Id,mozgoismer->igenvnem);
            if((mozgoismer->egyikId==en->Id&&mozgoismer->masikId==szemely->Id)&&mozgoismer->igenvnem==1)
            {
                return true;
            }
            else if((mozgoismer->egyikId==szemely->Id&&mozgoismer->masikId==en->Id)&&mozgoismer->igenvnem==1)
            {
                return true;
            }
        mozgoismer=mozgoismer->kov;
    }
    return false;
}
int ismeroseim_szama(Ismerosok* ismereleje,Lista* listaeleje,Lista* en)
{
    Ismerosok* mozgoismer=ismereleje;
    Lista* mozgolista;
    mozgolista=listaeleje;
    int szam=0;
    while(mozgoismer!=NULL)
    {
        mozgolista=listaeleje;
        while(mozgolista!=NULL)
        {
            //printf("ismeregy  %d  enid  %d  &&   ismerket  %d  litsaid  %d  &&  mozgoismer  %d\n",mozgoismer->egyikId,en->Id,mozgoismer->masikId,mozgolista->Id,mozgoismer->igenvnem);
            if((mozgoismer->egyikId==en->Id&&mozgoismer->masikId==mozgolista->Id)&&mozgoismer->igenvnem==1)
            {
                //printf("%s\n",mozgolista->Nev);
                szam++;
            }
            if((mozgoismer->egyikId==mozgolista->Id&&mozgoismer->masikId==en->Id)&&mozgoismer->igenvnem==1)
            {
                //printf("%s\n",mozgolista->Nev);
                szam++;
            }
            mozgolista=mozgolista->kov;
        }
        mozgoismer=mozgoismer->kov;
    }
    return szam;
}
bool ismerosom_e_inttel(Ismerosok* ismereleje,Lista* listaeleje,Lista* en,int szemely)
{
        Ismerosok* mozgoismer=ismereleje;
    while(mozgoismer!=NULL)
    {
            //printf("ismeregy  %d  enid  %d  &&   ismerket  %d  szemely  %d  &&  mozgoismer  %d \n",mozgoismer->egyikId,en->Id,mozgoismer->masikId,szemely->Id,mozgoismer->igenvnem);
            if((mozgoismer->egyikId==en->Id&&mozgoismer->masikId==szemely)&&mozgoismer->igenvnem==1)
            {
                return true;
            }
            else if((mozgoismer->egyikId==szemely&&mozgoismer->masikId==en->Id)&&mozgoismer->igenvnem==1)
            {
                return true;
            }
        mozgoismer=mozgoismer->kov;
    }
    return false;
}
Uzenet* Filebololvas_uzenet(Uzenet* uzeneteleje)
{
    FILE* fp;
    char ures[200];
    //temp=(Lista*)malloc(sizeof(Lista));
    fp=fopen("uzenetek.csv","rt");
    if(fp!=NULL){
        if(fgets(ures,200,fp)==NULL||strstr(ures,";")==0)
        {
        printf("az elejen terek egybol vissza\n");
        fclose(fp);
                return uzeneteleje;
        }
    }
    else
        perror("Nem sikerult megnyitni az uzenetek.csv filet");
        fp=fopen("uzenetek.csv","rt");

        Uzenet* temp;
        char beolvas[520];


    while(fgets(beolvas,200,fp)!=NULL)
    {

        temp=(Uzenet*)malloc(sizeof(Uzenet));
        //printf("%s\n",beolvas);
        char* token=strtok(beolvas,";");
        sscanf(token,"%d",&temp->cimzettId);

        token = strtok(NULL, ";");
        sscanf(token,"%d",&temp->felado);

        token = strtok(NULL, ";");
        sscanf(token,"%d",&temp->lattam);

        token = strtok(NULL, ";");
        temp->szoveg=(char*)malloc(strlen(token)*sizeof(char));
        strcpy(temp->szoveg, token);


        if(uzeneteleje==NULL)
            uzeneteleje=temp;
        else
        {
            Uzenet* mozgo=uzeneteleje;
            while(mozgo->kov!=NULL)
                mozgo=mozgo->kov;
            mozgo->kov=temp;
        }
    }

    fclose(fp);
    return uzeneteleje;
}
void Filebair_uzenet(Uzenet* uzeneteleje)           ///cimzettId;felado;lattam;szoveg;
{
    FILE* fp;
    fp=fopen("uzenetek.csv","wt");
    Uzenet* mozgo=uzeneteleje;
    while(mozgo!=NULL)
    {
        Uzenet *next_one = mozgo->kov;
        fprintf(fp,"%d;%d;%d;%s;\n",mozgo->cimzettId,mozgo->felado,mozgo->lattam,mozgo->szoveg);
        free(mozgo->szoveg);
        free(mozgo);
        mozgo=next_one;
    }
    fclose(fp);
}
int Uzeneteim_szama(Uzenet* uzeneeleje,Lista* en)
{
    Uzenet* mozgo=uzeneeleje;
    int i=0;
    while(mozgo!=NULL)
    {
        if(mozgo->cimzettId==en->Id&&mozgo->lattam==0)
        {
            i++;
        }
        mozgo=mozgo->kov;
    }
    return i;
}
