#include "Bone.h"

using namespace ViconDataStreamSDK::CPP;

/*******CONSTRUCTEURS********/

Bone::Bone() :	m_nomBone(),
    m_nomBoneParent(),
    m_nombreBoneEnfant(),
    m_nomBoneEnfant(),
    m_boneGlobalTranslation(),
    m_boneGlobalRotationMatrix(),
    m_boneGlobalRotationQuaternion(),
    m_boneLocalTranslation(),
    m_boneLocalRotationMatrix(),
    m_boneLocalRotationQuaternion()
{}

Bone::Bone(const Bone& B) :	m_nomBone(B.getNomBone() ),
    m_nomBoneParent(B.getNomBoneParent() ),
    m_nombreBoneEnfant(B.getNombreBoneEnfant() ),
    m_nomBoneEnfant(B.getNomBoneEnfant() ),
    m_boneGlobalTranslation(B.getBoneGlobalTranslation() ),
    m_boneGlobalRotationMatrix(B.getBoneGlobalRotationMatrix() ),
    m_boneGlobalRotationQuaternion(B.getBoneGlobalRotationQuaternion() ),
    m_boneLocalTranslation(B.getBoneLocalTranslation() ),
    m_boneLocalRotationMatrix(B.getBoneLocalRotationMatrix() ),
    m_boneLocalRotationQuaternion(B.getBoneLocalRotationQuaternion() )
{}

Bone::Bone(const Client& MyClient, const std::string& _nomSkeleton, const unsigned int& _index)
{

    m_nomBone = MyClient.GetSegmentName( _nomSkeleton, _index ).SegmentName;
    m_nomBoneParent = MyClient.GetSegmentParentName( _nomSkeleton, m_nomBone ).SegmentName;
    m_nombreBoneEnfant = MyClient.GetSegmentChildCount( _nomSkeleton, m_nomBone ).SegmentCount;

    m_nomBoneEnfant.reserve(m_nombreBoneEnfant);

    for( unsigned int j = 0; j < m_nombreBoneEnfant; j++)
    {
        m_nomBoneEnfant.push_back(MyClient.GetSegmentChildName( _nomSkeleton, m_nomBone, j ).SegmentName);
    }

    setAllTranslationRotation(MyClient, _nomSkeleton);
}


/********GETTERS********/

std::string Bone::getNomBone() const
{
    return m_nomBone;
}

std::string Bone::getNomBoneParent() const
{
    return m_nomBoneParent;
}

unsigned int Bone::getNombreBoneEnfant() const
{
    return m_nombreBoneEnfant;
}

std::vector<std::string> Bone::getNomBoneEnfant() const
{
    return m_nomBoneEnfant;
}

std::vector<double> Bone::getBoneGlobalTranslation() const
{
    return m_boneGlobalTranslation;
}

std::vector<double> Bone::getBoneGlobalRotationMatrix() const
{
    return m_boneGlobalRotationMatrix;
}

std::vector<double> Bone::getBoneGlobalRotationQuaternion() const
{
    return m_boneGlobalRotationQuaternion;
}

std::vector<double> Bone::getBoneLocalTranslation() const
{
    return m_boneLocalTranslation;
}

std::vector<double> Bone::getBoneLocalRotationMatrix( ) const
{
    return m_boneLocalRotationMatrix;
}

std::vector<double> Bone::getBoneLocalRotationQuaternion() const
{
    return m_boneLocalRotationQuaternion;
}


/********SETTERS********/

void Bone::setBoneGlobalTranslation(	const Client& MyClient, const std::string &nomSkeleton)
{
    Output_GetSegmentGlobalTranslation temp(MyClient.GetSegmentGlobalTranslation( nomSkeleton, m_nomBone ));

    for(int i = 0; i < 3; i++)
        m_boneGlobalTranslation.push_back(temp.Translation[i]);
}

void Bone::setBoneGlobalRotationMatrix( 	const Client& MyClient, const std::string &nomSkeleton)
{

    Output_GetSegmentGlobalRotationMatrix temp(MyClient.GetSegmentGlobalRotationMatrix( nomSkeleton, m_nomBone ));

    for(int i = 0; i < 9; i++)
        m_boneGlobalRotationMatrix.push_back(temp.Rotation[i]);
}

void Bone::setBoneGlobalRotationQuaternion( 	const Client& MyClient, const std::string &nomSkeleton)
{
    Output_GetSegmentGlobalRotationQuaternion temp(MyClient.GetSegmentGlobalRotationQuaternion( nomSkeleton, m_nomBone ));

    m_boneGlobalRotationQuaternion.push_back(temp.Rotation[3]);
    for(int i = 0; i < 3; i++)
        m_boneGlobalRotationQuaternion.push_back(temp.Rotation[i]);
}

void Bone::setBoneLocalTranslation(		const Client& MyClient, const std::string &nomSkeleton)
{
    Output_GetSegmentLocalTranslation temp(MyClient.GetSegmentLocalTranslation( nomSkeleton, m_nomBone ));

    for(int i = 0; i < 3; i++)
        m_boneLocalTranslation.push_back(temp.Translation[i]);
}

void Bone::setBoneLocalRotationMatrix( 	const Client& MyClient, const std::string &nomSkeleton)
{
    Output_GetSegmentLocalRotationMatrix temp(MyClient.GetSegmentLocalRotationMatrix( nomSkeleton, m_nomBone ));

    for(int i = 0; i < 9; i++)
        m_boneLocalRotationMatrix.push_back(temp.Rotation[i]);
}

void Bone::setBoneLocalRotationQuaternion( 	const Client& MyClient, const std::string &nomSkeleton)
{
    Output_GetSegmentLocalRotationQuaternion temp(MyClient.GetSegmentLocalRotationQuaternion( nomSkeleton, m_nomBone ));

    m_boneLocalRotationQuaternion.push_back(temp.Rotation[3]);
    for(int i = 0; i < 3; i++)
        m_boneLocalRotationQuaternion.push_back(temp.Rotation[i]);
}

void Bone::setAllTranslationRotation(const Client& MyClient, const std::string &_nomSkeleton)
{
    setBoneGlobalTranslation(MyClient, _nomSkeleton);
    setBoneGlobalRotationMatrix(MyClient, _nomSkeleton);
    setBoneGlobalRotationQuaternion(MyClient, _nomSkeleton);

    setBoneLocalTranslation(MyClient, _nomSkeleton);
    setBoneLocalRotationMatrix(MyClient, _nomSkeleton);
    setBoneLocalRotationQuaternion(MyClient, _nomSkeleton);
}


/********DESTRUCTEUR********/

Bone::~Bone()
{}

/********FRIENDS********/

std::ostream& operator<<(std::ostream& flux, const Bone& B)
{
    flux << "Start of Bone..."<< std::endl << std::endl;

    flux << "Name of bone :\t" << B.m_nomBone << std::endl;
    flux << "Name of parent :\t" << B.m_nomBoneParent << std::endl;

    size_t s(B.getNombreBoneEnfant() );
    for(int i = 0; i < s ; i++)
        flux << "Enfant n°" << i << " :\t" << B.m_nomBoneEnfant[i] << std::endl;

    flux << "Global Translation :\t( ";
    flux  << B.m_boneGlobalTranslation[0] << ", ";
    flux  << B.m_boneGlobalTranslation[1] << ", ";
    flux  << B.m_boneGlobalTranslation[2] << " )" << std::endl;

    flux << "Global Rotation Matrix :\t( ";
    for(int i = 0; i < 8; i++)
        flux  << B.m_boneGlobalRotationMatrix[i] << ", ";
    flux << B.m_boneGlobalRotationMatrix[8] << " )" << std::endl;


    flux << "Global Rotation Quaternion :\t( ";
    for(int i = 0; i < 3; i++)
        flux << B.m_boneGlobalRotationQuaternion[i] << ", ";
    flux << B.m_boneGlobalRotationQuaternion[3] << " )" << std::endl;

    flux << "Local Translation :\t( ";
    flux  << B.m_boneLocalTranslation[0] << ", ";
    flux  << B.m_boneLocalTranslation[1] << ", ";
    flux  << B.m_boneLocalTranslation[2] << " )" << std::endl;

    flux << "Local Rotation Matrix :\t( ";
    for(int i = 0; i < 8; i++)
        flux  << B.m_boneLocalRotationMatrix[i] << ", ";
    flux << B.m_boneLocalRotationMatrix[8] << " )" << std::endl;


    flux << "Local Rotation Quaternion :\t( ";
    for(int i = 0; i < 3; i++)
        flux << B.m_boneLocalRotationQuaternion[i] << ", ";
    flux << B.m_boneLocalRotationQuaternion[3] << " )" << std::endl;

    flux << "End of Bone..."<< std::endl << std::endl;
    return flux;
}

