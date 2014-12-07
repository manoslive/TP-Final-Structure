///////////////////////////////////////////
// main.cpp
// Fait par Emmanuel Beloin et Shaun Cooper
// Créer le 6 décembre 2014
// Dernière modification le 6 décembre 2014
// Résout un sudoku
///////////////////////////////////////////
#include "Fonctions.h"

void SolutionnerSudoku(string entete)
{
	Sudoku leSudoku(entete);
	Compteur timer;
	timer.Start(); // On démarre le compteur
	if (leSudoku.Resoudre())
	{
		timer.Stop(); // On arrête le compteur
		leSudoku.AfficherSudoku();
		cout << endl << "Résultat (en microsecondes): " << timer.Read() << endl;
	}
	else // Si le sudoku n'a pas été résolu
		cout << " Sudoku impossible " << endl;
}