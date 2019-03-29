#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

#define pi 3.14
#define x 300
#define y 200
#define l1 80
#define l2 100
#define m1 120
#define m2 80
#define g 1

float  theata1= pi/2;
float theata2= pi/2 ;
float t1_v=0;
float t2_v=0;

void main(){
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
float x1,y1,x2,y2;
int k,p;
int arr[1000][2],a=0;
//circle(300,300,5);
for ( k=0;k<1000;k++){

//setactivepage(0);
clearviewport();
fillellipse(x,y,2,2);
x1=x+l1*sin(theata1);
y1=y+l1*cos(theata1);
x2=x1+l2*sin(theata2);
y2=y1+l2*cos(theata2);
fillellipse(x1,y1,m1/15,m1/15);
fillellipse(x2,y2,m2/15,m2/15);
line(x,y,x1,y1);
line(x1,y1,x2,y2);
//clearviewport();
arr[a][0]=x2;
arr[a][1]=y2;

float num1=-g*(2*m1+m2)*sin(theata1);
float num2=-m2*g*sin(theata1-2*theata2);
float num3=-2*sin(theata1-theata2)*m2;
float num4=t2_v*t2_v*l2+t1_v*t1_v*l1*cos(theata1-theata2);
float den=l1*(2*m1+m2-m2*cos(2*theata1-2*theata2));

float t1_a=(num1+num2+num3*num4)/den;

num1=2*sin(theata1-theata2);
num2=(t1_v*t1_v*l1*(m1+m2));
num3=g*(m1+m2)*cos(theata1);
num4=t2_v*t2_v*l2*m2*cos(theata1-theata2);
den=l2*(2*m1+m2-m2*cos(2*theata1-2*theata2));

float t2_a=num1*(num2+num3+num4)/den;



t1_v=t1_v+t1_a;
t2_v=t2_v+t2_a;
theata1=theata1+t1_v;
theata2=theata2+t2_v;

//theata1+=0.1;
//theata2-=0.01;

a++;
//delay(100);
//setactivepage(1);
if(a>2){
for(p=1;p<a;p++){
line(arr[p-1][0],arr[p-1][1],arr[p][0],arr[p][1]);}
delay(100);
//setvisualpage(0);
}
}
getch();
closegraph();
}