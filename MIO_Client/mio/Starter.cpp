#include"Starter.h"
#ifdef WIN32
#include <windows.h> // For Sleep()
#else
#include <unistd.h> // For sleep()
#include <chrono>

#endif

#define  DEBUG
using namespace ViconDataStreamSDK::CPP;


Starter::Starter(std::string _HostName)
{
    m_host = _HostName;

}

void Starter::startConnection()
{
    // Connect to a server
    std::cout << "Connecting to " << m_host << " ..." <<  std::endl;
    while( !m_Client.IsConnected().Connected )
    {
        // Direct connection
        if(m_Client.Connect( m_host ).Result != Result::Success)
        {
            emit ConnectionFailed_s();
            std::cout << "Warning - connect failed..." << std::endl;
        }
        std::cout << m_Client.IsConnected().Connected;
#ifdef WIN32
        Sleep( 1000 );
#else
        sleep(1);
#endif
    }
    // Enable some different data types
    m_Client.EnableSegmentData();
    m_Client.EnableDebugData();
    // Set the streaming mode
    m_Client.SetStreamMode( ViconDataStreamSDK::CPP::StreamMode::ServerPush );
    // Set the global up axis
    m_Client.SetAxisMapping( Direction::Forward,
                             Direction::Left,
                             Direction::Up );
}


void Starter::retrieveData()
{
    std::cout << "Retrieving thread started\n";
    // if client got disconnected, reconnect.
    while (!m_Client.IsConnected().Connected)
    {
        std::cout << "thread was started without a proper connection\n";
        startConnection();
    }
    std::cout << "Connection done\n";
    static size_t FrameRateWindow = 1000; // frames
    size_t Counter = 0;
    clock_t LastTime = clock();

#ifdef WIN32
    while( !Hit() )
#else
    while(true)
#endif
    {
#ifdef WIN32
        Sleep(15);
#else
        usleep(15);
#endif
        m_Client.EnableSegmentData();
        m_Client.EnableUnlabeledMarkerData();
        m_Client.EnableDebugData();
        // Get a frame
        if(++Counter == FrameRateWindow)
        {
            clock_t Now = clock();
            double FrameRate = (double)(FrameRateWindow * CLOCKS_PER_SEC) / (double)(Now - LastTime);
            LastTime = Now;
            Counter = 0;
        }
        //Getting frame information
        m_MIOFrame = Frame(m_Client);
        Result::Enum TEST;
;
#ifdef DEBUG
TEST = m_Client.GetFrame().Result;
///@remark debugger
switch (TEST) {
case Result::Enum::NotConnected:
    std::cout << "NotConnected" <<std::endl;
    break;
case Result::Enum::Success:
    std::cout << "Success" <<std::endl;
    break;
case Result::Enum::InvalidIndex:
    std::cout << "InvalidIndex" <<std::endl;
    break;
case Result::Enum::NoFrame:
    std::cout << "NoFrame" <<std::endl;
    break;
case Result::Enum::Unknown:
    std::cout << "Unknown" <<std::endl;
    break;
default:
    break;
}
#endif

        size_t T = m_Client.GetSubjectCount().SubjectCount;
        std::cout << "number of skeleton: " << T <<std::endl;

        ///@bug: this will probably fail,
        /// passing a pointer to something alive
        emit DataRetrieved_s(&m_MIOFrame);
    }
}



void Starter::endConnection()
{  // Disconnect and dispose
    int t = clock();
    std::cout << " Disconnecting..." << std::endl;
    m_Client.Disconnect();
    int dt = clock() - t;
    double secs = (double) (dt)/(double)CLOCKS_PER_SEC;
    std::cout << " Disconnect time = " << secs << " secs" << std::endl;
}




void Starter::terminate(){
    endConnection();
}


Starter::~Starter()
{
    std::cout << "the client just commited suicide ! \n";
    endConnection();
}
