#ifndef MENUPONTOK_H_INCLUDED
#define MENUPONTOK_H_INCLUDED
void Kereses(Lista* first,Lista* fiok);
Ismerosok* Bejelol(Ismerosok* elso,Lista* fiok);
void Jeloleseim(Lista* fiok,Lista* listaeleje,Ismerosok* ismerosokeleje);
void Ismeroseim_listazasa(Ismerosok* ismereleje,Lista* listaeleje,Lista* en);
void Ismeroseim_ismerosei(Ismerosok* ismereleje,Lista* listaeleje,Lista* en);
Uzenet* Uzenetet_ir(Ismerosok* ismereleje,Lista*listaeleje,Lista* en,Uzenet* uzeneteleje);
void Uzenetek_megjelenitese(Uzenet* uzeneteleje,Lista* en,Lista* listaeleje);

#endif // MENUPONTOK_H_INCLUDED
