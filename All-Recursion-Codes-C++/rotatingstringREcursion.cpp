# include <iostream>
using namespace std;

void  reverse(string &str , int s , int e){
    cout << "reversing "<< str  <<"  " << s <<"  " << e << endl;
    if (s>e){
        return;
    }
   swap(str[s],str[e]);
   s++;
   e--;
   reverse(str , s, e);
}
int main(){
     int s = 0;
    string name = "abcde";
     cout << name.length() << endl;
    reverse(name , s , name.length()-s -1 );
    cout << name << endl;
}