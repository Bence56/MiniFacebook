#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
typedef struct Datum{
    int ev;
    int honap;
    int nap;
}Datum;
typedef struct Lista{
    int Id;
    char* Felhasznalonev;
    char* Jelszo;
    char* Nev;
    int Nem;
    char* Lakohely;
    char* Munkahely;
    char* Hobbi;
    Datum Szuletesi;
    struct Lista* kov;
}Lista;
int accid;

#endif // MAIN_H_INCLUDED
