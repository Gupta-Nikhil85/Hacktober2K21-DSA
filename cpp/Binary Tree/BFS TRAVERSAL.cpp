// Algorithm: Breadth First search (Graph G, Souce_Vertex S)
//1.    Create a queue Q to store the vertices.
//2.    Push the source vertex S in the queue Q.
//3.    Mark S as visited.
//4.    While the queue Q is not empty
//5.        Remove vertex U from the front of the queue. i.e Vertex U = Q.front(), Q.pop()
//6.        For every vertex V adjacent to the vertex U
//7.            If the vertex V is not visited Then
//8.               Explore the vertex V and mark V as visited.
//9.               Push the vertex V in the queue Q.
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,qu[10],front,rare,v,visit[10],visited[10];
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
    cout <<"Visitied vertices:";
    cout <<v<<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=1; j<=n; j++)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                qu[rare++]=j;
            }
        v=qu[front++];
        cout<<v <<" ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    return 0;
}
