#include"Starter.h"
#ifdef WIN32
#include <windows.h> // For Sleep()
#else
#include <unistd.h> // For sleep()
#include <chrono>

#endif

using namespace ViconDataStreamSDK::CPP;


Starter::Starter(std::string _HostName)
{
    m_host = _HostName;

}

void Starter::startConnection(std::string HostName)
{
    // Connect to a server
    std::cout << "Connecting to " << HostName << " ..." <<  std::endl;
    while( !m_Client.IsConnected().Connected )
    {
        // Direct connection
        if(m_Client.Connect( HostName ).Result != Result::Success)
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
        startConnection(m_host);
    }

    static size_t FrameRateWindow = 1000; // frames
    size_t Counter = 0;
    clock_t LastTime = clock();

#ifdef WIN32
    while( !Hit() )
#else
    while(true)
#endif
    {
        // Get a frame
        std::cout << "Waiting for new frame... ";
        std::cout << std::endl;
        if(++Counter == FrameRateWindow)
        {
            clock_t Now = clock();
            double FrameRate = (double)(FrameRateWindow * CLOCKS_PER_SEC) / (double)(Now - LastTime);
            LastTime = Now;
            Counter = 0;
            std::cout << FrameRate;
        }
        //Getting frame information
        m_MIOFrame = Frame(m_Client);
        std::cout << "Frame Captured \n";
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
