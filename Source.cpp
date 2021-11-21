#include <stdlib.h>
#include <GL/glut.h>


static int shoulder1 = -65, shoulder2 = 0, elbow = 0, fingerBase = 0, fingerUp = 0, waist = 0, flag = 0, thigh1 = 0, thigh2 = 0, thigh12 = 0, thigh22 = 0, leg1 = 0, leg2 = 0;
static float fvoy = 120.0;
static GLdouble eye[] = { 0,0,2 };
static GLdouble center[] = { 0,0,0 };
static GLdouble up[] = { 0,1,0 };

int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}




void display(void)
{




	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	//body
	glTranslatef(0.0, -2.5, 0.0);
	glRotatef((GLfloat)waist, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 2.5, 0.0);
	glPushMatrix();
	glScalef(3.4, 5.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();


	//arm1
	glTranslatef(1.7, 2.25, 0.0);
	glRotatef((GLfloat)shoulder1, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)shoulder2, 1.0, 0.0, 0.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.6, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.6, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	//Draw finger flang 1 
	glTranslatef(1.0, 0.0, -0.45);
	glRotatef((GLfloat)fingerBase, 0.0, 0.0, -1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glPopMatrix();



	//Draw finger flang 2
	glTranslatef(0.15, 0.0, 0.0);
	glRotatef((GLfloat)fingerUp, 0.0, 0.0, -1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glPopMatrix();




	//arm2
	glPopMatrix();
	glPushMatrix();

	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	glTranslatef(0, -2.5, 0.0);
	glRotatef((GLfloat)waist, 1.0, 0.0, 0.0);
	glTranslatef(-1.7, 4.75, 0.0);
	glRotatef((GLfloat)shoulder1, 0.0, 0.0, -1.0);
	glRotatef((GLfloat)shoulder2, 1.0, 0.0, 0.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.6, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, -1.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.6, 1.0);
	glutWireCube(1.0);
	glPopMatrix();


	//finger flang 1
	glTranslatef(-1.0, 0.0, -0.45);
	glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
	glTranslatef(-0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glPopMatrix();


	//finger flang 2
	glTranslatef(-0.15, 0.0, 0.0);
	glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
	glTranslatef(-0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glTranslatef(0.0, 0.0, 3.0);
	glutWireCube(1);
	glPopMatrix();



	//head
	glPopMatrix();
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	glTranslatef(0, -2.5, 0.0);
	glRotatef((GLfloat)waist, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 6.0, 0.0);
	glScalef(0.75, 1.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glutWireSphere(1, 16, 16);


	glPopMatrix();

	//leg1
	glPopMatrix();
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	glTranslatef(1.0, -2.5, 0.0);
	glRotatef((GLfloat)thigh1, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)thigh12, 0.0, 0.0, 1.0);
	glTranslatef(0, -1.35, 0.0);
	glPushMatrix();
	glScalef(1.4, 2.7, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0.0, -1.35, 0.0);
	glRotatef((GLfloat)leg1, 1.0, 0.0, 0.0);
	glTranslatef(0, -1.35, 0.0);
	glPushMatrix();
	glScalef(1.4, 2.7, 1.0);
	glutWireCube(1.0);
	glTranslatef(0, -0.65, 0.5);
	glScalef(1.0, 0.25, 2.2);
	glutWireCube(1.0);
	glPopMatrix();


	//leg2
	glPopMatrix();
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	glTranslatef(-1.0, -2.5, 0.0);
	glRotatef((GLfloat)thigh2, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)thigh22, 0.0, 0.0, -1.0);
	glTranslatef(0, -1.35, 0.0);
	glPushMatrix();
	glScalef(1.4, 2.7, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0.0, -1.35, 0.0);
	glRotatef((GLfloat)leg2, 1.0, 0.0, 0.0);
	glTranslatef(0, -1.35, 0.0);
	glPushMatrix();
	glScalef(1.4, 2.7, 1.0);
	glutWireCube(1.0);
	glTranslatef(0, -0.65, 0.5);
	glScalef(1.0, 0.25, 2.2);
	glutWireCube(1.0);
	glPopMatrix();


	glPopMatrix();
	glPushMatrix();
	glPopMatrix();
	glutSwapBuffers();





}

void reshape(int w, int h)
{

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective((GLfloat)fvoy, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		eye[0] = eye[0] + 0.1;
			break;
	case '2':
		eye[1] = eye[1] + 0.1;
			break;
	case '3':
		eye[2] = eye[2] + 0.1;
			break;
	case '4':
		center[0] = center[0] + 0.1;
			break;
	case '5':
		center[1] = center[1] + 0.1;
			break;
	case '6':
		center[2] = center[2] + 0.1;
			break;
	case '7':
		up[0] = up[0] + 0.1;
			break;
	case '8':
		up[1] = up[1] + 0.1;
			break;
	case '9':
		up[2] = up[2] + 0.1;
			break;
	case '!':
		eye[0] = eye[0] - 0.1;
			break;
	case '@':
		eye[1] = eye[1] - 0.1;
			break;
	case '#':
		eye[2] = eye[2] - 0.1;
			break;
	case '$':
		center[0] = center[0] - 0.1;
			break;
	case '%':
		center[1] = center[1] - 0.1;
			break;
	case '^':
		center[2] = center[2] - 0.1;
			break;
	case '&':
		up[0] = up[0] - 0.1;
			break;
	case '*':
		up[1] = up[1] - 0.1;
			break;
	case '(':
		up[2] = up[2] - 0.1;
			break;
	case 's':
		if (shoulder1 <= 160) {
			shoulder1 = (shoulder1 + 5);
			glutPostRedisplay();
		}
		break;
	case 'S':
		if (shoulder1 > -80) {
			shoulder1 = (shoulder1 - 5);
			glutPostRedisplay();
		}
		break;

	case 'a':
		if (shoulder2 <= 90) {
			shoulder2 = (shoulder2 + 5);
			glutPostRedisplay();
		}
		break;
	case 'A':
		if (shoulder2 > 0) {
			shoulder2 = (shoulder2 - 5);
			glutPostRedisplay();
		}
		break;

	case 'U':
		if (thigh1 <= 80) {
			thigh1 = (thigh1 + 5);
			glutPostRedisplay();
		}
		break;
	case 'u':
		if (thigh1 > -80) {
			thigh1 = (thigh1 - 5);
			glutPostRedisplay();
		}
		break;

	case 'I':
		if (thigh2 <= 80) {
			thigh2 = (thigh2 + 5);
			glutPostRedisplay();
		}
		break;
	case 'i':
		if (thigh2 > -80) {
			thigh2 = (thigh2 - 5);
			glutPostRedisplay();
		}
		break;


	case 'y':
		if (thigh12 <= 80) {
			thigh12 = (thigh12 + 5);
			glutPostRedisplay();
		}
		break;
	case 'Y':
		if (thigh12 > -10) {
			thigh12 = (thigh12 - 5);
			glutPostRedisplay();
		}
		break;

	case 'o':
		if (thigh22 <= 80) {
			thigh22 = (thigh22 + 5);
			glutPostRedisplay();
		}
		break;
	case 'O':
		if (thigh22 > -10) {
			thigh22 = (thigh22 - 5);
			glutPostRedisplay();
		}
		break;

	case 'j':
		if (leg1 <= 160) {
			leg1 = (leg1 + 5);
			glutPostRedisplay();
		}
		break;
	case 'J':
		if (leg1 > 0) {
			leg1 = (leg1 - 5);
			glutPostRedisplay();
		}
		break;

	case 'k':
		if (leg2 <= 160) {
			leg2 = (leg2 + 5);
			glutPostRedisplay();
		}
		break;
	case 'K':
		if (leg2 > 0) {
			leg2 = (leg2 - 5);
			glutPostRedisplay();
		}
		break;

	case 'w':
		if (waist <= 160) {
			waist = (waist + 5);
			glutPostRedisplay();
		}
		break;
	case 'W':
		if (waist > 0) {
			waist = (waist - 5);
			glutPostRedisplay();
		}
		break;

	case 'e':
		if (elbow <= 160) {
			elbow = (elbow + 5);
			glutPostRedisplay();
		}
		break;
	case 'E':
		if (elbow > 0) {
			elbow = (elbow - 5);
			glutPostRedisplay();
		}
		break;
	case 'f':
		if (fingerBase <= 160) {
			fingerBase = (fingerBase + 5);
			glutPostRedisplay();
		}
		break;
	case 'F':
		if (fingerBase > 0) {
			fingerBase = (fingerBase - 5);
			glutPostRedisplay();
		}
		break;
	case 'g':
		if (fingerUp <= 160) {
			fingerUp = (fingerUp + 5);
			glutPostRedisplay();
		}
		break;
	case 'G':
		if (fingerUp > 0) {
			fingerUp = (fingerUp - 5);
			glutPostRedisplay();

		}
		break;


	case 'z':
		fvoy += 1.0;
		reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();

		break;

	case 'Z':
		fvoy -= 1.0;
		reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();

		break;

	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

static void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			moving = 1;
			startx = x;
			starty = y;
		}
		if (state == GLUT_UP) {
			moving = 0;
		}
	}
}


static void motion(int x, int y)
{
	if (moving) {
		angle = angle + (x - startx);
		angle2 = angle2 + (y - starty);
		startx = x;
		starty = y;
		glutPostRedisplay();
	}
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}