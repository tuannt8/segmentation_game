// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include <QtCore/QCoreApplication>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>
#include <QOpenGLContext>


#include "myglwidget.h"

using namespace std;

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
      , m_update_pending(false)
      , m_animating(false)
      , m_context(0)
      , m_device(0)
      , m_program(0)
      , m_frame(0)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
}

MyGLWidget::~MyGLWidget()
{
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void MyGLWidget::setXRotation(int angle)
{
//    qNormalizeAngle(angle);
//    if (angle != xRot) {
//        xRot = angle;
//        emit xRotationChanged(angle);
//        updateGL();
//    }
}

void MyGLWidget::setYRotation(int angle)
{
//    qNormalizeAngle(angle);
//    if (angle != yRot) {
//        yRot = angle;
//        emit yRotationChanged(angle);
//        updateGL();
//    }
}

void MyGLWidget::setZRotation(int angle)
{
//    qNormalizeAngle(angle);
//    if (angle != zRot) {
//        zRot = angle;
//        emit zRotationChanged(angle);
//        updateGL();
//    }
}

void MyGLWidget::initializeGL()
{
#ifdef MOBILE_OS
    static const char *vertexShaderSource =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";

    static const char *fragmentShaderSource =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_colAttr = m_program->attributeLocation("colAttr");
    m_matrixUniform = m_program->uniformLocation("matrix");
#else
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
#endif

    m_app_seg.generate_dsc(width(), height(), 3);
}

#ifdef MOBILE_OS
GLuint MyGLWidget::loadShader(GLenum type, const char *source){
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, 0);
    glCompileShader(shader);
    return shader;
}
#endif

void MyGLWidget::paintGL()
{
#ifdef MOBILE_OS


    bool needsInitialize = false;

//    if (!m_context) {
//        m_context = new QOpenGLContext(this);
//        m_context->setFormat(requestedFormat());
//        m_context->create();

//        needsInitialize = true;
//    }

//    m_context->makeCurrent(this);

//    if (needsInitialize) {
//        initializeOpenGLFunctions();
//        initialize();
//    }

    draw();

//    m_context->swapBuffers(this);

//    if (m_animating)
//        renderLater();
#else
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    draw();
#endif
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
#ifdef MOBILE_OS

#else /*  MOBILE_OS */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
#endif /* ELSE MOBILE_OS */
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::draw()
{
#ifdef MOBILE_OS
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT);


    m_program->bind();

    QMatrix4x4 matrix;
 // matrix.perspective(60.0f, 4.0f/3.0f, 0.1f, 100.0f);
  //  matrix.translate(0, 0, -2);


    matrix.ortho(0.0f,width(), 0.f,height(), -1, 1);
    m_program->setUniformValue(m_matrixUniform, matrix);

    GLfloat vertices[] = {
        0.0f, 0.f,
        0.0f, 100.f,
        100.0f, 0.0f,
        100.0f, 0.f,
        100.0f, 100.f,
        200.0f, 0.0f
    };

    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };


    auto obj = m_app_seg.get_dsc_obj();

    static GLfloat vptr[100000];// = new GLfloat[obj.get_no_faces()*3*2];
    static GLfloat cptr[100000];// = new GLfloat[obj.get_no_faces()*3*3];

    int idx = 0;
    for(auto fkey : obj->faces()){
        auto tris = obj->get_pos(fkey);
        for(int i = 0; i < 3; i++){
            auto v = tris[i];

            vptr[idx*6 + i*2 + 0] = v[0];
            vptr[idx*6 + i*2 + 1] = v[1];

            cptr[idx*9 + i*3 + 0] = v[0]/600.f;
            cptr[idx*9 + i*3 + 1] = v[0]/600.f;
            cptr[idx*9 + i*3 + 2] = v[0]/600.f;
        }
        idx ++;
    }


//    for(int i = 0; i < obj.get_no_faces()*3; i++){
//        printf("%f %f %f %f %f\n", vptr[i*2], vptr[i*2 + 1],
//                        cptr[i*3], cptr[i*3 + 1], cptr[i*3 + 2]);
//    }


    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vptr);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, cptr);

//    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
//    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    int num = obj->get_no_faces();
    cout << num;

    glDrawArrays(GL_TRIANGLES, 0, num*3);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    m_program->release();


    ++m_frame;
    printf("Display: %d \n", m_frame);
#else
    qglColor(Qt::red);
    glBegin(GL_QUADS);
        glNormal3f(0,0,-1);
        glVertex3f(-1,-1,0);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,-1,0);

    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(0,-1,0.707);
        glVertex3f(-1,-1,0);
        glVertex3f(1,-1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(1,0, 0.707);
        glVertex3f(1,-1,0);
        glVertex3f(1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(0,1,0.707);
        glVertex3f(1,1,0);
        glVertex3f(-1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(-1,0,0.707);
        glVertex3f(-1,1,0);
        glVertex3f(-1,-1,0);
        glVertex3f(0,0,1.2);
    glEnd();
#endif
}
