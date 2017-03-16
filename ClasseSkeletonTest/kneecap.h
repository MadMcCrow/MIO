#ifndef DEF_KNEECAP
#define DEF_KNEECAP

#include <iostream.h>
#include <string.h>
#include "DataStreamClient.h"

class Kneecap
{

	public:
		/************CONSTRUCTION***********/
	Kneecap();

		/************METHODES************/

// Obtenir la nouvelle translation globale du kneecap
	Output_GetMarkerGlobalTranslation newMarkerGlobalTranslation(	const std::string &nomSkeleton,
									const std::string &nomKneecap ); 
	
	private:

// Le nom du kneecap ('marker' chez Vicon) :
	std::string m_nomKneecap;

// Le nom du kneecap parent ??

// Translation 'globale' (de toute manière on a accès qu'à ça) du kneecap :
	Output_GetMarkerGlobalTranslation m_kneecapGlobalTranslation;


};



#endif
