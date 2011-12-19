cmake_minimum_required(VERSION 2.6)

PROJECT(Geometry)
SUBDIRS(Tests)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

FIND_PACKAGE(VXL REQUIRED)
INCLUDE(${VXL_CMAKE_DIR}/UseVXL.cmake)

set(PROJECTS /media/portable/Projects/src)


INCLUDE_DIRECTORIES(${PROJECTS})

set(GeometrySources
${PROJECTS}/Geometry/Angles.cpp
${PROJECTS}/Geometry/Color.cpp 
${PROJECTS}/Geometry/Edge.cpp
${PROJECTS}/Geometry/Ray.cpp 
${PROJECTS}/Geometry/Triangle.cpp
${PROJECTS}/Geometry/Transformation.cpp
${PROJECTS}/Geometry/LineSegment.cpp
${PROJECTS}/Geometry/OrientedPoint.cpp
${PROJECTS}/Geometry/Geometry.cpp
${PROJECTS}/Geometry/Helpers.cpp
)
		
########################################
ADD_EXECUTABLE(Test Test.cpp
${GeometrySources}
${PROJECTS}/VXLHelpers/VXLHelpers.cpp
${PROJECTS}/SDLHelpers/SDLHelpers.cpp
${PROJECTS}/Tools/Tools.cpp
#${PROJECTS}/KDTree/KDTree.cpp
#${PROJECTS}/Octree/Octree.cpp
#${PROJECTS}/ModelFile/ModelFile.cpp
)

set(Libraries
 vnl vnl_algo vil
 vgl vgl_algo
 vul
glut GLU GL Xmu X11 
SDL SDL_image
vtkHybrid #for line segment drawing
)

TARGET_LINK_LIBRARIES(Test ${Libraries})

