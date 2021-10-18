#include<stdio.h>
#include<conio.h>

int min(int,int);
void floyds(int p[10][10],int n) {
	int i,j,k;
	for (k=1;k<=n;k++)
	  for (i=1;i<=n;i++)
	   for (j=1;j<=n;j++)
	    if(i==j)
	     p[i][j]=0; else
	     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b) {
	if(a<b)
	  return(a); else
	  return(b);
}
int main() {
	int p[10][10],w,n,e,u,v,i,j;
	int k;
	;

	printf("\n Enter the number of emergency exit:");
	scanf("%d",&n);
	printf("\n Enter the number of Ways between exit:\n");
	scanf("%d",&e);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++)
		   p[i][j]= 9999;
	}
	for (i=1;i<=e;i++) {
		printf("\n Enter the Emergeny exits of way %d with its Length \n",i);
		scanf("%d%d%d",&u,&v,&w);
		p[u][v]=w;
	}
	printf("\n Matrix of input data:\n");
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++)
		   printf("%d \t",p[i][j]);
		printf("\n");
	}
	floyds(p,n);
	printf("\n Distance matrix :\n");
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++)
		   printf("%d \t",p[i][j]);
		printf("\n");
	}
	printf("Enter the Emergency Exit that is affected by fire ");
	scanf("%d",&k);
	printf("\n The shortest paths from that exit to all exit is :\n");
	
	  for (j=1;j<=n;j++) {
		if(i!=j)
		    printf("\n <%d,%d>=%d",k,j,p[k][j]);
	}

}


