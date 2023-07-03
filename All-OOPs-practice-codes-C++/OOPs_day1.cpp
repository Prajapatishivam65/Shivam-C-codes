#include <iostream>
#include <cstring>
using namespace std;

class Hanuman {
private:
    int shakti;
public:
    char mann;
    char *name;

    Hanuman(){
        cout << " Simple Constructor called " << endl;
        name = new  char[100];
    }

    // Copy Constructor
    Hanuman(Hanuman& top){
        cout <<"Copy Constructor Called" << endl;
        this->shakti = this->shakti;
        this->mann = this->mann; 
    }

    // Parameterized Constructor
    Hanuman(int shakti) {
        cout << "This is " << this << endl;
        this->shakti = shakti;
    }
    
    // Parameterized Constructor
    Hanuman(int shakti, char mann) {
        this->mann = mann;
        this->shakti = shakti;
    }
    
    void print() {
        cout << "shakti " << this-> shakti << endl;
        cout << "mann  " << this->mann << endl;
        cout << "name " << this -> name << endl;
    }
    
    int getshakti() {
        return shakti;
    }
    
    char getmann() {
        return mann;
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

};

int main() {

    Hanuman hanuman1;
    hanuman1.setshakti(18);
    hanuman1.setmann('H');
    char name[8] = "Shivam";
    hanuman1.setName(name);
    hanuman1.print();



     /*
    Hanuman ram(79,'M');
    ram.print();
    Hanuman lakshman(ram);
    lakshman.print();
    */
    /*
    // Statically 
    Hanuman bhakt(10, 'S');
    cout << "Address of Bhakt is " << &bhakt << endl;
    cout << "Shakti: " << bhakt.getshakti() << endl;
    cout << "Mann is " << bhakt.getmann() << endl;
    
    // Dynamically
    Hanuman *daas = new Hanuman(6);
    daas->print();
    delete daas;
    
    Hanuman sevak(65, 'A');
    sevak.print();
   */
   /* // Statically

    Hanuman hanu;
    hanu.shakti = 100;
    cout << " Shakti is ->  " << hanu.shakti << endl;
    hanu.mann = 'B';
    cout << " mann is ->    " << hanu.mann << endl;


    hanu.setshakti(70);
    cout << " hanuman health is " << hanu.getshakti() << endl;
    hanu.setmann('A');
    cout << " mann is      " << hanu.getmann() << endl;


    // Dynamically
    Hanuman *man = new Hanuman;
    
    (*man).setmann('C');
    (*man).setshakti(80);
    cout << " mann is    " << (*man).mann << endl;
    cout << " shakti  is " << (*man).getshakti() << endl;

    man->setmann('D');
    man->setshakti(90);

    cout << " mann is    " << man-> mann << endl;
    cout << " shakti is  " << man-> getshakti()  << endl;
    */
}
