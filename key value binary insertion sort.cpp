#include<stdio.h>
#include<conio.h>
int a[100],b[100];
/*This function finds the position of selected element in the sorted list left to selected element.*/
int binsearch(int l,int h,int si,int si1)
{
	int m;
	while(l<=h)
	{
		m=(l+h)/2;
		if((si<a[m])&&(l<h))
		h=m-1;
		else if((si>a[m])&&(l<h))
		l=m+1;
		else if(si==a[m])
		{
			if((si1<b[m])&&(l<h))
			h=m-1;
			else if((si1>b[m])&&(l<h))
			l=m+1;
			else if((si1<b[m])&&(l==h))
			return m;
			else
			return m+1;
		}
		else if((si<a[m])&&(l==h))
		return m;
		else if((si>a[m])&&(l==h))
		return m+1;
	
	}
	
}
/*This is the main function which performs insertion sort.Finds the position of selected element inserts it in the left sorted list.*/
void inssort(int n)
{
	int i,select,l,j,select1;
	for(i=1;i<n;i++)
	{
		select=a[i];
		select1=b[i];
		j=i-1;
		l=binsearch(0,j,select,select1);
		while(j>=l)
		{
			a[j+1]=a[j];
			b[j+1]=b[j];
			j--;
		}
		a[j+1]=select;
		b[j+1]=select1;
		
	}
}
/*This function is for input and output of key value pairs.*/
int main()
{
	int n,i;
	printf("enter number of keys\n");
	scanf("%d",&n);
	printf("enter the keys and corresponding values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d,%d",&a[i],&b[i]);
	}
	inssort(n);
	printf("sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf(" (%d,%d)\n ",a[i],b[i]);
	}
	return 0;
	
}
