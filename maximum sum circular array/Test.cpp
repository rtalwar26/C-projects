//============================================================================
// Name        : Test.cpp
// Author      : Rajat
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>


using namespace std;
int currentSum=0;
int maxSum=0;
int getMax(int arr[],int size);
int updateCurrent(int val);
int setCurrent(int val);

int main() {

	int arr[]={-4,40,-400,400,80,-80,90,-100};
//	int arr[]={1,1,1,1,1,1,1};
//		int arr[]={-1,-1,-1,-1,-1,-1,-1};
	int result = getMax(arr,sizeof(arr)/sizeof(int));

	cout<<"The max is "<<result;
//Sub obj;
//	SuperClass *objSuper =&obj;
//	objSuper->description();
//	cout << "Hello World" << endl; // prints Hello World
	return 0;
}

int getMax(int arr[],int size)
{
	if(size<=0)
		return 0;

	int p,q,originalP;

	originalP=p=q=0;

	while(arr[p]<0)
	{
		p=(p+1)%size;

		if(p==originalP)
			return 0;
	}
	originalP=p;
	updateCurrent(arr[p]);

	cout<<"originalP is "<<originalP<<endl;

	q=(p+1)%size;
updateCurrent(arr[q]);

	while(1)
	{

		if(currentSum<0)
						{
							while(arr[q]<0){
								q=(q+1)%size;
								cout<<"skipping over negative q  "<<q<<endl;

								if(q==p)
									break;
							}

							p=q;
							if(p==originalP)
											{
								cout<<"p is"<<p<<"q is "<<q<<endl;
												return maxSum;
											}

							setCurrent(arr[q]);
						}
		else
		{
		q=(q+1)%size;

		if(p==q)
		{
			int prevP;
			while(arr[p]>=0)
			{
				cout<<"skipping ove positive p  "<<p<<endl;

				prevP=p;
				p=(p+1)%size;

				if(p==originalP)
				{
					cout<<"p is"<<p<<"q is "<<q<<endl;

					return maxSum;
				}

				updateCurrent(-arr[prevP]);

			}

			while(arr[p]<0)
			{
				cout<<"skipping over negative p  "<<p<<endl;

				prevP = p;
				p=(p+1)%size;

				if(p==originalP){
					cout<<"p is"<<p<<"q is "<<q<<endl;

					return maxSum;
				}

				updateCurrent(-arr[prevP]);

			}



		}



		cout<<"incrementing q to  "<<q<<endl;
		updateCurrent(arr[q]);
		}


	}

	return maxSum;
}


int setCurrent(int val)
{

	currentSum=val;
	cout<<"setting currentSum  "<<currentSum<<endl;

	if(currentSum>maxSum){
		maxSum = currentSum;

	}

return currentSum;
}


int updateCurrent(int val)
{

	currentSum+=val;
	cout<<"updating currentSum  "<<currentSum<<endl;

	if(currentSum>maxSum){
		maxSum = currentSum;

	}

return currentSum;
}
