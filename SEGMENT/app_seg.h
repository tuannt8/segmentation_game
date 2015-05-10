#ifndef APP_H
#define APP_H

#include "DSC.h"
#include "define.h"
#include "qgl.h"

class app_seg
{
public:
    app_seg();
    ~app_seg();

    int generate_dsc(double width, double height, int res = 5);
    std::shared_ptr<dsc_obj> get_dsc_obj(){return dsc_;}

public:
    void get_face_draw(GLfloat * v, GLfloat *color);

private:
    std::shared_ptr<dsc_obj> dsc_;
};

#endif // APP_H
