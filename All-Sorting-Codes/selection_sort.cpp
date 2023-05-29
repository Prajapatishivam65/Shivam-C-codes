# include <iostream>
using namespace std;
void printArray (int arr[] ,int n){
    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void selectionSort(int arr[] , int n){
      for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n ; j++){
            if (arr[j]< arr[minIndex]){
            minIndex = j ;
            }

        }
        swap(arr[minIndex],arr[i]);
      }
}

int main(){
 int arr1[5] =  { 5, 4, 3, 2, 1};
 selectionSort(arr1 , 5);
 cout << "Sorted array in Acsending Order:\n"<< endl;
  printArray(arr1 , 5);
}