# include <iostream>
using namespace std;
void printArray( int *arr, int n){
    for(int i = 0; i < n ; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void BubblySort( int arr[] , int n){
     //printArray(arr , 5);
    //base case 
    if(n == 0 || n == 1)
        return ;      
    // EK case solve karo baki recursion karlega 
    for (int i= 0; i<n-1; i++){
        if (arr[i] > arr[i+1]){         
            swap(arr[i] , arr[i+1]);
        }
    }
    BubblySort(arr , n-1);
}
int main(){
    int sort[11] = { 2,3,4,7,2,3,3,9,8,1,5};
    BubblySort(sort , 11);
    printArray(sort , 11);
}