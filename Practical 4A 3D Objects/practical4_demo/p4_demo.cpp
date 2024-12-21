
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>		// include math class

#define WINDOW_TITLE "OpenGL Window"

int qNo = 1;			// Question No =1
float tx = 0, ty = 0, rSpeed = 1;	// translate x and y
float angle1 = 0.0;
float angle2 = 0.0;
float x = 1.0, y = 1.0, z = 1.0;




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
			angle2 -= rSpeed;
		}
		else if (wParam == VK_RIGHT) {	//when press key RIGHT arrow key
			angle2 += rSpeed;
		}
		else if (wParam == VK_UP) {		//when press key UP arrow key
			angle1 += rSpeed;
		}
		else if (wParam == VK_DOWN) {	//when press key DOWN arrow key
			angle1 -= rSpeed;
		}
		else if (wParam == VK_SPACE) {		//when press Space key
			x = 1.0;
			y = 1.0;
			z = 1.0;
			angle1 = 0.0;
			angle2 = 0.0;
		}
		else if (wParam == 'x') {		//when press key X key
			x = -1.0;
			y = 1.0;
			z = 1.0;
		}
		else if (wParam == 'Y') {	//when press key Y key
			x = 1.0;
			y = -1.0;
			z = 1.0;
		}
		else if (wParam == 'Z') {		//when press key Z key
			x = 1.0;
			y = 1.0;
			z = -1.0;

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

	glEnd();

}

void drawCube(float size) {
	glBegin(GL_LINE_LOOP);
	// Face 1	BOTTOM
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, size);		// Point 1
	glVertex3f(size, 0.0, size);		// Point 2
	glVertex3f(size, 0.0, 0.0);		// Point 3
	glVertex3f(0.0, 0.0, 0.0f);		// Point 4
	// The next Face must have related to the last point of the previous Face
	// Face 2	LEFT
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, size, 0.0);
	glVertex3f(0.0, size, size);
	glVertex3f(0.0, 0.0, size);
	// Face 3	FRONT
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, size);
	glVertex3f(0.0, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, 0.0, size);
	// Face 4	RIGHT
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(size, 0.0, size);
	glVertex3f(size, 0.0, 0.0);
	glVertex3f(size, size, 0.0);
	glVertex3f(size, size, size);
	// Face 5	BACK
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(size, size, size);
	glVertex3f(0.0, size, size);
	glVertex3f(0.0, size, 0.0);
	glVertex3f(size, size, 0.0);
	// Face 6	
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(size, size, 0.0);
	glVertex3f(0.0, size, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(size, 0.0, 0.0);
	glEnd();
}

void pyramid(float size) {

	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(size / 2, size, size / 2);
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(size / 2, size, size / 2);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size / 2, size, size / 2);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(size / 2, size, size / 2);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
}

void drawArm(float size) {

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 1.0);
	
	// Face 1 BOTTOM
	glVertex3f(0.0f, 0.0f, size/4);
	glVertex3f(size, 0.0f, size/4);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	// Face 2 LEFT
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0f, size / 4, 0.0f);
	glVertex3f(0.0f, size / 4, size / 4);
	glVertex3f(0.0f, 0.0f, size / 4);
	glVertex3f(0.0f, 0.0f, 0.0f);

	// Face 3 FRONT
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.0f, 0.0f, size / 4);
	glVertex3f(0.0f, size / 4, size / 4);
	glVertex3f(size, size / 4, size / 4);
	glVertex3f(size, 0.0f, size / 4);

	// Face 4 RIGHT
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(size, 0.0f, size / 4);
	glVertex3f(size, size / 4, size / 4);
	glVertex3f(size, size / 4, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);

	// Face 5 BACK
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size / 4, 0.0f);
	glVertex3f(size, size / 4, 0.0f);

	// Face 6 TOP
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(size, size / 4, 0.0f);
	glVertex3f(0.0f, size / 4, 0.0f);
	glVertex3f(0.0f, size / 4, size / 4);
	glVertex3f(size, size / 4, size / 4);
	glEnd();

}

void robotArm(float size) {

	glLineWidth(1.0f);

	// Face 1	BOTTOM
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 0.0, size/3);
	glVertex3f(size, 0.0, size/ 3);
	glVertex3f(size, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	// Face 2	LEFT
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, size/ 3, 0.0);
	glVertex3f(0.0, size/ 3, size/ 3);
	glVertex3f(0.0, 0.0, size/ 3);
	glEnd();
	// Face 3	FRONT
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 0.0, size/ 3);
	glVertex3f(0.0, size/ 3, size/ 3);
	glVertex3f(size, size/ 3, size/ 3);
	glVertex3f(size, 0.0, size/ 3);
	glEnd();
	 //Face 4	RIGHT
		glBegin(GL_LINE_LOOP);
	glVertex3f(size, 0.0, size/ 3);
	glVertex3f(size, 0.0, 0.0);
	glVertex3f(size, size/ 3, 0.0);
	glVertex3f(size, size/ 3, size/ 3);
	glEnd();

	 //Face 5	BACK
	glBegin(GL_LINE_LOOP);
	glVertex3f(size, size/3, size/3);
	glVertex3f(0.0, size/3, size/3);
	glVertex3f(0.0, size/3, 0.0);
	glVertex3f(size, size/3, 0.0);
	glEnd();

	 //Face 6	TOP
	glBegin(GL_LINE_LOOP);
	glVertex3f(size, size/3, 0.0);
	glVertex3f(0.0, size/3, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(size, 0.0, 0.0);
	glEnd();

}


void Q1() {


	pyramid(0.5);
}

void Q2() {

	glRotatef(0.01, x, y, z);
	pyramid(0.5);
}

void Q3() {
	glLoadIdentity();

	glRotatef(angle2, 1.0, 1.0, 0.0);

	glPushMatrix();
	glTranslatef(-0.8, 0.0, 0.0);
	robotArm(0.8);
	glPopMatrix();

	glPushMatrix();
	glRotatef(angle1, 0.0, 0.0, 1.0);
	robotArm(0.8);
	glPopMatrix();
}




void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	switch (qNo)
	{
	case 1:
		Q1();
		break;
	case 2:
		Q2();
		break;
	case 3:
		Q3();
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