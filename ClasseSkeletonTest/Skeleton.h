#ifndef DEF_SKELETON
#define DEF_SKELETON


#include "includes.h"
#include "Bone.h"

class Skeleton
{

	public:
		/************CONSTRUCTION***********/
	Skeleton();

		/************METHODES************/




	
		/************DESTRUCTEUR***********/
	~Skeleton();

	
		/************FRIENDS**************/

	friend ostream& operator<<(ostream& flux, const Skeleton& S);


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
