#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int a[100],f[100];
/*This function merges the two sub arrays and performs sorting simultaneously.*/
void merg(int l,int m,int h)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=h-m;
	int b[n1],t[n2];
	int o[n1],p[n2];
	for(i=0;i<n1;i++)
	{
		b[i]=a[l+i];
		o[i]=f[l+i];
	}
	for(j=0;j<n2;j++)
	{
		t[j]=a[m+1+j];
		p[j]=f[m+1+j];
	}
	i=0;
	j=0;
	k=l;
	while((i<n1)&&(j<n2))
	{
		if((b[i]<t[j]))
		{
			a[k]=b[i];
			f[k]=o[i];
			i++;
		}
		else if((b[i]=t[j])&&(o[i]<=p[j]))
		{
			a[k]=b[i];
			f[k]=o[i];
			i++;
			
		}
		else
		{
			a[k]=t[j];
			f[k]=p[j];
			j++;
		}
		
		k++;
	}
	while(i<n1)
	{
		a[k]=b[i];
		f[k]=o[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=t[j];
		f[k]=p[j];
		j++;
		k++;
	}
}
/*This function divides the each array into two sub arrays recursively until each array contains single element and merges it by calling merg function.*/
void mersort(int l,int h)
{
	if(l<h)
	{
		int m=(l+h)/2;
		mersort(l,m);
		mersort(m+1,h);
		merg(l,m,h);
	}
}
/*This function is used for input and output of key value pairs.*/
int main()
{
	int n;
	int i,l=0,h;
	printf("enter number of keys\n");
	scanf("%d",&n);
	h=n-1;
	printf("enter the keys and corresponding values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d,%d",&a[i],&f[i]);
	}
	mersort(l,h);
	for(i=0;i<n;i++)
	{
		printf("(%d,%d)\n ",a[i],f[i]);
	}
	return 0;	
}
