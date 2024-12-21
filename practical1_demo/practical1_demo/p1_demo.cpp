
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>		// include math class

#define WINDOW_TITLE "OpenGL Window"

int qNo = 1;			// Question No =1
float x = 0, y = 0;		// Origin of circle(x,y) = (0,0)
float radius = 0.3;		// radius
float angle = 0;		// angle
float x2 = 0, y2 = 0;	// Origin of circle(x2,y2)
float PI = 3.142;			// PI
int noOfTri = 31;		// no of triangles


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
		else if (wParam == 0x31)		//when press key '1'
			qNo = 1;
		else if (wParam == 0x32)		//when press key '2'
			qNo = 2;
		else if (wParam == 0x33)		//when press key '3'
			qNo = 3;
		else if (wParam == 0x34)		//when press key '4'
			qNo = 4;
		else if (wParam == 0x35)		//when press key '5'
			qNo = 5;
		else if (wParam == 0x36)		//when press key '6'
			qNo = 6;
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

void pahangFlag()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2.0);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.8, 0.5);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, -0.5);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.8, 0.0);
	glVertex2f(0.8, 0.0);
	glVertex2f(0.8, -0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.8, 0.5);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, -0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.8, 0.5);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, -0.5);
	glEnd();



}

void negeriSembilanFlag()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-0.8, 0.5);
	glVertex2f(-0.8, -0.5);
	glVertex2f(0.8,-0.5);
	glVertex2f(0.8, 0.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.8, 0.5);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.8, 0.5);
	glVertex2f(-0.8, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.8, 0.5);
	glVertex2f(-0.8, -0.5);
	glVertex2f(0.8, -0.5);
	glVertex2f(0.8, 0.5);
	glEnd();

}

void englandFlag()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.8, 0.5);
	glVertex2f(-0.8, -0.5);
	glVertex2f(0.8, -0.5);
	glVertex2f(0.8, 0.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.1, 0.1);
	glVertex2f(0.1, 0.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.8, 0.5);
	glVertex2f(-0.8, 0.1);
	glVertex2f(-0.1, 0.1);
	glVertex2f(-0.1, 0.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.8, -0.5);
	glVertex2f(0.8, -0.1);
	glVertex2f(0.1, -0.1);
	glVertex2f(0.1, -0.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.8, -0.1);
	glVertex2f(-0.1, -0.1);
	glVertex2f(-0.1, -0.5);
	glEnd();


}

void scotlandFlag()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.8, 0.5);
	glVertex2f(-0.8, -0.5);
	glVertex2f(0.8, -0.5);
	glVertex2f(0.8, 0.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.6, 0.5);
	glVertex2f(-0.6, 0.5);
	glVertex2f(0.0, 0.1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.6, -0.5);
	glVertex2f(-0.6, -0.5);
	glVertex2f(0.0, -0.1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.8, 0.4);
	glVertex2f(0.8, -0.4);
	glVertex2f(0.2, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.8, 0.4);
	glVertex2f(-0.8, -0.4);
	glVertex2f(-0.2, 0.0);
	glEnd();


}

void japanFlag()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.8, 0.5);
	glVertex2f(-0.8, -0.5);
	glVertex2f(0.8, -0.5);
	glVertex2f(0.8, 0.5);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x, y);			// origin of circle
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = x + radius * cos (angle);
		y2 = y + radius * sin (angle);
		glVertex2f(x2, y2);
	}

	glEnd();

}



void emoji()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(3.0);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, -0.4);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0.0 + 0.4 * cos(angle);
		y2 = -0.4 + 0.3 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);;
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0.0 + 0.4 * cos(angle);
		y2 = -0.4 + 0.3 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(x, y);	
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = x + 0.6 * cos(angle);
		y2 = y + 0.6 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = x + 0.6 * cos(angle);
		y2 = y + 0.6 * sin(angle);
		glVertex2f(x2, y2);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0, 0);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0 + 0.5 * cos(angle);
		y2 = -0.1 + 0.5 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0 + 0.5 * cos(angle);
		y2 = -0.1 + 0.5 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0.15 + 0.15 * cos(angle);
		y2 = 0.15 + 0.2 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = -0.15 + 0.15 * cos(angle);
		y2 = 0.15 + 0.2 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.15, 0.15);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0.1 + 0.05 * cos(angle);
		y2 = 0.15 + 0.1 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.15, 0.15);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = -0.1 + 0.05 * cos(angle);
		y2 = 0.15 + 0.1 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);

	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, -0.4);
	
	glVertex2f(0.35, 0.0);
	glVertex2f(0.2, -0.1);

	glVertex2f(0.4, -0.2);
	glVertex2f(0.2, -0.2);

	glVertex2f(0.35, -0.4);
	glVertex2f(0.2, -0.3);

	glVertex2f(-0.35, 0.0);
	glVertex2f(-0.2, -0.1);

	glVertex2f(-0.4, -0.2);
	glVertex2f(-0.2, -0.2);

	glVertex2f(-0.35, -0.4);
	glVertex2f(-0.2, -0.3);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, -0.1);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0 + 0.1 * cos(angle);
		y2 = -0.1 + 0.1 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();


	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0 + 0.1 * cos(angle);
		y2 = -0.1 + 0.1 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, -0.35);
	for (angle = PI; angle <= 2 * PI; angle += PI / noOfTri) {
		x2 = 0 + 0.2 * cos(angle);
		y2 = -0.35 + 0.2 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();


	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	for (angle = PI; angle <= 2 * PI; angle += PI / noOfTri) {
		x2 = 0 + 0.2 * cos(angle);
		y2 = -0.35 + 0.2 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.0, -0.7);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0.0 + 0.1 * cos(angle);
		y2 = -0.7 + 0.1 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.0, -0.7);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0.0 + 0.03 * cos(angle);
		y2 = -0.7 + 0.03 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	for (angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTri) {
		x2 = 0.0 + 0.1 * cos(angle);
		y2 = -0.7 + 0.1 * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);

	glVertex2f(0.0, -0.7);
	glVertex2f(0.0, -0.8);

	glEnd();



}



void display()
{
	switch (qNo)
	{
	case 1:
		pahangFlag();
		break;
	case 2:
		negeriSembilanFlag();
		break;
	case 3:
		englandFlag();
		break;
	case 4:
		scotlandFlag();
		break;
	case 5:
		japanFlag(); 
		break;
	case 6:
		emoji();
		break;

	default:
		pahangFlag();
		break;
	}


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
		1150, 10, 640, 640,
		NULL, NULL, wc.hInstance, NULL);

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
//--------------------------------------------------------------------