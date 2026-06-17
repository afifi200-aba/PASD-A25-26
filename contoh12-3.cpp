#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
int del();
void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);
void push(int item);
int pop();
int main()
{
    int n,i,s,ch,j;
    cout << "Masukkan Data "; cin >> n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout << "Masukkan "<< i <<" Data Jika Mempunyai Simpul " << j <<" selain itu  " ;
            cin >> a[i][j];
        }
    }
    cout << "Matrik Adjacency" << endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        cout << "  MENU" << endl;
        cout << "~~~~~~~~~~" << endl;
        cout << "1. BFS - Breadth First Search"<< endl;
        cout << "2. DFS - Depth First Search"<< endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout << "         Pilihan" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout << "Pilih : "; cin >> ch;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout << "Masukan Simpul Sumber: "; cin >> s;
        switch(ch)
        {
            case 1: bfs(s,n); break;
            case 2: dfs(s,n); break;
            case 3:
            break;
        }
        return(0);
    }
    return 0;
}

void bfs(int s,int n)
{
    int p,i;
    add(s);
    vis[s]=1;
    p=del();
    if(p!=0)
        cout << p <<" ";
    while(p!=0)
    {
        for(i=1;i<=n;i++)
            if((a[p][i]!=0)&&(vis[i]==0))
            {
                add(i);
                vis[i]=1;
            }
        p=del();
        if(p!=0)
            cout << p << " ";
    }
    for(i=1;i<=n;i++)
        if (vis[i]==0)
            bfs(i,n);
}

void add(int item)
{
    if (rear==19)
    {
        cout << "Antrian Penuh" << endl;
        cout << "~~~~~~~~~~~~~~~" << endl;
    }
    else
        if (rear==-1)
        {
            q[++rear]=item;
            front++;
        }
        else
            q[++rear]=item;
}

int del()
{
    int k;
    if((front>rear)||(front==-1))
        return(0);
    else
    {
        k=q[front++];
        return(k);
    }
}

void dfs(int s, int n)
{
    int i,k;
    push(s);
    vis[s]=1;
    k=pop();
    if(k!=0)
        cout << k << " ";
    while(k!=0)
    {
        for(i=1;i<=n;i++)
            if((a[k][i]!=0)&&(vis[i]==0))
            {
                push(i);
                vis[i]=1;
            }
        k=pop();
        if (k!=0)
            cout << k << " ";
    }
    for(i=1;i<=n;i++)
        if (vis[i]==0)
            dfs(i,n);
}

void push(int item)
{
    if(top==19)
        cout << "Stack Overflow" << endl;
    else
        stack[++top]=item;
}

int pop()
{
    int k;
    if (top==-1)
        return(0);
    else
    {
        k=stack[top--];
        return(k);
    }
}