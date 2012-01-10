#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct eleve eleve;
struct eleve
{
	char nom[50];
	char prenom[50];
	char promo[10];
	float notes[9];
};

eleve* enregistrer(FILE* fichier);

int main()
{
	eleve* classe[100];
	FILE* fichier = NULL;
	fichier = fopen("Promo.txt", "r");

	if (fichier != NULL)
	{
		int i = 0;
		while(*classe[i-1]->nom != 0)
		{
			classe[i] = enregistrer(fichier);
			if (*classe[i]->nom == NULL) break;
			cout << classe[i]->nom;
			cout << classe[i]->prenom << endl;
			cout << classe[i]->promo << endl;
			for (int j=0; j<9; j++)
			{
				cout <<  classe[i]->notes[j] <<endl;
			}
			i++;
		}
		cout << i << endl;

		fclose(fichier);
	}
	else cout << "Erreur à l'ouverture du fichier" <<endl;

	//TODO : menu
	int nb;
	while (nb != 666)
	{
		cout << "tapez 1 pour la liste des eleves, 2 pour rechercher un eleve, 3 pour la moyenne d'une matiere, 4 pour ..., 666 pour quitter" << endl;
		cin >> nb;
		cout << endl;
		switch (nb)
		{
			case 1 :
			{
			}
			case 2 :
			{
			}
		}
	}
	return 0;
}

eleve* enregistrer(FILE* fichier)
{
	eleve* nouveau = new eleve;
	fscanf(fichier,"%s %s %s",nouveau->nom,nouveau->prenom,nouveau->promo);

	for (int i=0; i<9; i++)
	{
		fscanf(fichier,"%f",&nouveau->notes[i]);
	}
	return nouveau;
}
