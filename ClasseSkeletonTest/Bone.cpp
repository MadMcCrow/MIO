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

std::vector<std::string> getNomBoneEnfant() const
{
return m_nomBoneEnfant;
}

Output_GetSegmentGlobalTranslation getBoneGlobalTranslation() const
{
return m_boneGlobalTranslation;
}

Output_GetSegmentGlobalRotationMatrix getBoneGlobalRotationMatrix() const
{
return m_boneGlobalRotationMatrix;
}

Output_GetSegmentGlobalRotationQuaternion getBoneGlobalRotationQuaternion() const
{
return m_boneGlobalRotationQuaternion;
}

Output_GetSegmentLocalTranslation getBoneLocalTranslation() const
{
return m_boneLocalTranslation;
}

Output_GetSegmentLocalRotationMatrix getBoneLocalRotationMatrix( ) const
{
return m_boneLocalRotationMatrix;
}

Output_GetSegmentLocalRotationQuaternion getBoneLocalRotationQuaternion() const
{
return m_boneLocalRotationQuaternion;
}


		/********SETTERS********/

void setBoneGlobalTranslation(	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneGlobalTranslation = MyClient.GetSegmentGlobalTranslation( nomSkeleton, m_nomBone );
}

void setBoneGlobalRotationMatrix( 	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneGlobalRotationMatrix = MyClient.GetSegmentGlobalRotationMatrix( nomSkeleton, m_nomBone );
}

void setBoneGlobalRotationQuaternion( 	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneGlobalRotationQuaternion = MyClient.GetSegmentGlobalRotationQuaternion( nomSkeleton, m_nomBone );
}

void setBoneLocalTranslation(		const Client& MyClient, const std::string &nomSkeleton)
{
m_boneLocalTranslation = MyClient.GetSegmentLocalTranslation( nomSkeleton, m_nomBone );
}

void setBoneLocalRotationMatrix( 	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneLocalRotationMatrix = MyClient.GetSegmentLocalRotationMatrix( nomSkeleton, m_nomBone );
}

void setBoneLocalRotationQuaternion( 	const Client& MyClient, const std::string &nomSkeleton)
{
m_boneLocalRotationQuaternion = MyClient.GetSegmentLocalRotationQuaternion( nomSkeleton, m_nomBone );
}


		/********DESTRUCTEUR********/

Bone::~Bone()
{}

		/********FRIENDS********/

ostream& operator<<(ostream& flux, const Bone& B)
{

flux << "Name of bone :\t" << B.m_nomBone << endl;
flux << "Parent of bone :\t" << B.m_nomBoneParent << endl;

size_t s(B.getNombreBoneEnfant() );
for(int i = 0; i < s ; i++)
	flux << "Enfant n°" << i << " :\t" << B.m_nomBoneEnfant[i] << endl;

flux << "Global translation :\t"<< "( ";
flux  << B.m_boneGlobalTranslation.Translation[0] << ", ";
flux  << B.m_boneGlobalTranslation.Translation[1] << ", ";
flux  << B.m_boneGlobalTranslation.Translation[2] << " )" << endl;




return flux;
}

