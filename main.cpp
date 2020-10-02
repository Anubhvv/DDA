#include <graphics.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <stdio.h>

//driver code
int maxy,maxx;
float m;
float x1,yy1,x2,y2,X1,X2,Y1,Y2;
char str[]={'L','i','n','e',' ','1',' ','\0'};


void printaxes()
{
    line(30,0,30,maxy);
line(31,0,31,maxy);

line(0,maxy,maxx,maxy);
line(0,maxy-1,maxx,maxy-1);
outtextxy(300,maxy+2,"X-axis -->");


outtextxy(0+2,maxy+2,"(0,0)");
}
void printslope()
{
    std::cout<<"m="<<m<<"\n";
    std::cout<<"1/m="<<1/m<<"\n";
}

void start()
{
    setcolor(LIGHTRED);

    circle(X1,Y1,7);
    line(X1,maxy-5,X1,maxy+5);
    line(25,Y1,35,Y1);
    line(X1+1,maxy-5,X1+1,maxy+5);
    line(25,Y1+1,35,Y1+1);

    setcolor(LIGHTBLUE);
    line(X2,maxy-5,X2,maxy+5);
    line(X2+1,maxy-5,X2+1,maxy+5);
    line(25,Y2,35,Y2);
    line(25,Y2+1,35,Y2+1);

    putpixel(X1,Y1,RED);
}
void ending()
{
        setcolor(LIGHTBLUE);
    putpixel(X2,Y2,RED);
    circle(X2,Y2,7);
    setcolor(WHITE);
    char *str[8]={"Y","|","a","x","i","s","|","^"};
    for(int i=0;i<8;i++)
        outtextxy(4,340-30*i,str[i]);

    line(30,0,15,15);
    line(30,0,45,15);
    line(maxx-15,maxy-15,maxx,maxy);
    line(maxx-15,maxy+15,maxx,maxy);
}
int main()
{

    maxx=1000,maxy=600;
    	initwindow(maxx+30,maxy+25,"DDL plotting by Anubhav");
    int count=0;

    while(++count){
    std::cout<<count<<".) Enter the point (x1,y1) , (x2,y2) separated by SPACE:";
    std::cin>>x1>>yy1>>x2>>y2;
    str[5]=count+'0';
    outtextxy(x1+15,maxy-yy1+15,str);

    if(x2<x1)
    {
        float t=x1;
        x1=x2;
        x2=t;
        t=yy1;
        yy1=y2;
        y2=t;
    }
    maxx=1000,maxy=600;

	maxx+=30;
    X1=x1+30;
    Y1=maxy-yy1;
    X2=x2+30;
    Y2=maxy-y2;
    x1+=30; x2+=30;
    printaxes();

    m=(yy1-y2)*1.0/(x1-x2)*1.0;

    printslope();

    start();

    float x=X1,y=Y1;

    if(x1==x2)
    {
        std::cout<<"infinity slope ";
      while(y!=Y2)
        {
            y--;
            std::cout<<"("<<x<<", "<<y<<")";
            putpixel(lround(x),lround(y),GREEN);
            delay(10);
        }

    }
    else if(m>=0 && m<=1)
    {   while(x<=X2)
        {
            x=x+1;
            y=y-m;

            putpixel(lround(x),lround(y),GREEN);
            delay(10);
        }

    }
    else if(m>1)
    {   while(x<=X2)
        {
            y=y-1;
            x=x+1.0/m;
            putpixel(lround(x),lround(y),GREEN);
            delay(10);
        }

    }
    else if(m<0 && m>=-1)
    {
        while(x<=x2)
        {
            x=x+1;
            y=y-m;

            putpixel(lround(x),lround(y),GREEN);
            delay(10);
        }

    }
    else
    {
        while(x<=x2)
        {
            x=x-1/m;
            y=y+1;
            putpixel(lround(x),lround(y),GREEN);
            delay(10);
        }

    }
    ending();

    }
    getch();
}
