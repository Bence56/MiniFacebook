#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "navigal.h"
#include "segedfuggvenyek.h"
void Kereses(Lista* first,Lista* fiok)
{
        int szam=0;
        char szoveg[50];
        while(szam!=5)
        {
            printf("Mi alapjan szeretne keresni?\n\n");
            printf("1-->Nev\n");
            printf("2-->Iskola\n");
            printf("3-->Lakohely\n");
            printf("4-->Hobbi\n");
            printf("5-->Inkabb kielepek\n");
            printf("Valasztas: ");
            scanf("%d",&szam);
            puts("Gepelje be a szoveget:");

            if(szam!=5)
            {
            gets(szoveg);
            gets(szoveg);
            }
            printf("\n");
            system("cls");
            Lista*mozgo=first;
            int talalat=0;
            if(szam==1)
            {
                while(mozgo!=NULL)
                {
                    if(strstr(mozgo->Nev,szoveg)!=0&&fiok->Id!=mozgo->Id)
                    {
                        printf("Nev: %s\n",mozgo->Nev);
                        printf("Itt dolgozik: %s\n",mozgo->Munkahely);
                        printf("Hobbija: %s\n",mozgo->Hobbi);
                        printf("Itt lakik: %s\n",mozgo->Lakohely);
                        printf("Id: %d\n",mozgo->Id);
                        printf("Jegyezd meg az id-t!Ez kell a bejeloleshez es az uzenetkzuldeshez\n\n");
                        talalat++;
                    }
                    mozgo=mozgo->kov;
                }
                if(talalat==0)
                    printf("nincs talalat");
            }
            else if(szam==2)
            {
                while(mozgo!=NULL)
                {
                    if(strstr(mozgo->Munkahely,szoveg)!=0&&fiok->Id!=mozgo->Id)
                    {
                        printf("Nev: %s\n",mozgo->Nev);
                        printf("Itt dolgozik: %s\n",mozgo->Munkahely);
                        printf("Hobbija: %s\n",mozgo->Hobbi);
                        printf("Itt lakik: %s\n",mozgo->Lakohely);
                        printf("Id: %d\n",mozgo->Id);
                        printf("Jegyezd meg az id-t!Ez kell a bejeloleshez es az uzenetkzuldeshez\n\n");
                        talalat++;
                    }
                    mozgo=mozgo->kov;
                }
                if(talalat==0)
                    printf("nincs talalat");
            }
            else if(szam==3)
            {
                while(mozgo!=NULL)
                {
                    if(strstr(mozgo->Lakohely,szoveg)!=0&&fiok->Id!=mozgo->Id)
                    {
                        printf("Nev: %s\n",mozgo->Nev);
                        printf("Itt dolgozik: %s\n",mozgo->Munkahely);
                        printf("Hobbija: %s\n",mozgo->Hobbi);
                        printf("Itt lakik: %s\n",mozgo->Lakohely);
                        printf("Id: %d\n",mozgo->Id);
                        printf("Jegyezd meg az id-t!Ez kell a bejeloleshez es az uzenetkzuldeshez\n\n");
                        talalat++;
                    }
                    mozgo=mozgo->kov;
                }
                if(talalat==0)
                    printf("nincs talalat");
            }
            else if(szam==4)
            {
                while(mozgo!=NULL)
                {
                    if(strstr(mozgo->Hobbi,szoveg)!=0&&fiok->Id!=mozgo->Id)
                    {
                        printf("Nev: %s\n",mozgo->Nev);
                        printf("Itt dolgozik: %s\n",mozgo->Munkahely);
                        printf("Hobbija: %s\n",mozgo->Hobbi);
                        printf("Itt lakik: %s\n",mozgo->Lakohely);
                        printf("Id: %d\n",mozgo->Id);
                        printf("Jegyezd meg az id-t!Ez kell a bejeloleshez es az uzenetkzuldeshez\n\n");
                        talalat++;
                    }
                    mozgo=mozgo->kov;
                }
                if(talalat==0)
                    printf("nincs talalat\n\n");
            }
        }
        //return;

}
Ismerosok* Bejelol(Ismerosok* elso,Lista* fiok)         ///feladoId;cimzettId;elfogadvavnem;lattaevnem;
{
    printf("Kit szeretnel bejelolni (id alapjan) :");
    int szam;
    scanf("%d",&szam);
    Ismerosok* temp;
    temp=(Ismerosok*) malloc(sizeof(Ismerosok));
    temp->egyikId=fiok->Id;
    temp->masikId=szam;
    temp->igenvnem=0;
    temp->lattam=0;
    temp->kov=elso;
    elso=temp;
//     int i=0;
//    if(elso==NULL)
//            elso=temp;
//    else
//    {
//        printf("eddig jo");
//
//        Ismerosok* mozgo=elso;
//        while(mozgo->kov!=NULL)
//        {
//            mozgo=mozgo->kov;
//            printf("%d\n",i++);
//        }
//        printf("%d\n",i++);
//        mozgo->kov=temp;
//    }
//    printf("%d\n",i++);
    return elso;
}
void Jeloleseim(Lista* fiok,Lista* listaeleje,Ismerosok* ismerosokeleje)
{
    int db=felkeresek_szama(ismerosokeleje,fiok);
    int szam=0;
    if(db==0)
        printf("Nincs uj jelolesed :(\n");
    else
    {
        Ismerosok* mozgoismer=ismerosokeleje;
        Lista* mozgolista=listaeleje;
        while(mozgoismer!=NULL)
        {
            //printf("ism %d\n",mozgoismer->egyikId);


            mozgolista=listaeleje;

            while(mozgolista!=NULL)
            {
                //printf("ismer elso  %d  lista id  %d  && ismer masik  %d  fiok id  %d  &&  lattam  %d",mozgoismer->egyikId,mozgolista->Id,mozgoismer->masikId,fiok->Id,mozgoismer->lattam);
                if((mozgoismer->egyikId==mozgolista->Id&&mozgoismer->masikId==fiok->Id)&&mozgoismer->lattam==0)
                {
                    printf("Ismerõsnek jeloltek!\n");
                    printf("%s\n",mozgolista->Nev);
                    printf("%s\n",mozgolista->Lakohely);
                    printf("%s\n\n",mozgolista->Munkahely);
                    printf("Ha elfogadod a felkerest nyom 1-et, ha nem akkor 0-t:\n");
                    scanf("%d",&szam);
                    if(szam==0)
                    {
                        printf("Elutasitottad\n");
                        mozgoismer->lattam=1;
                        mozgoismer->igenvnem=0;
                    }
                    else if(szam==1)
                    {
                        printf("Mostantol %s az ismerosod\n",mozgolista->Nev);
                        mozgoismer->lattam=1;
                        mozgoismer->igenvnem=1;
                    }
                    else
                        printf("Ervenytelen eredmeny\n");
                }
                //printf("list %s\n",mozgolista->Nev);

                mozgolista=mozgolista->kov;
            }

            mozgoismer=mozgoismer->kov;
        }

    }
}
void Ismeroseim_listazasa(Ismerosok* ismereleje,Lista* listaeleje,Lista* en)
{
    Ismerosok* mozgoismer=ismereleje;
    Lista* mozgolista;
    mozgolista=listaeleje;
    //bool versio1=false;
    //bool versio2=false;
    int szam=0;
    printf("Ismeroseim:\n");
//    printf("ismerosok lista:\n");
//    Ismerosok* segit=ismereleje;
//    while(segit!=NULL)
//    {
//        printf("%d,%d,%d\n",segit->egyikId,segit->masikId,segit->igenvnem);
//        segit=segit->kov;
//    }

    while(mozgoismer!=NULL)
    {
        mozgolista=listaeleje;
        while(mozgolista!=NULL)
        {
            //printf("ismeregy  %d  enid  %d  &&   ismerket  %d  litsaid  %d  &&  mozgoismer  %d\n",mozgoismer->egyikId,en->Id,mozgoismer->masikId,mozgolista->Id,mozgoismer->igenvnem);
            if((mozgoismer->egyikId==en->Id&&mozgoismer->masikId==mozgolista->Id)&&mozgoismer->igenvnem==1)
            {
                printf("%s   id: %d\n",mozgolista->Nev,mozgolista->Id);
                szam++;
            }
            if((mozgoismer->egyikId==mozgolista->Id&&mozgoismer->masikId==en->Id)&&mozgoismer->igenvnem==1)
            {
                printf("%s   id: %d\n",mozgolista->Nev,mozgolista->Id);
                szam++;
            }
            mozgolista=mozgolista->kov;
        }
        mozgoismer=mozgoismer->kov;
    }
    if(szam==0)
    {
        printf("Meg nincsenek ismeroseid.Jelolj be parat!\n");
    }
    else
        printf("%d ismerosod van.\n",szam);

    printf("\n\n\n");
}
void Ismeroseim_ismerosei(Ismerosok* ismereleje,Lista* listaeleje,Lista* en)  ///tobbszor is kiirja mert vegig megy a listan de mukodik meg ezt meg kell irni
{
    int tomb[ismeroseim_szama(ismereleje,listaeleje,en)];
    Lista* mozgolista=listaeleje;
    ///ismerosom_e(ismereleje,listaeleje,en,mozgolista)
    Ismerosok* mozgoismer=ismereleje;
    int i=0;
    while(mozgolista!=NULL)
    {
        if(ismerosom_e(ismereleje,listaeleje,en,mozgolista))
        {
            tomb[i]=mozgolista->Id;
            i++;
        }
        mozgolista=mozgolista->kov;
    }
    for(int i=0;i<ismeroseim_szama(ismereleje,listaeleje,en);i+=1)
    {
        //printf("%d\n",tomb[i]);
    }
    int length=fiokoslista(listaeleje);
    Kozos barat[length];
    int kozosi=0;
    while(mozgoismer!=NULL)
    {
        mozgolista=listaeleje;

        while(mozgolista!=NULL)
        {
            ///tehat ha az en ismeroseim kozt van akkor vegigmegyunk az o ismerosein aki nem en vagyok es en nem ismerem
            int i=0;
            bool ezjo=false;
            while(i<ismeroseim_szama(ismereleje,listaeleje,en)||!ezjo)
            {
                if(mozgolista->Id==tomb[i])
                    ezjo=true;
                i++;
            }
            if(!ezjo||i==0)
            {
                printf("Neked ilyennek nem leteznek\n");
                return;
            }
            if(ezjo)
            {
                Lista* masiklistmozgo=listaeleje;
                while(masiklistmozgo!=NULL)
                {
                    if(ismerosom_e(ismereleje,listaeleje,mozgolista,masiklistmozgo)&&!ismerosom_e(ismereleje,listaeleje,en,masiklistmozgo)&&masiklistmozgo->Id!=en->Id&&!ismerosom_e(ismereleje,listaeleje,masiklistmozgo,en)&&ismerosom_e(ismereleje,listaeleje,mozgolista,en))
                    {
                        bool eleme=false;
                        for(int i=0;i<kozosi;i++){
                            if(strcmp(barat[i].kit,masiklistmozgo->Nev)==0&&strcmp(barat[i].kialltal,mozgolista->Nev)==0){
                                eleme=true;
                                break;
                            }
                        }
                        if(eleme==false){
                            strcpy(barat[kozosi].kit,masiklistmozgo->Nev);
                            strcpy(barat[kozosi++].kialltal,mozgolista->Nev);
                            printf("%s   kozos ismeros: %s\n",masiklistmozgo->Nev,mozgolista->Nev);
                        }
                    }
                    masiklistmozgo=masiklistmozgo->kov;
                }
            }
            mozgolista=mozgolista->kov;
        }
        mozgoismer=mozgoismer->kov;
    }

}
Uzenet* Uzenetet_ir(Ismerosok* ismereleje,Lista*listaeleje,Lista* en,Uzenet* uzeneteleje)
{
    int cimzett;
    printf("Add meg az id-jet az uzeneted cimzettjenek:");
    scanf("%d",&cimzett);
    Uzenet* uj;
    if(!ismerosom_e_inttel(ismereleje,listaeleje,en,cimzett))
    {
            printf("O nem az ismerosod,nem tudsz neki irni");
            uj=NULL;
            //uj->kov=NULL;
    }
    else
    {
        char uzi[500];
        printf("Mit szeretnel uzenni:\n");
        gets(uzi);
        gets(uzi);

        uj=(Uzenet*)malloc(sizeof(Uzenet));
        uj->szoveg=(char*)malloc(strlen(uzi)*sizeof(char));
        strcpy(uj->szoveg,uzi);
        uj->cimzettId=cimzett;
        uj->felado=en->Id;
        //printf("%s\n",uj->szoveg);
        uj->lattam=0;
        uj->kov=NULL;
    }

    return uj;

}
void Uzenetek_megjelenitese(Uzenet* uzeneteleje,Lista* en,Lista* listaeleje)
{
    int szam=Uzeneteim_szama(uzeneteleje,en);
    if(szam==0)
    {
        printf("Nincsenek olvasatlan uzeneteid.\n");
    }
    else
    {
        Uzenet* mozgouzenet=uzeneteleje;
        Lista* mozgolista=listaeleje;
        while(mozgouzenet!=NULL)
        {
            mozgolista=listaeleje;
            while(mozgolista!=NULL)
            {
                if(mozgouzenet->felado==mozgolista->Id&&mozgouzenet->cimzettId==en->Id&&mozgouzenet->lattam==0)
                {
                    printf("Felado: %s\n",mozgolista->Nev);
                    printf("%s\n\n",mozgouzenet->szoveg);
                    mozgouzenet->lattam=1;
                }
                mozgolista=mozgolista->kov;
            }
            mozgouzenet=mozgouzenet->kov;
        }
    }
}
