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

void Starter::worker()
{
    Client myClient = startConnection(m_host);
    retrieveData(myClient);
    endConnection(myClient);
}

Client Starter::startConnection(std::string HostName)
{
    // Make a new client
    Client MyClient;
    // Connect to a server
    std::cout << "Connecting to " << HostName << " ..." <<  std::endl;
    while( !MyClient.IsConnected().Connected )
    {
        // Direct connection
        bool ok = false;
        ok =( MyClient.Connect( HostName ).Result == Result::Success );
        if(!ok)
        {
            std::cout << "Warning - connect failed..." << std::endl;
        }
        std::cout << MyClient.IsConnected().Connected;
#ifdef WIN32
        Sleep( 1000 );
#else
        sleep(1);
#endif
    }


    // Enable some different data types
    MyClient.EnableSegmentData();
    MyClient.EnableDebugData();

    // Set the streaming mode
    MyClient.SetStreamMode( ViconDataStreamSDK::CPP::StreamMode::ServerPush );

    // Set the global up axis
    MyClient.SetAxisMapping( Direction::Forward,
                             Direction::Left,
                             Direction::Up );

    return MyClient;
}


void Starter::retrieveData(Client myClient)
{
    static size_t FrameRateWindow = 1000; // frames
    size_t Counter = 0;
    clock_t LastTime = clock();

#ifdef WIN32
        while( !Hit() )
#else
        while( Counter <= 1)
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
    ++Counter;
    //Getting frame information
    m_MIOFrame = Frame(myClient);
    std::cout << "Frame Captured \n";
    emit DataRetrieved_s(m_MIOFrame);

    }
}



void Starter::endConnection(ViconDataStreamSDK::CPP::Client myClient)
{

    // Disconnect and dispose
    int t = clock();
    std::cout << " Disconnecting..." << std::endl;
    myClient.Disconnect();
    int dt = clock() - t;
    double secs = (double) (dt)/(double)CLOCKS_PER_SEC;
    std::cout << " Disconnect time = " << secs << " secs" << std::endl;

}


Starter::~Starter()
{
}

