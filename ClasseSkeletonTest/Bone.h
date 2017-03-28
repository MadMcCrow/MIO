#ifndef DEF_BONE
#define DEF_BONE

#include "includes.h"

class Bone
{

	public:
		/************CONSTRUCTION***********/
	Bone();

		/************METHODES************/

		/************DESTRUCTEUR********/
	~Bone();

		/************FRIENDS***********/
	friend ostream& operator<<(ostream& flux, const Bone& B);

	/************TRANSLATION ET ROTATION GLOBALE***************/

// Obtenir la nouvelle translation globale
	Output_GetSegmentGlobalTranslation m_newBoneGlobalTranslation(	const std::string &nomSkeleton,
									const std::string &nomBone );

// Obtenir la nouvelle rotation globale sous forme de matrice
	Output_GetSegmentGlobalRotationMatrix m_newBoneGlobalRotationMatrix( 	const std::string &nomSkeleton,
										const std::string &nomBone );

// Obtenir la nouvelle rotation globale en quaternion
	Output_GetSegmentGlobalRotationQuaternion m_newBoneGlobalRotationQuaternion(	const std::string &nomSkeleton,
											const std::string &nomBone );

	/************TRANSLATION ET ROTATION LOCALE***************/

// Obtenir la nouvelle translation locale
	Output_GetSegmentLocalTranslation m_newBoneLocalTranslation(	const std::string &nomSkeleton,
									const std::string &nomBone );

// Obtenir la nouvelle rotation locale sous forme de matrice
	Output_GetSegmentLocalRotationMatrix m_newBoneLocalRotationMatrix( 	const std::string &nomSkeleton,
										const std::string &nomBone );

// Obtenir la nouvelle rotation locale en quaternion
	Output_GetSegmentLocalRotationQuaternion m_newBoneLocalRotationQuaternion(	const std::string &nomSkeleton,
											const std::string &nomBone );
	private:

// Le nom du bone (segment chez Vicon) : 
	std::string m_nomBone;

// Le nom du bone parent 
	std::string m_nomBoneParent;

// Le nombre de bone enfant
	unsigned int m_nombreBoneEnfant;

// Le nom du bone enfant
	std::string m_nomBoneEnfant;

	/************TRANSLATION ET ROTATION GLOBALE***************/

// La translation 'globale' du bone :
	Output_GetSegmentGlobalTranslation m_boneGlobalTranslation;

// La rotation 'globale' du bone sous forme de matrice : 
	Output_GetSegmentGlobalRotationMatrix m_boneGlobalRotationMatrix;

// La rotation 'globale' du bone en quaternion :
	Output_GetSegmentGlobalRotationQuaternion m_boneGlobalRotationQuaternion;


	/************TRANSLATION ET ROTATION LOCALE***************/

// La translation 'locale' du bone :
	Output_GetSegmentLocalTranslation m_boneGlobalTranslation;

// La rotation 'locale' du bone sous forme de matrice : 
	Output_GetSegmentLocalRotationMatrix m_boneGlobalRotationMatrix;

// La rotation 'locale' du bone en quaternion :
	Output_GetSegmentLocalRotationQuaternion m_boneGlobalRotationQuaternion;


};
