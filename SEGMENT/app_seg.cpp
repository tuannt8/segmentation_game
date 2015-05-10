#include "app_seg.h"
#include "trializer.h"
#include "object_generator.h"

using namespace DSC2D;

app_seg::app_seg()
{

}

app_seg::~app_seg()
{

}

int app_seg::generate_dsc(double width, double height, int res)
{
    double DISCRETIZATION = (double) height / res;

    width -= 2*DISCRETIZATION;
    height -= 2*DISCRETIZATION;

    std::vector<double> points;
    std::vector<int> faces;
    Trializer::trialize(width, height, DISCRETIZATION, points, faces);

    DesignDomain *domain = new DesignDomain(DesignDomain::RECTANGLE, width, height, DISCRETIZATION);

    dsc_ = std::shared_ptr<dsc_obj>(
                new dsc_obj(DISCRETIZATION, points, faces, domain));
    return 0;
}

void app_seg::get_face_draw(GLfloat * v, GLfloat *color){

}

