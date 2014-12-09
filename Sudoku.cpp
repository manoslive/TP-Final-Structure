///////////////////////////////////////////
// Sudoku.cpp
// Fait par Emmanuel Beloin et Shaun Cooper
// Créer le 6 décembre 2014
// Dernière modification le 7 décembre 2014
// Corps des méthodes de la classe Sudoku
///////////////////////////////////////////
#include "Sudoku.h"


Sudoku::Sudoku(string nom)
{
	monSudoku_.SetNbLignes(NBLIGNECOLONNE);
	monSudoku_.SetNbColonnes(NBLIGNECOLONNE);
	ifstream leSudoku(nom + ".txt"); // Prend en compte le type de fichier
	RemplirMatrice(leSudoku);
}

void Sudoku::RemplirMatrice(ifstream & doc)
{
	char nombre;
	if (!doc.fail()) //si le fichier est ouvert
		for (int i = 0; i < NBLIGNECOLONNE; i++)
		{
		for (int j = 0; j < NBLIGNECOLONNE; j++)
		{
			doc.get(nombre);
			if (nombre == CARRIAGERETURN) // Vérifie si ce n'est pas un carriage return
				doc.get(nombre);
			if (nombre == ASTERIX) // * en 0
				nombre = ZERO;
			monSudoku_.at(i).at(j) = nombre + CONVERSIONCHARENINT; // Converti les astérix en 0. Pour ensuite le convertir en int
		}
		}
	else
		throw exception("Le nom du fichier est introuvable");
}

void Sudoku::AfficherSudoku(ostream &out)
{
	for (int i = 0; i < NBLIGNECOLONNE; i++) // i = rangée
	{
		for (int j = 0; j < NBLIGNECOLONNE; j++) // j = colonne
		{
			out << monSudoku_.at(i).at(j);
			out << "  "; // Espace entre les nombres
			if (j == NBRECADRAN - 1 || j == 6 - 1)
				out << "  "; // Entre les cadrans
		}
		if (i == NBRECADRAN || i == NBRECADRAN * 2) // Espaces entre les cadrans
			out << "  ";
		out << endl;
		if (i == NBRECADRAN - 1 || i == NBRECADRAN * 2 - 1)
			out << endl; // carriage return entre les cadrans
	}
}

bool Sudoku::TrouvePosVide(int& ligne, int& colonne)
{
	for (ligne = 0; ligne < NBLIGNECOLONNE; ligne++) // Pour chaque ligne
		for (colonne = 0; colonne < NBLIGNECOLONNE; colonne++) // Pour chaque colonne
			if (monSudoku_.at(ligne).at(colonne) == MAUVAISCHIFFRE) // Vérifie si c'est 0
				return true;
	return false;
}

bool Sudoku::EstValide(int ligne, int colonne, int nombre)
{
	// Si on peut rien jouer. Le sudoku est invalide
	return !UtiliserLigne(ligne, nombre) &&
		!UtiliserColonne(colonne, nombre) &&
		!UtiliserCadran(ligne - ligne % NBRECADRAN, colonne - colonne % NBRECADRAN, nombre);
}


bool Sudoku::Resoudre()
{
	int colonne, ligne;
	if (!TrouvePosVide(ligne, colonne)) // S'il n'y a pas de position vide. On a fini de résoudre
		return true;

	for (int num = 1; num <= NBLIGNECOLONNE; num++)
	{
		if (EstValide(ligne, colonne, num))
		{
			monSudoku_.at(ligne).at(colonne) = num; // On met le nombre dans la case

			if (Resoudre())
				return true;

			monSudoku_.at(ligne).at(colonne) = MAUVAISCHIFFRE; // Si on peut pas mettre le nombre dans la case on met 0
		}
	}
	return false;
}

bool Sudoku::UtiliserColonne(int colonne, int nombre)
{
	for (int ligne = 0; ligne < NBLIGNECOLONNE; ligne++)
		if ((monSudoku_.at(ligne).at(colonne)) == nombre) // Vérifie si le nombre est présent dans la colonne
			return true;
	return false;
}

bool Sudoku::UtiliserLigne(int ligne, int nombre)
{
	for (int col = 0; col < NBLIGNECOLONNE; col++)
		if ((monSudoku_.at(ligne).at(col)) == nombre) // Vérifie si le nombre est présent dans la ligne
			return true;
	return false;
}

bool Sudoku::UtiliserCadran(int lignedepart, int colonnedepart, int nombre)
{
	for (int rangee = 0; rangee < NBRECADRAN; rangee++)
		for (int col = 0; col < NBRECADRAN; col++)
			if (monSudoku_.at(rangee + lignedepart).at(col + colonnedepart) == nombre) // Vérifie si le nombre est présent dans le cadran
				return true;
	return false;
}