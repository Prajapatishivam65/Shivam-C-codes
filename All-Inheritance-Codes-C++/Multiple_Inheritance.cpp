# include <iostream>
using namespace std;

class Animal{
    public:
    int age ;
    int weight;

    public:

    void bark(){
        cout <<"BHau BHau BHOK Diya  " << endl;
    }

};

class Human {

    public :
    string colour;
    public:
    
    void speak(){
        cout << "Bol Rha hu Gunga nhi hU NOOB " << endl;
    }
};

// Multiple Inheritance 

class Hybrid : public Human , public Animal {

};

int main(){

 Hybrid d;
 d.speak();
 d.bark();
 
 return 0;
}