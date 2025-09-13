#include <iostream>
using namespace std;

typedef struct {
    int *data;
    int capacity;
    int top;
} Stack;

void initStack(Stack *S, int capacity) {
    S->data = nullptr;
    S->capacity = capacity;
    S->top = -1;
}

void freeStack(Stack *S) {
    delete[] S->data;
    S->data = nullptr;
    S->capacity = 0;
    S->top = -1;
}

void resize(Stack *S) {
    int newCapacity = S->capacity * 2;
    int *newData = new int[newCapacity];
    for (int i = 0; i <= S->top; i++) {
        newData[i] = S->data[i];
    }
    delete[] S->data;
    S->data = newData;
    S->capacity = newCapacity;
}

bool isEmpty(Stack *S) {
    return S->top == -1;
}

int size(Stack *S) {
    return S->top + 1;
}

void push(Stack *S, int value) {
    if (S->top == S->capacity - 1) {
        resize(S);
    }
    S->data[++S->top] = value;
}

int pop(Stack *S) {
    if (isEmpty(S)) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return S->data[S->top--];
}

int peek(Stack *S) {
    if (isEmpty(S)) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return S->data[S->top];
}

void printStack(Stack *S) {
    if (isEmpty(S)) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack (bottom -> top): ";
    for (int i = 0; i <= S->top; i++) {
        cout << S->data[i] << " ";
    }
    cout << endl;
}