#include<bits/stdc++.h>
#include<graphics.h>
#include<windows.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include <ctime>


using namespace std;
int mx, my;
char arr[10000]="" ;
int play_push=true;

double x  = 10 , y = 200 ;
double cx1 = 5, cy1 = 0  , cr1 = 1 ;

int score = 0, s = 0, c= 1, g=0;
int temp=0, ck=0;

float ball_speed=1;
float timer=2000;
int i=1;

void over();
void play();
void start();
void uprocess();
void ins();

void uprocess()
{
    cleardevice();
    setcolor(BLACK);
    outtextxy(10,40,"??? Sorry, option is under constructed");
    setcolor(BLACK);
    setbkcolor(WHITE);

    delay(10);
    getch();

    start();
}
void ins()
{
    cleardevice();

    setcolor(WHITE);
    outtextxy(10,20,"Just catch the ball in the limited time.");
    outtextxy(10,45,"Catch ball and earn score.");
    outtextxy(10,70,"For moving in various rotation you can follow");
    outtextxy(10,95,"these instructions: ");

    outtextxy(10,125,"1. press 4 for left, 6 for right");
    outtextxy(10,150,"2. press 8 for up, 2 for down");
    outtextxy(10,175,"3. press 1 for left-down, 3 for right-down");
    outtextxy(10,200,"4. press 7 for left-up, 9 for right-up");

    setcolor(BLACK);
    outtextxy(10,235,"Idea is given by Amrita and Developed by Ruhul");
    outtextxy(10,270,"Special thanks to Dear Kawsar Ahmed Sir.");


    getch();
    start();

}

void over()
{
    FILE *f;
    f=fopen("High Score","r");
    fscanf(f,"%d",&temp);
    if(temp<score)
    {
        f=fopen("High Score","w");
        fprintf(f,"%d",score);

        fclose(f);
    }
    else
    {
        fclose(f);
    }

    cleardevice();

    settextstyle(3,0,5);
    setcolor(BLACK);
    outtextxy(170,40,"GAME OVER");
    sprintf(arr, "Your level %d", i);
    outtextxy(180,100,arr);

    sprintf(arr,"Your Score  %d", score);
    outtextxy(180,160,arr);
    setcolor(BLACK);

    getch();
    start();
}
void play()
{

z:
    for(; i<=100; i++)
        while(true)
        {
            timer=timer-0.89;
            if(timer < 0)
            {
                over();

            }
            if(kbhit())
            {
                char ch=getch();

                if(ch=='8')
                {
                    y-=10;
                }
                if(ch=='2')
                {
                    y+=10;
                }
                if(ch=='6')
                {
                    x+=10;
                }
                if(ch=='4')
                {
                    x-=10;
                }
                if(ch=='9')
                {
                    x+=10;
                    y-=10;

                }
                if(ch=='7')
                {
                    x-=10;
                    y-=10;
                }
                if(ch=='1')
                {
                    x-=10;
                    y+=10;
                }
                if(ch=='3')
                {
                    x+=10;
                    y+=10;
                }

                if(ch==' ')
                {
                    outtextxy(250,360,"Press Any key to Continue");
                    getch();
                }

            }

            sprintf(arr,"Level  %d   Score  =  %d ",i,score) ;
            settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
            setcolor(GREEN);
            outtextxy(450,20,arr);

            setcolor(WHITE);
            circle(cx1,cy1,cr1) ;
            setcolor(BLACK_PEN);
            setbkcolor(WHITE_PEN);

            sprintf(arr,"TimeLeft  =  %.2f",timer) ;
            outtextxy(450,50,arr);

            cy1+=ball_speed;

            if(cy1>400)
            {
                cy1 = 0 ;
                cx1 = rand() % 400 + 100 ;

            }
            bar(x, y, x+50, y+50);

            rectangle(x,y,x+50,y+50) ;

            setcolor(RED);
            setfillstyle(1,GREEN);
            rectangle(x,y, x+50,y-20);


            double temp = (cx1-x) *(cx1-x) + (cy1 - y ) *(cy1 - y )  ;
            temp = sqrt(temp);

            if(temp < (50))
            {
                cx1 = rand() % 400 + 100 ;
                cy1 = 0 ;
                score++;
            }

            delay(10) ;

            cleardevice();

            if(score>s)
            {
                s=score;
                cx1+=1;
                cy1+=.5;
                cr1+=1;
            }

            if(score==10*i)
            {
                ball_speed++;
                i++;
                timer=2000;
                goto z;
            }

            if(score==40*c)
            {
                cx1=5;
                cy1=0;
                cr1=1;
                c++;
            }
        }
    if(timer==0)
        over();
}

void start()
{
    int ck=0,temp=0;

    while(true)
    {

        cleardevice();

        mx=mousex();
        my=mousey();

        setfillstyle(15,2);
        bar(0,0,650,450);

        setfillstyle(1,BLACK);
        bar(200,50,435,90);
        settextstyle(8,0,3);
        setbkcolor(BLACK);
        setcolor(WHITE);
        outtextxy(260,56,"New Game");

        setfillstyle(1,WHITE_BRUSH);
        bar(200,120,435,160);
        settextstyle(8,0,3);
        setbkcolor(WHITE_BRUSH);
        setcolor(RED);
        outtextxy(240,66+60,"Select Level");

        setfillstyle(1,BLUE);
        bar(200,190,435,230);
        settextstyle(8,0,3);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(230,66+130,"Highest score");

        setfillstyle(1,WHITE_PEN);
        bar(200,250,435,295);
        settextstyle(8,0,3);
        setbkcolor(WHITE_PEN);
        setcolor(WHITE);
        outtextxy(240,66+195,"Instructions");

        setfillstyle(1,RED);
        bar(200,320,435,360);
        settextstyle(8,0,3);
        setbkcolor(RED);
        setcolor(WHITE);
        outtextxy(290,66+260,"Exit");

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mx>200 && mx<435 && my>130 && my<170)
            {

                uprocess();
            }
            if(mx>200 && mx<435 && my>60 && my<100)
            {
                ck=1;
                cleardevice();
                goto yeah;
            }
            if(mx>200 && mx<435 && my>200 && my<240)
            {
                char arr[20];
                FILE *f;
                f=fopen("High Score","r");
                fscanf(f,"%d",&temp);
                fclose(f);
                sprintf(arr,"High Score : %d",temp);
                cleardevice();
                settextstyle(1,0,4);
                outtextxy(150,200,arr);
                getch();

            }
            if(mx>200 && mx<435 && my>250 && my<290)
            {
                ins();
            }
            if(mx>200 && mx<435 && my>320 && my<360)
            {
                exit(0);
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }

        delay(400);
        cleardevice();
    }

yeah:

    if(ck==1)
    {
        play();
    }

}
int main()
{
    system("color D");
    printf("Simple bubble touching game project.");
    initwindow(650,450);

    setbkcolor(BLACKNESS);
    setcolor(BLUE);
    settextstyle(BLUE,0,GREEN);

    outtextxy(40,230,"WELCOME TO OUR C PROJECT.");
    delay(1200);
    cleardevice();
    outtextxy(40,230,"WELCOME TO OUR C PROJECT..");
    delay(1200);
    cleardevice();
    outtextxy(40,230,"WELCOME TO OUR C PROJECT...");
    delay(1200);
    cleardevice();
    outtextxy(40,230,"WELCOME TO OUR C PROJECT....");
    delay(1200);
    cleardevice();
    outtextxy(40,230,"WELCOME TO OUR C PROJECT.....");
    delay(1000);
    cleardevice();
    outtextxy(200,200,"LET'S START");
    delay(800);
    cleardevice();


    start();

    getch();
    closegraph();

    return 0;
}