#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct employe employe;
struct employe
{
	string nom;
	employe *next;
	employe *boss;
};

employe* ajouteremploye(employe *arbre, string nom, string boss);
void licencieemploye(string nom);
void creerArbreInitial(employe*);
void afficher(employe*);
void ask(employe*);
void afficherbranche(employe*, string boss);

int main()
{
	employe *arbre = new employe;
	(*arbre).next = NULL;
	(*arbre).boss = arbre;
	(*arbre).nom = "john";

	creerArbreInitial(arbre);
	afficher(arbre);
	ask(arbre);
	afficher(arbre);

	return 0;
}

employe* ajouteremploye(employe* arbre, string nom, string boss)
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

void licencieemploye(employe* arbre, string nom)
{
	if (arbre == NULL)
	{
	//	return NULL;
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
	ajouteremploye(arbre, "bob", "john");
	ajouteremploye(arbre, "glou", "john");
	ajouteremploye(arbre, "fi", "bob");
	ajouteremploye(arbre, "doux", "bob");
	licencieemploye(arbre, "glou");
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

void afficherbranche(employe *arbre, string boss)
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
	int nb;
	while(nb != 5)
	{
		string nom,boss,sup,bossc;
		cout << endl << "Entrez 1 pour ajouter un employé, 2 pour licencier, 3 pour afficher l'arbre complet, 4 pour afficher une branche de l'arbre, 5 pour quitter" << endl;
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
					cout << "OK" << endl;
					break;
				}
			case 2 : 
				{
					cout << "entrez le nom de l'employe a supprimer : ";
					cin >> sup;
					cout << endl;
					licencieemploye(arbre, sup);
					cout << "OK" << endl;
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
					cout << "Resultat :" << endl;
					afficherbranche(arbre, bossc);
					break;
				}
		}
	}
}
