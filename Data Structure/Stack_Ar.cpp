#include <iostream>
#include <cstdlib>
using namespace std;

#define ERR(e)\
do { \
    if (e == -1) { \
        cout<<"[ERROR]" << __FUNCTION__<<endl; \
        exit(EXIT_FAILURE); \
        } \
} while(0)

int* stack;
int top;
int Stsize;

int init(int sz) {
    Stsize = sz;
    stack = new int[Stsize];
    top = -1;
    if (stack == NULL) {
        ERR(-1);
    }
    return 0;
}

int push(int data) {
    if (top == Stsize-1) {
        cout<<"Stack Overflow"<<endl;
        ERR(-1);
    }
    top++;
    stack[top] = data;
    return 0;
}

int pop(){
    if (top == -1) {
        cout<<"Stack Underflow"<<endl;
        ERR(-1);
    }
    top--;
    return 0;
}

int peek(){
    if (top == -1) {
        cout<<"Stack is Empty"<<endl;
        ERR(-1);
    }
    return stack[top];
}

void display(){
    int i;
    for (i=0; i<=top; i++) {
        printf("%d\n", stack[i]);
    }
    return;
}

int main() {
    int i;
    int err = 0;
    err = init(5);

    //Push 10, 22, 30, 40, 50
    err = push(10);
    err = push(22);
    err = push(30);
    err = push(40);
    err = push(50);

    display();

    cout<<"top element:"<<peek()<<endl;

    for(i=0; i<2; i++) {
        err = pop();
    }

    display();

    cout<<"top element:"<<peek()<<endl;

    return 0;
}