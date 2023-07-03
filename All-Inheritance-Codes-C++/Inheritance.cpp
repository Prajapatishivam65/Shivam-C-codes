#include <iostream>
using namespace std;

class Human {
    public:
    int height;
    int weight;
    int age;

    public:
    int getage(){
        return this->age;
    }
    void setweight(int w){
        this->weight = w;
    }
    void setheight(int hj){
        this-> height = hj;
    }

};

class Male: public Human {
    public :
    string Colour;
    void sleep(){
        cout <<"Male  sleeping  " << endl;
    }
     void setheight(int hj){
        this-> height = hj;
    }
};


int main(){
    Human object2;
    Male object1;
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;
    cout << object1.Colour << endl;
    object1.sleep();
    object1.setweight(56);
    cout << object1.weight << endl;
    object2.setheight(11);
    cout << object2.height << endl;
    object1.setheight(6);
    cout << object1.height << endl;

    return 0;
}