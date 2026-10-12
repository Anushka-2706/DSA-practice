#include <iostream>
#include <cstdlib>
using namespace std;

#define ERR(e)                                      \
do {                                                \
    if (e == -1) {                                  \
        cout<<"[ERROR]"<<endl;                        \
        exit(EXIT_FAILURE);                         \
    }                                               \
} while (0)

int *Queue;
int front;
int rear;
int Qsize;

void init(int sz) {
    Qsize = sz;
    Queue = new int[Qsize];
    front = -1;
    rear = -1;
}

void enQueue(int data) {
    if (rear == Qsize - 1) {
        cout<<"Overflow"<<endl;
        ERR(-1);
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    Queue[rear] = data;
}

int deQueue() {
    int data;
    if (front == -1 || front > rear) {
        cout<<"Underflow"<<endl;
        ERR(-1);
    }
    data = Queue[front];
    front++;
    return data;
}

int peek(){
    if (front == -1 || front > rear) {
        cout<<"Empty"<<endl;
        ERR(-1);
    }
    return Queue[front];
}

void display() {
    int i;

    if (front == -1 || front > rear) {
        cout<<"Queue is Empty"<<endl;
        return;
    }

    for (i = front; i <= rear; i++) {
        cout<<Queue[i]<<endl;
    }

    cout<<"NULL"<<endl;
}

int main() {
    init(5);

    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);

    display();

    peek();

    deQueue();
    deQueue();

    display();

    cout<<"Front element:"<<peek()<<endl;

    free(Queue);

    return 0;
}