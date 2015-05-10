// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include "SEGMENT/app_seg.h"

#include <QtGui/QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QScreen>

#ifdef _WIN64
   //define something for Windows (64-bit)
#elif _WIN32
   //define something for Windows (32-bit)
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE && TARGET_IPHONE_SIMULATOR
        // define something for simulator
        #define MOBILE_OS
    #elif TARGET_OS_IPHONE
        // define something for iphone
        #define MOBILE_OS
    #else
        #define TARGET_OS_OSX 1
        // define something for OSX
        #define DESKTOP_OS
    #endif
#elif __linux
    // linux
#elif __unix // all unices not caught above
    // Unix
#elif __posix
    // POSIX
#endif

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;


#include <QGLWidget>
#include "SEGMENT/define.h"


class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:
    void draw();

    int xRot;
    int yRot;
    int zRot;

    QPoint lastPos;

#ifdef MOBILE_OS
private:
    bool m_update_pending;
    bool m_animating;

    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;

    GLuint loadShader(GLenum type, const char *source);

    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QOpenGLShaderProgram *m_program;
    int m_frame;

#endif

    app_seg m_app_seg;
};

#endif // MYGLWIDGET_H

