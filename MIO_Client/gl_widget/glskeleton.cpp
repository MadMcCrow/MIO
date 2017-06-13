#include "glskeleton.h"

GLSkeleton::GLSkeleton()
{
    m_model.clear();
    QMatrix4x4 M;
    M.setToIdentity();
    M.translate(0,0,0);
    m_model.push_back(M);
}

GLSkeleton::GLSkeleton(const GLSkeleton &source)
{
 m_model = source.m_model;
}


GLSkeleton& GLSkeleton::operator= (GLSkeleton source){
    this->m_model = source.m_model;
    return *this;
}

///@todo        check experimentally if this works
/// @remarks    could be simpler if Skeleton had an accessor for each bone.
///             something like getbone(int at) and operator[] .
///             Would also like to see some inlining in your headers. it improves
GLSkeleton& GLSkeleton::operator= (Skeleton MIOSkeleton){
    this->m_model.clear();
    // we don't know how getBonesCountWorks, and it may slow the process to call it for every bone.
    size_t it = MIOSkeleton.getBonesCount();
    for (size_t bone = 0; bone < it; bone++ )
    {
        ///@warning Construct is always children to parent
        ///
        /// @todo : determine experimentally if we need the rotation, or if we can do everything
        ///  with position ( and local rotation - to give alignement)
        QMatrix4x4  WorldTransform;
        QQuaternion WorldRotationQ;
        QMatrix4x4  WorldRotationM;
        QVector3D   WorldTranslate;
        QMatrix4x4  AdaptToParent;
        float precision = 100; ///< 100 means


        //float Lenght;
        ///@remark   it would help to have standard float notation instead of using
        ///          Vicon's types, that makes that awful encapsulation that may slow
        ///          the process down. SPEED IS VITAL HERE !
        ///          This would make our program more open to other manufacturers.
        ///

        /// getting the WORLD rotation
        ///@remark I used a scope to make quat inexistant out of this.
        {
            std::vector<double> Quat = MIOSkeleton.getSkeleton().at(bone).getBoneGlobalRotationQuaternion();
            WorldRotationQ = QQuaternion((float)Quat[0], (float)Quat[1], (float)Quat[2], (float)Quat[3]);
        }
        {
            std::vector<double> Mat = MIOSkeleton.getSkeleton().at(bone).getBoneGlobalRotationMatrix();
            WorldRotationM.setRow(0,QVector4D(Mat[0],Mat[1],Mat[2],0));
            WorldRotationM.setRow(1,QVector4D(Mat[3],Mat[4],Mat[5],0));
            WorldRotationM.setRow(2,QVector4D(Mat[6],Mat[7],Mat[8],0));
        }
        ///Getting the WORLD translation
        {
            QVector3D trs = QVector3D(
                        MIOSkeleton.getSkeleton().at(bone).getBoneGlobalTranslation()[0]/precision,
                    MIOSkeleton.getSkeleton().at(bone).getBoneGlobalTranslation()[1]/precision,
                    MIOSkeleton.getSkeleton().at(bone).getBoneGlobalTranslation()[2]/precision);
            WorldTranslate = trs;
        }
        ///Getting the proper scale/rotation/translate to parent.
        {
            QVector3D ltrs = QVector3D(
                    MIOSkeleton.getSkeleton().at(bone).getBoneLocalTranslation()[0]/precision,
                    MIOSkeleton.getSkeleton().at(bone).getBoneLocalTranslation()[1]/precision,
                    MIOSkeleton.getSkeleton().at(bone).getBoneLocalTranslation()[2]/precision);
            AdaptToParent.setToIdentity();
            AdaptToParent.scale(1,0.5*ltrs.length(),1);
            AdaptToParent.translate(0,0.5*ltrs.length(),0);

        }
        /// Applying all operations in order : Scale, Rotation, translate.
        /// C=S*R*T.
        WorldTransform.setToIdentity();
        WorldTransform.rotate(WorldRotationQ);
        WorldTransform.scale(precision);

        WorldTransform *= AdaptToParent;
        WorldTransform.translate(WorldTranslate);
        //WorldTransform *= WorldRotationM;

        this->m_model.push_back(WorldTransform);
    }
    return *this;
}

GLSkeleton GLSkeleton::import(Skeleton MIOSkeleton)
{
    GLSkeleton retval;
    retval = MIOSkeleton;
    return retval;
}
