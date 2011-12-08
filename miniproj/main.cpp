#include <iostream>
#include <math.h>
#include <stdlib.h>
//#define DEBUG
using namespace std;

typedef struct matrice { //structure de matrice contenant un tableau et le nombre d'elts par ligne du tableau
	int tab[10][10];
	int l[10];
} matrice;
void insert(int elt, matrice* mat, int etape);
int ask(matrice* mat);
void afficher(matrice* mat);
void sort(matrice* in, matrice* out, int etape);
void initialise(matrice* mat) ;


int main () {
	matrice* m1 = (matrice*)malloc(sizeof(matrice)); //on alloue la memoire pour nos 2 matrices
	matrice* m2 = (matrice*)malloc(sizeof(matrice));
	int n;

	initialise(m1); //initialisation des matrices
	initialise(m2);

    n = ask(m1); //demande d'entrées
    afficher(m1);
	cout << "Nombre d'étapes nécessaires : " << n << endl;

	int i;
    for (i = 1; i < n; i++) {

#ifdef DEBUG
		cout << "Etape " << i << endl;
#endif

		sort(m1, m2, i); // on tri
		matrice* tmp = m1; // a la fin de la manipulation, on echange les pointeurs des matrices
		m1 = m2;
		m2 = tmp;
		initialise(m2);
	}
    afficher(m1);
	free(m1); //on libère la memoire prise par les matrices
	free(m2);
	return 0;
};


//fonction qui classe les elements des differentes classes dans la matrice d'arrivée
void sort(matrice* in, matrice* out, int etape) {
	for(int i = 0; i < 10; i++) { // parcours des classes
		for (int j = 0; j < in->l[i]; j++) { // parcours des éléments
			insert(in->tab[i][j] , out, etape);
		}
	}
}

//fonction qui insert l'element elt dans la matrice mat pour la puissance de 10 qui correspond à l'etape
void insert(int elt, matrice* mat, int etape) {
	int flo;
	int indice;

	flo = floor(elt/pow(10,etape));
	indice = flo%10; //calcule

#ifdef DEBUG
	cout << "\tElt : " << elt << ", indice : " << indice << ", position : " << mat->l[indice] << endl;
#endif

	mat->tab[indice][mat->l[indice]] = elt;
	mat->l[indice]++;
}

//fonction qui initialise le tableau contenant le nombre d'element par classe.
void initialise(matrice* mat) {
	int i;
	for (i=0; i<10; i++) {
		mat->l[i] = 0;
	}
}

 // fonction permettant d'afficher les matrices
void afficher(matrice* mat) {
	for (int i(0);i<10;i++) {
		cout << "Classe " << i << " : ";
		for (int j(0);j<(*mat).l[i];j++) {
			cout << mat->tab[i][j]<< " ";
		}
		cout << "(" << mat->l[i] << " elts)" << endl;
	 }
};

// fonction qui demande les valeurs et classe une premiere fois
int ask(matrice* mat) {
	int n(0);
    int nb(0);
    int nbelt(0);

    cout << "Combien d'éléments voulez-vous classer ?" << endl;
    cin >> nbelt;
	cout << "Entrez vos nombres à classer :" << endl;
    for (int i = 0; i < nbelt; i++) {		cin >> nb;
		insert(nb, mat, 0); /* elt, tableau, indice de tri */

		while(nb > pow(10,n)) n++;
    }

    return n;
};

