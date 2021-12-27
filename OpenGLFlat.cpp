#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace sf;

//int main()
//{
//	RenderWindow window(VideoMode(1080, 1080), "Lab 5");
//	glEnable(GL_TEXTURE_2D);
//	glClearColor(1, 1, 1, 1);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-10, 10, -10, 10, -10, 10);
//	glViewport(0, 0, 1080, 1080);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_COLOR_ARRAY);
//	GLfloat vertex[5][2] = {
//		{-1, 6},
//		{ 1, 6},
//		{ 1,-5},
//		{-1,-5},
//		{-8, 0}
//	};
//	GLfloat colorArray[5][3] = {
//		{1, 0, 0},
//		{0, 1, 0},
//		{0, 0, 1},
//		{1, 1, 0},
//		{0, 1, 1}
//	};
//	GLubyte triangleIndexArray[3] = { 0, 1, 2 };
//	GLubyte quadIndexArray[4] = { 0, 2, 3, 4 };
//	GLubyte lineIndexArray[6] = { 0, 1, 2, 3, 4, 0 };
//	GLubyte triangleArray2[3][3] = {
//		{1, 4, 0},
//		{4, 1, 2},
//		{2, 3, 4}
//	};
//
//	glVertexPointer(2, GL_FLOAT, 0, vertex);
//	glColorPointer(3, GL_FLOAT, 0, colorArray);
//	bool wire = false;
//	while (window.isOpen())
//	{
//		Event event;
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed) window.close();
//
//			if (event.type == Event::Resized) glViewport(0, 0, event.size.width, event.size.height);
//
//			if (event.type == Event::KeyPressed) {
//				switch (event.key.code) {
//				case Keyboard::Left:
//					glTranslatef(-1, 0, 0);
//					break;
//
//				case Keyboard::Right:
//					glTranslatef(1, 0, 0);
//					break;
//
//				case Keyboard::Up:
//					glTranslatef(0, 1, 0);
//					break;
//
//				case Keyboard::Down:
//					glTranslatef(0, -1, 0);
//					break;
//
//				case Keyboard::Add:
//					glScalef(1.1, 1.1, 1.1);
//					break;
//
//				case Keyboard::Subtract:
//					glScalef(0.9, 0.9, 0.9);
//					break;
//
//				case Keyboard::Q:
//					glRotatef(10, 0, 0, 1);
//					break;
//
//				case Keyboard::E:
//					glRotatef(-10, 0, 0, 1);
//					break;
//
//				case Keyboard::W:
//					glRotatef(10, 0, 1, 0);
//					break;
//
//				case Keyboard::S:
//					glRotatef(-10, 0, 1, 0);
//					break;
//
//				case Keyboard::Space:
//					wire = !wire;
//					break;
//
//				default:
//					break;
//				}
//			}
//		}
//
//		if (wire) glDrawElements(GL_LINE_STRIP, 6, GL_UNSIGNED_BYTE, lineIndexArray);
//		else glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_BYTE, triangleArray2);
//
//		window.display();
//	}
//
//	return 0;
//}