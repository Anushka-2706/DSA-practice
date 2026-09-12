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

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
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
    head = InsertionAtTail(head, 60);

    display(head);

    head = InsertionAtPos(head, 56, 2);
    display(head);

    head = InsertionAtPos(head, 79, 5);
    display(head);

    return 0;

}