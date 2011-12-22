#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct employe employe;
struct employe
{
	int nom;
	employe *next;
	employe *boss;
};

employe* ajouteremploye(employe *arbre, int nom, int boss);
employe* licencieemploye(string nom);
void creerArbreInitial(employe*);
void afficher(employe*);
void ask(employe*);
void afficherbranche(employe*, int boss);

int main()
{
	employe *arbre = new employe;
	(*arbre).next = NULL;
	(*arbre).boss = arbre;

	creerArbreInitial(arbre);
	ask(arbre);
	afficher(arbre);

	return 0;
}

employe* ajouteremploye(employe* arbre, int nom, int boss)
{
	employe* nouvelemploye = new employe;
	(*nouvelemploye).nom = nom;
	(*nouvelemploye).next = NULL;
	(*nouvelemploye).boss = NULL;

	if (arbre == NULL)
	{
		return nouvelemploye;
	}
	else
	{
		employe *temp = arbre;
		while ((*temp).next != NULL)
		{
			temp = (*temp).next;
		}
		(*temp).next = nouvelemploye;

		temp = arbre;
		while ((*temp).next != NULL)
		{
			if ((*temp).nom == boss)
			{
				(*nouvelemploye).boss = temp;
			}
			temp = (*temp).next;
		}

		return nouvelemploye;
	}
}

employe* licencieemploye(employe* arbre, int nom)
{
	if (arbre == NULL)
	{
		return NULL;
	}

	employe *temp = arbre;
	while ((*temp).next != NULL)
	{
		if ((*(*temp).next).nom == nom)
		{
			employe *tmp = (*(*temp).next).next;
			delete (*temp).next;
			(*temp).next = tmp;
		}
		else
		{
			temp = (*temp).next;
		}
	}
}

void creerArbreInitial(employe *arbre)
{
	ajouteremploye(arbre, 1, 0);
	ajouteremploye(arbre, 2, 0);
	ajouteremploye(arbre, 4, 1);
	ajouteremploye(arbre, 3, 1);
	licencieemploye(arbre, 2);
}

void afficher(employe *arbre)
{
	employe *temp = arbre;
	while ((*temp).next != NULL)
	{
		cout << "nom de l'employé : " << (*temp).nom;
		cout << " | boss : " << (*(*temp).boss).nom << endl;
		temp = (*temp).next;
	}
	cout << "dernier employé ajouté : " << (*temp).nom;
	cout << " | boss : " << (*(*temp).boss).nom << endl;
}

void afficherbranche(employe *arbre, int boss)
{
	employe *temp = arbre;
	while ((*temp).next != NULL)
	{
		if ((*(*temp).boss).nom == boss)
		{
			cout << "nom de l'employé : " << (*temp).nom << endl;
		}
	temp = (*temp).next;
	}
	if ((*(*temp).boss).nom == boss)
	{
		cout << "dernier employé en date : " << (*temp).nom << endl;
	}
	cout << "Ces employés ont tous comme boss : " << boss << endl;
}


void ask(employe *arbre)
{
	int nom,nb,boss,sup,bossc;
	cout << "Entrez 1 pour ajouter un employé, 2 pour licencier, 3 pour afficher l'arbre complet, 4 pour afficher une branche de l'arbre" << endl;
	cin >> nb; cout << endl;
	switch (nb)
	{
		case 1 : 
			{
				cout << "entrez le nom de l'employé : ";
				cin >> nom;
				cout << endl << "entrez le nom de son boss : ";
				cin >> boss;
				cout << endl;
				ajouteremploye(arbre, nom, boss);
				break;
			}
		case 2 : 
			{
				cout << "entrez le nom de l'employe a supprimer : ";
				cin >> sup;
				cout << endl;
				licencieemploye(arbre, sup);
				break;
			}
		case 3 : 
			{
				afficher(arbre);
				break;
			}
		case 4 : 
			{
				cout << "Entrez le nom du boss dont vous voulez connaitre les employés : ";
				cin >> bossc;
				afficherbranche( arbre, bossc);
				break;
			}
	}
}
