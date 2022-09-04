#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

float _Car_move = -800;
float _Car2_move = 800;
float _boat_move = 800;
float _cloud_move = -300;
float _cameraAngle = 0.0;
float _angle = 0.0;
float _bird_move = -800;
float theta;

void init()
{
    glClearColor(0, 0, 0, 10);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-800, 800.0, -600, 600.0);
    glMatrixMode(GL_MODELVIEW);
     glLoadIdentity ();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.529, 0.808, 0.922,0.0);

	//water line
    glColor3f(0.3, 0.1, 0.4);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(-800, -350);
    glVertex2i(800, -350);
    glEnd();

    //water
    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.000, 0.804);
    glVertex2i(-800, -350);
    glColor3f(0.255, 0.412, 0.882);
    glVertex2i(-500, -350);
    glColor3f(0.255, 0.412, 0.882);
    glVertex2i(-550, -600);
    glColor3f(0.000, 0.000, 0.804);
    glVertex2i(-800, -600);
    glEnd();

    glBegin(GL_POLYGON);
     glColor3f(0.255, 0.412, 0.882);
    glVertex2i(-500, -350);
     glColor3f(0.118, 0.565, 1.000);
    glVertex2i(-450, -350);
    glColor3f(0.000, 0.749, 1.000);
    glVertex2i(-300, -350);
     glColor3f(0.118, 0.565, 1.000);
    glVertex2i(350, -350);
    glVertex2i(250, -600);
    glColor3f(0.255, 0.412, 0.882);
    glVertex2i(-550, -600);
    glEnd();



    glBegin(GL_POLYGON);

    glColor3f(0.118, 0.565, 1.000);
    glVertex2i(350, -350);
    glColor3f(0.255, 0.412, 0.882);
    glVertex2i(450, -350);
    glColor3f(0.000, 0.000, 0.804);
    glVertex2i(600, -350);
    glColor3f(0.000, 0.000, 0.804);
    glVertex2i(800, -350);
    glColor3f(0.000, 0.000, 0.804);
    glVertex2i(800, -600);
    glColor3f(0.255, 0.412, 0.882);
    glVertex2i(400, -600);
    glColor3f(0.118, 0.565, 1.000);
    glVertex2i(250, -600);
    glEnd();



     //Building body
   glPushMatrix();
   glTranslatef(350,0,0);
   glBegin(GL_POLYGON);
   glColor3f(1.000, 0.714, 0.757);
   glVertex2i(150,-200);
   glColor3f(0.859, 0.439, 0.576);
   glVertex2i(400,-200);
   glColor3f(1.000, 0.714, 0.757);
   glVertex2i(400,200);
   glVertex2i(150,200);
   glEnd();
   glPopMatrix();

   // building roof
   glPushMatrix();
   glTranslatef(350,0,0);
   glColor3f(0.780, 0.082, 0.522);
   glBegin(GL_POLYGON);
   glVertex2i(140,180);
   glVertex2i(410,180);
   glVertex2i(410,210);
   glVertex2i(140,210);
   glEnd();
   glPopMatrix();

    // building garage
   glPushMatrix();
   glTranslatef(350,-380,0);
   glColor3f(0.780, 0.082, 0.522);
   glBegin(GL_POLYGON);
   glVertex2i(140,180);
   glVertex2i(410,180);
   glVertex2i(410,210);
   glVertex2i(140,210);
   glEnd();
   glPopMatrix();

    // building door
   glPushMatrix();
   glTranslatef(490,-200,0);
   glColor3f(0.804, 0.361, 0.361);
   glBegin(GL_POLYGON);
   glVertex2i(100,0);
   glVertex2i(100,30);
   glVertex2i(135,55);
   glColor3f(0.698, 0.133, 0.133);
   glVertex2i(170,30);
   glVertex2i(170,0);
   glEnd();
   glPopMatrix();

   //Building windows
   //window 3
   glPushMatrix();
   glTranslatef(350,0,0);
   glBegin(GL_POLYGON);
   glColor3f(0.275, 0.510, 0.706);
   glVertex2i(180,-30);
   glVertex2i(230,-30);
   glVertex2i(230,30);
   glColor3f(0.863, 0.863, 0.863);
   glVertex2i(180,30);
   glEnd();
   glPopMatrix();

   //window 4
   glPushMatrix();
   glTranslatef(490,0,0);
   glBegin(GL_POLYGON);
   glColor3f(0.275, 0.510, 0.706);
   glVertex2i(180,-30);
   glVertex2i(230,-30);
   glVertex2i(230,30);
   glColor3f(0.863, 0.863, 0.863);
   glVertex2i(180,30);
   glEnd();
   glPopMatrix();

   //window 1

   glPushMatrix();
   glTranslatef(350,100,0);
   glBegin(GL_POLYGON);
   glColor3f(0.275, 0.510, 0.706);
   glVertex2i(180,-30);
   glVertex2i(230,-30);
   glVertex2i(230,30);
   glColor3f(0.863, 0.863, 0.863);
   glVertex2i(180,30);
   glEnd();
   glPopMatrix();


    //window 2

   glPushMatrix();
   glTranslatef(490,100,0);
   glBegin(GL_POLYGON);
   glColor3f(0.275, 0.510, 0.706);
   glVertex2i(180,-30);
   glVertex2i(230,-30);
   glVertex2i(230,30);
   glColor3f(0.863, 0.863, 0.863);
   glVertex2i(180,30);
   glEnd();
   glPopMatrix();

    //window 5

   glPushMatrix();
   glTranslatef(350,-100,0);
   glBegin(GL_POLYGON);
   glColor3f(0.275, 0.510, 0.706);
   glVertex2i(180,-30);
   glVertex2i(230,-30);
   glVertex2i(230,30);
   glColor3f(0.863, 0.863, 0.863);
   glVertex2i(180,30);
   glEnd();
   glPopMatrix();

    //window 1

   glPushMatrix();
   glTranslatef(490,-100,0);
   glBegin(GL_POLYGON);
   glColor3f(0.275, 0.510, 0.706);
   glVertex2i(180,-30);
   glVertex2i(230,-30);
   glVertex2i(230,30);
   glColor3f(0.863, 0.863, 0.863);
   glVertex2i(180,30);
   glEnd();
   glPopMatrix();



     //car 1
      glPushMatrix();
    glLoadIdentity();
    glTranslated(_Car2_move,-410,0.0);

    //car under part
    glBegin(GL_POLYGON);
    glColor3f(0.576, 0.439, 0.859);
    glVertex2i(110, 200);
    glColor3f(1.000, 0.894, 0.882);
    glVertex2i(110, 220);
    glVertex2i(190, 220);
     glColor3f(0.576, 0.439, 0.859);
    glVertex2i(190, 200);

    //car upper part
    glBegin(GL_POLYGON);
    glVertex2i(125, 220);
    glVertex2i(137, 230);
    glVertex2i(162, 230);
    glVertex2i(175, 220);

    glEnd();
    //car wheel 1

    glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(130+8*cos(theta), 200+12*sin(theta));
   }
    glEnd();

    //car wheel 2

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(170+8*cos(theta), 200+12*sin(theta));
   }
    glEnd();

    glPopMatrix();

    //car2
    glPushMatrix();
    glLoadIdentity();

    glTranslated(_Car_move,-410,0.0);

    //car under part
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.549, 0.000);
    glVertex2i(110, 200);
    glColor3f(0.863, 0.078, 0.235);
    glVertex2i(110, 220);
    glVertex2i(190, 220);
    glColor3f(1.000, 0.549, 0.000);
    glVertex2i(190, 200);

    //car upper part
    glBegin(GL_POLYGON);
    glVertex2i(125, 220);
    glVertex2i(137, 230);
    glVertex2i(162, 230);
    glVertex2i(175, 220);

    glEnd();
    //car wheel 1
    glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(130+8*cos(theta), 200+12*sin(theta));
   }
    glEnd();

    //car wheel 2
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(170+8*cos(theta), 200+12*sin(theta));
   }
    glEnd();

    glPopMatrix();

    //windmill
    glPushMatrix();
    glTranslatef(-600, 100, 0.0);
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex2i(-5, 0);
    glVertex2i(-10, -200);
     glColor3f(0.827, 0.827, 0.827);
    glVertex2i(10, -200);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-600, 100, 0.0);
    glRotatef(_angle, 0.0, 0.0, -1.0);


    glBegin(GL_POLYGON);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2i(-100, 8);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2i(-100, -8);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2i(100, -8);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2i(100, 8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2i(-8, 100);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2i(8, 100);
     glColor3f(0.663, 0.663, 0.663);
    glVertex2i(8, -100);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2i(-8, -100);
    glEnd();
    glPopMatrix();

    // centre of windmill
    glColor3f(0.502, 0.000, 0.000);

        glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-600+8*cos(theta), 100+12*sin(theta));
   }
    glEnd();



       //bridge line
    glBegin(GL_QUADS);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2i(-520, -220);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2i(-500, -250);
    glVertex2i(410, -250);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2i(410, -220);
    glEnd();

     //bridge lining
     //1st pillar left side

    glColor3f(0.184, 0.310, 0.310);
    glBegin(GL_LINES);
    //1st pillar left side
    glVertex2i(-520, -220);
    glVertex2i(-295, 35);

    glVertex2i(-480, -220);
    glVertex2i(-295, 35);

    glVertex2i(-440, -220);
    glVertex2i(-295, 35);

    glVertex2i(-400, -220);
    glVertex2i(-295, 35);

    glVertex2i(-360, -220);
    glVertex2i(-295, 35);

    glVertex2i(-330, -220);
    glVertex2i(-295, 35);

    //1st pillar right side

    glVertex2i(-80, -220);
    glVertex2i(-295, 35);

    glVertex2i(-120, -220);
    glVertex2i(-295, 35);

    glVertex2i(-160, -220);
    glVertex2i(-295, 35);

    glVertex2i(-195, -220);
    glVertex2i(-295, 35);

    glVertex2i(-230, -220);
    glVertex2i(-295, 35);

    glVertex2i(-260, -220);
    glVertex2i(-295, 35);

    //2nd pillar left side
    glVertex2i(-80, -220);
    glVertex2i(155, 35);

    glVertex2i(-40, -220);
    glVertex2i(155, 35);

    glVertex2i(0, -220);
    glVertex2i(155, 35);

    glVertex2i(40, -220);
    glVertex2i(155, 35);

    glVertex2i(80, -220);
    glVertex2i(155, 35);

    glVertex2i(115, -220);
    glVertex2i(155, 35);


    //2nd pillar right side
    glVertex2i(410, -220);
    glVertex2i(155, 35);

    glVertex2i(370, -220);
    glVertex2i(155, 35);

    glVertex2i(330, -220);
    glVertex2i(155, 35);

    glVertex2i(295, -220);
    glVertex2i(155, 35);

    glVertex2i(260, -220);
    glVertex2i(155, 35);

    glVertex2i(225, -220);
    glVertex2i(155, 35);

    glVertex2i(195, -220);
    glVertex2i(155, 35);

    glEnd();



   //bridge pillars
    glPushMatrix();
    glTranslatef(-250,-250,0.0);
    glScalef(0.3,1.0,0.0);
   glBegin(GL_TRIANGLES);
   glColor3f(0.184, 0.310, 0.310);
   glVertex2i(-100, -100);
   glColor3f(0.439, 0.502, 0.565);
   glVertex2i(-200, -100);
   glColor3f(0.184, 0.310, 0.310);
   glVertex2i(-150, 310);
   glEnd();
    glPopMatrix();

    glColor3f(0.184, 0.310, 0.310);
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-295+8*cos(theta), 50+11*sin(theta));
   }
    glEnd();

   glPushMatrix();
    glTranslatef(200,-250,0.0);
    glScalef(0.3,1.0,0.0);
   glBegin(GL_TRIANGLES);
   glColor3f(0.184, 0.310, 0.310);
   glVertex2i(-100, -100);
   glColor3f(0.439, 0.502, 0.565);
   glVertex2i(-200, -100);
   glColor3f(0.184, 0.310, 0.310);
   glVertex2i(-150, 310);
   glEnd();
   glPopMatrix();

   glColor3f(0.184, 0.310, 0.310);
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(155+8*cos(theta), 50+11*sin(theta));
   }
    glEnd();
    //mountain under line
    glBegin(GL_LINES);
    glColor3f(0.502, 0.000, 0.000);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(-800, -250);
    glVertex2i(-500, -250);
    glEnd();

    //mountain under part

    glBegin(GL_POLYGON);

    glColor3f(0.098, 0.098, 0.439);
    glVertex2i(-800, -200);
    glColor3f(0.000, 0.000, 0.545);
    glVertex2i(-700, -225);
    glVertex2i(-670, -215);
    glVertex2i(-620, -230);
    glVertex2i(-500, -240);
    glVertex2i(-500, -370);
    glVertex2i(-520, -380);
    glVertex2i(-550, -370);
    glColor3f(0.098, 0.098, 0.439);
    glVertex2i(-650, -400);
    glVertex2i(-750, -370);
    glVertex2i(-800, -450);
    glEnd();




    // city line
    glBegin(GL_LINES);
    glColor3f(0.333, 0.420, 0.184);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(400, -250);
    glVertex2i(800, -250);
    glEnd();

    //city under part

    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.000, 0.804);
    glVertex2i(410, -200);
    glVertex2i(410, -220);
    glColor3f(0.000, 0.000, 0.545);
    glVertex2i(350, -350);
    glVertex2i(350, -370);
    glColor3f(0.098, 0.098, 0.439);
    glVertex2i(500, -350);
    glColor3f(0.098, 0.098, 0.439);
    glVertex2i(800, -420);
    glVertex2i(800, -200);
    glEnd();

    // boat
    glPushMatrix();
    glTranslatef(_boat_move,-620.0,-0.5);
    glScalef(0.8, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(450,200);
    glVertex2i(50,200);
    glColor3f(0.545, 0.000, 0.000);
    glVertex2i(150,100);
    glVertex2i(350,100);
    glEnd();


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(250,300);
    glVertex2i(250,250);
    glVertex2i(180,250);
    glEnd();

 glColor3f(0.160,0.658,0.203);
    glBegin(GL_POLYGON);
    glVertex2i(250,250);
    glVertex2i(250,200);
    glVertex2i(230,200);
    glVertex2i(230,250);
    glEnd();
    glPopMatrix();

     //Mountain
    glPushMatrix();
    glTranslatef(-980,-890.0,0.0);
    glScalef(0.8, 1.0, 0.0);
   glBegin(GL_POLYGON);
   glColor3f(0.250,0.100,0.0);
   glVertex2i(100,650);
   glColor3f(0.545, 0.271, 0.075);
   glVertex2i(300,800);
   glColor3f(0.250,0.100,0.0);
   glVertex2i(450,650);
   glEnd();

   glColor3f(0.250,0.100,0.0);
   glBegin(GL_POLYGON);
   glColor3f(0.250,0.100,0.0);
   glVertex2i(300,650);
   glColor3f(0.545, 0.271, 0.075);
   glVertex2i(450,850);
   glColor3f(0.250,0.100,0.0);
   glVertex2i(600,650);
   glEnd();
   glPopMatrix();


   //sun
   glColor3f(1.000, 0.843, 0.000);
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-300+70*cos(theta), 400+95*sin(theta));
   }
    glEnd();

    //cloud 1

    glPushMatrix();
    glTranslatef(_cloud_move,0.0,-0.5);
    glColor3f(1.1, 1.1, 1.1);
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-400+70*cos(theta), 400+20*sin(theta));
   }
    glEnd();

    glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-440+80*cos(theta), 370+30*sin(theta));
   }
    glEnd();
    glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-480+70*cos(theta), 430+30*sin(theta));
   }
    glEnd();
 //cloud 2
   glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(600+70*cos(theta), 300+30*sin(theta));
   }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(520+100*cos(theta), 320+30*sin(theta));
   }
    glEnd();
    //cloud 3
     glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(200+70*cos(theta), 500+30*sin(theta));
   }

    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(170+70*cos(theta), 470+30*sin(theta));
   }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(100+100*cos(theta), 530+30*sin(theta));
   }
    glEnd();
    //cloud 4
    glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-800+70*cos(theta), 300+30*sin(theta));
   }
   glEnd();
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-830+90*cos(theta), 350+40*sin(theta));
   }
   glEnd();
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-850+50*cos(theta), 390+20*sin(theta));
   }
   glEnd();

     glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-1100+70*cos(theta), 550+30*sin(theta));
   }

    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(-1200+70*cos(theta), 520+30*sin(theta));
   }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(800+70*cos(theta), 390+30*sin(theta));
   }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
   {
       theta=i*3.142/180;
       glVertex2f(950+100*cos(theta), 365+30*sin(theta));
   }
    glEnd();
    glPopMatrix();



    //tree 1
    glPushMatrix();
    glTranslatef(350, -140, 0.0);
    glScalef(0.8, 1.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.000, 1.000, 0.000);
    glVertex2i(60, 0);
    glColor3f(0.000, 0.502, 0.000);
    glVertex2i(240, 0);
    glColor3f(0.000, 1.000, 0.000);
    glVertex2i(150, 100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.000, 1.000, 0.000);
    glVertex2i(80, 50);
     glColor3f(0.000, 0.502, 0.000);
    glVertex2i(220, 50);
    glColor3f(0.000, 1.000, 0.000);
    glVertex2i(150, 120);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.000, 1.000, 0.000);
    glVertex2i(100, 100);
    glColor3f(0.000, 0.502, 0.000);
    glVertex2i(200, 100);
    glColor3f(0.000, 1.000, 0.000);
    glVertex2i(150, 150);
    glEnd();



    glColor3f(0.647, 0.165, 0.165);
    glBegin(GL_QUADS);
    glVertex2i(140, 0);
    glVertex2i(140, -60);
    glVertex2i(160, -60);
    glVertex2i(160, 0);
    glEnd();
    glPopMatrix();

    //tree 2
    glPushMatrix();
    glTranslatef(650, -110, 0.0);
    glScalef(1, 1.5, 0.0);


    glBegin(GL_TRIANGLES);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2i(60, 0);
    glColor3f(0.000, 0.392, 0.000);
    glVertex2i(240, 0);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2i(150, 100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2i(80, 50);
    glColor3f(0.000, 0.392, 0.000);
    glVertex2i(220, 50);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2i(150, 120);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3f(0.196, 0.804, 0.196);
    glVertex2i(100, 100);
    glColor3f(0.000, 0.392, 0.000);
    glVertex2i(200, 100);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2i(150, 150);
    glEnd();



    glColor3f(0.647, 0.165, 0.165);
    glBegin(GL_QUADS);
    glVertex2i(140, 0);
    glVertex2i(140, -60);
    glVertex2i(160, -60);
    glVertex2i(160, 0);
    glEnd();
    glPopMatrix();

    //birds

    glPushMatrix();
    glTranslatef(_bird_move,0.0,-0.5);
    glTranslatef(0,300,-0.5);
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(10, -10, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(-10, -10, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(-10, 10, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(20, -20, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(-20, -20, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

     glTranslatef(-20, 20, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(-30, 20, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(30, 25, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(-35, -10, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(-35, -10, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();


    glTranslatef(-35, -10, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(-40, -10, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();

    glTranslatef(90, -30, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 6);
    glVertex2i(5, -6);
    glVertex2i(15, 0);
    glEnd();


    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

void update(int value)
{

    _Car_move +=5;
	if (_Car_move > 700) {
		_Car_move -=1600;
	}

	_Car2_move -=4;
	if (_Car2_move <- 800) {
		_Car2_move +=1600;
	}

	_boat_move -=2;
	if (_boat_move < -1200) {
		_boat_move +=1900;
	}
	_cloud_move +=1;
	if (_cloud_move > 700) {
		_cloud_move -=1100;
	}
	_bird_move +=2;
	if (_bird_move > 980) {
		_bird_move -=1900;
	}
    _angle += 1;
	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA| GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(900, 600);
    glutCreateWindow("River-bridge");
    init();
    glutDisplayFunc(drawScene);
    glutIdleFunc(drawScene);
    glutTimerFunc(25, update, 0);
    //glutFullScreen();
    glutMainLoop();
    return 0;
}
