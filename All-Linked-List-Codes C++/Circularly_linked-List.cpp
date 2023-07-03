# include <iostream>
# include <map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};
void InsertAtNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    
void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

void deleteNode(Node* &tail , int value ){
    if(tail == NULL){
        cout << " List Is EMpty Please check again " << endl;
        return;
    }
    else{
    // List is Not empty
    Node* prev = tail;
    Node* curr = prev-> next;
    while(curr -> data !=  value){
        prev = curr;
        curr = curr-> next;
        }
        prev -> next = curr -> next;
         //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr){
            tail = prev;
        }
         curr->next = NULL;
         delete curr;
    }

}
Node* floydDetectLoop(Node* head){
    if (head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL){

        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow-> next;
        if(slow == fast) {
            //cout << "present at " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;

}


int main(){
    Node* tail = NULL;
    InsertAtNode(tail, 5, 3);
    print(tail);
    InsertAtNode(tail, 3, 5);
    print(tail);
    InsertAtNode(tail, 5, 7);
    print(tail);
    InsertAtNode(tail, 7, 9);
    print(tail);
    InsertAtNode(tail, 5, 6);
    print(tail);
    InsertAtNode(tail, 9, 10);
    print(tail);
    InsertAtNode(tail, 3, 4);
    print(tail);
    deleteNode(tail, 5);
    print(tail);

    Node* loopNode = floydDetectLoop(tail);

    if (loopNode != NULL) {
        cout << "Cycle is present at node " << loopNode->data << endl;
    }
    else {
        cout << "No cycle" << endl;
    }

}
