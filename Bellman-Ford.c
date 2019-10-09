#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

/*
** Program to find shortest path using Bellman-Ford algorithm
** Made by - Abhishek Chand
*/

struct Edge
{
	int u;
	int v;
	int w;
};

struct Graph
{
	int V;
	int E;
	struct Edge *edge;
};

void bellmanford(struct Graph *g, int source);
void printpath(int *pred,int x);

int main()
{
	int i,j,k,w;
	
	struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
	printf("\nEnter the no. of vertex:");
	scanf("%d",&(g->V));
	printf("\nEnter the no. of edges:");
	scanf("%d",&(g->E));
	
	g->edge=(struct Edge*)malloc(g->E*sizeof(struct Edge));
	
	for(k=0;k<(g->E);k++)
	{
		printf("\nEnter an edge(in form i j w):");
		scanf("%d %d %d",&i,&j,&w);
		g->edge[k].u=i;
		g->edge[k].v=j;
		g->edge[k].w=w;
	}
	
	
	bellmanford(g,0);
	
	return 0;
}

void bellmanford(struct Graph *g, int source)
{
	
	int i,j,u,v,w;
	int tV=g->V;
	int tE=g->E;
	int d[tV];
	int p[tV];
	
	for (i=0;i<tV;i++)
	{
		d[i]=INFINITY;
		p[i]=-1;
	}
	
	d[source]=0;
	
	for(i=1;i<=tV-1;i++)
	{
		for(j=0;j<tE;j++)
		{
			u=g->edge[j].u;
			v=g->edge[j].v;
			w=g->edge[j].w;
			
			if(d[u]!=INFINITY && d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				p[v]=u;
			}
		}
	}
	

	for(i=0;i<tE;i++)
	{
		u=g->edge[i].u;
		v=g->edge[i].v;
		w=g->edge[i].w;
		if(d[u]!=INFINITY && d[v]>d[u]+w)
		{
			printf("\nNegative weight cycle detected!\n");
			return;
		}
	}
	
	
	printf("\nDistance");
	for(i=0;i<tV;i++)
	{
		printf("\n%d %d",i,d[i]);
		printpath(p,i);
	}
}

void printpath(int *pred,int x)
{
	if(pred[x]==-1)
	{
		printf(" %d",x);
		return;
	}	
	printpath(pred,pred[x]);
	printf("-->%d",x);
}
