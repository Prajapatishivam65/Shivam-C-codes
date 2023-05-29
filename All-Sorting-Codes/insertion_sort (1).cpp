# include <iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}
void insertionSort(int arr[], int n){
     int i = 1;
     while(i<n){
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
            j--;
        }
         //copy temp value
        arr[j+1] = temp; 
        i++;
     }
}
int main() {
int srt[4] = {4,3,2,1};
insertionSort(srt,4);
printArray(srt,4);
}
