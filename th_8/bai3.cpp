#include<iostream>
#include<stack>
#include <cstdlib>

#define N 10

using namespace std;
// segment
void quickSort(int a[], int n, int l, int r)
{
	if(l >= r)
		return;
		
	int pivot = l;
	int ap = a[pivot];
	int i = l;
	int j = r;
	
	while(i < j)
	{
		if(i < pivot && a[i] <= a[pivot]) 
			i++;
		if(j > pivot && a[j] > a[pivot]) 
			j--;
			
		//cout<<i << " " <<j<< endl;//

		if(a[i] < a[pivot] && a[j] > a[pivot])
			continue;
	
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	quickSort(a, n, l, pivot - 1);
	quickSort(a, n, pivot + 1, r);
}

void randomization(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		a[i] = rand() % 210;
	}
}

void print(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout<<endl;
}

int main()
{
	int a[N];
	randomization(a, N);
	print(a, N);
	quickSort(a, N, 0, N - 1);
	print(a, N);
	return 0;
}
