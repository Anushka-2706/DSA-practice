#include <iostream>
using namespace std;

int top;
int size;

struct stack {
    int data;
    stack* next;
};

stack* CreateNode(int data) {
    stack* ptr = new stack;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

stack* push(stack* top, int data) {
    stack* ptr = NULL;
    if (top == NULL) {
        top = CreateNode(data);
        return top;
    }
    ptr = CreateNode(data);
    ptr->next = top;
    top = ptr;
    return top;
}

stack* pop(stack* top) {
    stack* ptr = NULL;
    if (top == NULL) {
        cout<<"stack Underflow"<<endl;
        return NULL;
    }
    ptr = top;
    top = top->next;
    delete ptr;
    return top;
}

int peek(stack* top) {
    if (top == NULL) {
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return top->data;
}

bool isEmpty(stack* top) {
    return top == NULL;
}

void display(stack* top){
    stack* temp = top;
    while (temp) {
        cout<< temp->data <<"->" ;
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

int main() {
    stack* top = NULL;
    int i;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    top = push(top, 60);

    display(top);
    
    cout<<"top element:"<<peek(top)<<endl;

    for (i=0; i<2; i++) {
    top = pop(top);
    }

    display(top);
    for (i=0; i<1; i++) {
    top = pop(top);
    }

    display(top);

    cout<<"Is stack empty:"<<isEmpty(top)<<endl;

    cout<<"top element:"<<peek(top)<<endl;

    return 0;
}