#include <iostream>
using namespace std;

//define a node.
struct Node {
    int data;
    struct Node* next;
};

//create a new node.
Node* createNode(int data) {
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

Node* InsertionAtend(Node* head, int data){
    Node* ptr = createNode(data);
    Node* temp = head;

    if (head == NULL) {
        return ptr;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ptr;
    return head;
}

Node* reversList(Node* head) {
    Node* ptr = head;
    Node* temp = NULL;
    Node* newHead = NULL;

    while (ptr != NULL) {
        temp = ptr->next;
        ptr->next = newHead; // newHead was null so now address of first node becomes null 
        newHead = ptr;
        ptr = temp;
    }
    return newHead;
}
 void display (Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data <<" ";
        if (temp->next != NULL) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
 }

 int main() {
    Node* head = NULL;

    head = InsertionAtend(head, 10);
    head = InsertionAtend(head, 20);
    head = InsertionAtend(head, 30);
    head = InsertionAtend(head, 40);
    head = InsertionAtend(head, 50);
    head = InsertionAtend(head, 60);

    display(head);

    head = reversList(head);
    display(head);

    return 0;

 }