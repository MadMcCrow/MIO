#include "glstream.h"
#include <QDataStream>

static bool ENABLE_ALTERNATIVE = false;

GLStream::GLStream()
{

}


void GLStream::insertInDataStream(QDataStream &out){
    ///Header
    out << (quint32)0x3D3D3D3D; ///Magic Number
    out << (qint32)100;         ///version
    out.setVersion(QDataStream::Qt_4_0);
    ///Data
    out << (qint32)m_skeletonData.size();
    for (auto &bonedata : m_skeletonData) ///for each
    {
        out << (QMatrix4x4)bonedata;
    }
}

void GLStream::getFromDataStream(QDataStream &in)
{
    quint32 size;
    QMatrix4x4 bonedata;
    ///Header
    quint32 magic;
    in >> magic;
    if (magic != 0x3D3D3D3D)
        return; ///@todo add exception
    qint32 version;
    in >> version;
    if (version < 100)
        return; ///@todo add exception
    ///Qt version of DataStream
    in.setVersion(QDataStream::Qt_4_0);
    ///DATA
    in >> size;
    ///two ways of handling this:
    /// either we append:
    if(ENABLE_ALTERNATIVE){


        m_skeletonData.clear();
        for (size_t i = 0; i<size; i++)
        {
            in >> bonedata;
            m_skeletonData.push_back(bonedata);
        }
    }
    ///or we build our matrix
    else
    {
        m_skeletonData.resize(size);
        for(auto &bone:m_skeletonData)
        {
            in >>bonedata;
            bone=bonedata;
        }
    }

    ///Done
}

