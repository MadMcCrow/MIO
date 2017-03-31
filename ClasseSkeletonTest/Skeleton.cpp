#include "Skeleton.h"

using namespace ViconDataStreamSDK::CPP;

		/********CONSTRUCTEURS********/

Skeleton::Skeleton() : 	m_nomSkeleton(),
			m_nomRootBone(),
			m_bonesCount(),
			m_skeleton()
{}

Skeleton::Skeleton(const Skeleton& S) : m_nomSkeleton(S.getNomSkeleton() ),
					m_nomRootBone(S.getNomRootBone() ),
					m_bonesCount(S.getBonesCount() ),
					m_skeleton(S.getSkeleton() )
{}

Skeleton::Skeleton(const Client& MyClient, const unsigned int& index)
{
setSkeleton(MyClient, index);
}


		/********GETTERS********/

std::string Skeleton::getNomSkeleton() const
{
return m_nomSkeleton;
}

std::string Skeleton::getNomRootBone() const
{
return m_nomRootBone;
}

unsigned int Skeleton::getBonesCount() const
{
return m_bonesCount;
}

std::vector<Bone> Skeleton::getSkeleton() const
{
return m_skeleton;
}


		/********SETTERS********/

void Skeleton::setSkeleton(const Client& MyClient, const unsigned int& index)
{
m_nomSkeleton = MyClient.GetSubjectName( index ).SubjectName;
m_nomRootBone = MyClient.GetSubjectRootSegmentName( m_nomSkeleton ).SegmentName;
m_bonesCount = MyClient.GetSegmentCount( m_nomSkeleton ).SegmentCount;

m_skeleton.reserve(m_bonesCount);

for(unsigned int i = 0; i < m_bonesCount; i++)
	{
	m_skeleton.push_back( Bone(MyClient, m_nomSkeleton, i) );
	}
}

		/********DESTRUCTEUR********/

Skeleton::~Skeleton()
{}

		/********FRIENDS********/

std::ostream& operator<<(std::ostream& flux, const Skeleton& S)
{
flux << "\t\tSTART OF SKELETON" << std::endl << std::endl;

flux << "Name of skeleton :\t" << S.m_nomSkeleton << std::endl;
flux << "Name of root bone :\t" << S.m_nomRootBone << std::endl;

for(int i = 0; i < S.m_bonesCount; i++)
	{
	flux << "\t" << S.m_skeleton[i];
	}

flux << "\t\tEND OF SKELETON" << std::endl << std::endl;

return flux;
}
