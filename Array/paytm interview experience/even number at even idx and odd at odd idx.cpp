// C++ implementation to arrange 
// odd and even numbers 
#include <bits/stdc++.h> 
using namespace std; 

int findnext(int s , int e , int des , int a[]){
	for(int i=s+1;i<e;i++){
    	if(a[i]%2 == des){
        	return i;
        }
    }
}

// function to arrange odd and even numbers 
void arrangeOddAndEven(int a[], int n) 
{ 
	for(int i=0;i<n;i++){
    
      int pos = i;
      int value = a[i];
      
      if(pos % 2 ==0 and value % 2 ==0){
        continue;
      }
      
      if(pos % 2 == 1 and value % 2 == 1){
        continue;
      }
      
      int idx = findnext(pos , n , pos%2,a);
    	swap(a[idx],a[pos]);
    }
} 

// function to print the array 
void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = { 3, 6, 12, 1, 5, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << "Original Array: "; 
	printArray(arr, n); 

	arrangeOddAndEven(arr, n); 

	cout << "\nModified Array: "; 
	printArray(arr, n); 

	return 0; 
} 
a