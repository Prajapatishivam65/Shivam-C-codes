# include <iostream>
# include <math.h>
using namespace std;
  bool ispalindrome(string &str , int s, int n ){
    // base case
    int e = n-s-1;
    if (s>e){
        return true;
    }
    if (str[s]!=str[e]){
        return false;
    }
    else {
        // recursive call
    return ispalindrome(str , s+1 , n);
       }
  }

int main(){
    string name = "bookkoob";
    int nn =name.length()-1;
    bool pallo = ispalindrome(name , 0,name.length());
    if (pallo){
        cout << "Its a Pallindrome " << endl;
    }
    else{
        cout << " Its Not a Palindrome " << endl;
    }
}
