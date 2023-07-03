#include <iostream>
using namespace std;

class A{
    public :
    void fun(){
        cout << " I Am A " << endl;
    }
};

class B{
    public :
    void fun(){
        cout << " I Am B " << endl;
    }
};

class C : public A , public B {
    public :
    void fun(){
        cout << " I Am C " << endl;
    }
};

int main(){
    
    C obj;
    obj.A::fun(); // Call the fun() member function of class A
    obj.B::fun(); // Call the fun() member function of class B
    obj.C::fun(); // Call the fun() member function of Class C
    return 0;

}