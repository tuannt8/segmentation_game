#-------------------------------------------------
#
# Project created by QtCreator 2015-04-21T10:31:10
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = segment_demo
TEMPLATE = app
CONFIG += c++11

#NDK_TOOLCHAIN_VERSION = clang


INCLUDEPATH += ./GEL
INCLUDEPATH += ./DSC

SOURCES += main.cpp\
        optionwindows.cpp \
    DSC/design_domain.cpp \
    DSC/DSC.cpp \
    DSC/object_generator.cpp \
    DSC/trializer.cpp \
    GEL/CGLA/ArithSqMat3x3Float.cpp \
    GEL/CGLA/ArithSqMat4x4Float.cpp \
    GEL/CGLA/ArithVec2Float.cpp \
    GEL/CGLA/ArithVec3Float.cpp \
    GEL/CGLA/eigensolution.cpp \
    GEL/CGLA/gel_rand.cpp \
    GEL/CGLA/Mat3x3d.cpp \
    GEL/CGLA/Mat3x3f.cpp \
    GEL/CGLA/Mat4x4d.cpp \
    GEL/CGLA/Mat4x4f.cpp \
    GEL/CGLA/statistics.cpp \
    GEL/CGLA/TableTrigonometry.cpp \
    GEL/CGLA/Vec2i.cpp \
    GEL/CGLA/Vec3f.cpp \
    GEL/CGLA/Vec3i.cpp \
    GEL/Geometry/AABox.cpp \
    GEL/Geometry/BBox.cpp \
    GEL/Geometry/BoundingINode.cpp \
    GEL/Geometry/BoundingLNode.cpp \
    GEL/Geometry/BoundingNode.cpp \
    GEL/Geometry/BoundingTree.cpp \
    GEL/Geometry/BSPTree.cpp \
    GEL/Geometry/build_bbtree.cpp \
    GEL/Geometry/geo_load.cpp \
    GEL/Geometry/geo_obj_load.cpp \
    GEL/Geometry/GradientFilter.cpp \
    GEL/Geometry/Implicit.cpp \
    GEL/Geometry/load_raw.cpp \
    GEL/Geometry/Neighbours.cpp \
    GEL/Geometry/OBox.cpp \
    GEL/Geometry/Polygonizer.cpp \
    GEL/Geometry/QEM.cpp \
    GEL/Geometry/rply_load.cpp \
    GEL/Geometry/tessellate.cpp \
    GEL/Geometry/ThreeDDDA.cpp \
    GEL/Geometry/Triangle.cpp \
    GEL/Geometry/TrilinFilter.cpp \
    GEL/Geometry/TriMesh.cpp \
    GEL/Geometry/verification.cpp \
    GEL/HMesh/cleanup.cpp \
    GEL/HMesh/ConnectivityKernel.cpp \
    GEL/HMesh/curvature.cpp \
    GEL/HMesh/dual.cpp \
    GEL/HMesh/flatten.cpp \
    GEL/HMesh/harmonics.cpp \
    GEL/HMesh/load.cpp \
    GEL/HMesh/Manifold.cpp \
    GEL/HMesh/mesh_optimization.cpp \
    GEL/HMesh/obj_load.cpp \
    GEL/HMesh/obj_save.cpp \
    GEL/HMesh/off_load.cpp \
    GEL/HMesh/off_save.cpp \
    GEL/HMesh/ply_load.cpp \
    GEL/HMesh/polygonize.cpp \
    GEL/HMesh/quadric_simplify.cpp \
    GEL/HMesh/refine_edges.cpp \
    GEL/HMesh/smooth.cpp \
    GEL/HMesh/subdivision.cpp \
    GEL/HMesh/triangulate.cpp \
    GEL/HMesh/x3d_load.cpp \
    GEL/HMesh/x3d_save.cpp \
    GEL/LinAlg/LapackFunc.cpp \
    GEL/LinAlg/LinAlgIO.cpp \
    GEL/Util/HashKey.cpp \
    GEL/Util/Parse.cpp \
    GEL/Util/string_utils.cpp \
    GEL/Util/XmlParser.cpp \
    GEL/Geometry/rply.c \
    openglwindow.cpp \
    SEGMENT/define.cpp \
    SEGMENT/dynamics_mul.cpp \
    SEGMENT/image.cpp \
    SEGMENT/helper.cpp \
    draw.cpp \
    SEGMENT/app_seg.cpp \
    SEGMENT/dsc_draw.cpp \
    myglwidget.cpp \
    window.cpp

HEADERS  += optionwindows.h \
    DSC/design_domain.h \
    DSC/DSC.h \
    DSC/object_generator.h \
    DSC/trializer.h \
    DSC/util.h \
    DSC/velocity_function.h \
    GEL/CGLA/ArithMatFloat.h \
    GEL/CGLA/ArithQuat.h \
    GEL/CGLA/ArithSqMat2x2Float.h \
    GEL/CGLA/ArithSqMat3x3Float.h \
    GEL/CGLA/ArithSqMat4x4Float.h \
    GEL/CGLA/ArithSqMatFloat.h \
    GEL/CGLA/ArithVec.h \
    GEL/CGLA/ArithVec2Float.h \
    GEL/CGLA/ArithVec3Float.h \
    GEL/CGLA/ArithVec3Int.h \
    GEL/CGLA/ArithVec4Float.h \
    GEL/CGLA/ArithVec4Int.h \
    GEL/CGLA/ArithVecFloat.h \
    GEL/CGLA/ArithVecInt.h \
    GEL/CGLA/BitMask.h \
    GEL/CGLA/CGLA.h \
    GEL/CGLA/eigensolution.h \
    GEL/CGLA/ExceptionStandard.h \
    GEL/CGLA/Mat2x2d.h \
    GEL/CGLA/Mat2x2f.h \
    GEL/CGLA/Mat2x3d.h \
    GEL/CGLA/Mat2x3f.h \
    GEL/CGLA/Mat3x3d.h \
    GEL/CGLA/Mat3x3f.h \
    GEL/CGLA/Mat4x4d.h \
    GEL/CGLA/Mat4x4f.h \
    GEL/CGLA/Quatd.h \
    GEL/CGLA/Quaternion.h \
    GEL/CGLA/Quatf.h \
    GEL/CGLA/statistics.h \
    GEL/CGLA/TableTrigonometry.h \
    GEL/CGLA/UnitVector.h \
    GEL/CGLA/Vec2d.h \
    GEL/CGLA/Vec2f.h \
    GEL/CGLA/Vec2i.h \
    GEL/CGLA/Vec2ui.h \
    GEL/CGLA/Vec3d.h \
    GEL/CGLA/Vec3f.h \
    GEL/CGLA/Vec3i.h \
    GEL/CGLA/Vec3uc.h \
    GEL/CGLA/Vec3usi.h \
    GEL/CGLA/Vec4d.h \
    GEL/CGLA/Vec4f.h \
    GEL/CGLA/Vec4i.h \
    GEL/CGLA/Vec4uc.h \
    GEL/Geometry/AABox.h \
    GEL/Geometry/AncestorGrid.h \
    GEL/Geometry/BBox.h \
    GEL/Geometry/BoundingINode.h \
    GEL/Geometry/BoundingLNode.h \
    GEL/Geometry/BoundingNode.h \
    GEL/Geometry/BoundingTree.h \
    GEL/Geometry/BSPTree.h \
    GEL/Geometry/build_bbtree.h \
    GEL/Geometry/Cell.h \
    GEL/Geometry/GradientFilter.h \
    GEL/Geometry/GridAlgorithm.h \
    GEL/Geometry/HGrid.h \
    GEL/Geometry/Implicit.h \
    GEL/Geometry/IndexedFaceSet.h \
    GEL/Geometry/KDTree.h \
    GEL/Geometry/load.h \
    GEL/Geometry/load_raw.h \
    GEL/Geometry/Material.h \
    GEL/Geometry/Neighbours.h \
    GEL/Geometry/obj_load.h \
    GEL/Geometry/OBox.h \
    GEL/Geometry/ply_load.h \
    GEL/Geometry/Polygonizer.h \
    GEL/Geometry/QEM.h \
    GEL/Geometry/Ray.h \
    GEL/Geometry/RGrid.h \
    GEL/Geometry/rply.h \
    GEL/Geometry/save_raw.h \
    GEL/Geometry/tessellate.h \
    GEL/Geometry/ThreeDDDA.h \
    GEL/Geometry/Triangle.h \
    GEL/Geometry/TrilinFilter.h \
    GEL/Geometry/TriMesh.h \
    GEL/Geometry/verification.h \
    GEL/Geometry/XForm.h \
    GEL/HMesh/AttributeVector.h \
    GEL/HMesh/cleanup.h \
    GEL/HMesh/ConnectivityKernel.h \
    GEL/HMesh/curvature.h \
    GEL/HMesh/dual.h \
    GEL/HMesh/flatten.h \
    GEL/HMesh/harmonics.h \
    GEL/HMesh/ItemID.h \
    GEL/HMesh/ItemVector.h \
    GEL/HMesh/Iterators.h \
    GEL/HMesh/load.h \
    GEL/HMesh/Manifold.h \
    GEL/HMesh/mesh_optimization.h \
    GEL/HMesh/obj_load.h \
    GEL/HMesh/obj_save.h \
    GEL/HMesh/off_load.h \
    GEL/HMesh/off_save.h \
    GEL/HMesh/ply_load.h \
    GEL/HMesh/polygonize.h \
    GEL/HMesh/quadric_simplify.h \
    GEL/HMesh/refine_edges.h \
    GEL/HMesh/smooth.h \
    GEL/HMesh/subdivision.h \
    GEL/HMesh/triangulate.h \
    GEL/HMesh/Walker.h \
    GEL/HMesh/x3d_load.h \
    GEL/HMesh/x3d_save.h \
    GEL/LinAlg/LapackFunc.h \
    GEL/LinAlg/LinAlgIO.h \
    GEL/LinAlg/Matrix.h \
    GEL/LinAlg/Vector.h \
    GEL/Util/ArgExtracter.h \
    GEL/Util/Grid2D.h \
    GEL/Util/HashKey.h \
    GEL/Util/HashTable.h \
    GEL/Util/Parse.h \
    GEL/Util/string_utils.h \
    GEL/Util/Timer.h \
    GEL/Util/XmlParser.h \
    openglwindow.h \
    SEGMENT/define.h \
    SEGMENT/dynamics_mul.h \
    SEGMENT/image.h \
    SEGMENT/CImg.h \
    SEGMENT/helper.h \
    draw.h \
    SEGMENT/app_seg.h \
    SEGMENT/dsc_draw.h \
    myglwidget.h \
    window.h

FORMS    += optionwindows.ui \
    window.ui

CONFIG += mobility
MOBILITY = 

DISTFILES +=

RESOURCES += \
    shaders.qrc \
    textures.qrc

