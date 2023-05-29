# include <iostream>
using namespace std;
void printArray( int arr[], int n){
    for(int i = 0; i < n ; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int n){
for(int i = 0; i < n-1; i++){
      bool exp = false;
    for(int j = 0; j < n-i-1; j++){
        if(arr[j]>arr[j + 1]){
            swap(arr[j],arr[j + 1]);
        }
        exp = true;
    }
    if(exp == false){
        break;
    }
}
}
int main() {
int arr1[8] = { 2,3,4,7,9,8,1,5};
bubbleSort(arr1 , 8);
printArray(arr1 , 8);
}