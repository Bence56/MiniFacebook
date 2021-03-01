#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"main.h"
void Bejelentkezes(Lista* first) //mukodik
{
    bool megvan=false;
    printf("Adja meg a felhasznalonevet :");
    char login[50];
    scanf("%s",login);
    printf("Adja meg a jelszavat :");
    char pw[50];
    scanf("%s",pw);
    Lista* elozo=NULL;
    Lista* mozgo;
    mozgo=first;
    bool rossz=false;
    if(mozgo->kov==NULL)
    {
        if(strcmp(login,mozgo->Felhasznalonev)==0&&strcmp(pw,mozgo->Jelszo)==0)
        {
            //printf("Jo a felhasznalonev es a jelszo\n");
            megvan=true;
        }
        else if(strcmp(login,mozgo->Felhasznalonev)==0&&strcmp(pw,mozgo->Jelszo)!=0)
        {
            rossz=true;
            //printf("Letezik ilyen felhasznalonev de a jelszavad rossz");
        }
        else
        {
            //printf("Hibas bejelentkezesi adatok\n");
        }

    }
    else{
        while(mozgo!=NULL&&!megvan)
        {
            if(strcmp(login,mozgo->Felhasznalonev)==0&&strcmp(pw,mozgo->Jelszo)==0)
            {
                //printf("Jo a felhasznalonev es a jelszo\n");
                megvan=true;
            }
            else if(strcmp(login,mozgo->Felhasznalonev)==0&&strcmp(pw,mozgo->Jelszo)!=0)
            {
                rossz=true;
                //printf("Letezik ilyen felhasznalonev de a jelszavad rossz");
            }
            else
            {
                //printf("Hibas bejelentkezesi adatok\n");
            }
            elozo=mozgo;
            mozgo=mozgo->kov;
        }
    }
    system("cls");
    if(rossz&&!megvan)
        printf("Letezik ilyen felhasznalonev az adatbazisban, de a jelszavad rossz.\n");
    else if(!rossz&&!megvan)
        printf("Hibas bejelentkezesi adatok.\n");
    if(megvan){
            //printf("az ifbe is belep");
            Navigal(elozo,first);
    }

}
