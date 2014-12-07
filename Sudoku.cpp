///////////////////////////////////////////
// main.cpp
// Fait par Emmanuel Beloin et Shaun Cooper
// Créer le 6 décembre 2014
// Dernière modification le 6 décembre 2014
// Résout un sudoku
///////////////////////////////////////////
#include "Sudoku.h"
const char asterix = '*';
const char zero = '0';
const char carriageReturn = '\n';

Sudoku::Sudoku(string nom)
{
	monSudoku_.SetNbLignes(NBLIGNECOLONNE);
	monSudoku_.SetNbColonnes(NBLIGNECOLONNE);
	ifstream leSudoku(nom + ".txt");
	RemplirMatrice(leSudoku);
}

void Sudoku::RemplirMatrice(ifstream & doc)
{
	char nombre;
	if (!doc.fail()) //si le fichier est ouvert
	{
		for (int i = 0; i < NBLIGNECOLONNE; i++)
		{
			for (int j = 0; j < NBLIGNECOLONNE; j++)
			{
				doc.get(nombre);
				if (nombre == carriageReturn) // Vérifie si ce n'est pas un carriage return
				{
					doc.get(nombre);
				}
				if (nombre == asterix) // * en 0
				{
					nombre = zero;
				}
				monSudoku_.at(i).at(j) = nombre + CHARTOINTASCII;
			}
		}
	}
	else
	{
		throw exception("Le nom du fichier est introuvable");
	}
}

void Sudoku::AfficherSudoku()
{
	for (int i = 0; i < NBLIGNECOLONNE; i++)
	{
		for (int j = 0; j < NBLIGNECOLONNE; j++)
		{
			cout << monSudoku_[i][j];
			if (j == NBRECADRAN - 1 || j == 6 - 1)
			{
				cout << " ";
			}
		}
		if (i == 3 || i == 6)
		{
			cout << " ";
		}
		cout << endl;
		if (i == NBRECADRAN - 1 || i == 6 - 1)
		{
			cout << endl;
		}
	}
}

bool Sudoku::TrouvePosVide(int& ligne, int& colonne)
{
	for (ligne = 0; ligne < NBLIGNECOLONNE; ligne++)
		for (colonne = 0; colonne < NBLIGNECOLONNE; colonne++)
			if (monSudoku_.at(ligne).at(colonne) == MAUVAISCHIFFRE)
				return true;
	return false;
}

bool Sudoku::EstValide(int ligne, int colonne, int nombre)
{
	return !UtiliserLigne(ligne, nombre) && 
		   !UtiliserColonne(colonne, nombre) &&
		   !UtiliserCadran(ligne - ligne % 3, colonne - colonne % 3, nombre);
}


bool Sudoku::Resoudre()
{
	int colonne, ligne;
	if (!TrouvePosVide(ligne, colonne))
		return true;

	for (int num = 1; num <= NBLIGNECOLONNE; num++)
	{
		if (EstValide(ligne, colonne, num))
		{
			monSudoku_.at(ligne).at(colonne) = num;

			if (Resoudre())
				return true;

			monSudoku_.at(ligne).at(colonne) = MAUVAISCHIFFRE;
		}
	}
	return false;
}

bool Sudoku::UtiliserColonne(int colonne, int nombre)
{
	for (int ligne = 0; ligne < NBLIGNECOLONNE; ligne++)
		if ((monSudoku_.at(ligne).at(colonne)) == nombre)
			return true;
	return false;
}

bool Sudoku::UtiliserLigne(int ligne, int nombre)
{
	for (int col = 0; col < NBLIGNECOLONNE; col++)
		if ((monSudoku_.at(ligne).at(col)) == nombre)
			return true;
	return false;
}

bool Sudoku::UtiliserCadran(int lignedepart, int colonnedepart, int nombre)
{
	for (int rangee = 0; rangee < NBRECADRAN; rangee++)
		for (int col = 0; col < NBRECADRAN; col++)
			if (monSudoku_.at(rangee + lignedepart).at(col + colonnedepart) == nombre)
				return true;
	return false;
}