#ifndef DEF_SKELETON
#define DEF_SKELETON


#include "includes.h"
#include "Bone.h"

class Skeleton
{

	public:
		/************CONSTRUCTEURS***********/
	Skeleton();
	Skeleton(const Skeleton& S);
	Skeleton(const Client& MyClient, const unsigned int& index);


		/************METHODES************/

			/****GETTERS****/
// Get le nom du Skeleton
	std::string getNomSkeleton() const;

// Get le nom du root Bone
	std::string getNomRootBone() const;

// Get le nombre de Bone dans le Skeleton
	unsigned int getBonesCount() const;

// Get le Skeleton (ensemble de Bone)
	std::vector<Bone> getSkeleton() const;

			/****SETTERS****/

// Set le nouveau Skeleton (collection de bones)
	void setSkeleton(const Client& MyClient, const unsigned int& index);


	
		/************DESTRUCTEUR***********/
	~Skeleton();

	
		/************FRIENDS**************/

	friend ostream& operator<<(ostream& flux, const Skeleton& S);


	private:

// Le nom du Skeleton (subject chez Vicon) : 
	std::string m_nomSkeleton;

// Le nom du bone 'root' (segment 'root' chez Vicon)
	std::string m_nomRootBone;

// Le nbre de bones du Skeleton :
	unsigned int m_bonesCount;

// L'ensemble des bones du Skeleton :
	std::vector<Bone> m_skeleton;
};









#endif
