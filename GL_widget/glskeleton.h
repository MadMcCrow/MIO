#ifndef GLSKELETON_H
#define GLSKELETON_H
#include <QMatrix4x4>
/**
 * @brief The GLSkeleton class - Contains only a list of Projection matrix and the number of cube to draw.
 * @see Skeleton
 * @todo add the "operator=" from MIOSkeleton
 * @remark all the maths implied should be executed server side to ensure best latency result.
 */
class GLSkeleton
{
public:
    /**
     * @brief GLSkeleton - simple constructor
     */
    GLSkeleton();

    /**
     * @brief modelAt
     * @param nth - the vector adress
     * @return transform matrix
     */
    QMatrix4x4 modelAt(int nth){return m_model[nth];}

    QMatrix4x4 operator[] (int nth){return modelAt(nth);} ///< @brief simple overload for ease

    QMatrix4x4* begin (){return m_model.begin();} ///< @brief simple passthrought for ease
    QMatrix4x4* end ()  {return m_model.end();}   ///< @brief simple passthrought for ease
private:
    /**
    * @brief m_model - vector of transform matrices.
    * @remark could be replaced by std::vector easily
    *
    */
   QVector<QMatrix4x4> m_model;
};

#endif // GLSKELETON_H
