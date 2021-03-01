#ifndef SEGEDFUGGVENYEK_H_INCLUDED
#define SEGEDFUGGVENYEK_H_INCLUDED
int fiokoslista(Lista* listaeleje);
Uzenet* Uzenetuccso(Uzenet *uzenetelso);
Ismerosok* Ismuccso(Ismerosok* elso);
Ismerosok* Filebeolvas(Ismerosok* eleje);
void Filebair_ism(Lista* fiok,Ismerosok* eleje);
int felkeresek_szama(Ismerosok* eleje,Lista* en);
bool ismerosom_e(Ismerosok* ismereleje,Lista* listaeleje,Lista* en,Lista* szemely);
int ismeroseim_szama(Ismerosok* ismereleje,Lista* listaeleje,Lista* en);
bool ismerosom_e_inttel(Ismerosok* ismereleje,Lista* listaeleje,Lista* en,int szemely);
Uzenet* Filebololvas_uzenet(Uzenet* uzeneteleje);
void Filebair_uzenet(Uzenet* uzeneteleje);
int Uzeneteim_szama(Uzenet* uzeneeleje,Lista* en);
#endif // SEGEDFUGGVENYEK_H_INCLUDED
