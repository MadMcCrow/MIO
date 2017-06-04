#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include "glshape.h"
#include "glcube.h"
#include "glskeleton.h"

///@remark thi is necessary for the correct use of the shaders
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

/**
 * @brief The GLWidget class - Does it all.
 * @remark not thread safe. Should be run from main thread.
 * @todo replace m_skeleton by m_skeletons (vector of Skeletons)
 * @todo add signals and slot for content change
 * @todo set the shaders inside the ".h" file for ease of lecture.
 */
class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();
    ///@remark built in methods by Qt Team (not used)
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    /**
     * @brief setSkeleton - modify the content of m_skeleton
     * @param MIOSkeleton a Skeleton built the MIO way
     */
    void setSkeleton(Skeleton MIOSkeleton){m_skeleton = MIOSkeleton;}


    /**
     * @brief setSkeleton - modify the content of m_skeleton
     * @param Skeleton
     */
    void setSkeleton(GLSkeleton Skeleton){m_skeleton = Skeleton;}

    /**
     * @brief getSkeleton - get the Skeleton content
     * @return
     */
    const GLSkeleton getSkeleton(){return m_skeleton;}

public slots:
    ///@remark built-in slots by Qt Team(rotate the scene)
    void setXWorldRotation(int angle);
    void setYWorldRotation(int angle);
    void setZWorldRotation(int angle);
    void cleanup();

    /**
     * @brief updateSkeleton_c  - a custom slot for updating the skeleton
     */
    void updateSkeleton_c(GLSkeleton);

signals:
    ///@remark built-in signals by Qt Team(scene has rotated)
    void xWorldRotationChanged(int angle);
    void yWorldRotationChanged(int angle);
    void zWorldRotationChanged(int angle);

protected:
    ///@remark You guessed it. this was just modified to fit our needs ;)
    void initializeGL() override;
    void paintGL() override;   ///<@brief refresh the screen
    void resizeGL(int width, int height) override; ///<@brief resize the viewport
    void mousePressEvent(QMouseEvent *event) override; ///<@brief used for click-dragging
    void mouseMoveEvent(QMouseEvent *event) override;  ///<@brief used for click-dragging

private:
    /**
     * @brief glDrawBone - draw the data stocked in m_skeleton
     * called in paintGL()
     */
    void glDrawBone();

    /**
     * @brief setupVertexAttribs
     */
    void setupVertexAttribs();
    bool m_core;                    ///<@brief what version of OpenGL (core or standard)
    int m_xWorldRot;                ///<@brief whole world x rotation. used for rotating the view
    int m_yWorldRot;                ///<@brief whole world y rotation. used for rotating the view
    int m_zWorldRot;                ///<@brief whole world z rotation. used for rotating the view
    QPoint m_lastPos;               ///<@brief mouse last position.
    QOpenGLVertexArrayObject m_vao; ///<@brief the VAO. we use it to store the vertex data
    QOpenGLBuffer m_vbo;            ///<@brief the VBO. we don't use it (but we could)
    QOpenGLShaderProgram *m_program;///<@brief the compiled shader program
    int m_projMatrixLoc;            ///<@brief P   input to the GLSL
    int m_mvMatrixLoc;              ///<@brief MV  input to the GLSL
    int m_vMatrixLoc;               ///<@brief V   input to the GLSL
    int m_normalMatrixLoc;          ///<@brief NormalVector input to the GLSL
    int m_lightPosLoc;              ///<@brief light input to the GLSL
    QMatrix4x4 m_proj;              ///<@brief P
    QMatrix4x4 m_camera;            ///<@brief EYE (V)
    QMatrix4x4 m_model;             ///<@brief M
    QMatrix4x4 m_world;             ///<@brief World rotation/scale (transform everything)
    glshape* m_boneShape;           ///<@brief the bone shape we're gonna use.
    GLSkeleton m_skeleton;          ///<@brief the skeleton (@see #GLSkeleton)
    bool m_transparent = true;      ///<@brief if the background is transparent or not.(aplha of the background)
};

#endif
