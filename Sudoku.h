///////////////////////////////////////////
// Sudoku.h
// Fait par Emmanuel Beloin et Shaun Cooper
// Créer le 6 décembre 2014
// Dernière modification le 7 décembre 2014
// Définition de la classe Sudoku
///////////////////////////////////////////
#ifndef _SUDOKU_H
#define _SUDOKU_H

#include <iostream>
#include <ostream>
#include "Matrice.h"
#include "Compteur.h"
#include <fstream>
#include <sstream>
using namespace std;

const char ASTERIX = '*';
const char ZERO = '0';
const char CARRIAGERETURN = '\n';
const int NBLIGNECOLONNE = 9;
const int NBRECADRAN = 3;
const int MAUVAISCHIFFRE = 0;
const int CONVERSIONCHARENINT = -48;

class Sudoku
{
public:
	//////////////////////////////////////////////////////////////////////
	// Constructeur paramétrique     
	//////////////////////////////////////////////////////////////////////
	Sudoku(string nom);

	//////////////////////////////////////////////////////////////////////
	// RemplirMatrice  
	// Intrants : le fichier text en référence                                 
	// Extrant : aucun
	// But : Remplir la matrice du contenu du fichier
	//////////////////////////////////////////////////////////////////////
	void RemplirMatrice(ifstream & doc);

	//////////////////////////////////////////////////////////////////////
	// TrouvePosVide  
	// Intrants : la colonne et la ligne en référence                                 
	// Extrant : Si oui ou non il a trouvé une position vide (bool)
	// But : Trouve une position vide dans la matrice
	//////////////////////////////////////////////////////////////////////
	bool TrouvePosVide(int& colonne, int& ligne);

	//////////////////////////////////////////////////////////////////////
	// EstValide  
	// Intrants : la ligne, la colonne et le nombre                                 
	// Extrant : Si oui ou non le nombre est valide (bool)
	// But : Vérifie si le nombre en intrant pour aller a la position
	//		 en paramètre
	//////////////////////////////////////////////////////////////////////
	bool EstValide(int colonne, int ligne, int nombre);

	//////////////////////////////////////////////////////////////////////
	// Resoudre  
	// Intrants : Aucun                                 
	// Extrant : Si oui ou non il est résoulu
	// But : Essaie de résoudre le sudoku
	//////////////////////////////////////////////////////////////////////
	bool Resoudre();

	//////////////////////////////////////////////////////////////////////
	// UtiliserColonne  
	// Intrants : La colonne à vérifier et le nombre                                 
	// Extrant : Si oui ou non la nombre est utiliser (bool) 
	// But : Vérifie si le nombre est dans la colonne passée en paramètre
	//////////////////////////////////////////////////////////////////////
	bool UtiliserColonne(int colonne, int nombre);

	//////////////////////////////////////////////////////////////////////
	// UtiliserLigne  
	// Intrants : La ligne à vérifier et le nombre                                   
	// Extrant : Si oui ou non la nombre est utiliser (bool)
	// But : Vérifie si le nombre est dans la ligne passée en paramètre
	//////////////////////////////////////////////////////////////////////
	bool UtiliserLigne(int ligne, int nombre);

	//////////////////////////////////////////////////////////////////////
	// UtiliserCadran  
	// Intrants :                                  
	// Extrant : Si oui ou non la nombre est utiliser (bool)      
	// But : Vérifie si le nombre se trouve dans le cadran
	//////////////////////////////////////////////////////////////////////
	bool UtiliserCadran(int lignedepart, int colonnedepart, int nombre);

	//////////////////////////////////////////////////////////////////////
	// AfficherSudoku
	// Intrants :                                  
	// Extrant : Si oui ou non la nombre est utiliser (bool) 	
	// But : Affiche le sudoku
	//////////////////////////////////////////////////////////////////////
	void AfficherSudoku(ostream &out);

private:
	Compteur horloge_;
	Matrice<int> monSudoku_;
};

#endif

