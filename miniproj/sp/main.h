#include <iostream>
#include <math.h>
#include <stdlib.h>

typedef struct matrice
{
int tab[10][100];
int elt[10];
} matrice;

void insert(int nb, matrice* mat, int etape) ;
void sort(matrice* in, matrice* out, int etape);
void afficher(matrice* mat);
void initialise(matrice* mat);
