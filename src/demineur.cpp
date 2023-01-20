/**
 * @file demineur.cpp
 * @author Bryan Bohec, Ilo Rabiarivelo
 * Projet demineur
 */

#include "demineur.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;



/**
 * @brief Initialisation de la grille
 * @param[in-out] g : la grille
 * @param[in] lon : la longueur
 * @param[in] lar : la largeur
 */
void init_probleme(Grille& g, unsigned int lon, unsigned int lar) {
    g.longueur = lon;
    g.largeur = lar;
    g.totalcase = lon * lar;
    g.tab=new Case*[g.longueur];
    
    for (unsigned int i = 0; i < g.longueur; i ++) {
        g.tab[i] = new Case[g.largeur];
    }

    for (unsigned int x = 0; x < g.longueur; x++) {
        for (unsigned int y = 0; y < g.largeur; y++) {
            g.tab[x][y].minee = false;
            g.tab[x][y].demasquee = false;
            g.tab[x][y].marque = false;
            g.tab[x][y].bombesautour = 0;
        }
    }
}







/**
 * @brief Initialise les mines dans la grille dans l'ordre
 * @param[in-out] g : la grille
 */
void ini_mines(Grille& g, unsigned int mine) { // On met les mines dans l'ordre
  for (int i = 0, j = 0, k=0; k < mine; i++) {

    if (i == g.largeur) {
      j++;
      i = 0;
    }
    g.tab[j][i].minee = true;
    k++;
  }


}


/**
 * @brief Mélange les cases de la grille au hasard
 * @param[in-out] g : la grille
 */
void melanger(Grille& g) {          // On melange les cases des grilles au hasard
  for (int i = 0; i < 100; i++) {
    int longueur1, largeur1, longueur2, largeur2;
    longueur1 = rand()%(g.longueur-1 - 0 + 1) + 0;
    largeur1 = rand()%(g.largeur-1 - 0 + 1) + 0;
    longueur2 = rand()%(g.longueur-1 - 1 + 1) + 0;
    largeur2 = rand()%(g.largeur-1 - 1 + 1) + 0;
    bool tmp = g.tab[longueur1][largeur1].minee;
    g.tab[longueur1][largeur1].minee = g.tab[longueur2][largeur2].minee;
    g.tab[longueur2][largeur2].minee = tmp;
    
    //cout << endl << x << " " << y << endl; //test pour voir si les nombres sont bien générés
  }
  
}


/**
 * @brief Affiche le numéro des cases ou il y a des mines
 * @param[in] g : la grille
 */
void probleme(Grille& g) {
  for (unsigned int x = 0; x < g.longueur; x++) {
        for (unsigned int y = 0; y < g.largeur; y++) {
            if (g.tab[x][y].minee == true) {
                cout << (x * g.largeur) + y << " ";
            }
        }
  }
}




/**
 * @brief Destruction en mémoire de la grille
 * @param[in-out] g : la grille
 */
void detruire(Grille& g) {
    delete[]g.tab;
    g.tab = NULL;
}





/**
 * @brief Ajoute à chaque case le nombre de bombes autour de celle-ci
 * @param[in-out] g : la grille
 */
void ajout_nombres_bombes_autour(Grille& g) {
	for (int x = 0; x < g.longueur; x++) {
		for (int y = 0; y < g.largeur; y++) {
			if (g.tab[x][y].minee == true) {

				if ((x + 1 >= 0 && x + 1 < g.longueur) && (y >= 0 && y < g.largeur)) {   // bas    Si les coordonnées sont dans le tableau uniquement, on incrémente
					g.tab[x + 1][y].bombesautour += 1;
				}
				if ((x - 1 >= 0 && x - 1 < g.longueur) && (y >= 0 && y < g.largeur)) {   // haut
					g.tab[x - 1][y].bombesautour += 1;
				}
				if ((x >= 0 && x < g.longueur) && (y + 1 >= 0 && y + 1 < g.largeur)) {   // droite
					g.tab[x][y + 1].bombesautour += 1;
				}
				if ((x >= 0 && x < g.longueur) && (y - 1 >= 0 && y - 1 < g.largeur)) {   // gauche
					g.tab[x][y - 1].bombesautour += 1;
				}
				if ((x + 1 >= 0 && x + 1 < g.longueur) && (y + 1 >= 0 && y + 1 < g.largeur)) {   // bas droit
					g.tab[x + 1][y + 1].bombesautour += 1;
				}
				if ((x + 1 >= 0 && x + 1 < g.longueur) && (y - 1 >= 0 && y - 1 < g.largeur)) {   // bas gauche
					g.tab[x + 1][y - 1].bombesautour += 1;
				}
				if ((x - 1 >= 0 && x - 1 < g.longueur) && (y + 1 >= 0 && y + 1 < g.largeur)) {   // haut droit
					g.tab[x - 1][y + 1].bombesautour += 1;
				}
				if ((x - 1 >= 0 && x - 1 < g.longueur) && (y - 1 >= 0 && y - 1 < g.largeur)) {   // haut gauche
					g.tab[x - 1][y - 1].bombesautour += 1;
				}


			}
		}
	}
}




/**
 * @brief Lis les mines et les ajoute a la grille
 * @param[in-out] g : la grille
 * @param[in] nbMines : le nombre de mines
 */
void lecture_mines(Grille& g, unsigned int nbMines) {
  for (int i = 0; i < nbMines; i++) {
    int numMine = 0;
    cin >> numMine;
    g.tab[numMine/g.largeur][numMine % g.largeur].minee = true;
  }
}



/**
 * @brief Lis les coups et les ajoute à la grille
 * @param[in-out] g : la grille
 * @param[in] nbCoups : le nombre de coups
 */
void lecture_coups(Grille& g, unsigned int nbCoups) {
  char coup;
  int numeroCase;

  //lecture des cases démasquées
  for (int i = 0; i < nbCoups; i++) {
    cin >> coup >> numeroCase;
    if (coup == 'D') {
      demasquer(g, numeroCase / g.largeur, numeroCase % g.largeur);
    }

    //lecture des cases marquées
    if (coup == 'M') {
      g.tab[numeroCase/g.largeur][numeroCase % g.largeur].marque = true;
    }
  }
}




/**
 * @brief Affiche la grille lorsque la partie n'est pas perdue (sans les mines)
 * @param[in] g : la grille
 */
void affiche_grille_entiere(const Grille& g) {
    for (unsigned int i = 0; i < g.longueur; i++) {
        for (unsigned int j = 0; j < g.largeur; j++) {
            cout << " " << "___";
            if (j == g.largeur - 1) {
                cout << endl;
            }
        }
        for (unsigned int j = 0; j < g.largeur; j++) {
            
           if (g.tab[i][j].demasquee == true) {
             if (g.tab[i][j].bombesautour == 0) {
              
                 cout<<"|"<<" "<< " " << " ";
             }
             else {
                 
                 cout<<"|"<<" "<< g.tab[i][j].bombesautour << " ";
             }
          }


          else if (g.tab[i][j].marque == true) {
               
               cout<<"|"<<" "<< "x" << " ";
          }
          else {
               
               cout<<"|"<<" "<< "." << " ";
          }

        }
        cout <<"|"<< endl;
    }
    for (unsigned int j = 0; j < g.largeur; j++) {
        cout << " " << "___";
    }
    cout << endl;
}






/**
 * @brief Démasque la case et celles autour récursivement si le nombre de bombes autour est 0
 * @param[in-out] g : la grille
 * @param[in] x : numéro de la ligne de la case
 * @param[in] y : numéro de la colonne de la case
 */
void demasquer(Grille& g, int x, int y) {
    
    if (x < 0 || x >= g.longueur || y < 0 || y >= g.largeur)        // ça s'arrete avant de sortir du tableau
        return;
    
     if (g.tab[x][y].bombesautour != 0)  {                  // ça demasque la case puis ça s'arrete si la case n'a pas bombesautour = 0;
        g.tab[x][y].demasquee = true;
        return;
     }                                             
     if (g.tab[x][y].demasquee == true)                     // ça s'arrete si la case est déja démasquée
         return;
 
    
    g.tab[x][y].demasquee = true;
 
   
    demasquer(g, x+1, y);
    demasquer(g, x-1, y);
    demasquer(g, x, y+1);
    demasquer(g, x, y-1);

    demasquer(g, x+1, y +1);
    demasquer(g, x+1, y - 1);
    demasquer(g, x-1, y + 1);
    demasquer(g, x-1, y - 1);


}


/**
 * @brief Renvoie l'état de la partie (gagnée, perdue ou en cours)
 * @param[in] g : la grille
 * @param[in] nbMines : le nombre de mines
 * @return l'état de la partie
 */
int won_or_lost(const Grille& g, int nbMines) {
    //partie perdue
    for (unsigned int x = 0; x < g.longueur; x++) {
        for (unsigned int y = 0; y < g.largeur; y++) {
            if ((g.tab[x][y].marque == true && g.tab[x][y].minee == false) || (g.tab[x][y].minee == true && g.tab[x][y].demasquee == true)) {
                return PERDUE;
            }
        }
    }


    //partie gagnée ou partie pas finie

    int nBCasesAdecouvrir = g.totalcase - nbMines;
    int casesDecouvertes = 0;

    for (unsigned int x = 0; x < g.longueur; x++) {
        for (unsigned int y = 0; y < g.largeur; y++) {
            if (g.tab[x][y].demasquee == true) {
                casesDecouvertes++;
            }
        }
    }
    if (nBCasesAdecouvrir == casesDecouvertes) {;
        return GAGNEE;
    }
    if (nBCasesAdecouvrir != casesDecouvertes) {
        return ENCOURS;
    }

}




/**
 * @brief Affiche la grille lorsque la partie est perdue (avec les mines)
 * @param[in] g : la grille
 */
void affiche_grille_mines(const Grille& g) {
    for (unsigned int i = 0; i < g.longueur; i++) {
        for (unsigned int j = 0; j < g.largeur; j++) {
            cout << " " << "___";
            if (j == g.largeur-1) {
                cout << endl;
            }
        }
        for (unsigned int j = 0; j < g.largeur; j++) {
           if (g.tab[i][j].minee == true){
            cout<<"|"<<" "<< "m" << " " ;
          }
          else if (g.tab[i][j].demasquee == true) {
               
             if (g.tab[i][j].bombesautour == 0) {
               cout<<"|"<<" "<< " " << " " ;
             }
             else {
               cout<<"|"<<" "<< g.tab[i][j].bombesautour << " " ;
             }
          } else if (g.tab[i][j].marque == true) {
            cout<<"|"<<" "<< "x" << " " ;
          }
          else {
            cout << "|" << " " << "." << " " ;
          }
        }
        cout << "|" << endl;
        
    }
    for (unsigned int j = 0; j < g.largeur; j++) {
        cout << " " << "___";
    }
    cout << endl;
}



/**
 * @brief Affiche un nouveau coup pouvant être joué à partir d'une grille
 */
void coup_possible() {
    int longueur, largeur;
    cin >> longueur >> largeur;
    string ligne;

    getline(cin, ligne);

    int index = 0;
    int* tableau;
    tableau = new int[largeur * longueur];
    int indextableau = 0;

    for (int i = 0; i < longueur; i++) {


        getline(cin, ligne);

        getline(cin, ligne);

        for (int j = 2; j < (largeur * 4) - 1; j += 4) {
            if (ligne[j] == '.') {
                tableau[indextableau] = index;
                indextableau++;
                index++;


            }
            else {
                index++;
            }
        }


    }


    cout << "D" << tableau[rand() % (indextableau - 1 - 0 + 1) + 0];

    delete []tableau;
}