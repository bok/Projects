#include "main.h"

using namespace std;

int main()
{
    int n(0), nbelt, nb;
    matrice *m1(0);
    matrice *m2(0); //on creer des pointeurs vers des matrices
    m1 = new matrice; //on aloue la memoire des matrices
    m2 = new matrice;

    initialise(m1); //on initialise les nombres d'elements dans les lignes à zero
    initialise(m2);

    cout << "Combien de nb à classer ?" << endl;
    cin >> nbelt;
    cout << "Entrez ces nombres :" << endl;
    for (int i(0);i<nbelt;i++)
    {
        cin >> nb;
        insert(nb, m1, 0); 
// on met l'element nb dans la matrice m1, indice 0
		while(nb > pow(10,n)) n++; 
//on determine le nombres d'etapes a faire
    }
    afficher(m1); //on affiche la matrice
    cout << "Il y aura " << n << " etapes" << endl;

    for (int j(1);j<n;j++)
    {
        sort(m1, m2, j); //on tri 
        matrice* tmp = m1;
        m1 = m2; //on echange les pointeurs des 2 matrices
        m2 = tmp;
        initialise(m2);
 //on remet les nombres d'elements à 0 dans la matrice d'arrivée
    }
    cout << "Resultat :" << endl;
    afficher(m1);
    delete m1;    //On libère la case mémoire
    m1 = 0;
    delete m2;    //On libère la case mémoire
    m2 = 0;
}

void initialise(matrice* mat) //initialisation des matrices
{
    for (int i(0);i<10;i++)
    {
    (*mat).elt[i] = 0;
    }
}

void afficher(matrice* mat) //fonction d'affichage
{
    for (int i(0);i<10;i++)
    {
        cout << "Classe " << i << " :";
        for (int j(0);j<(*mat).elt[i];j++)
        {
            cout << (*mat).tab[i][j] << " ";
        }
        cout << "(" << (*mat).elt[i] << " elts)" <<endl;
    }
}

void insert(int nb, matrice* mat, int etape) 
//fonction d'insertion des nombres dans une matrice suivant une etape
{
    int indice = (int)floor(nb/pow(10,etape))%10;
    (*mat).tab[indice][(*mat).elt[indice]] = nb;
    (*mat).elt[indice]++;
}

void sort(matrice *in, matrice *out, int etape) //on tri la matrice d'entree in dans la matrice de sortie out suivant l'etape
{
    for (int i(0);i<10;i++)
    {
        for (int j(0);j<(*in).elt[i];j++)
        {
            insert((*in).tab[i][j],out,etape);
        }
    }
}
