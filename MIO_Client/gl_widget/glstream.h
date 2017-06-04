#ifndef GLSTREAM_H
#define GLSTREAM_H
#include <QDataStream>  ///how we transfer
#include "glskeleton.h" ///what we're transfering


/**
 * @brief The GLStream class - a simple pass-through class
 */
class GLStream
{
public:
    GLStream(); ///@brief default constructor. DO NOT USE.
    GLStream(GLSkeleton Skeleton);
    void insertInDataStream(QDataStream &out);
    void getFromDataStream(QDataStream &in);
private:
    QVector<QMatrix4x4> m_skeletonData;
};

#endif // GLSTREAM_H
