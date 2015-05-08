#ifndef DSC_DRAW_H
#define DSC_DRAW_H

#include "openglwindow.h"

class dsc_draw: public OpenGLWindow
{
public:
    dsc_draw();
    ~dsc_draw();

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

#endif // DSC_DRAW_H
