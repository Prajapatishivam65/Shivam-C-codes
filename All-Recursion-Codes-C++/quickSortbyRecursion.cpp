#include <iostream>
using namespace std;
void printArray(int *arr, int n){
   for(int i = 0; i<n-1 ; i++){
      cout << arr[i] << endl;
   }cout << endl;
}

int partition(int *arr , int s , int e){
   int pivot = arr[s];
   int count = 0;
   for (int i = s+1; i<=e ; i++){
      if (arr[i] <= pivot){
         count++;
      }
   }
   // place pivot at riht place 
   int pivotIndex = s + count;
   swap(arr[pivotIndex],arr[s]);
   // left and right wala part sambhal lena 
   int i = s , j = e;
   while(i< pivotIndex && j > pivotIndex){
      while(arr[i] <= pivot){
         i++;
      }
      while(arr[j] >= pivot){
         j--;
      }
      if (i < pivotIndex && j > pivotIndex ){
         swap (arr[i++],arr[j--]);
      }
   }
   return pivotIndex;
}
void quickSort(int *arr , int s , int e){
   //base case
   if (s >= e){
      return;
   }
   //partition karenge
   int p = partition(arr , s , e);
   //
   quickSort( arr , s , p-1);
   // right wale part me jao
   quickSort( arr , p+1 , e);
}
int main (){
 
   int arr[10] = {2,4,1,6,9 ,9,9,9,9,9};
    int n = 10;
   quickSort(arr , 0, n -1);
   printArray(arr , n);
}