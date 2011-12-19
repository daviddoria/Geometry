cmake_minimum_required(VERSION 2.6)

PROJECT(Geometry)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

FIND_PACKAGE(VXL REQUIRED)
INCLUDE(${VXL_CMAKE_DIR}/UseVXL.cmake)

set(PROJECTS /media/portable/Projects/src)

include_directories(${PROJECTS})

add_library(libGeometry
Angles.cpp
Color.cpp
Edge.cpp
Ray.cpp
Triangle.cpp
Transformation.cpp
LineSegment.cpp
OrientedPoint.cpp
Geometry.cpp
Helpers.cpp
)

ADD_EXECUTABLE(Test Test.cpp
${GeometrySources}
${PROJECTS}/VXLHelpers/VXLHelpers.cpp
${PROJECTS}/Tools/Tools.cpp
#${PROJECTS}/KDTree/KDTree.cpp
#${PROJECTS}/Octree/Octree.cpp
#${PROJECTS}/ModelFile/ModelFile.cpp
)

set(Libraries libGeometry
 vnl vnl_algo vil
 vgl vgl_algo
 vul
${VTK_LIBRARIES}
)

add_subdirectory(Tests)

target_link_libraries(Test ${Libraries})

