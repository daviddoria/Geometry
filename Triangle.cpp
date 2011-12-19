#include "Triangle.h"

#include <algorithm>

#include <vgl/vgl_point_3d.h>
#include <vgl/vgl_vector_3d.h>

#include <GL/glut.h>

#include <VXLHelpers/VXLHelpers.h>

//////////////// Operators /////////////////
ostream& operator << (ostream &output, const Triangle &T)
{
  output << "Triangle" << endl
	 << "--------" << endl
	 << "P1: " << T.getVertex(0) << endl
	 << "P2: " << T.getVertex(1) << endl
	 << "P3: " << T.getVertex(2) << endl;

  return output;
}

void Triangle::Draw(bool Normals, bool InMesh) const
{
	if(!InMesh)
	{
		if(!Normals)
		{
			glBegin(GL_TRIANGLES);
				glVertex3d(Vertices_[0].x(), Vertices_[0].y(), Vertices_[0].z());
				glVertex3d(Vertices_[1].x(), Vertices_[1].y(), Vertices_[1].z());
				glVertex3d(Vertices_[2].x(), Vertices_[2].y(), Vertices_[2].z());
			glEnd();
		}
		else
		{
			vgl_vector_3d<double> V1 = Vertices_[2] - Vertices_[0];
			vgl_vector_3d<double> V2 = Vertices_[1] - Vertices_[0];
			vgl_vector_3d<double> N = VXLHelpers::cross(V1, V2);
				
			N = normalize(N);
				
			glBegin(GL_TRIANGLES);
				glNormal3d(N.x(), N.y(), N.z());
				glVertex3d(Vertices_[0].x(), Vertices_[0].y(), Vertices_[0].z());
				glVertex3d(Vertices_[1].x(), Vertices_[1].y(), Vertices_[1].z());
				glVertex3d(Vertices_[2].x(), Vertices_[2].y(), Vertices_[2].z());
			glEnd(); 
		}
	}
	else //if the triangle is part of a mesh, dont call glBegin() again
	{
		if(!Normals)
		{
				
			glVertex3d(Vertices_[0].x(), Vertices_[0].y(), Vertices_[0].z());
			glVertex3d(Vertices_[1].x(), Vertices_[1].y(), Vertices_[1].z());
			glVertex3d(Vertices_[2].x(), Vertices_[2].y(), Vertices_[2].z());
		}
		else
		{
			vgl_vector_3d<double> V1 = Vertices_[2] - Vertices_[0];
			vgl_vector_3d<double> V2 = Vertices_[1] - Vertices_[0];
			vgl_vector_3d<double> N = VXLHelpers::cross(V1, V2);
				
			N = normalize(N);
				
			glNormal3d(N.x(), N.y(), N.z());
			glVertex3d(Vertices_[0].x(), Vertices_[0].y(), Vertices_[0].z());
			glVertex3d(Vertices_[1].x(), Vertices_[1].y(), Vertices_[1].z());
			glVertex3d(Vertices_[2].x(), Vertices_[2].y(), Vertices_[2].z());		
		}
	}
}

bool Triangle::PointInside(vgl_point_3d<double> &P) const
{
	 return vgl_triangle_3d_test_inside(P, Vertices_[0], Vertices_[1], Vertices_[2]);
}

double Triangle::DistanceToPoint(vgl_point_3d<double> &P) const
{
	return vgl_triangle_3d_distance(P , Vertices_[0], Vertices_[1], Vertices_[2]);
}
