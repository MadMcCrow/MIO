#ifndef DEF_BONE
#define DEF_BONE

#include "includes.h"

class Bone
{

	public:
		/************CONSTRUCTION***********/
	Bone();
	Bone(const Bone& B);
	Bone(const Client& MyClient, const std::string& _nomSkeleton, const unsigned int& _index); 


		/************METHODES************/

			/****GETTERS****/
// Get nom du bone
	std::string getNomBone() const;

// Get nom du bone parent
	std::string getNomBoneParent() const;

// Get nombre de bones enfants
	unsigned int getNombreBoneEnfant() const;

// Get nom d'un Bone enfant
	std::vector<std::string> getNomBoneEnfant() const;

// Get la translation globale
	Output_GetSegmentGlobalTranslation getBoneGlobalTranslation() const;	

// Get la rotation globale sous forme de matrice
	Output_GetSegmentGlobalRotationMatrix getBoneGlobalRotationMatrix() const;

// Get la rotation globale en quaternion
	Output_GetSegmentGlobalRotationQuaternion getBoneGlobalRotationQuaternion() const;

// Get la translation locale
	Output_GetSegmentLocalTranslation getBoneLocalTranslation() const;

// Get la rotation locale sous forme de matrice
	Output_GetSegmentLocalRotationMatrix getBoneLocalRotationMatrix( ) const;

// Get la rotation locale en quaternion
	Output_GetSegmentLocalRotationQuaternion getBoneLocalRotationQuaternion() const;

			/****SETTERS****/

// Set la nouvelle translation globale
	void setBoneGlobalTranslation(		const Client& MyClient, const std::string &nomSkeleton);	

// Set la nouvelle rotation globale sous forme de matrice
	void setBoneGlobalRotationMatrix( 	const Client& MyClient, const std::string &nomSkeleton);

// Set la nouvelle rotation globale en quaternion
	void setBoneGlobalRotationQuaternion( 	const Client& MyClient, const std::string &nomSkeleton);

// Set la nouvelle translation locale
	void setBoneLocalTranslation(		const Client& MyClient, const std::string &nomSkeleton);

// Set la nouvelle rotation locale sous forme de matrice
	void setBoneLocalRotationMatrix( 	const Client& MyClient, const std::string &nomSkeleton);

// Set la nouvelle rotation locale en quaternion
	void setBoneLocalRotationQuaternion(	const Client& MyClient, const std::string &nomSkeleton);

// Set toutes les translations et rotations d'un seul coup
	void setAllTranslationRotation(const Client& MyClient, const std::string &nomSkeleton)

		/************DESTRUCTEUR********/
	~Bone();

		/************FRIENDS***********/
	friend ostream& operator<<(ostream& flux, const Bone& B);


	private:

// Le nom du bone (segment chez Vicon) : 
	std::string m_nomBone;

// Le nom du bone parent 
	std::string m_nomBoneParent;

// Le nombre de bone enfant
	unsigned int m_nombreBoneEnfant;

// Le nom des Bone enfants
	std::vector<std::string> m_nomBoneEnfant;

	/************TRANSLATION ET ROTATION GLOBALE***************/

// La translation 'globale' du bone :
	Output_GetSegmentGlobalTranslation m_boneGlobalTranslation;

// La rotation 'globale' du bone sous forme de matrice : 
	Output_GetSegmentGlobalRotationMatrix m_boneGlobalRotationMatrix;

// La rotation 'globale' du bone en quaternion :
	Output_GetSegmentGlobalRotationQuaternion m_boneGlobalRotationQuaternion;


	/************TRANSLATION ET ROTATION LOCALE***************/

// La translation 'locale' du bone :
	Output_GetSegmentLocalTranslation m_boneLocalTranslation;

// La rotation 'locale' du bone sous forme de matrice : 
	Output_GetSegmentLocalRotationMatrix m_boneLocalRotationMatrix;

// La rotation 'locale' du bone en quaternion :
	Output_GetSegmentLocalRotationQuaternion m_boneLocalRotationQuaternion;


};
