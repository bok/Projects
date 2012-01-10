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
			for (int i=0; i<10, i++)
			{
			classe[i] = enregistrer(fichier);
			
			cout <<  classe[i]->notes[i] <<endl;
			//TODO : boucle pour creer les eleves

			fclose(fichier);
		}
	else cout << "Erreur à l'ouverture du fichier" <<endl;
	return 0;

	//TODO : menu
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
