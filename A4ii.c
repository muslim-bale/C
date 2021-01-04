#include<stdio.h>
#define S 30

int binSearch(int a[],int beg,int end,int ele)
{
	int mid;
	if (end>=beg)
	{
		mid = (beg+end)/2;
		if (a[mid] == ele)
		{
			return mid+1;
		}
		else if (a[mid]<ele)
		{
			return binSearch (a, mid+1, end, ele);
		}
		else
		{
			return binSearch (a, beg, mid-1, ele);
		}	
	}
	else
	{
		return -1;
	}
}


void main ()
{
	int a[S];
	int ele, i, n, pos=0;


	printf("\nEnter the Size of the Array : ");
	scanf("%d", &n);
	
	printf("\nEnter the Elements of the Array : \n");
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	

	printf("\nEnter the element to be searched for : ");
	scanf("%d", &ele);

	pos = binSearch (a, 0, n-1, ele);
	

	if (pos ==-1)
	{
		printf("\nElement Not Found\n");
	}
	else
	{
		printf("\nElement Found at %d\n",pos);
	}
}