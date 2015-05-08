#ifndef DRAW_H
#define DRAW_H

#include "openglwindow.h"

class draw: public OpenGLWindow
{
public:
    draw();
    ~draw();

    void initialize() Q_DECL_OVERRIDE;
    void render() Q_DECL_OVERRIDE;

private:
    GLuint loadShader(GLenum type, const char *source);

    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QOpenGLShaderProgram *m_program;
    int m_frame;
};

#endif // DRAW_H
