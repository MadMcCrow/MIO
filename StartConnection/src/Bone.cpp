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

for( unsigned int j = 0; j < m_nombreBoneEnfant; j++)
	m_nomBoneEnfant[j] = MyClient.GetSegmentChildName( _nomSkeleton, m_nomBone, j ).SegmentName;


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

Output_GetSegmentGlobalTranslation Bone::getBoneGlobalTranslation() const
{
return m_boneGlobalTranslation;
}

Output_GetSegmentGlobalRotationMatrix Bone::getBoneGlobalRotationMatrix() const
{
return m_boneGlobalRotationMatrix;
}

Output_GetSegmentGlobalRotationQuaternion Bone::getBoneGlobalRotationQuaternion() const
{
return m_boneGlobalRotationQuaternion;
}

Output_GetSegmentLocalTranslation Bone::getBoneLocalTranslation() const
{
return m_boneLocalTranslation;
}

Output_GetSegmentLocalRotationMatrix Bone::getBoneLocalRotationMatrix( ) const
{
return m_boneLocalRotationMatrix;
}

Output_GetSegmentLocalRotationQuaternion Bone::getBoneLocalRotationQuaternion() const
{
return m_boneLocalRotationQuaternion;
}


		/********SETTERS********/

void Bone::setBoneGlobalTranslation(	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneGlobalTranslation = MyClient.GetSegmentGlobalTranslation( nomSkeleton, m_nomBone );
}

void Bone::setBoneGlobalRotationMatrix( 	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneGlobalRotationMatrix = MyClient.GetSegmentGlobalRotationMatrix( nomSkeleton, m_nomBone );
}

void Bone::setBoneGlobalRotationQuaternion( 	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneGlobalRotationQuaternion = MyClient.GetSegmentGlobalRotationQuaternion( nomSkeleton, m_nomBone );
}

void Bone::setBoneLocalTranslation(		const Client& MyClient, const std::string &nomSkeleton)
{
m_boneLocalTranslation = MyClient.GetSegmentLocalTranslation( nomSkeleton, m_nomBone );
}

void Bone::setBoneLocalRotationMatrix( 	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneLocalRotationMatrix = MyClient.GetSegmentLocalRotationMatrix( nomSkeleton, m_nomBone );
}

void Bone::setBoneLocalRotationQuaternion( 	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneLocalRotationQuaternion = MyClient.GetSegmentLocalRotationQuaternion( nomSkeleton, m_nomBone );
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
flux << "Parent of bone :\t" << B.m_nomBoneParent << std::endl;

size_t s(B.getNombreBoneEnfant() );
for(int i = 0; i < s ; i++)
	flux << "Enfant n°" << i << " :\t" << B.m_nomBoneEnfant[i] << std::endl;

flux << "Global Translation :\t( ";
flux  << B.m_boneGlobalTranslation.Translation[0] << ", ";
flux  << B.m_boneGlobalTranslation.Translation[1] << ", ";
flux  << B.m_boneGlobalTranslation.Translation[2] << " )" << std::endl;

flux << "Global Rotation Matrix :\t( ";
for(int i = 0; i < 8; i++)
	flux  << B.m_boneGlobalRotationMatrix.Rotation[i] << ", ";	
flux << B.m_boneGlobalRotationMatrix.Rotation[8] << " )" << std::endl;


flux << "Global Rotation Quaternion :\t( ";
for(int i = 0; i < 3; i++)
	flux << B.m_boneGlobalRotationQuaternion.Rotation[i] << ", ";
flux << B.m_boneGlobalRotationQuaternion.Rotation[3] << " )" << std::endl;

flux << "Local Translation :\t( ";
flux  << B.m_boneLocalTranslation.Translation[0] << ", ";
flux  << B.m_boneLocalTranslation.Translation[1] << ", ";
flux  << B.m_boneLocalTranslation.Translation[2] << " )" << std::endl;

flux << "Local Rotation Matrix :\t( ";
for(int i = 0; i < 8; i++)
	flux  << B.m_boneLocalRotationMatrix.Rotation[i] << ", ";	
flux << B.m_boneLocalRotationMatrix.Rotation[8] << " )" << std::endl;


flux << "Local Rotation Quaternion :\t( ";
for(int i = 0; i < 3; i++)
	flux << B.m_boneLocalRotationQuaternion.Rotation[i] << ", ";
flux << B.m_boneLocalRotationQuaternion.Rotation[3] << " )" << std::endl;

flux << "End of Bone..."<< std::endl << std::endl;
return flux;
}

