#include "openglwindow.h"

#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>

#include <QtCore/qmath.h>

#include "DSC.h"
#include "trializer.h"
#include "SEGMENT/app_seg.h"
#include "optionwindows.h"

#include "SEGMENT/dsc_draw.h"
#include "openglwindow.h"
#include "window.h"

#include <QApplication>
#include <QDesktopWidget>


int main(int argc, char **argv)
{
//    QGuiApplication app(argc, argv);

//    QSurfaceFormat format;
//    format.setSamples(16);

//    QScreen *screen = app.screens().at(0);
//    int w = screen->size().width();
//    int h = screen->size().height();

//    OpenGLWindow window;
//    window.setFormat(format);
//    window.resize(w, h);
//    window.show();
//    window.setAnimating(true);

//    return app.exec();



    QApplication app(argc, argv);
    Window window;
    window.resize(window.sizeHint());
    int desktopArea = QApplication::desktop()->width() *
                     QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();

    window.setWindowTitle("OpenGL with Qt");

    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        window.show();
    else
        window.showMaximized();
    return app.exec();
}
