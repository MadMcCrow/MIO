#include "Frame.h"

using namespace ViconDataStreamSDK::CPP;

/********CONSTRUCTEURS********/

Frame::Frame():	m_frameNumber(),
    m_frameRate(),
    m_frameTimeCode(),
    m_skeletonCount(),
    m_frameSkeleton()
{}

Frame::Frame(const Frame& F):	m_frameNumber(F.getFrameNumber() ),
    m_frameRate(F.getFrameRate() ),
    m_frameTimeCode(F.getFrameTimeCode() ),
    m_skeletonCount(F.getSkeletonCount() ),
    m_frameSkeleton(F.getFrameSkeletons() )
{}

Frame::Frame(const Client& MyClient)
{
    m_frameNumber = MyClient.GetFrameNumber();
    m_frameRate = MyClient.GetFrameRate();
    m_frameTimeCode = MyClient.GetTimecode();
    m_skeletonCount = MyClient.GetSubjectCount().SubjectCount;

    m_frameSkeleton.reserve(m_skeletonCount);

    for( unsigned int i = 0 ; i < m_skeletonCount ; ++i )
    {
        m_frameSkeleton.push_back( Skeleton(MyClient, i) );
    }

}

/********GETTERS********/

Output_GetFrameNumber Frame::getFrameNumber() const
{
    return m_frameNumber;
}

Output_GetFrameRate Frame::getFrameRate() const
{
    return m_frameRate;
}

Output_GetTimecode Frame::getFrameTimeCode() const
{
    return m_frameTimeCode;
}

unsigned int Frame::getSkeletonCount() const
{
    return m_skeletonCount;
}

std::vector<Skeleton> Frame::getFrameSkeletons() const
{
    return m_frameSkeleton;
}

/********SETTERS********/

void Frame::setFrame(const Client& MyClient)
{
    m_frameNumber = MyClient.GetFrameNumber();
    m_frameRate = MyClient.GetFrameRate();
    m_frameTimeCode = MyClient.GetTimecode();
    m_skeletonCount = MyClient.GetSubjectCount().SubjectCount;

    m_frameSkeleton.reserve(m_skeletonCount);

    for(int i = 0; i < m_skeletonCount; i++)
    {
        m_frameSkeleton.push_back(Skeleton(MyClient, i) );
    }
}


/********DESTRUCTEUR********/

Frame::~Frame()
{}

/********FRIENDS********/

std::ostream& operator<<(std::ostream& flux, const Frame& F)
{
    flux << "\t$$$$ START OF FRAME $$$$" << std::endl << std::endl;
    flux << "Number of frame :\t" << F.m_frameNumber.FrameNumber << std::endl;
    flux << "Framerate :\t" << F.m_frameRate.FrameRateHz  << " Hz" << std::endl;
    flux << "Frame TimeCode :\t" << F.m_frameTimeCode.Hours << ":" << F.m_frameTimeCode.Minutes << ":" << F.m_frameTimeCode.Seconds << std::endl;

    for(int i = 0; i < F.m_skeletonCount; i++)
    {
        flux << F.m_frameSkeleton[i];
    }

    return flux;
}
