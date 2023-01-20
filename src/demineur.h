/**
 * @file demineur.h
 * @author Bryan Bohec, Ilo Rabiarivelo
 * Projet demineur
 */

#include"structure.h"


 /**
  * @brief Initialisation de la grille
  * @param[in-out] g : la grille
  * @param[in] lon : la longueur
  * @param[in] lar : la largeur
  */
void init_probleme(Grille& g, unsigned int lon, unsigned int lar); //initialise grille de jeu


 /**
  * @brief Destruction en m�moire de la grille
  * @param[in-out] g : la grille
  */
void detruire(Grille& g);

/**
 * @brief Initialise les mines dans la grille dans l'ordre
 * @param[in-out] g : la grille
 */
void ini_mines(Grille&, unsigned int mine);


/**
 * @brief M�lange les cases de la grille au hasard
 * @param[in-out] g : la grille
 */
void melanger(Grille& g);


/**
 * @brief Affiche le num�ro des cases ou il y a des mines
 * @param[in] g : la grille
 */
void probleme(Grille& g);



/**
 * @brief Ajoute � chaque case le nombre de bombes autour de celle-ci
 * @param[in-out] g : la grille
 */
void ajout_nombres_bombes_autour(Grille& g);

/**
 * @brief Lis les mines et les ajoute a la grille
 * @param[in-out] g : la grille
 * @param[in] nbMines : le nombre de mines
 */
void lecture_mines(Grille& g, unsigned int nbMines);


/**
 * @brief Lis les coups et les ajoute � la grille
 * @param[in-out] g : la grille
 * @param[in] nbCoups : le nombre de coups
 */
void lecture_coups(Grille& g, unsigned int nbCoups);

/**
 * @brief D�masque la case et celles autour r�cursivement si le nombre de bombes autour est 0
 * @param[in-out] g : la grille
 * @param[in] x : num�ro de la ligne de la case
 * @param[in] y : num�ro de la colonne de la case
 */
void demasquer(Grille& g, int x, int y);

/**
 * @brief Renvoie l'�tat de la partie (gagn�e, perdue ou en cours)
 * @param[in] g : la grille
 * @param[in] nbMines : le nombre de mines
 * @return l'�tat de la partie
 */
int won_or_lost(const Grille& g, int nbMines);

/**
 * @brief Affiche la grille lorsque la partie n'est pas perdue (sans les mines)
 * @param[in] g : la grille
 */
void affiche_grille_entiere(const Grille& g);

/**
 * @brief Affiche la grille lorsque la partie est perdue (avec les mines)
 * @param[in] g : la grille
 */
void affiche_grille_mines(const Grille& g);

/**
 * @brief Affiche un nouveau coup pouvant �tre jou� � partir d'une grille
 */
void coup_possible();


