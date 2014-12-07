///////////////////////////////////////////
// main.cpp
// Fait par Emmanuel Beloin et Shaun Cooper
// Cr�er le 6 d�cembre 2014
// Derni�re modification le 6 d�cembre 2014
// R�sout un sudoku
///////////////////////////////////////////
#include "Fonctions.h"

void SolutionnerSudoku(string entete)
{
	Sudoku leSudoku(entete);
	Compteur timer;
	timer.Start(); // On d�marre le compteur
	if (leSudoku.Resoudre())
	{
		timer.Stop(); // On arr�te le compteur
		leSudoku.AfficherSudoku();
		cout << endl << "R�sultat (en microsecondes): " << timer.Read() << endl;
	}
	else // Si le sudoku n'a pas �t� r�solu
		cout << " Sudoku impossible " << endl;
}