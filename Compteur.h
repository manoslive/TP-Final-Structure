// Classe permettant de calculer un temps d'ex�cution en microsecondes
// Merci � Francis Lemaire pour avoir trouv� le code brut � la source
// de cette classe.
//
// Usage : 
//   a) Instancier la classe
//   b) Faire appel � Start() pour d�marrer le chrono
//   c) Faire appel � Stop() pour arr�ter le chrono
//   d) Faire appel � Read() pour obtenir le temps calcul� par le chrono
//      en microsecondes. 
//
// Note : on peut refaire Start(), Stop() et Read() pour obtenir une deuxi�me
//        lecture sans avoir � r�instancier la classe
//
// par Pierre Prud'homme, octobre 2014
//--------------------------------------------------------------------------------
#ifndef _COMPTEUR_H_
#define _COMPTEUR_H_
#include <Windows.h>

class Compteur
{
	LARGE_INTEGER StartingTime_;
	LARGE_INTEGER EndingTime_;
	LARGE_INTEGER ElapsedMicroseconds_;
	LARGE_INTEGER Frequency_;

public:
	Compteur()
	{
		QueryPerformanceFrequency(&Frequency_);
	}

	void Start()
	{
		QueryPerformanceCounter(&StartingTime_);
	}

	void Stop()
	{
		QueryPerformanceCounter(&EndingTime_);
	}

	LONGLONG Read()
	{
		ElapsedMicroseconds_.QuadPart = EndingTime_.QuadPart - StartingTime_.QuadPart;
		////
		//// We now have the elapsed number of ticks, along with the
		//// number of ticks-per-second. We use these values
		//// to convert to the number of elapsed microseconds.
		//// To guard against loss-of-precision, we convert
		//// to microseconds *before* dividing by ticks-per-second.
		////
		ElapsedMicroseconds_.QuadPart *= 1000000;
		ElapsedMicroseconds_.QuadPart /= Frequency_.QuadPart;
		return ElapsedMicroseconds_.QuadPart;
	}

};

#endif