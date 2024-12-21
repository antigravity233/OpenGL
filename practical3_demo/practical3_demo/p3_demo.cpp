
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>		// include math class

#define WINDOW_TITLE "OpenGL Window"

int qNo = 1;			// Question No =1
float tx1 = 0, tx2 = 0, ty1 = 0, ty2 = 0, tSpeed = 0.1;	// translate x and y
float r = 0.0, g = 0.0, b = 0.0;
float angle = 0.0, rSpeed = 0.001;
float radius = 0.7;		// radius
float PI = 3.142;			// PI
int noOfTri = 31;		// no of triangles
float x1 = 0.0;
float x2 = 0.5;





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
		else if (wParam == VK_LEFT) {		//when press key LEFT arrow key
			tx1 -= tSpeed;
			tx2 += tSpeed;
			rSpeed = -rSpeed;
		}
		else if (wParam == VK_RIGHT) {	//when press key RIGHT arrow key
			tx1 += tSpeed;
			tx2 -= tSpeed;
		}
		else if (wParam == VK_UP) {		//when press key UP arrow key
			ty1 -= tSpeed;
			ty2 += tSpeed;
			rSpeed += 0.001;
		}
		else if (wParam == VK_DOWN)	{	//when press key DOWN arrow key
			ty1 += tSpeed;
			ty2 -= tSpeed;
			rSpeed -= 0.001;
		}
		else if (wParam == VK_SPACE) {		//when press Space key
			tx1 = 0;
			tx2 = 0;
			ty1 = 0;
			ty2 = 0;
			rSpeed = 0.0;
			x1 = 0.0;
			x2 = 0.5;
		}

		break;

	case WM_CHAR:
		if (wParam == 'j') {	//when press key J key
			x1 += 0.01;
			x2 += 0.01;
		}
		else if (wParam == 'k') {	//when press key K key
			x1 -= 0.01;
			x2 -= 0.01;
		}
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

	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);

	glPushMatrix();
	glTranslatef(0.0, 0.5, 0.0);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.5, 0.0, 0.0);

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.0, 0.0);

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


}
void Q1() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);

	glPushMatrix();
	glTranslatef(tx1, ty1, 0.0);

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(tx2, ty2, 0.0);

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

}


void Q2() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);

	glPointSize(10.0);
	glLineWidth(3.0);

	glLoadIdentity();

	glBegin(GL_QUADS);
	glColor3ub(135, 206, 235);
	glVertex2f(4.0, 4.0);
	glVertex2f(4.0, -4.0);
	glVertex2f(-4.0, -4.0);
	glVertex2f(-4.0, 4.0);
	glEnd();



	glPushMatrix();
	glTranslatef(x1+0.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(-0.025, 0.15);
	glVertex2f(-0.025, 0.2);
	glVertex2f(0.125, 0.2);
	glVertex2f(0.125, 0.15);
	glVertex2f(0.2, 0.15);
	glVertex2f(0.2, 0.05);
	glVertex2f(-0.1, 0.05);
	glVertex2f(-0.1, 0.15);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x2, 0.3, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(-0.025, 0.15);
	glVertex2f(-0.025, 0.2);
	glVertex2f(0.125, 0.2);
	glVertex2f(0.125, 0.15);
	glVertex2f(0.2, 0.15);
	glVertex2f(0.2, 0.05);
	glVertex2f(-0.1, 0.05);
	glVertex2f(-0.1, 0.15);
	glEnd();
	glPopMatrix();


	glBegin(GL_QUADS);
	glColor3ub(50, 112, 67);
	glVertex2f(1.0, -0.4);
	glVertex2f(-1.0, -0.3);
	glColor3ub(27, 245, 86);
	glVertex2f(-1.0, -1.0);
	glVertex2f(1.0, -1.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.9f, 0.35f, 0.05f);
	glVertex2f(-0.6, 0.5);
	glVertex2f(-0.3, 0.5);
	glVertex2f(-0.2, -0.6);
	glVertex2f(-0.7, -0.6);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(168, 111, 32);
	glVertex2f(-0.6, 0.5);
	glVertex2f(-0.3, 0.5);
	glVertex2f(-0.2, -0.6);
	glVertex2f(-0.7, -0.6);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.65, 0.5);
	glVertex2f(-0.45, 0.7);
	glVertex2f(-0.25, 0.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(249, 224, 141);
	glVertex2f(-0.5, -0.3);
	glVertex2f(-0.3, -0.3);
	glVertex2f(-0.3, -0.6);
	glVertex2f(-0.5, -0.6);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(168, 111, 32);
	glVertex2f(-0.5, -0.3);
	glVertex2f(-0.3, -0.3);
	glVertex2f(-0.3, -0.6);
	glVertex2f(-0.5, -0.6);
	glEnd();

	glBegin(GL_POINTS);
	glColor3ub(168, 111, 32);
	glVertex2f(-0.45, -0.45);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(168, 111, 32);
	glVertex2f(-0.65, 0.5);
	glVertex2f(-0.45, 0.7);
	glVertex2f(-0.25, 0.5);
	glEnd();


	glPushMatrix();
	glTranslatef(0.6, -0.5, 0.0);
	glScalef(0.5, 0.5, 0.0);
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.2, 0.0);
	glVertex2f(0.2, 0.1);
	glVertex2f(0.0, 0.1);
	glVertex2f(0.05, -0.05);
	glVertex2f(0.15, -0.05);
	glVertex2f(0.15, 0.15);
	glVertex2f(0.05, 0.15);
	glColor3ub(0, 0, 0);
	glVertex2f(0.05, 0.0);
	glVertex2f(0.15, 0.0);
	glVertex2f(0.15, 0.1);
	glVertex2f(0.05, 0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, -0.6, 0.0);
	glScalef(0.5, 0.5, 0.0);
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.2, 0.0);
	glVertex2f(0.2, 0.1);
	glVertex2f(0.0, 0.1);
	glVertex2f(0.05, -0.05);
	glVertex2f(0.15, -0.05);
	glVertex2f(0.15, 0.15);
	glVertex2f(0.05, 0.15);
	glColor3ub(0, 0, 0);
	glVertex2f(0.05, 0.0);
	glVertex2f(0.15, 0.0);
	glVertex2f(0.15, 0.1);
	glVertex2f(0.05, 0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, -0.5, 0.0);
	glScalef(0.5, 0.5, 0.0);
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.2, 0.0);
	glVertex2f(0.2, 0.1);
	glVertex2f(0.0, 0.1);
	glVertex2f(0.05, -0.05);
	glVertex2f(0.15, -0.05);
	glVertex2f(0.15, 0.15);
	glVertex2f(0.05, 0.15);
	glColor3ub(0, 0, 0);
	glVertex2f(0.05, 0.0);
	glVertex2f(0.15, 0.0);
	glVertex2f(0.15, 0.1);
	glVertex2f(0.05, 0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.6, 0.0);
	glScalef(0.5, 0.5, 0.0);
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.2, 0.0);
	glVertex2f(0.2, 0.1);
	glVertex2f(0.0, 0.1);
	glVertex2f(0.05, -0.05);
	glVertex2f(0.15, -0.05);
	glVertex2f(0.15, 0.15);
	glVertex2f(0.05, 0.15);
	glColor3ub(0, 0, 0);
	glVertex2f(0.05, 0.0);
	glVertex2f(0.15, 0.0);
	glVertex2f(0.15, 0.1);
	glVertex2f(0.05, 0.1);
	glEnd();
	glPopMatrix();



	angle += rSpeed;

	if (angle > 360) {
		angle = 0.0;
	}

	glPushMatrix();
	glTranslatef(-0.45, 0.3, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 1.0);
	glVertex2f(0.0, 0.0 );
	glVertex2f(0.0, 0.08 );
	glVertex2f(0.5 , 0.08);
	glVertex2f(0.5 , 0.0 );
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, -0.08);
	glVertex2f(-0.5, -0.08);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.08, 0.5);
	glVertex2f(-0.08, 0.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, -0.5);
	glVertex2f(0.08, -0.5);
	glVertex2f(0.08, 0.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(168, 111, 32);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.08);
	glVertex2f(0.5, 0.08);
	glVertex2f(0.5, 0.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(168, 111, 32);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, -0.08);
	glVertex2f(-0.5, -0.08);
	glVertex2f(-0.5, 0.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(168, 111, 32);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.08, 0.5);
	glVertex2f(-0.08, 0.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(168, 111, 32);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, -0.5);
	glVertex2f(0.08, -0.5);
	glVertex2f(0.08, 0.0);
	glEnd();
	glPopMatrix();

	glBegin(GL_POINTS);
	glColor3ub(168, 111, 32);
	glVertex2f(-0.45, 0.3);
	glEnd();


}




void display()
{


	switch (qNo)
	{
	case 1:
		Q1();
		break;
	case 2:
		Q2();
		break;


	default:
		Q1();
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