///////////////////////////////////////////
// main.cpp
// Fait par Emmanuel Beloin et Shaun Cooper
// Créer le 6 décembre 2014
// Dernière modification le 6 décembre 2014
// Résout un sudoku
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

const int NBLIGNECOLONNE = 9;
const int NBRECADRAN = 3;
const int MAUVAISCHIFFRE = 0;
const int CHARTOINTASCII = -48;


class Sudoku
{
public:
	//////////////////////////////////////////////////////////////////////
	// Constructeur paramétrique     
	//////////////////////////////////////////////////////////////////////
	Sudoku(string nom);

	//////////////////////////////////////////////////////////////////////
	// Constructeur paramétrique  
	// Intrants :                                  
	// Extrant :                                                
	//////////////////////////////////////////////////////////////////////
	void RemplirMatrice(ifstream & doc);

	//////////////////////////////////////////////////////////////////////
	// Constructeur paramétrique  
	// Intrants :                                  
	// Extrant :                                                
	//////////////////////////////////////////////////////////////////////
	// trouve une position dans le vecteur qui n'a pas de valeur attribué (0)
	bool TrouvePosVide(int& colonne, int& ligne);

	//////////////////////////////////////////////////////////////////////
	// Constructeur paramétrique  
	// Intrants :                                  
	// Extrant :                                                
	//////////////////////////////////////////////////////////////////////
	// verifie si le nombre entré en parametre peut aller a la position passé en parametre
	bool EstValide(int colonne, int ligne, int nombre);

	//////////////////////////////////////////////////////////////////////
	// Constructeur paramétrique  
	// Intrants :                                  
	// Extrant :                                                
	//////////////////////////////////////////////////////////////////////
	//essaie de resoudre le sudoku
	bool Resoudre();

	//////////////////////////////////////////////////////////////////////
	// Constructeur paramétrique  
	// Intrants :                                  
	// Extrant : Si oui ou non la nombre est utiliser (bool) 
	// But : 
	//////////////////////////////////////////////////////////////////////
	// verifie si la valeur entré en parametre est dans la colonne donné
	bool UtiliserColonne(int colonne, int nombre);

	//////////////////////////////////////////////////////////////////////
	// Constructeur paramétrique  
	// Intrants :                                  
	// Extrant : Si oui ou non la nombre est utiliser (bool)                                                 
	// But : Vérifie si le nombre se trouve dans la ligne
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
	void AfficherSudoku();

private:
	Compteur horloge_;
	Matrice<int> monSudoku_;
};

#endif

