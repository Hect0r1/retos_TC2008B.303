#include <GL/glut.h>
// (or others, depending on the system in use)
void init (void) {
    glClearColor (1.0, 1.0, 1.0, 0.0);    // Set display-window color to white.
    glMatrixMode (GL_PROJECTION);         // Set projection parameters.
    gluOrtho2D (0.0, 400.0, 0.0, 400.0);
}

void points (void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.4, 0.2);
    glBegin (GL_POINTS);
    int x1, y1, x2, y2, dx, dy;


    x1=200;
    y1=300;

    x2=250;
    y2=50;

    dx = x2 - x1;
    dy = y2 - y1;

    for(int x = x1; x <= x2; x++){
       int y = y1 + dy * (x - x1) / dx;
       glVertex2i (x, y);
    
    }


    x1=350;
    y1=350;

    x2=100;
    y2=300;

    dx = x2 - x1;
    dy = y2 - y1;

    for(int x = x1; x >= x2; x--){
       int y = y1 + dy * (x - x1) / dx;
       glVertex2i (x, y);
    
    }



    x1=1;
    y1=2;

    x2=100;
    y2=20;

    dx = x2 - x1;
    dy = y2 - y1;

    for(int x = x1; x <= x2; x++){
       int y = y1 + dy * (x - x1) / dx;
       glVertex2i (x, y);
    
    }

    x1=10;
    y1=200;

    x2=50;
    y2=10;

    dx = x2 - x1;
    dy = y2 - y1;

    for(int x = x1; x <= x2; x++){
       int y = y1 + dy * (x - x1) / dx;
       glVertex2i (x, y);
    
    }
    

    x1=300;
    y1=300;

    x2=10;
    y2=10;

    dx = x2 - x1;
    dy = y2 - y1;

    for(int x = x1; x >= x2; x--){
      int y = y1 + dy * (x - x1) / dx;
      glVertex2i (x, y);
    }

      
    glEnd ();
    glFlush();
}

int main (int argc, char** argv) {
    glutInit (&argc, argv);    // Initialize GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);    // Set display mode.
    glutInitWindowPosition (50, 100);    // Set top-left display-window position.
    glutInitWindowSize (400, 400);    // Set display-window width and height.
    glutCreateWindow ("Graphing lines with points"); // Create display window.
    init ( ); // Execute initialization procedure.
    glutDisplayFunc (points);
    glutMainLoop ( );    // Display everything and wait.
    return 0;
}
