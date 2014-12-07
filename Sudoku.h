///////////////////////////////////////////
// main.cpp
// Fait par Emmanuel Beloin et Shaun Cooper
// Cr�er le 6 d�cembre 2014
// Derni�re modification le 6 d�cembre 2014
// R�sout un sudoku
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
	// Constructeur param�trique     
	//////////////////////////////////////////////////////////////////////
	Sudoku(string nom);

	//////////////////////////////////////////////////////////////////////
	// Constructeur param�trique  
	// Intrants :                                  
	// Extrant :                                                
	//////////////////////////////////////////////////////////////////////
	void RemplirMatrice(ifstream & doc);

	//////////////////////////////////////////////////////////////////////
	// Constructeur param�trique  
	// Intrants :                                  
	// Extrant :                                                
	//////////////////////////////////////////////////////////////////////
	// trouve une position dans le vecteur qui n'a pas de valeur attribu� (0)
	bool TrouvePosVide(int& colonne, int& ligne);

	//////////////////////////////////////////////////////////////////////
	// Constructeur param�trique  
	// Intrants :                                  
	// Extrant :                                                
	//////////////////////////////////////////////////////////////////////
	// verifie si le nombre entr� en parametre peut aller a la position pass� en parametre
	bool EstValide(int colonne, int ligne, int nombre);

	//////////////////////////////////////////////////////////////////////
	// Constructeur param�trique  
	// Intrants :                                  
	// Extrant :                                                
	//////////////////////////////////////////////////////////////////////
	//essaie de resoudre le sudoku
	bool Resoudre();

	//////////////////////////////////////////////////////////////////////
	// Constructeur param�trique  
	// Intrants :                                  
	// Extrant : Si oui ou non la nombre est utiliser (bool) 
	// But : 
	//////////////////////////////////////////////////////////////////////
	// verifie si la valeur entr� en parametre est dans la colonne donn�
	bool UtiliserColonne(int colonne, int nombre);

	//////////////////////////////////////////////////////////////////////
	// Constructeur param�trique  
	// Intrants :                                  
	// Extrant : Si oui ou non la nombre est utiliser (bool)                                                 
	// But : V�rifie si le nombre se trouve dans la ligne
	//////////////////////////////////////////////////////////////////////
	bool UtiliserLigne(int ligne, int nombre);

	//////////////////////////////////////////////////////////////////////
	// UtiliserCadran  
	// Intrants :                                  
	// Extrant : Si oui ou non la nombre est utiliser (bool)      
	// But : V�rifie si le nombre se trouve dans le cadran
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

