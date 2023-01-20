/**
 * @file structure.h
 * @author Bryan Bohec, Ilo Rabiarivelo
 * Projet demineur
 */



using namespace std;

#define lg 30 //longueur de tableau
enum ETAT{PERDUE = 1, GAGNEE = 2, ENCOURS = 3};


struct Case { // Chaque case 
    bool minee; //mine ou pas mine
    bool demasquee; //démasqué ou pas démasqué
    bool marque; //marqué ou pas marqué
    int bombesautour;
};

struct Grille { //grille de jeu
    int totalcase; // nombre de case total
    int longueur;
    int largeur;
    Case** tab; //allocation dynamique pour stocker la grille
};
