#ifndef DEF_BONE
#define DEF_BONE

#include "includes.h"

/**
* TODO 	-Mettre en place un système d'exception.
*/

class Bone
{

public:
    /************CONSTRUCTION***********/
    /**
    * @brief Default constructor of Bone class.
    */
    Bone();
    /**
    * @brief Copy constructor of Bone class.
    *
    * @param B the bone you want to copy.
    */
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

// Get la translation globale
    std::vector<double> getBoneGlobalTranslation() const;

// Get la rotation globale sous forme de matrice
    std::vector<double> getBoneGlobalRotationMatrix() const;

// Get la rotation globale en quaternion
    std::vector<double> getBoneGlobalRotationQuaternion() const;

// Get la translation locale
    std::vector<double> getBoneLocalTranslation() const;

// Get la rotation locale sous forme de matrice
    std::vector<double> getBoneLocalRotationMatrix( ) const;

// Get la rotation locale en quaternion
    std::vector<double> getBoneLocalRotationQuaternion() const;

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

    /************TRANSLATION ET ROTATION GLOBALE***************/

// La translation 'globale' du bone :
    std::vector<double> m_boneGlobalTranslation;

// La rotation 'globale' du bone sous forme de matrice :
    std::vector<double> m_boneGlobalRotationMatrix;

// La rotation 'globale' du bone en quaternion :
    std::vector<double> m_boneGlobalRotationQuaternion;


    /************TRANSLATION ET ROTATION LOCALE***************/

// La translation 'locale' du bone :
    std::vector<double> m_boneLocalTranslation;

// La rotation 'locale' du bone sous forme de matrice :
    std::vector<double> m_boneLocalRotationMatrix;

// La rotation 'locale' du bone en quaternion :
    std::vector<double> m_boneLocalRotationQuaternion;


};

#endif
