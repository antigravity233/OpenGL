
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>		// include math class

#define WINDOW_TITLE "OpenGL Window"

int qNo = 1;			// Question No =1
float tx = 0, ty = 0, tSpeed = 0.1;	// translate x and y
float r = 1.0, g = 1.0, b = 1.0;
float angle = 0.0;
float radius = 0.7;		// radius
float f = 0.01;
float x2 = 0.0, y2 = 0.0;	// Origin of circle(x2,y2)
float PI = 3.142;			// PI
int noOfTri = 31;		// no of triangles
float size = 0.1;



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
		else if (wParam == VK_LEFT)		//when press key LEFT arrow key
			tx -= tSpeed;
		else if (wParam == VK_RIGHT)	//when press key RIGHT arrow key
			tx += tSpeed;
		else if (wParam == VK_UP)		//when press key UP arrow key
			ty += tSpeed;
		else if (wParam == VK_DOWN)		//when press key DOWN arrow key
			ty -= tSpeed;
		else if (wParam == 'R') { 	//when press key R key
			r = 1.0;
			g = 0.0;
			b = 0.0;
		}
		else if (wParam == 'G') {			//when press key G key
			r = 0.0;
			g = 1.0;
			b = 0.0;
		}
		else if (wParam == 'B') {		//when press key B key
			r = 0.0;
			g = 0.0;
			b = 1.0;
		}
		else if (wParam == VK_SPACE) {		//when press key Space key
			r = 1.0;
			g = 1.0;
			b = 1.0;
			tx = 0.0;
			ty = 0.0;
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

	glLoadIdentity();					// reset the transformation matrix
	glTranslatef(tx, ty, 0.0);			// translate x and y
	glScalef(0.5, 0.5, 1.0);

	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();

	
}

void Q2() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);

	glLoadIdentity();					// reset the transformation matrix


	if (r > 1.0) {
		r = 0;

	}
	if (g > 1.0) {
		b = 0;

	}
	if (b > 1.0) {
		b = 0;

	}

	r += 0.0003;
	g += 0.0002;
	b += 0.0001;

	angle += f;
	if (angle > 360) {
		angle = 0.0;
	};
	glRotatef(angle, 0.0, 0.0, 0);


	const float angleStep = 2 * PI / 5;
	const float startAngle = -PI / 2;
	glLoadIdentity();
	glRotatef(angle, angle, angle, angle);
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 0); // Center of the star
	for (int i = 0; i <= 5; i++) {
		float outerAngle = startAngle + i * angleStep;
		float innerAngle = outerAngle + angleStep / 2;
		glVertex2f(0 + cos(outerAngle) * radius, 0 + sin(outerAngle) * radius);
		glVertex2f(0 + cos(innerAngle) * (radius / 2.5), 0 + sin(innerAngle) * (radius / 2.5));
	}
	glEnd();
}

void Q3() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);


	glLoadIdentity();	



	angle += 0.001f;



	if (angle > 360) {
		angle = 0.0;
	}

	glRotatef(angle, 0.0, 0.0, 0.0);



	float x = x2 + radius * cos(angle); 
	float y = y2 + radius * sin(angle); 

	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();

	
}

void Q4() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	size += 0.0001;


	if (size > 1.7) {
		size = 0.0;
	}



	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-size, size);
	glVertex2f(size, size);
	glVertex2f(size, -size);
	glVertex2f(-size, -size);
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
	case 3:
		Q3();
		break;
	case 4:
		Q4();
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