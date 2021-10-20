//Algorithm : Depth first search (Graph G, Souce_Vertex S)
//1.    Create a stack STK to store the vertices.
//2.    Push the source vertex S in the stack STK.
//3.    While the stack STK is not empty
//4.        Pop the vertex U from the top of the stack. i.e Vertex U = STK.top(), STK.pop()
//5.        If the vertex U is not visited, Then
//6.            Explore the vertex U and mark U as visited.
//7.            For every vertex V adjacent to vertex U
//8.                Push the vertex V in the stack STK
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10];
int main()
{
    int m;
    cout <<"Enter no of vertices:";
    cin >> n;
    cout <<"Enter no of edges:";
    cin >> m;
    cout <<"\nEDGES \n";
    for(k=1; k<=m; k++)
    {
        cin >>i>>j;
        cost[i][j]=1;
    }
    cout <<"Enter initial vertex to traverse from:";
    cin >>v;
    cout <<"DFS ORDER OF VISITED VERTICES:";
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=n; j>=1; j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                stk[top]=j;
                top++;
            }
        v=stk[--top];
        cout<<v << " ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    return 0;
}
