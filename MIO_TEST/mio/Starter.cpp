#include"Starter.h"
#ifdef WIN32
#include <windows.h> // For Sleep()
#else
#include <unistd.h> // For sleep()
#endif

using namespace ViconDataStreamSDK::CPP;


Starter::Starter(std::string _HostName)
{

Client MyClient (startConnection(_HostName));

std::thread::id main_thread_id = std::this_thread::get_id();

std::thread thread([this, MyClient]() { retrieveData((Client&)MyClient); });

if(std::this_thread::get_id() != main_thread_id)
{

	endConnection(MyClient);
}
else
{}

}

Client Starter::startConnection(std::string HostName)
{

    // Make a new client
    Client MyClient;

    // Connect to a server
    std::cout << "Connecting to " << HostName << " ..." << std::flush;
    while( !MyClient.IsConnected().Connected )
    {
        // Direct connection
        bool ok = false;
        ok =( MyClient.Connect( HostName ).Result == Result::Success );
        if(!ok)
        {
            std::cout << "Warning - connect failed..." << std::endl;
        }

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


void Starter::retrieveData(Client &MyClient)
{
    size_t FrameRateWindow = 1000; // frames
    size_t Counter = 0;
    clock_t LastTime = clock();

#ifdef WIN32
        while( !Hit() )
#else
        while( true)
#endif
        {

    // Get a frame
    std::cout << "Waiting for new frame...";
    while( MyClient.GetFrame().Result != Result::Success )
    {
        // Sleep a little so that we don't lumber the CPU with a busy poll
#ifdef WIN32
        Sleep( 200 );
#else
        sleep(1);
#endif

        std::cout << ".";
    }


    std::cout << std::endl;
    if(++Counter == FrameRateWindow)
    {
        clock_t Now = clock();
        double FrameRate = (double)(FrameRateWindow * CLOCKS_PER_SEC) / (double)(Now - LastTime);
        LastTime = Now;
        Counter = 0;
    }

    //Getting frame information
    if(m_lock.try_lock())
    {
    Frame m_MIOFrame(MyClient);
    m_lock.unlock();
    }
}
}

void Starter::endConnection(ViconDataStreamSDK::CPP::Client &MyClient)
{

    // Disconnect and dispose
    int t = clock();
    std::cout << " Disconnecting..." << std::endl;
    MyClient.Disconnect();
    int dt = clock() - t;
    double secs = (double) (dt)/(double)CLOCKS_PER_SEC;
    std::cout << " Disconnect time = " << secs << " secs" << std::endl;

}

Skeleton Starter::getFirstSkeleton(){
    static Skeleton SKEL;
    if(m_lock.try_lock())
    {
        SKEL = m_MIOFrame.getFrameSkeletons()[0];
        m_lock.unlock();
    }
    return SKEL;
}


Frame Starter::getFrame(){
    static Frame FRAME;
    if(m_lock.try_lock())
    {
        FRAME = m_MIOFrame;
        m_lock.unlock();
    }
    return FRAME;
}



Starter::~Starter()
{

}

