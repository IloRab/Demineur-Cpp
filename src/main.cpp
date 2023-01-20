/**
 * @file main.cpp
 * @author Bryan Bohec, Ilo Rabiarivelo
 * Projet demineur
 */

#include "demineur.h"
#include <time.h>
#include <cstring>
#include <iostream>
#include <cstdlib>



int main() {

	Grille grille;
	int commande;
	unsigned int longueur;
	unsigned int largeur;
	unsigned int mine;
	unsigned int nbCoups;
	cin >> commande;
	srand(time(NULL));

	switch(commande) {
	case 1: // Commande 1
		cin >> longueur;
		cin >> largeur;
		cin >> mine ;
		init_probleme(grille, longueur, largeur);
		cout << longueur << " " << largeur << " ";
		ini_mines(grille, mine);
		melanger(grille);
		cout << mine << " ";
		probleme(grille);
		cout << endl;
		detruire(grille);
		break;

	case 2: // Commande 2
		cin >> longueur;
		cin >> largeur;
		cin >> mine;
		init_probleme(grille, longueur, largeur);
		cout << longueur << " " << largeur << endl;
		lecture_mines(grille,mine);
		ajout_nombres_bombes_autour(grille);   //ajoute le nombre de bombes autour d'une case
		cin >> nbCoups;
		lecture_coups(grille, nbCoups);   //Met les cases démasquées et marquées
		if (won_or_lost(grille,mine) == ENCOURS) {
			affiche_grille_entiere(grille);
		}
		else {
			affiche_grille_mines(grille);
		}
		detruire(grille);
		break;

	case 3: //Comande 3
		cin >> longueur;
		cin >> largeur;
		cin >> mine; // nombre de mines
		init_probleme(grille, longueur, largeur);
		lecture_mines(grille, mine);
		ajout_nombres_bombes_autour(grille); 
		cin >> nbCoups;
		lecture_coups(grille, nbCoups);
		if (won_or_lost(grille, mine) == GAGNEE) {
			cout << "game won" << endl;
		}
		else {
			cout << "game not won" << endl;
		}
		detruire(grille);
		break;

	case 4: //Commande 4
		cin >> longueur;
		cin >> largeur;
		cin >> mine; // nombre de mines
		init_probleme(grille, longueur, largeur);
		lecture_mines(grille, mine);
		ajout_nombres_bombes_autour(grille);   
		cin >> nbCoups;
		lecture_coups(grille, nbCoups);
		if (won_or_lost(grille, mine) == PERDUE) {
			cout << "game lost" << endl;
		}
		else {
			cout <<  "game not lost" << endl;
		}
		detruire(grille);
		break;

	case 5 : //Commande 5
		coup_possible();
		cout << endl;
	}
	
	

}



