//
//  define.h
//  DSC
//
//  Created by Tuan Nguyen Trung on 2/11/15.
//  Copyright (c) 2015 Asger Nyman Christiansen. All rights reserved.
//

#ifndef DSC_define_h
#define DSC_define_h

#include "DSC.h"
#include <string>
#include <vector>



/*********************************************************************/
/* Type def
 */
typedef DSC2D::vec2 Vec2;
typedef DSC2D::vec3 Vec3;
typedef DSC2D::DeformableSimplicialComplex dsc_obj;
typedef dsc_obj::node_key Node_key;
typedef dsc_obj::face_key Face_key;
typedef dsc_obj::edge_key Edge_key;
typedef std::vector<Vec2> Vec2_array;

struct dynamics_param{
    dynamics_param(){}
    dynamics_param(double a, double b, double m){alpha = a; beta = b; mass = m;}
    
    double alpha = 1.0; // Curvature
    double beta = 1.0; // Forth derivative. Keep the curve straight
    double mass = 10.0; // Display scale
    
    std::map<int, double> mean_intensity;
} ;

/*******
 Flags
 */

/*********************************************************************/
/* GLobal variable
 */
extern int debug_num[10];

// Image to load
extern std::string IMAGE_NAME;
// Dynamics parameter
extern dynamics_param g_param;

// Discretization
extern double DISCRETIZE_RES;


#endif // File protection
