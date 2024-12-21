
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>		// include math class

#define WINDOW_TITLE "OpenGL Window"

int qNo = 1;			// Question No =1
float angle = 0.0;



LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
	


		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void demo() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	// Face 1 BOTTOM
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	// Face 2 LEFT
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	// Face 3
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	// Face 4
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	// Face 5
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	// Face 6
	glColor3f(1.0, 1.0, .0);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	glEnd();

}


void drawSphere(float r) {

	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, r, 30, 30);
	gluDeleteQuadric(sphere);


}

void drawCylinder(float br, float tr, float h) {

	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, br, tr, h, 10, 10);
	gluDeleteQuadric(cylinder);
}

void drawCone(float br, float h) {

	GLUquadricObj* cone = NULL;
	cone = gluNewQuadric();
	gluQuadricDrawStyle(cone, GLU_LINE);
	gluCylinder(cone, br, 0, h, 10, 10);
	gluDeleteQuadric(cone);
}

void drawCone2(float br, float h) {

	GLUquadricObj* cone = NULL;
	cone = gluNewQuadric();
	gluQuadricDrawStyle(cone, GLU_FILL);
	gluCylinder(cone, br, 0, h, 10, 10);
	gluDeleteQuadric(cone);
}


void drawDisk(float inr, float outr) {

	GLUquadricObj* disk = NULL;
	disk = gluNewQuadric();
	gluQuadricDrawStyle(disk, GLU_FILL);
	gluDisk(disk, inr, outr, 30, 30);
	gluDeleteQuadric(disk);
}


void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glLineWidth(0.1);
	angle += 0.01;

	if (angle > 360) {
		angle =0.0;
	}

	glPushMatrix();
	glRotatef(angle, 0.0, 0.1, 0);

	glPushMatrix();
	glTranslatef(0.2, 0.4, 0.0);
	glRotatef(45, 1.0, 0.0, 0);
	glColor3f(0.482, 0.247, 0);
	drawDisk(0.0, 0.15);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.2, 0.4, 0.0);
	glRotatef(45, 1.0, 0.0, 0);
	glColor3f(0.482, 0.247, 0);
	drawDisk(0.0, 0.15);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	drawSphere(0.25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	drawSphere(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.4, 0.0);
	glRotatef(-130, 0.8, 0.0, 0);
	glColor3f(0.482, 0.247, 0);
	drawCylinder(0.05, 0.05, 0.4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glRotatef(-110, 0.8, 0.0, 0);
	glColor3f(0.482, 0.247, 0);
	drawCylinder(0.05, 0.05, 0.6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glRotatef(-100, 0.8, 0.0, 0);
	glColor3f(0.482, 0.247, 0);
	drawCylinder(0.05, 0.05, 0.8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glColor3f(0.482, 0.247, 0);
	drawCone2(0.2, 0.4);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0);
	glColor3f(0.61, 0.48, 0.0);
	drawCone2(0.299, 0.799);
	glColor3f(1.0, 1.0, 1.0);
	drawCone(0.3, 0.8);
	glPopMatrix();

	glPopMatrix();

}

//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		1150, 10, 640, 640, NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//-------------------------------------------------------------------------------