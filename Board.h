// Board.h: interface for the CBoard class.
//
//////////////////////////////////////////////////////////////////////
#pragma once
#include "Matrice.h"
#include "PreciseTimer.h"
#include <iostream>
#include <vector>
using namespace std;

class CBoard
{
public:
	//--- Constructeur et destructeur
	CBoard(ostream &, bool bVeutTrace);
	virtual ~CBoard();

	//--- Méthode publique pour mettre en marche la recherche
	void RechercherSolution();

private:
	void PlacerReine   (int NbReines, int i, int j);
	void Afficher      (bool bTrace = false);
	void Afficher      (int TempsAttente);
	bool EstDisponible (int x, int y);
	void DebloquerCases(int x, int y);
	void BloquerCases  (int x, int y);
	void ChangerEtat   (int x, int y, int iValeur);
	void Wait          (int iNbSec);
	int  GetNbSolutions() const;
	void SetNbSolutions(int);
	__int64  GetTempsCumulatif() const;
	void SetTempsCumulatif(__int64);

private:
	static const int iMAXCASES;     // Nombre de cases de l'échiquier
	CPreciseTimer oPreciseTimer;    // Pour mesurer le temps
	CMatrice<int>  CaseUtilisable;  // Un échiquier d'entiers
	vector <int> TabPositionReines; // Vecteur des positions des reines
	bool bFaireTrace_;				// Signification évidente
	int iNbSolutions_;				// idem
	__int64 iTempsCumulatif_;
	ostream & rOut_;
};

