#include "main.h"

using namespace std;

int main()
{
    int n(0), nbelt, nb;
    matrice *m1(0);
    matrice *m2(0);
    m1 = new matrice;
    m2 = new matrice;

    initialise(m1);
    initialise(m2);

    cout << "Combien de nb à classer ?" << endl;
    cin >> nbelt;
    cout << "Entrez ces nombres :" << endl;
    for (int i(0);i<nbelt;i++)
    {
        cin >> nb;
        insert(nb, m1, 0); // elt, tableau, indice de tri
		while(nb > pow(10,n)) n++;
    }
    afficher(m1);
    cout << "Il y aura " << n << " etapes" << endl;

    for (int j(1);j<n;j++)
    {
        sort(m1, m2, j);
        matrice* tmp = m1;
        m1 = m2;
        m2 = tmp;
        initialise(m2);
    }
    cout << "Resultat :" << endl;
    afficher(m1);
    delete m1;    //On libère la case mémoire
    m1 = 0;
    delete m2;    //On libère la case mémoire
    m2 = 0;
}

void initialise(matrice* mat)
{
    for (int i(0);i<10;i++)
    {
    (*mat).elt[i] = 0;
    }
}

void afficher(matrice* mat)
{
    for (int i(0);i<10;i++)
    {
        cout << "Classe " << i << " :";
        for (int j(0);j<(*mat).elt[i];j++)
        {
            cout << (*mat).tab[i][j] << " ";
        }
        cout << "(" << (*mat).elt[i] << " elts)" <<endl;// | Classe " << i << ")"<< endl;
    }
}

void insert(int nb, matrice* mat, int etape)
{
    int indice = (int)floor(nb/pow(10,etape))%10;
    (*mat).tab[indice][(*mat).elt[indice]] = nb;
    (*mat).elt[indice]++;
}

void sort(matrice *in, matrice *out, int etape)
{
    for (int i(0);i<10;i++)
    {
        for (int j(0);j<(*in).elt[i];j++)
        {
            insert((*in).tab[i][j],out,etape);
        }
    }
}
