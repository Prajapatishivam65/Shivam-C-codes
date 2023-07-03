# include <iostream>
# include <map>
using namespace std;

class Node{
    public:
    int data;
    Node*next ;
    // Constructor
   Node(int data){
    this -> data = data;
    this -> next = NULL;
   }
   // Destructor
   ~Node(){
    int value = this-> data;
    // memory free
    if( this-> next != NULL){
        delete next;
        this->next = NULL;
    }
    cout << " Memeory is freed for the Element " << value << endl;
   }
};

void DeleteNode(int position , Node* &head){
    // Deleting node at start Position
    if(position == 1){
    Node* temp = head;
    head = temp->next;
    temp -> next = NULL;
    delete temp;
    }
    else{
        // Deleting any Last Node Or Middle Node
        Node* curr = head;
        Node* prev = NULL;
        int Count = 1;
        while(Count < position){
            prev = curr;
            curr = curr-> next;
            Count++;
        }

        prev->next = curr-> next;
        curr -> next = NULL;
        delete curr;

    }
}
void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void InsertAThead( Node* &head, int d ){
    // new Node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void InsertATtail(Node* &Tail , int d){
    Node* temp = new Node(d);
    Tail -> next = temp;
    Tail = temp;

}
void InsertATposition(Node* &head, Node* &Tail, int position, int d) {
    // Inserting at first position
    if (position == 1) {
        InsertAThead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        InsertATtail(Tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

bool  detectloop(Node* head){
    
   if (head == NULL || head->next == NULL)
        return false;

    Node* temp = head; 
     map<Node*, bool> visited;
    while(temp != NULL){
        // cyccle is present
    if(visited[temp] == true){
        return true;
    }
    // to mark true
        visited[temp] = true;
        temp = temp->next;
    }    
    return false;
}

Node* floydDetectLoop(Node* head){
    if (head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow-> next;
        if(slow == fast) {
            cout << "present at " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;

}
Node* getstarting(Node* &head){
    if(head == NULL){
        return NULL;
    }
    
    Node* intersection = floydDetectLoop(head);
    Node* slow = head;
    while(slow !=  intersection){
        slow = slow->next;
        intersection = intersection-> next;
    }
    return slow ;
}

void removeloop(Node* &head){
    if (head == NULL){
        return ;
    }
    Node* startofloop = getstarting(head);
    if (startofloop == NULL) {
        return;
    }
    Node* temp = startofloop;
    while(temp ->  next  != startofloop){
        temp = temp-> next;
    }

      temp->next = NULL;
}
int main(){
   //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
   // cout << node1 -> next << endl;
    
    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    //print(head);

   InsertATtail(tail, 12);


    //print(head);
    
    InsertATtail(tail, 15);
    //print(head);

    InsertATposition(head,tail, 4, 22);
    //print(head);    

    //cout << "head " << head -> data << endl;
    //cout << "tail " << tail -> data << endl;

    //deleteNode(4, head);
    
    tail-> next = head->next;

    cout << "head " << head-> data << endl;
    cout << "tail " << tail-> data << endl;
    //print(head);


   Node* loopNode = floydDetectLoop(head);

    if (loopNode != NULL) {
        cout << "Cycle is present at node " << loopNode->data << endl;
    }
    else {
        cout << "No cycle is present " << endl;
    }

    Node* loopno = getstarting(head);
    cout << "Loop starts from " << loopno->data << endl;

    removeloop(head);
    print(head);
    cout << "head " << head-> data << endl;
    cout << "tail " << tail-> data << endl;
}