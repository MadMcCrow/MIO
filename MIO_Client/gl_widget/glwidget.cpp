#include "glwidget.h"
#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QCoreApplication>
#include <math.h>



GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      m_xWorldRot(0),
      m_yWorldRot(0),
      m_zWorldRot(0),
      m_program(0),
      m_boneShape(new glcube),
      m_skeleton()
{

    m_core = QCoreApplication::arguments().contains(QStringLiteral("--coreprofile"));
    /// --transparent causes the clear color to be transparent. Therefore, on systems that
    /// support it, the widget will become transparent apart from the logo.
    m_transparent = QCoreApplication::arguments().contains(QStringLiteral("--transparent"));
    //m_transparent = true;
    if (m_transparent) {
        QSurfaceFormat fmt = format();
        fmt.setAlphaBufferSize(8);
        setFormat(fmt);
    }
}

GLWidget::~GLWidget()
{
    cleanup();
}


QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

/**
 * @brief qNormalizeAngle used for normalising the angle coming from the mouse.
 * @param angle
 */
static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

///@brief: the next 3 functions acts on world rotation.
///@remark: this is only for rotating the scene, so the update
/// and everything is a good thing.
void GLWidget::setXWorldRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xWorldRot) {
        m_xWorldRot = angle;
        emit xWorldRotationChanged(angle);
        update();
    }
}

void GLWidget::setYWorldRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yWorldRot) {
        m_yWorldRot = angle;
        emit yWorldRotationChanged(angle);
        update();
    }
}

void GLWidget::setZWorldRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_zWorldRot) {
        m_zWorldRot = angle;
        emit zWorldRotationChanged(angle);
        update();
    }
}


void GLWidget::cleanup()
{
    makeCurrent();
    m_vbo.destroy();
    delete m_program;
    m_program = 0;
    doneCurrent();
}

/**
 * @brief vertexShaderSourceCore - the Vertex shader if you're in core OpenGL
 * @see vertexShaderSource
 */
static const char *vertexShaderSourceCore =
    "#version 220\n"
    "in vec4 vertex;\n"
    "in vec3 normal;\n"
    "out vec3 vert;\n"
    "out vec3 vertNormal;\n"
    "out vec3 vertColor;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "uniform mat3 normalMatrix;\n"
    "void main() {\n"
    "   vert = vertex.xyz;\n"
    "   vertNormal = normalMatrix * normal;\n"
    "   vertColor = abs(normal);\n"
    "   gl_Position = projMatrix * mvMatrix * vertex;\n"
    "}\n";
/**
 * @brief fragmentShaderSourceCore - the Fragment shader if you're in core OpenGL
 * @see fragmentShaderSource
 */
static const char *fragmentShaderSourceCore =
    "#version 220\n"
    "in highp vec3 vert;\n"
    "in highp vec3 vertNormal;\n"
    "in highp vec3 vertColor;\n"
    "out highp vec4 fragColor;\n"
    "uniform highp vec3 lightPos;\n"
    "void main() {\n"
    "   highp vec3 L = normalize(lightPos - vert);\n"
    "   highp vec3 color = vertColor;\n"
    "   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
    "   highp vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);\n"
    "   fragColor = vec4(col, 1.0);\n"
    "}\n";
/**
 * @brief vertexShaderSource - the Vertex shader if you're in core OpenGL.
 * @remark made to find the best OpenGL version
 * @todo separate the shader GLSL from the cpp
 */
static const char *vertexShaderSource =
    "attribute vec4 vertex;\n"
    "attribute vec3 normal;\n"
    "varying vec3 vert;\n"
    "varying vec3 vertNormal;\n"
    "varying vec3 vertColor;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "uniform mat3 normalMatrix;\n"
    "void main() {\n"
    "   vert = vertex.xyz;\n"
    "   vertNormal = normalMatrix * normal;\n"
    "   vertColor = abs(normal);\n"
    "   gl_Position = projMatrix * mvMatrix * vertex;\n"
    "}\n";

/**
 * @brief fragmentShaderSource - the fragment shader if you're in core OpenGL.
 * @remark made to find the best OpenGL version
 * @todo separate the shader GLSL from the cpp
 */
static const char *fragmentShaderSource =
    "varying highp vec3 vert;\n"
    "varying highp vec3 vertNormal;\n"
    "varying highp vec3 vertColor;\n"
    "uniform highp vec3 lightPos;\n"
    "void main() {\n"
    "   highp vec3 L = normalize(lightPos - vert);\n"
    "   highp vec3 color = vertColor;\n"
    "   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
    "   highp vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);\n"
    "   gl_FragColor = vec4(col, 1.0);\n"
    "}\n";

void GLWidget::initializeGL()
{
    ///@remark: BEWARE THERE IS A CHANCE THAT QT KILLS US.
    /// be prepared and cleanup if we receive the "aboutToBeDestroyed()" signal
    /// read in detail for more info.
    // In this example the widget's corresponding top-level window can change
    // several times during the widget's lifetime. Whenever this happens, the
    // QOpenGLWidget's associated context is destroyed and a new one is created.
    // Therefore we have to be prepared to clean up the resources on the
    // aboutToBeDestroyed() signal, instead of the destructor. The emission of
    // the signal will be followed by an invocation of initializeGL() where we
    // can recreate all resources.
    connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &GLWidget::cleanup);

    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, m_transparent ? 0 : 1);

    // shader compiling
    m_program = new QOpenGLShaderProgram;
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, m_core ? vertexShaderSourceCore : vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, m_core ? fragmentShaderSourceCore : fragmentShaderSource);
    // you could add other attribute location but that would require modifying the glShape
    m_program->bindAttributeLocation("vertex", 0);
    m_program->bindAttributeLocation("normal", 1);
    m_program->link();

    ///@remark: linkink the variable to the shader for later fun
    m_program->bind();
    m_projMatrixLoc = m_program->uniformLocation("projMatrix");
    m_mvMatrixLoc = m_program->uniformLocation("mvMatrix");
    m_normalMatrixLoc = m_program->uniformLocation("normalMatrix");
    m_lightPosLoc = m_program->uniformLocation("lightPos");

    // Create a vertex array object. In OpenGL ES 2.0 and OpenGL 2.x
    // implementations this is optional and support may not be present
    // at all. Nonetheless the below code works in all cases and makes
    // sure there is a VAO when one is needed.
    m_vao.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

    // Setup our vertex buffer object.
    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(m_boneShape->constData(), m_boneShape->count() * sizeof(GLfloat));

    // Store the vertex attribute bindings for the program.
    setupVertexAttribs();

    // Here is the camera operations
    m_camera.setToIdentity();
    m_camera.translate(0, 0, -10);

    // Light position is fixed.
    m_program->setUniformValue(m_lightPosLoc, QVector3D(0, 0, 30));

    m_program->release();
}

///@brief: this functions seems to activate the access to the vertexAttribArray (AFAIK)
void GLWidget::setupVertexAttribs()
{
    m_vbo.bind();
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    f->glEnableVertexAttribArray(0); ///@remark vertex position
    f->glEnableVertexAttribArray(1); ///@remark vertex normal

    ///@remark reminder :glVertexAttribPointer(attribute, dimensions, type, normalize,vertex size, interlacing);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
    f->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), reinterpret_cast<void *>(3 * sizeof(GLfloat)));

    ///@remark now that vertex
    m_vbo.release();
}

void GLWidget::glDrawBone(){
    for(const auto &bone : m_skeleton)
    {
    m_world.setToIdentity();
    ///setting up the view from the camera: that's not the camera that rotate, that's the whole world.
    m_world.rotate(180.0f - (m_xWorldRot / 16.0f), 1, 0, 0);
    m_world.rotate(m_yWorldRot / 16.0f, 0, 1, 0);
    m_world.rotate(m_zWorldRot / 16.0f, 0, 0, 1);
    /// and we get the correct transform matrix from our bone.
    m_world *= bone;
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);
    m_program->bind();
    m_program->setUniformValue(m_projMatrixLoc, m_proj);
    m_program->setUniformValue(m_mvMatrixLoc, m_camera * m_world);
    QMatrix3x3 normalMatrix = m_world.normalMatrix();
    m_program->setUniformValue(m_normalMatrixLoc, normalMatrix);
    glDrawArrays(GL_TRIANGLES, 0, m_boneShape->vertexCount());
    m_program->release();
    }
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glDrawBone();
}

void GLWidget::resizeGL(int w, int h)
{
    m_proj.setToIdentity();
    m_proj.perspective(45.0f, GLfloat(w) / h, 0.01f, 100.0f);
}


void GLWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}


void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - m_lastPos.x();
    int dy = event->y() - m_lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXWorldRotation(m_xWorldRot + 8 * dy);
        setYWorldRotation(m_yWorldRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXWorldRotation(m_xWorldRot + 8 * dy);
        setZWorldRotation(m_zWorldRot + 8 * dx);
    }
    m_lastPos = event->pos();
}

void GLWidget::updateSkeleton_c(GLSkeleton sk)
{
    m_skeleton = sk;
}
