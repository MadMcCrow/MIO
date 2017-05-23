#ifndef DEF_STARTER_H
#define DEF_STARTER_H

#include "includes.h"
#include "Bone.h"
#include "Skeleton.h"
#include "Frame.h"
#include <fstream>
#include <thread>
#include <mutex>
#include <QApplication>
/**
* TODO -Permettre plus d'options pour l'initialisation du client
*/

class Starter : public QObject
{
       Q_OBJECT
public :
    /**
    * @brief Default constructor of Starter class.
    */    
    Starter(std::string HostName = "localhost:801");

    /**
    * @brief Default destructor of Starter class.
    */
    ~Starter();

    /**
     * @brief worker - call it in a worker thread that'll collect data for you and send signals
     */
    void worker();




signals:
    void DataRetrieved_s(Frame F);

private:

    /**
    * @brief Starting a connection with the Vicon server.
    *
    * @param HostName contains the adress of the Vicon server.
    * @return The initialized Vicon client connected to Vicon server.
    */
    ViconDataStreamSDK::CPP::Client startConnection(std::string HostName);


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
    void retrieveData(ViconDataStreamSDK::CPP::Client myClient);


    /**
    * @brief End the connection between the Vicon client and the Vicon server.
    *
    * @param MyClient the initialized Vicon client to shutdown.
    */
    void endConnection(ViconDataStreamSDK::CPP::Client myClient);


    Frame m_MIOFrame; 		/*!< The skeletons taken from the frame.*/
    std::mutex m_lock;		/*!< A lock for our thread*/
    std::string m_host;
};

#endif
