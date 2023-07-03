#include <iostream>
#include <cstring>  // Required for strcpy()
using namespace std;

class Hanuman {
private:
    int shakti;
public:
    char mann;
    char* name;

    Hanuman() {
        cout << "Simple Constructor called" << endl;
        name = new char[100];
    }

    // Copy Constructor (shallow copy)
    Hanuman(const Hanuman& top) {
        cout << "Copy Constructor Called" << endl;
        this->shakti = top.shakti;  // Copy shakti from the source object
        this->mann = top.mann;      // Copy mann from the source object
        this->name = top.name;      // Shallow copy of the name pointer
    }

    // Parameterized Constructor
    Hanuman(int shakti) {
        cout << "This is " << this << endl;
        this->shakti = shakti;
        name = new char[100];  // Allocate memory for name
    }

    // Parameterized Constructor
    Hanuman(int shakti, char mann) {
        this->mann = mann;
        this->shakti = shakti;
        name = new char[100];  // Allocate memory for name
    }

    void print() {
        cout << "shakti: " << this->shakti << endl;
        cout << "mann: " << this->mann << endl;
        cout << "name: " << this->name << endl;
    }

    int getshakti() {
        return shakti;
    }

    char getmann() {
        return mann;
    }

    char* getname() {
        return name;
    }

    void setshakti(int power) {
        shakti = power;
    }

    void setmann(char dis) {
        mann = dis;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    // Destructor
    ~Hanuman() {
        delete[] name;  // Deallocate the dynamically allocated memory
    }
};

int main() {
    Hanuman hanuman1;
    hanuman1.setshakti(18);
    hanuman1.setmann('H');
    char name[8] = "Shivam";
    hanuman1.setName(name);
    hanuman1.print();

    // Create a new object using the copy constructor
    Hanuman hanuman2(hanuman1);
    hanuman2.print();

    // Modify the name in hanuman1
    hanuman1.setName("Ram");

    // Both hanuman1 and hanuman2 will reflect the same change due to shallow copy
    hanuman1.print();
    hanuman2.print();

    return 0;
}

