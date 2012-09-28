#include <stdio.h>

int main()
{
	int arr[9]={2,4,0,5,2,0,9,0,1};
//	int arr[9]={2,4,0,5,2,0,9,10,1};
	
	int numIndex,zeroIndex,size;
size=	numIndex = zeroIndex = sizeof(arr)/sizeof(int) - 1;
	
	while(1)
	{
		if(arr[numIndex]==0)
		{	numIndex--;
			break;
		}
		numIndex--;
		zeroIndex--;
	}

	while(numIndex>=0)
	{
		if(arr[numIndex]==0)
		{
			numIndex--;
			continue;
		}
		else if(numIndex<zeroIndex);
		{
			arr[zeroIndex]=arr[numIndex];
			zeroIndex--;
			numIndex--;
			
		}
		
		
	}
	
	
	while(zeroIndex>=0)
	{
		arr[zeroIndex]=0;
		zeroIndex--;
	}
	printf("\n");
int i;
	for(i = 0 ;i<=size;i++)
	{
		printf("%d ",arr[i]);
	}
}
