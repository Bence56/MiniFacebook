#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"main.h"
Lista* Regisztracio()
{
    Lista* uj;
    uj=(Lista*)malloc(sizeof(Lista)*2);
    char sztring[50];
    printf("Adja meg a felhasznalonevet: ");
    scanf("%s",sztring);
    uj->Felhasznalonev=(char*)malloc(strlen(sztring)*sizeof(char));
    strcpy(uj->Felhasznalonev,sztring);
    //printf("%s\n",uj->Felhasznalonev);
    printf("Adja meg a jelszot: ");
    scanf("%s",sztring);
    uj->Jelszo=(char*)malloc(strlen(sztring)*sizeof(char));
    strcpy(uj->Jelszo,sztring);
    //printf("%s\n",uj->Jelszo);
    printf("Adja meg a nevet: ");
    gets(sztring);
    gets(sztring);
    uj->Nev=(char*)malloc(strlen(sztring)*sizeof(char));
    strcpy(uj->Nev,sztring);
    //printf("%s\n",uj->Nev);
    int szam;
    printf("Adja meg a nemet(gender:0ha no 1 ha ferfi): ");
    scanf("%d",&szam);
    uj->Nem=szam;
    printf("Adja meg a lakohelyet: ");
    gets(sztring);
    gets(sztring);
    uj->Lakohely=NULL;
    uj->Lakohely=(char*)malloc(strlen(sztring)*sizeof(char));
    strcpy(uj->Lakohely,sztring);
    //printf("%s\n",uj->Lakohely);
    printf("Adja meg a hobbijat: ");
    gets(sztring);
    //gets(sztring);
    uj->Hobbi=NULL;
    uj->Hobbi=(char*)malloc(strlen(sztring)*sizeof(char)*2);
    //printf("foglaltam helyet");
    strcpy(uj->Hobbi,sztring);
    //uj->Hobbi=sztring;
    //printf("%s\n",uj->Hobbi);
    printf("Adja meg a munkahelyet/iskolajat: ");
    gets(sztring);
    uj->Munkahely=NULL;
    uj->Munkahely=(char*)malloc(strlen(sztring)*sizeof(char)*2);
    strcpy(uj->Munkahely,sztring);
    //uj->Munkahely=sztring;
    //printf("%s\n",uj->Munkahely);
    printf("Adja meg a szuletesi evet:");
    scanf("%d",&szam);
    uj->Szuletesi.ev=szam;
    printf("Adja meg a szuletesi honapjat:");
    scanf("%d",&szam);
    uj->Szuletesi.honap=szam;
    printf("Adja meg a szuletesi napjat:");
    scanf("%d",&szam);
    uj->Szuletesi.nap=szam;
    accid++;
    uj->Id=accid;
    uj->kov=NULL;
    return uj;
}
