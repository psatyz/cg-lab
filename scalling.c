#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
struct point
{
int x;
int y;
};
typedef float mat[3][3];
mat tm;
void identity(mat m)
{
int i,j;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
if(i==j)
m[i][j]=1;
else
m[i][j]=0;
}
void multiply(mat a,mat b)
{
int i,j,k;
mat temp;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{
temp[i][j]=0;
for(k=0;k<3;k++)
temp[i][j]+=a[i][k]*b[k][j];
}
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=temp[i][j];
}
void scalling(float sx,float sy,struct point refpt)
{
mat m;
identity(m);
m[0][0]=sx;
m[0][2]=refpt.x*(1-sx);
m[1][1]=sy;
m[1][2]=refpt.y*(1-sy);
multiply(m,tm);
}
void transform(int n,struct point *pts)
{
int k;
float temp;
for(k=0;k<n;k++)
{
temp=tm[0][0]*pts[k].x+tm[0][1]*pts[k].y+tm[0][2];
pts[k].y=tm[1][0]*pts[k].x+tm[1][1]*pts[k].y+tm[1][2];
pts[k].x=temp;
}
}
void main()
{
int i,j;
struct point pts[4]={220.0,50.0,320.0,200.0,150.0,200.0,220.0,50.0};
struct point refpt={220.0,50.0};
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(0);
setcolor(RED);
drawpoly(4,pts);
getch();
identity(tm);
for(i=0;i<3;i++)
for(j=0;j<3;j++)
printf("%d  ",tm[i][j]);
getch();
scalling(0.5,0.5,refpt);
for(i=0;i<3;i++)
for(j=0;j<3;j++)
printf("%d  ",tm[i][j]);
getch();
transform(4,pts);
cleardevice();
setcolor(BLUE);
drawpoly(4,pts);
getch();
closegraph();
}
