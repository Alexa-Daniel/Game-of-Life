#include <fstream>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#define NMAX 100
#define ND 8

using namespace std;

ifstream fin("joc.in");

bool a[NMAX][NMAX], b[NMAX][NMAX];
int n, m, i, j;
int dl[]={-1, -1, -1, 0, 1, 1, 1, 0};
int dc[]={-1, 0, 1, 1, 1, 0, -1, -1};

void joc();
void mutare();

int main()
{
    char x='4';
    fin>>n>>m;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            fin>>a[i][j];
        }
    }
    system("Color 04");
    while(true)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(a[i][j]==1)
                {
                    cout<<'O';
                }
                else
                {
                    cout<<' ';
                }
            }
            cout<<'\n';
        }
        Sleep(200);
        joc();
        mutare();
        cin.get(x);
        system("CLS");
    }
    return 0;
}

void joc()
{
    int k, celule;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            celule=0;
            for(k=0; k<ND; k++)
            {
                if(a[i+dl[k]][j+dc[k]]==1)
                {
                    celule++;
                }
            }
            if(a[i][j]==1)
            {
                if(celule<=1 || celule>3)
                {
                    b[i][j]=0;
                }
                else
                {
                    b[i][j]=a[i][j];
                }
            }
            else if(celule==3)
            {
                b[i][j]=1;
            }
            else
            {
                b[i][j]=a[i][j];
            }
        }
    }
}

void mutare()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            a[i][j]=b[i][j];
        }
    }
}


/*
25 25

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/
