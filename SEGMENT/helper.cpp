//
//  helper.cpp
//  DSC
//
//  Created by Tuan Nguyen Trung on 2/12/15.
//  Copyright (c) 2015 Asger Nyman Christiansen. All rights reserved.
//

#include "helper.h"

float helper_t::sign(Vec2 p1, Vec2 p2, Vec2 p3){
    return (p1[0] - p3[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p3[1]);
}
bool helper_t::is_point_in_tri(Vec2 pt, Vec2 t1, Vec2 t2, Vec2 t3){
    bool b1, b2, b3;
    b1 = sign(pt, t1, t2) < 0.0f;
    b2 = sign(pt, t2, t3) < 0.0f;
    b3 = sign(pt, t3, t1) < 0.0f;
    
    return ((b1 == b2) && (b2 == b3));
}

bool helper_t::is_point_in_tri(Vec2 p, std::vector<Vec2> const & pts){
    return is_point_in_tri(p, pts[0], pts[1], pts[2]);
}

namespace helper_t {
    Vec3 autoColor::next(){
        static std::vector<Vec3> colorList =
        {
            Vec3(1,0,0)     // red
            ,Vec3(0,1,0)    // green
            , Vec3(0,0,1)  // Blue
            , Vec3(1, 1, 0)
            , Vec3(1, 0, 1)
            , Vec3(0, 1, 1)
            , Vec3(0.3, 0.3, 0.3)
        };
        
        return colorList[index++];
    }
}