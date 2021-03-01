#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "navigal.h"
#include "menupontok.h"
#include "segedfuggvenyek.h"
void Navigal(Lista* fiok,Lista* first)
{
    Ismerosok* eleje=NULL;
    //eleje=NULL;
    eleje=Filebeolvas(eleje);
    Uzenet* uzeneteleje=NULL;
    uzeneteleje=Filebololvas_uzenet(uzeneteleje);
    //system("cls");
    int valaszt=0;

        while(valaszt!=9)
        {
            valaszt=0;
            printf("Udvozoljuk %s\n\n",fiok->Nev);
            printf("1-->Üzenet kuldese\n");                             ///                         megvan
            printf("2-->Ismerosok megjelenitese\n");                    ///                         megvan
            printf("3-->Ismerosnek jeloles\n");                         ///                         megvan
            printf("4-->Bejovo ismerosjelolesek (%d uj)\n",felkeresek_szama(eleje,fiok)); ///       megvan
            printf("5-->Kereses....\n");                                ///                         megvan
            printf("6-->Ismeros keresese(ismeroseim ismerosei)\n");     ///                         megvan
            printf("8-->Bejovo uzeneteim (%d uj)\n",Uzeneteim_szama(uzeneteleje,fiok));                      ///                       idejon
            printf("9-->Kijelentkezes\n");                              ///                         megvan
            printf("Valasztas: ");
            scanf("%d",&valaszt);
            if(valaszt==5)
            {
                system("cls");
                Kereses(first,fiok);
            }
            else if(valaszt==3)
            {
                system("cls");
                eleje=Bejelol(eleje,fiok);
            }
            else if(valaszt==4)
            {
                system("cls");
                Jeloleseim(fiok,first,eleje);
            }
            else if(valaszt==2)
            {
                system("cls");
                Ismeroseim_listazasa(eleje,first,fiok);
            }
            else if(valaszt==6)
            {
                system("cls");
                Ismeroseim_ismerosei(eleje,first,fiok);
            }
            else if(valaszt==1)
            {
                system("cls");
                Uzenet* ujuzi=Uzenetet_ir(eleje,first,fiok,uzeneteleje);
                if(ujuzi==NULL)
                {

                }
                else
                {
                    if(uzeneteleje==NULL)
                        uzeneteleje=ujuzi;
                    else
                    {
                        Uzenet* mozgo;
                        mozgo=uzeneteleje;
                        while(mozgo->kov!=NULL)
                        {
                            mozgo=mozgo->kov;
                        }
                        mozgo->kov=ujuzi;
                    }
                }

            }
            else if(valaszt==8)
            {
                system("cls");
                Uzenetek_megjelenitese(uzeneteleje,fiok,first);
            }

        }
        Filebair_ism(fiok,eleje);
        Filebair_uzenet(uzeneteleje);
        system("cls");
}
