// TITLE : APPLICATION OF GRAVITATION AND ORBITAL MECHANICS

#include <stdio.h>
#include <math.h>
#include <graphics.h>
float gravity(float *g1,float m1,float r1,float *g2,float m2, float r2)
{
     float G1=6.67,G2=-11;
     *g1=(G1*m1)/(r1*r1);
     *g2=G2+m2-(2*r2);
}
float gravity_h(float g,float r,float h,float *gh)
{
     *gh=g*r*r/((r+h)*(r+h));
}
float velocity(float *Vc1,float m1,float r1,float *Vc2,float m2,float r2,float h)
{
     float G1=6.67,G2=-11,R;
     R=r1*pow(10,r2);
     *Vc1=sqrt((G1*m1)/(R+h));
     *Vc2=(G2+m2)/2;
}
int main()
{
     float G1=6.67,G2=-11,M1,M2,R1,R2,a,b,R,height,v1,v2,Vc,Ve,Vh,g,m,g_h;
     float KE,KE1,KE2,PE,TE,BE,Te=1,Tp,rp;
     int gd=DETECT, gm;
     printf("Give the significant figures in mass of planet\n");
     scanf("%f",&M1);
     printf("Give the term in power of 10 in mass of planet\n");
     scanf("%f",&M2);
     printf("Give the significant figures in radius of planet\n");
     scanf("%f",&R1);
     printf("Give the term in power of 10 in radius of planet\n");
     scanf("%f",&R2);
     R=R1*pow(10,R2);
     gravity(&a,M1,R1,&b,M2,R2);
     g=a*pow(10,b);
     printf("\nAcceleration due to gravity with high precision is    %.7f x 10^%.7f m/s^2\n",a,b);
     printf("\nAcceleration due to gravity is    %.1f m/s^2\n",g);
     printf("\nEnter the Height to which satellite is to be launched\n");
     scanf("%f",&height);
     gravity_h(g,R,height,&g_h);
     printf("\nThe Acceleration due to gravity at height %f metres is %f m/s^2 \n",height,g_h);
     printf("\nGive the mass of the satellite\n");
     scanf("%f",&m);
     printf("\nGive the velocity of projection : ");
     scanf("%f",&Vh);
     velocity(&v1,M1,R1,&v2,M2,R2,height);
     Vc=v1*pow(10,v2);
     Ve=sqrt(2*g*R);
     printf("\nCritical velocity of satellite in that orbit is     %f m/s\n",Vc);
     printf("\nVelocity of projection of satellite at the height is      %.7f  m/s\n",Vh);
     printf("\nEscape velocity of satellite from the gravitational field is    %.1f m/s\n",Ve);
     initgraph(&gd, &gm,(char*)"");
     if(Vh<Vc)
     {
        printf("\nTHE SATELLITE WILL PERFORM MOTION IN ELLIPTICAL ORBIT WITH STARTING POSITION AS APOGEE\n");
        for(int i=0;i<50;i++)
        {
         setcolor(BROWN);
         circle(250, 200, i);
         delay(30);
        }
        ellipse(250,190,0,360,60,100);
     }
     if(Vh==Vc)
     {
        printf("\nTHE SATELLITE WILL PERFORM CIRCULAR MOTION AROUND PLANET IN A DEFINITE ORBIT\n");
        for(int i=0;i<50;i++)
        {
         setcolor(GREEN);
         circle(250, 200, i);
         delay(30);
        }
        circle(250, 200, 150);
     }
     if(Vh>Vc && Vh<Ve)
     {
        printf("\nTHE SATELLITE WILL PERFORM ELLIPTICAL MOTION AROUND PLANET \n");
        for(int i=0;i<50;i++)
        {
         setcolor(YELLOW);
         circle(250, 200, i);
         delay(30);
        }
        ellipse(250,250,0,360,80,150);
     }
     if(Vh==Ve)
     {
        printf("\nTHE SATELLITE WILL PERFORM MOTION IN PARABOLIC PATH\n");
        for(int i=0;i<50;i++)
        {
         setcolor(BLUE);
         circle(250, 200, i);
         delay(30);
        }
        ellipse(250,450,0,360,150,350);
     }
     if(Vh>Ve)
     {
        printf("\nTHE SATELLITE WILL PERFORM MOTION IN HYPERBOLIC PATH AND ESCAPE FROM PLANET'S GRAVITIONAL FIELD\n");
        for(int i=0;i<50;i++)
        {
         setcolor(WHITE);
         circle(300, 200, i);
         delay(30);
        }
        ellipse(300,590,0,360,300,550);
     }
     printf("\nEnter the radius of orbit of planet from the star around which it is revolving with respect to earth \n");
     scanf("%f",&rp);
     Tp=sqrt(pow(rp,3))*Te;
     printf("\nTime period of the planet is %f years\n",Tp);
     KE1=(G1*M1*m)/(2*(R+height));
     KE2=G2+M2;
     KE=KE1*pow(10,KE2);
     PE=(-2)*KE;
     BE=KE;
     TE=-KE;
     printf("\nKinetic energy associated with the satellite is %f J\n",KE);
     printf("\nPotential energy associated with the satellite is %f J\n",PE);
     printf("\nTotal energy associated with the satellite is %f J\n",TE);
     printf("\nBinding energy associated with the satellite is %f J\n",BE);
     getch();
     closegraph();
     return 0;
}
