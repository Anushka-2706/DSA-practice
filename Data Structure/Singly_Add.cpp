#include <iostream>
using namespace std;

//define a node.
struct Node {
    int data;
    struct Node* next;
};

//create a new node.
Node* createNode(int data) {
    Node* PTR = new Node;
    PTR->data = data;
    PTR->next = NULL;
    return PTR;
}

//add a node at begnning.
Node* InsertionAtHead(Node* head, int data){
    Node* PTR = createNode(data);

    if (head == NULL) {
        head = PTR;   //first node
        return head;
    }

    PTR->next = head;
    head = PTR;
    return head;
}

//add node at end.
Node* InsertionAtTail(Node* head, int data){
    Node* PTR = createNode(data);
    Node* temp = head;

    if (head == NULL) {
        head = PTR;   //first node
        return head;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = PTR;
    return head;
}

//add node at specific position.
Node* InsertionAtPos(Node* head, int data, int pos){
    Node* PTR = createNode(data);

    if (head == NULL) {
        cout << "Empty linked list" << endl;
        return NULL;
    }

    if (pos == 1){
        PTR->next = head;
        head = PTR;
        return head;
    }

    int i = 1;
    Node* temp = head;

    while (i < pos -1) {
        temp = temp->next;
        i = i+1;
    }

    PTR->next = temp->next;
    temp->next = PTR;
    return head;
}

//delete a node at first position.
Node* DelAtHead(Node* head) {
    if (head == NULL) {
        cout<< "Empty Linked List" <<endl;
        return head;
    }
    
    Node* PTR = head;
    head = head->next;
    delete PTR;
    return head;
}
//delete a node at last position.
Node* DelAtTail(Node* head) {
    if (head == NULL) {
        cout<< "Empty Linked List" <<endl;
        return head;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* PTR = head;
    Node* temp = PTR;
    while (PTR->next != NULL) {
        temp = PTR;
        PTR = PTR->next;
    }
    temp->next = NULL;
    delete PTR;
    return head;
}

//delete a node at specific position.
Node* DelAtPos(Node* head, int pos) {
    if (head == NULL) {
        cout<< "Empty Linked List" <<endl;
        return head;
    }
    if (pos == 1) {
        Node* PTR = head;
        head = head->next;
        delete PTR;
        return NULL;
    }
    int i = 0;
    Node* PTR = head;
    Node* temp = PTR;

    while (i < pos-1) {
        temp = PTR;
        PTR = PTR->next;
        i = i+1;
    }
    temp->next = PTR->next;
    delete PTR;
    return head;
}

void display(Node* head) {
    Node* PTR = head;

    while (PTR != NULL) {
        cout << PTR->data << " ";
        PTR = PTR->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    head = InsertionAtHead(head, 24);
    head = InsertionAtHead(head, 12);
    head = InsertionAtHead(head, 10);

    head = InsertionAtTail(head, 36);
    head = InsertionAtTail(head, 48);
    head = InsertionAtTail(head, 62);

    display(head);

    head = DelAtHead(head);
    display(head);

    head = DelAtTail(head);
    display(head);

    head = InsertionAtHead(head, 0);
    display(head);

    head = InsertionAtTail(head, 60);
    display(head);

    head = DelAtPos(head, 4);
    display(head);
    
    return 0;

}