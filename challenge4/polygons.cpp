#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

const double TWO_PI = 6.2831853;

/* Initial display-window size. */
GLsizei winWidth = 400, winHeight = 400;

/* Counter is used to control polygon size
it is initialized at 6 because it is firstly
used when the first click is made so the polygon
goes from a pentagon to an hexagon */
GLuint regHex, counter = 6;

/* This variable is also used to control polygon size
but the difference with this variable compared to counter
is that this variable is used to calculate the value of
theta used to calculate the points for the polygon */
GLdouble counterDb = 6.0;

class screenPt
{
private:
    GLint x, y;
public:
    /* Default Constructor: initializes coordinate position to (0, 0).*/
    screenPt ( ) {
	x = y = 0;
    }
    void setCoords (GLint xCoord, GLint yCoord) {
	x = xCoord;
	y = yCoord;
    }
    GLint getx ( ) const {
	return x;
    }
    GLint gety ( ) const {
	return y;
    }
};


static void init (void)
{
  glClearColor (1.0, 1.0, 1.0, 0.0); //    Display-window color = white.
}

void regHexagon (void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    screenPt hexVertex, circCtr;
    GLdouble theta;
    GLint k;
    /* Set circle center coordinates. */
    circCtr.setCoords (winWidth / 2, winHeight / 2);
    srand( (unsigned)time( NULL ) );
    glColor3f ((float) rand()/RAND_MAX, (float) rand()/RAND_MAX, (float) rand()/RAND_MAX);  // Set fill color for polygon to a random color.
   
    glBegin (GL_POLYGON);
    for (k = 0; k < 5; k++) {
	theta = TWO_PI * k / 5.0;
	hexVertex.setCoords (circCtr.getx ( ) + 150 * cos (theta),
			     circCtr.gety ( ) + 150 * sin (theta));
	glVertex2i (hexVertex.getx ( ), hexVertex.gety ( ));
    }
    glEnd ( );
   
    glFlush ( );
}

void winReshapeFcn (int newWidth, int newHeight)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ( );
    gluOrtho2D (0.0, (GLdouble) newWidth, 0.0, (GLdouble) newHeight);
    glClear (GL_COLOR_BUFFER_BIT);
}

void generatePolygon (void)
{
    if(counter == 13 && counterDb == 13){
        counter = 5;
        counterDb = 5;
    }
    glClear (GL_COLOR_BUFFER_BIT);

    screenPt hexVertex, circCtr;
    GLdouble theta;
    GLint k;
    /* Set circle center coordinates. */
    circCtr.setCoords (winWidth / 2, winHeight / 2);
    srand( (unsigned)time( NULL ) );
    glColor3f ((float) rand()/RAND_MAX, (float) rand()/RAND_MAX, (float) rand()/RAND_MAX);  // Set fill color for polygon to a random color.
   
    glBegin (GL_POLYGON);
    for (k = 0; k < counter; k++) {
	theta = TWO_PI * k / counterDb;
	hexVertex.setCoords (circCtr.getx ( ) + 150 * cos (theta),
			     circCtr.gety ( ) + 150 * sin (theta));
	glVertex2i (hexVertex.getx ( ), hexVertex.gety ( ));
    }
    counter++;
    counterDb++;
    glEnd ( );
   
    glFlush ( );
}

void mousePolygonHelper (GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
        generatePolygon ();
    }
    glFlush ( );
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (winWidth, winHeight);
    glutCreateWindow ("Polygons generated with left clicks");
    init ( );
    glutDisplayFunc (regHexagon);
    glutReshapeFunc (winReshapeFcn);
    glutMouseFunc (mousePolygonHelper);
    glutMainLoop ( );
    return 0;
}
