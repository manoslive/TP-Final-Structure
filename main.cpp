///////////////////////////////////////////
// main.cpp
// Fait par Emmanuel Beloin et Shaun Cooper
// Cr�er le 6 d�cembre 2014
// Derni�re modification le 6 d�cembre 2014
// R�sout un sudoku
///////////////////////////////////////////
#include "Fonctions.h"

int main()
{
	setlocale(LC_ALL, "");
	string fichierText = "sudoku";
	SolutionnerSudoku(fichierText);
	return 0;
}