
#ifndef GLSKELETON_H
#define GLSKELETON_H
#include <QMatrix4x4>
///@todo improve the integration and/or the conversion
#include "../StartConnection/src/Skeleton.h"
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
     * @brief GLSkeleton - simple constructor
     */
    GLSkeleton();

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

private:
    /**
    * @brief m_model - vector of transform matrices.
    * @remark could be replaced by std::vector easily
    *
    */
   QVector<QMatrix4x4> m_model;
};

// inline function

inline GLSkeleton& GLSkeleton::operator= (GLSkeleton source){
   this->m_model = source.m_model;
    return *this;
}

///@todo        check experimentally if this works
/// @remarks    could be simpler if Skeleton had an accessor for each bone.
///             something like getbone(int at) and operator[] .
///             Would also like to see some inlining in your headers. it improves
inline GLSkeleton& GLSkeleton::operator= (Skeleton MIOSkeleton){
   this->clear();
    // we don't know how getBonesCountWorks, and it may slow the process to call it for every bone.
   size_t it = MIOSkeleton.getBonesCount();
   for (size_t bone = 0; bone < it; bone++ )
   {
       ///@warning Construct is always children to parent
       ///
       /// @todo : determine experimentally if we need the rotation, or if we can do everything
       ///  with position ( and local rotation - to give alignement)
       QMatrix4x4  WorldTransform;
       QQuaternion WorldRotation;
       QVector3D   WorldTranslate;
       QMatrix4x4 look_at_parent;


       //float Lenght;
       ///@remark   it would help to have standard float notation instead of using
       ///          Vicon's types, that makes that awful encapsulation that may slow
       ///          the process down. SPEED IS VITAL HERE !
       ///          This would make our program more open to other manufacturers.
       ///

       /// getting the WORLD rotation
       ///@remark I used a scope to make quat inexistant out of this.
       {
           ///@warning from Vicon SDK:
           /// The quaternion is of the form (x, y, z, w)
           /// where w is the real component and x, y & z are the
           /// imaginary components.
           /// N.B. This is different from that used in many other applications,
           /// which use (w, x, y, z).
           double Quat[4];
           // this is due to the stupid way Vicon Works :
           Quat[0] = MIOSkeleton.getSkeleton().at(bone).getBoneGlobalRotationQuaternion().Rotation[0];
           Quat[1] = MIOSkeleton.getSkeleton().at(bone).getBoneGlobalRotationQuaternion().Rotation[1];
           Quat[2] = MIOSkeleton.getSkeleton().at(bone).getBoneGlobalRotationQuaternion().Rotation[2];
           Quat[3] = MIOSkeleton.getSkeleton().at(bone).getBoneGlobalRotationQuaternion().Rotation[3];
           WorldRotation = QQuaternion((float)Quat[3], (float)Quat[0], (float)Quat[1], (float)Quat[2]);
       }
       ///Getting the WORLD translation
       {
           QVector3D trs = QVector3D(
           MIOSkeleton.getSkeleton().at(bone).getBoneGlobalTranslation().Translation[0],
           MIOSkeleton.getSkeleton().at(bone).getBoneGlobalTranslation().Translation[1],
           MIOSkeleton.getSkeleton().at(bone).getBoneGlobalTranslation().Translation[2]);
           WorldTranslate = QVector3D((float)trs[0], (float)trs[1], (float)trs[2]);
       }
       ///Getting the proper scale/rotation/translate to parent.
       {
           QVector3D ltrs = QVector3D(
           MIOSkeleton.getSkeleton().at(bone).getBoneLocalTranslation().Translation[0],
           MIOSkeleton.getSkeleton().at(bone).getBoneLocalTranslation().Translation[1],
           MIOSkeleton.getSkeleton().at(bone).getBoneLocalTranslation().Translation[2]);
           QVector3D scale = QVector3D(1*ltrs.length(),0.5,0.5);
           look_at_parent.setToIdentity();
           look_at_parent.scale(scale);
           look_at_parent.lookAt(QVector3D(.0f, .0f, .0f), ltrs, QVector3D(1,0,0));

       }
       /// Applying all operations in order : Scale, Rotation, translate.
       /// C=S*R*T.
       WorldTransform.setToIdentity();
       WorldTransform = look_at_parent * WorldTransform;
       WorldTransform.translate(WorldTranslate);
   }

    return *this;
}

#endif // GLSKELETON_H
