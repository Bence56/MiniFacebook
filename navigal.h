#ifndef UZENET_H_INCLUDED
#define UZENET_H_INCLUDED
#include "main.h"
//int jeloltid(Lista* eleje,char* nev);
typedef struct Kozos{
    char kit[120];
    char kialltal[120];
}Kozos;
typedef struct Ismerosok{
    int egyikId;
    int masikId;
    int igenvnem;
    int lattam;
    struct Ismerosok* kov;
}Ismerosok;
typedef struct Uzenet{
    int cimzettId;
    int felado;
    int lattam;
    char* szoveg;
    struct Uzenet* kov;
}Uzenet;
void Navigal(Lista* fiok,Lista* first);
//void Navigal(Lista* fiok,Lista* first);
#endif // UZENET_H_INCLUDED
