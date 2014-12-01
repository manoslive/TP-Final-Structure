// Board.cpp: implementation of the CBoard class.
//
//////////////////////////////////////////////////////////////////////
#include "Board.h"
#include "fonctions.h"
#include "atltime.h"
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int CBoard::iMAXCASES = 8;  // Nombre de cases de l'échiquier

CBoard::CBoard(ostream & out, bool bVeutTrace)
: rOut_(out), bFaireTrace_(bVeutTrace)
{
	CaseUtilisable.SetNbLignes  (iMAXCASES);
	CaseUtilisable.SetNbColonnes(iMAXCASES);

	TabPositionReines.resize(iMAXCASES,-1); 
	SetNbSolutions(0);
	SetTempsCumulatif(0);
}

CBoard::~CBoard()
{
}

// NbReines est le nombre de Reines qui restent à placer
// i et j sont les coordonnées à partir desquelles placer
// les reines qui restent
void CBoard::PlacerReine(int NbReines, int i, int j)
{
	for (int x = i; x < iMAXCASES; x++)
		for (int y = j; y < iMAXCASES; y++)
		{
			// Peut-on placer une reine à cette position ligne, colonne?
			if (EstDisponible(x, y))
			{	
				// Si oui, placer la reine et bloquer les cases qu'elle peut 'attaquer'
				BloquerCases(x,y);
				NbReines--;              // il y a une reine de moins à placer

				// Le paramètre entier représente le nombre de millisecondes à attendre
				// un nombre négatif fait une pause
				// Afficher(0);

				if (NbReines == 0)
				{	// Fini ! On affiche
					oPreciseTimer.StopTimer();
					SetNbSolutions(GetNbSolutions() + 1);
					Afficher();
					oPreciseTimer.StartTimer();
				}
				else	
					// sinon on poursuit la recherche
					PlacerReine(NbReines, x+1, 0);

				// arrivé ici, la recherche récursive d'une solution pour n-1 reine est terminée
				// donc on enlève la reine pour la placer plus loin sur l'échiquier et reprendre 
				// le processus
				NbReines++;
				DebloquerCases(x,y);
			}
		}
}

void CBoard::BloquerCases(int x, int y)
{	
	// Retenir la position de la reine placée dans l'échiquier
	TabPositionReines[x] = y;

	// Augmenter de 1 les compteurs de blocages
	ChangerEtat(x, y, 1);
	if (bFaireTrace_) Afficher(true);
}

void CBoard::DebloquerCases(int x, int y)
{
	// Retirer la reine de sa position sur l'échiquier
	TabPositionReines[x] = -1;

	// Diminuer de 1 les compteurs de blocages
	ChangerEtat(x, y, -1);
	if (bFaireTrace_) Afficher(true);
}

void CBoard::ChangerEtat(int x, int y, int iValeur)
{
	int i, j; 

	// Modifier les compteurs de blocages pour la ligne
	for (j=0; j<iMAXCASES; j++)
		CaseUtilisable[x][j] += iValeur;	

	// Modifier les compteurs de blocages pour la colonne
	for (i=0; i<iMAXCASES; i++)
		CaseUtilisable[i][y]+= iValeur;

	// Modifier les compteurs de blocages pour les diagonales
	for (i=1; i<iMAXCASES; i++)
	{
		if (((x-i) >= 0) && ((y-i) >= 0))
			CaseUtilisable[x-i][y-i]+= iValeur;
		if (((x-i) >= 0) && ((y+i) < iMAXCASES))
			CaseUtilisable[x-i][y+i]+= iValeur;
		if (((x+i) < iMAXCASES) && ((y-i) >= 0))
			CaseUtilisable[x+i][y-i]+= iValeur;
		if (((x+i) < iMAXCASES) && ((y+i) < iMAXCASES))
			CaseUtilisable[x+i][y+i]+= iValeur;
	}	
}

bool CBoard::EstDisponible(int x, int y)
{
	return CaseUtilisable[x][y] == 0;
}

void CBoard::Afficher(bool bTrace)
{
	if (&rOut_ == &cout) system("cls");
	if (!bTrace) 
	{
		rOut_ << "Solution # " << iNbSolutions_ << endl;
		__int64 i64Diff = oPreciseTimer.GetTime();
		SetTempsCumulatif(GetTempsCumulatif() + i64Diff);
		rOut_ << "en " << Int64ToString(i64Diff) << " microsecondes" <<endl;
		rOut_ << "cumulatif " << Int64ToString(GetTempsCumulatif()) << " microsecondes" << endl;
	}
	rOut_ << string(41,'-') << endl;
	for (int i=0; i<iMAXCASES; i++)
	{
		rOut_ << "| ";
		for (int j=0; j<iMAXCASES; j++)
		{
			if ( j == this->TabPositionReines[i])
			{
				rOut_ << " R | ";
			}
			else if (bTrace && CaseUtilisable[i][j] != 0 && CaseUtilisable[i][j] != -1)
			{
				rOut_.width(2);
				rOut_ << CaseUtilisable[i][j] << " | ";
				// rOut_ << " - | ";
			}
			else 
			{
				rOut_ << "   | ";
			}
		}
		rOut_ << endl;
		rOut_ << string(41,'-') << endl;
	}
	if (&rOut_ == &cout && !bTrace) system("pause");
	if (bTrace) Wait(1);
}

void CBoard::Afficher(int TempsAttente)
{
	system("cls");
	rOut_ << string(41,'-') << endl;
	for (int i=0; i<iMAXCASES; i++)
	{
		rOut_ << "| ";
		for (int j=0; j<iMAXCASES; j++)
		{
			if ( j == this->TabPositionReines[i])
			{
				rOut_ << " R | ";
			}
			else 
			{
				rOut_ << "   | ";
			}
		}
		rOut_ << endl;
		rOut_ << string(41,'-') << endl;
	}
	if (TempsAttente >= 0)
		Sleep(TempsAttente);
	else
		system("pause");
}

void CBoard::Wait(int iNbSec)
{
	CTime startTime = CTime::GetCurrentTime();
	CTime endTime= CTime::GetCurrentTime();
	CTimeSpan elapsedTime = endTime - startTime;
	while (elapsedTime < iNbSec)
	{
		endTime = CTime::GetCurrentTime();
		elapsedTime = endTime - startTime;
	}
}

int  CBoard::GetNbSolutions () const
{
	return iNbSolutions_;
}

void CBoard::SetNbSolutions (int i)
{
	iNbSolutions_ = i;
}

__int64  CBoard::GetTempsCumulatif() const
{
	return iTempsCumulatif_;
}

void CBoard::SetTempsCumulatif(__int64 iTemps)
{
	iTempsCumulatif_ = iTemps;
}

void CBoard::RechercherSolution()
{
	this->oPreciseTimer.StartTimer();
	PlacerReine(8,0,0);
}
