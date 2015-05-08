#ifndef APP_H
#define APP_H

#include "DSC.h"
#include "define.h"

class app_seg
{
public:
    app_seg();
    ~app_seg();

    int generate_dsc(int res = 5);

private:
    dsc_obj *dsc_;
};

#endif // APP_H
