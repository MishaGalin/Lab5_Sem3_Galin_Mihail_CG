#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1080, 1080), "Lab 5");

	GLfloat cubeColor[8][3] = {
		1, 1, 0,
		0, 1, 0,
		0, 0, 1,
		1, 1, 0,
		0, 1, 1,
		1, 0, 1,
		0.5, 0.5, 0.5,
		1, 1, 1,
	};
	GLfloat pyramidColor[10][3] = {
		0.5, 0.25, 1,
		0.25, 1, 0.25,
		1, 0.25, 0.5,
		0, 0, 1,
		0, 1, 0,
		1, 0, 0,
		1, 1, 0,
		0, 1, 1,
		0.5, 0.5, 0.5
	};
	GLint cubeVertex[8][3] = {
		-1,-1,-1,
		-1,-1, 1,
		-1, 1,-1,
		-1, 1, 1,
		 1,-1,-1,
		 1,-1, 1,
		 1, 1,-1,
		 1, 1, 1
	};
	GLuint cubeFace[6][4] = {
		1, 5, 7, 3,
		5, 4, 6, 7,
		4, 0, 2, 6,
		3, 2, 0, 1,
		3, 7, 6, 2,
		4, 5, 1, 0
	};

	GLfloat pyramidVertex[7][3]{};
	GLuint pyramidFaces[10][3]{};
	pyramidVertex[0][0] = 0;
	pyramidVertex[0][1] = 1;
	pyramidVertex[0][2] = 0;
	for (int i = 0; i < 6; i++) {
		pyramidVertex[i + 1][0] = cos(M_PI / 3 * i);
		pyramidVertex[i + 1][2] = sin(M_PI / 3 * i);
		pyramidVertex[i + 1][1] = 0;
	}
	for (int i = 1; i <= 6; i++) {
		pyramidFaces[i - 1][1] = i;
		pyramidFaces[i - 1][2] = i % 6 + 1;
		pyramidFaces[i - 1][0] = 0;
	}
	for (int i = 1; i < 6; i += 2) {
		pyramidFaces[6 + i / 2][2] = i;
		pyramidFaces[6 + i / 2][1] = i % 6 + 1;
		pyramidFaces[6 + i / 2][0] = (i + 1) % 6 + 1;
	}

	pyramidFaces[9][0] = 5;
	pyramidFaces[9][1] = 3;
	pyramidFaces[9][2] = 1;

	window.setVerticalSyncEnabled(true);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-10, 10, -10, 10, -10, 10);
	glViewport(0, 0, 1080, 1080);
	glShadeModel(GL_FLAT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_CULL_FACE);
	glScalef(0.4, 0.4, 0.4);

	while (window.isOpen())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::KeyPressed:
				switch (event.key.code) {
				case Keyboard::Left:
					glTranslatef(-0.1, 0, 0);
					break;

				case Keyboard::Right:
					glTranslatef(0.1, 0, 0);
					break;

				case Keyboard::Up:
					glTranslatef(0, 0.1, 0);
					break;

				case Keyboard::Down:
					glTranslatef(0, -0.1, 0);
					break;

				case Keyboard::Add:
					glScalef(1.1, 1.1, 1.1);
					break;

				case Keyboard::Subtract:
					glScalef(0.9, 0.9, 0.9);
					break;

				case Keyboard::Q:
					glRotatef(10, 0, 0, 1);
					break;

				case Keyboard::E:
					glRotatef(-10, 0, 0, 1);
					break;

				case Keyboard::W:
					glRotatef(10, 0, 1, 0);
					break;

				case Keyboard::S:
					glRotatef(-10, 0, 1, 0);
					break;

				case Keyboard::A:
					glRotatef(10, 1, 0, 0);
					break;

				case Keyboard::D:
					glRotatef(-10, 1, 0, 0);
					break;

				default:
					break;
				}
				break;

			case Event::MouseWheelScrolled:
				if (event.mouseWheelScroll.wheel == Mouse::VerticalWheel) {
					double approach = event.mouseWheelScroll.delta > 0 ? 1.1 : 0.9;
					glScalef(approach, approach, approach);
				}
				break;

			default:
				break;
			}
		}
		glPushMatrix();
		glTranslatef(1, 0, 0);
		glScalef(0.8, 0.8, 0.8);
		glColorPointer(3, GL_FLOAT, 0, cubeColor);
		glVertexPointer(3, GL_INT, 0, cubeVertex);

		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, cubeFace);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1, 0, 0);
		glScalef(0.8, 0.8, 0.8);
		glColorPointer(3, GL_FLOAT, 0, pyramidColor);
		glVertexPointer(3, GL_FLOAT, 0, pyramidVertex);
		glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, pyramidFaces);
		glPopMatrix();

		window.display();
	}
}