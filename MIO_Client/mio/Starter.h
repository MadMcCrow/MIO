#ifndef DEF_STARTER_H
#define DEF_STARTER_H

#include "includes.h"
#include "Bone.h"
#include "Skeleton.h"
#include "Frame.h"
#include <fstream>
#include <QApplication>

/**
 * @brief The Starter class
 * @remark it is meant to live on a separate thread - move it to thread in main.
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


signals:
    /**
     * @brief DataRetrieved_s - the produced signal
     * @param F
     */
    void DataRetrieved_s(Frame*);
    void ConnectionFailed_s();
    void ConnectionSucces_s();
    void finished();

public slots:
    /**
    * @brief Retrieve one frame from the server. - the producer slot
    *  this is a producer slot.
    */
    void retrieveData();

    /**
     * @brief terminate -disconnect and get the hell outta here.
     */
    void terminate();


private:
    /**
    * @brief Starting a connection with the Vicon server.
    * @remark used in constructor.
    * @param HostName contains the adress of the Vicon server.
    */
    void startConnection();


    /**
    * @brief End the connection between the Vicon client and the Vicon server.
    * @remark used in the terminate slot.
    * @param MyClient the initialized Vicon client to shutdown.
    */
    void endConnection();

    ///PARAMETERS
    /**
     * @brief m_Client the VICON Client variable.
     * @warning it may commit suicide and crash the whole application
     */
    ViconDataStreamSDK::CPP::Client m_Client;
    Frame m_MIOFrame; 		/*!< The skeletons taken from the frame.*/

    std::string m_host;
};

#endif
