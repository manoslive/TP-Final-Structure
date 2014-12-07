///////////////////////////////////////////
// main.cpp
// Fait par Emmanuel Beloin et Shaun Cooper
// Créer le 6 décembre 2014
// Dernière modification le 6 décembre 2014
// Résout un sudoku
///////////////////////////////////////////
#include "Fonctions.h"

int main()
{
	setlocale(LC_ALL, "");
	string fichierText = "sudoku";
	SolutionnerSudoku(fichierText);
	return 0;
}