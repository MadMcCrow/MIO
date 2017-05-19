#ifndef DEF_BONE
#define DEF_BONE

#include "includes.h"

class Bone
{

	public:
		/************CONSTRUCTION***********/
	Bone();
	Bone(const Bone& B);
	Bone(const ViconDataStreamSDK::CPP::Client& MyClient, const std::string& _nomSkeleton, const unsigned int& _index); 


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
    
// Get le vecteur vers le premier enfant.
	std::vector<std::string> getBone() const;

// Get la translation globale
	ViconDataStreamSDK::CPP::Output_GetSegmentGlobalTranslation getBoneGlobalTranslation() const;	

// Get la rotation globale sous forme de matrice
	ViconDataStreamSDK::CPP::Output_GetSegmentGlobalRotationMatrix getBoneGlobalRotationMatrix() const;

// Get la rotation globale en quaternion
	ViconDataStreamSDK::CPP::Output_GetSegmentGlobalRotationQuaternion getBoneGlobalRotationQuaternion() const;

// Get la translation locale
	ViconDataStreamSDK::CPP::Output_GetSegmentLocalTranslation getBoneLocalTranslation() const;

// Get la rotation locale sous forme de matrice
	ViconDataStreamSDK::CPP::Output_GetSegmentLocalRotationMatrix getBoneLocalRotationMatrix( ) const;

// Get la rotation locale en quaternion
	ViconDataStreamSDK::CPP::Output_GetSegmentLocalRotationQuaternion getBoneLocalRotationQuaternion() const;

    /****SETTERS****/

// Set la nouvelle translation globale
	void setBoneGlobalTranslation(		const ViconDataStreamSDK::CPP::Client& MyClient, const std::string &nomSkeleton);	

// Set la nouvelle rotation globale sous forme de matrice
	void setBoneGlobalRotationMatrix( 	const ViconDataStreamSDK::CPP::Client& MyClient, const std::string &nomSkeleton);

// Set la nouvelle rotation globale en quaternion
	void setBoneGlobalRotationQuaternion( 	const ViconDataStreamSDK::CPP::Client& MyClient, const std::string &nomSkeleton);

// Set la nouvelle translation locale
	void setBoneLocalTranslation(		const ViconDataStreamSDK::CPP::Client& MyClient, const std::string &nomSkeleton);

// Set la nouvelle rotation locale sous forme de matrice
	void setBoneLocalRotationMatrix( 	const ViconDataStreamSDK::CPP::Client& MyClient, const std::string &nomSkeleton);

// Set la nouvelle rotation locale en quaternion
	void setBoneLocalRotationQuaternion(	const ViconDataStreamSDK::CPP::Client& MyClient, const std::string &nomSkeleton);

// Set toutes les translations et rotations d'un seul coup
	void setAllTranslationRotation(const ViconDataStreamSDK::CPP::Client& MyClient, const std::string &_nomSkeleton);

		/************DESTRUCTEUR********/
	~Bone();

		/************FRIENDS***********/
	friend std::ostream& operator<<(std::ostream& flux, const Bone& B);


	private:

// Le nom du bone (segment chez Vicon) : 
	std::string m_nomBone;

// Le nom du bone parent 
	std::string m_nomBoneParent;

// Le nombre de bone enfant
	unsigned int m_nombreBoneEnfant;

// Le nom des Bone enfants
	std::vector<std::string> m_nomBoneEnfant;
    
// La ref du premier bone enfants
//	Bone& m_FirstBoneEnfant;

	/************TRANSLATION ET ROTATION GLOBALE***************/

// La translation 'globale' du bone :
	ViconDataStreamSDK::CPP::Output_GetSegmentGlobalTranslation m_boneGlobalTranslation;

// La rotation 'globale' du bone sous forme de matrice : 
	ViconDataStreamSDK::CPP::Output_GetSegmentGlobalRotationMatrix m_boneGlobalRotationMatrix;

// La rotation 'globale' du bone en quaternion :
	ViconDataStreamSDK::CPP::Output_GetSegmentGlobalRotationQuaternion m_boneGlobalRotationQuaternion;


	/************TRANSLATION ET ROTATION LOCALE***************/

// La translation 'locale' du bone :
	ViconDataStreamSDK::CPP::Output_GetSegmentLocalTranslation m_boneLocalTranslation;

// La rotation 'locale' du bone sous forme de matrice : 
	ViconDataStreamSDK::CPP::Output_GetSegmentLocalRotationMatrix m_boneLocalRotationMatrix;

// La rotation 'locale' du bone en quaternion :
	ViconDataStreamSDK::CPP::Output_GetSegmentLocalRotationQuaternion m_boneLocalRotationQuaternion;


};

#endif
