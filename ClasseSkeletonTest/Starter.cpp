#include "includes.h"

#include "Bone.h"
#include "Skeleton.h"
#include "Frame.h"

#ifdef WIN32
  #include <windows.h> // For Sleep()
#else
  #include <unistd.h> // For sleep()
#endif

// g++ Frame.cpp Skeleton.cpp Bone.cpp Starter.cpp -o toto -Wl,-rpath=libs -Llibs/ -lViconDataStreamSDK_CPP

using namespace ViconDataStreamSDK::CPP;

int main(int argc, char* argv[] )
{
  // Program options
  std::string HostName = "localhost:801";
  if( argc > 1 )
  {
    HostName = argv[1];
  }

  // Make a new client
  Client MyClient;

for(int i=0; i != 3; ++i) // repeat to check disconnecting doesn't wreck next connect
{
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


    size_t FrameRateWindow = 1000; // frames
    size_t Counter = 0;
    clock_t LastTime = clock();
    // Loop until a key is pressed
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
	Frame MainFrame(MyClient);
	//Displaying all info to see if it works
	std::cout << MainFrame << std::endl;

    }

    // Disconnect and dispose
    int t = clock();
    std::cout << " Disconnecting..." << std::endl;
    MyClient.Disconnect();
    int dt = clock() - t;
    double secs = (double) (dt)/(double)CLOCKS_PER_SEC;
    std::cout << " Disconnect time = " << secs << " secs" << std::endl;

}

std::cout << "Hello World" << std::endl;

return 0;
}
