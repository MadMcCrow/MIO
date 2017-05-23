#ifndef DEF_STARTER_H
#define DEF_STARTER_H

#include "includes.h"
#include "Bone.h"
#include "Skeleton.h"
#include "Frame.h"
#include <fstream>
#include <thread>
#include <mutex>
/**
* TODO -Permettre plus d'options pour l'initialisation du client
*/

class Starter
{
public :

    /**
    * @brief Default constructor of Starter class.
    */    
    Starter(std::string HostName = "localhost:801");

    Skeleton getFirstSkeleton();

    Frame getFrame();

    /**
    * @brief Default destructor of Starter class.
    */
    ~Starter();

private:

    /**
    * @brief Starting a connection with the Vicon server.
    *
    * @param HostName contains the adress of the Vicon server.
    * @return The initialized Vicon client connected to Vicon server.
    */
    ViconDataStreamSDK::CPP::Client startConnection(std::string HostName );


    /**
    * @brief Retrieve one frame from the server.
    *
    * This function retrieves one frame from the Vicon server.
    * Be aware that if you want to retrieve many frames you must
    * use a loop.
    *
    * @param MyClient the initialized Vicon client connected to Vicon server.
    * @return A single Frame.
    */
    void retrieveData(ViconDataStreamSDK::CPP::Client &MyClient);


    /**
    * @brief End the connection between the Vicon client and the Vicon server.
    *
    * @param MyClient the initialized Vicon client to shutdown.
    */
    void endConnection(ViconDataStreamSDK::CPP::Client &MyClient);


    Frame m_MIOFrame; 		/*!< The skeletons taken from the frame.*/
    std::mutex m_lock;		/*!< A lock for our thread*/

};

#endif
