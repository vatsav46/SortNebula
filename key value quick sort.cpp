#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n;
int a[100],b[100];
/*This function swaps the values given.*/
void swap(int *s,int *d,int *x,int *z)
{
	int y,b;
	y=*s;
	*s=*d;
	*d=y;
	b=*x;
	*x=*z;
	*z=b;
}
/*This function finds the position of pivot in the list.This position is called partitioning position.*/
int part(int l,int h)
{
	int i,j,pvt,bpvt;
	i=l;
	j=h;
	pvt=a[l];
	bpvt=b[l];
	while(i<j)
	{
		do
		{
			i++;
		}while((a[i]<=pvt)&&(b[i]<=bpvt));
		do
		{
			j--;
		}while(a[j]>pvt);
		if(i<j)
		{
			swap(&a[i],&a[j],&b[i],&b[j]);
		}
		
	}
	swap(&a[l],&a[j],&b[l],&b[j]);
	return j;
}
/*This function performs quick sort finds the partitioning position and calls itself recursively for a[l...p] and a[p+1.....h] arrays.*/
void quicksort(int l,int h)
{
	int p;
	if(l<h)
	{
		p=part(l,h);
		quicksort(l,p);
		quicksort(p+1,h);
	}
}
/*This function is for input and output of key value pairs.*/
int main()
{
	int i,l=0,h;
	printf("enter number of keys\n");
	scanf("%d",&n);
	h=n;
	a[n]=30000;
	printf("enter the keys and corresponding values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d,%d",&a[i],&b[i]);
	}
	quicksort(l,h);
	printf("sorted key values are\n");
	for(i=0;i<n;i++)
	{
		printf("(%d,%d)\n",a[i],b[i]);
	}
	return 0;	
}
