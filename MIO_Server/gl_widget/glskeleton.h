
#ifndef GLSKELETON_H
#define GLSKELETON_H
#include <QMatrix4x4>
#include <iostream>
///@todo improve the integration and/or the conversion
#include "mio/Skeleton.h"
/**
 * @brief The GLSkeleton class - Contains only a list of Projection matrix and the number of cube to draw.
 * @see Skeleton
 * @todo add the "operator=" from MIOSkeleton
 * @remarks all the maths implied should be executed server side to ensure best latency result.
 *          there should also be implemented in an other file.
 */
class GLSkeleton
{
public:
    /**
     * @brief GLSkeleton - simple constructor - DO NOT USE
     */
    GLSkeleton();

    /**
     * @brief GLSkeleton - copy constructor
     * @param source
     */
    GLSkeleton(const GLSkeleton& source);
    /**
     * @brief GLSkeleton - simple constructor with matrix vector input.
     */
    GLSkeleton(QVector<QMatrix4x4> Data ){m_model = Data;}


    int size(void){return m_model.size();}
    /**
     * @brief clear - clear the data. used for init or destruction.
     */
    void clear(){m_model.clear();}

    ~GLSkeleton(){this->clear();}

    /**
     * @brief modelAt
     * @param nth - the vector adress
     * @return transform matrix
     */
    QMatrix4x4 modelAt(int nth){return m_model[nth];}

    QMatrix4x4 operator[] (int nth){return modelAt(nth);} ///< @brief simple overload for ease
    QMatrix4x4* begin (){return m_model.begin();}         ///< @brief simple passthrought for ease
    QMatrix4x4* end ()  {return m_model.end();}           ///< @brief simple passthrought for ease
    GLSkeleton& operator= (GLSkeleton source);            ///< @brief simple overload for ease

    /**
     * @brief operator = for copying MIOSkeletons.
     * @param MIOSkeleton
     * @return this
     * @remark IMHO it would be more sensible to have the interface for exporting in the MIO skeleton.
     */
    GLSkeleton& operator= (Skeleton MIOSkeleton);
    GLSkeleton import(Skeleton MIOSkeleton);

private:
    /**
    * @brief m_model - vector of transform matrices.
    * @remark could be replaced by std::vector easily
    *
    */
    QVector<QMatrix4x4> m_model;
};


#endif // GLSKELETON_H
