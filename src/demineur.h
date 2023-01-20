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
  * @brief Destruction en mémoire de la grille
  * @param[in-out] g : la grille
  */
void detruire(Grille& g);

/**
 * @brief Initialise les mines dans la grille dans l'ordre
 * @param[in-out] g : la grille
 */
void ini_mines(Grille&, unsigned int mine);


/**
 * @brief Mélange les cases de la grille au hasard
 * @param[in-out] g : la grille
 */
void melanger(Grille& g);


/**
 * @brief Affiche le numéro des cases ou il y a des mines
 * @param[in] g : la grille
 */
void probleme(Grille& g);



/**
 * @brief Ajoute à chaque case le nombre de bombes autour de celle-ci
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
 * @brief Lis les coups et les ajoute à la grille
 * @param[in-out] g : la grille
 * @param[in] nbCoups : le nombre de coups
 */
void lecture_coups(Grille& g, unsigned int nbCoups);

/**
 * @brief Démasque la case et celles autour récursivement si le nombre de bombes autour est 0
 * @param[in-out] g : la grille
 * @param[in] x : numéro de la ligne de la case
 * @param[in] y : numéro de la colonne de la case
 */
void demasquer(Grille& g, int x, int y);

/**
 * @brief Renvoie l'état de la partie (gagnée, perdue ou en cours)
 * @param[in] g : la grille
 * @param[in] nbMines : le nombre de mines
 * @return l'état de la partie
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
 * @brief Affiche un nouveau coup pouvant être joué à partir d'une grille
 */
void coup_possible();


