#ifndef DEF_SKELETON
#define DEF_SKELETON


#include "includes.h"
#include "bone.h"

class skeleton
{

	public:
		/************CONSTRUCTION***********/
	Skeleton();

		/************METHODES************/
	
	


	private:

// Le nom du squelette (subject chez Vicon) : 
	std::string m_nomSkeleton;

// Le nom du bone 'root' (segment 'root' chez Vicon)
	std::string m_nomRootBone;

// Le nbre de bones du squelette :
	unsigned int m_bonesCount;

// L'ensemble des bones du squelette :
	std::vector<Bone>m_allBones;
};









#endif
