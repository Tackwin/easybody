#include "Graphics.hpp"

#include <math.h>
#include <SDL_opengl.h>
#include <GL/glut.h>

void graphic::render(const Camera& camera, const Orders& orders) noexcept {

	glLoadIdentity();
	gluPerspective(70, 1, 0.1, 100);
	gluLookAt(
		camera.x, camera.y, camera.z,
		camera.x + camera.lx, camera.y + camera.ly, camera.z + camera.lz,
		0.0f, 1.0f,  0.0f
	);

	double pi = 3.141592;
    double di =0.1;
    double dj =0.1;
    double du =di*2*pi;
    double dv =dj*pi;


	for (auto& s : orders.spheres) {
		for (double i = 0; i < 1.0; i+=di)  //horizonal
			for (double j = 0; j < 1.0; j+=dj)  //vertical
			{       
				double u = i*2*pi;      //0     to  2pi
				double v = (j-0.5)*pi;  //-pi/2 to pi/2

				double  p[][3] = {
					s.x + cos(v) * cos(u) * s.radius,
						s.y + cos(v) * sin(u) * s.radius,
							s.z + sin(v) * s.radius,

					s.x + cos(v) * cos(u + du) * s.radius,
						s.y + cos(v) * sin(u + du) * s.radius,
							s.z + sin(v) * s.radius,

					s.x + cos(v + dv) * cos(u + du) * s.radius,
						s.y + cos(v + dv) * sin(u + du) * s.radius,
							s.z + sin(v + dv) * s.radius,

					s.x + cos(v + dv)* cos(u) * s.radius,
						s.y + cos(v + dv) * sin(u) * s.radius,
							s.z + sin(v + dv) * s.radius
				};

				//normal
				glNormal3d(cos(v+dv/2)*cos(u+du/2),cos(v+dv/2)*sin(u+du/2),sin(v+dv/2));

				glBegin(GL_POLYGON);
					glTexCoord2d(i,   j);    glVertex3dv(p[0]);
					glTexCoord2d(i+di,j);    glVertex3dv(p[1]);
					glTexCoord2d(i+di,j+dj); glVertex3dv(p[2]);
					glTexCoord2d(i,   j+dj); glVertex3dv(p[3]);
				glEnd();
			}
	}
}
