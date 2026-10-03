# include <iostream>
using namespace std;

struct Queue{
    int data;
    Queue* next;
};

Queue* CreateNode(int data){
    Queue* temp = new Queue;
    temp->data =data;
    temp->next = NULL;
    return temp;
}

Queue* push(Queue* front, int data) {
    //insert the node at the tail of the LL.
    Queue* temp, *ptr = front;
    temp = CreateNode (data);
    if (front == NULL) {
        //Queue is empty
        front = temp;
        return front;
    }
    //going to the tail
    while (ptr->next){
        ptr = ptr->next;
    }
    ptr->next = temp;
    return front;
}

Queue* pop(Queue* front) {
    // Delete the node from the front(head) of the LL.
    Queue* temp = front;
    if (front == NULL) {
        cout<<"Queue is empty"<<endl;
        return NULL;
    }
    front = front->next;
    delete temp;
    return front;
}

void display (Queue* front) {
    Queue* temp = front;
    while (temp) {
        cout<< temp->data <<"->";
        temp = temp->next;    
    }
    cout<<"NULL"<<endl;
}

int main() {
    Queue* front = NULL;
    
    front = push(front, 10);
    front = push(front, 20);
    front = push(front, 30);
    front = push(front, 40);
    front = push(front, 50);
    
    display(front);

    front = pop (front);
    front = pop (front);

    display(front);
    return 0;
}