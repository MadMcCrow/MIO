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

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

/**
 * @brief The GLWidget class - Does it all.
 */
class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    ///@remark built-in classes by Qt Team
    void setXWorldRotation(int angle);
    void setYWorldRotation(int angle);
    void setZWorldRotation(int angle);
    void cleanup();
    ///@remark just for fun
    void setRColor(float r);
    void setGColor(float g);
    void setBColor(float b);

signals:
    ///@remark built-in classes by Qt Team
    void xWorldRotationChanged(int angle);
    void yWorldRotationChanged(int angle);
    void zWorldRotationChanged(int angle);

    ///@remark just for fun
    void rColorChanged(float color);
    void gColorChanged(float color);
    void bColorChanged(float color);
protected:
    ///@remark You guessed it. this was just modified to fit our needs ;)
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void glDrawBone();
    void setupVertexAttribs();
    bool m_core;
    int m_xWorldRot;
    int m_yWorldRot;
    int m_zWorldRot;
    QPoint m_lastPos;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLShaderProgram *m_program;
    QVector3D m_rgbColor;
    int m_colorLoc;
    int m_projMatrixLoc;
    int m_mvMatrixLoc;
    int m_vMatrixLoc;
    int m_normalMatrixLoc;
    int m_lightPosLoc;
    QMatrix4x4 m_proj;
    QMatrix4x4 m_camera;
    QMatrix4x4 m_model;
    QMatrix4x4 m_world;
    glshape* m_boneShape;
    GLSkeleton m_skeleton;
    bool m_transparent;
};

#endif
