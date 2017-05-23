#ifndef GLSHAPE_H
#define GLSHAPE_H

#include <qopengl.h>
#include <QVector>
#include <QVector3D>
#include <iostream>
/**
 * @brief The glshape class - it is a pure virtual class
 * @todo add a method that returns the data either in a single bloc (PoS + Norm) and one that separates.
 */
class glshape
{
public:
    /**
     * @brief count
     * @return the number of values inside the data.
     */
    int count() const { return m_data.size(); }

    /**
     * @brief constData
     * @return return the array, but as a const, for security.
     */
    const GLfloat *constData() const { return m_data.constData(); }

    /**
     * @brief vertexCount
     * @return the number of vertices.
     * @remark the inline value of 6 is for x,y,z (3) and r,g,b (3).
     */
    int vertexCount() const { return m_data.size() / 6; }

protected:
    /**
     * @brief m_data - the vector (as in c++ vector) containing all the coordinates$
     * @remark We could choose between std::vector or QVector.
     *  the thing is that QVector makes our code less standard but more compatible with Qt.
     */
    QVector<GLfloat> m_data;

private:
    /**
     * @brief fill - Fill the data with the correct shape.
     */
     virtual void fill() = 0;
};


#endif // SHAPE_H

