#include <iostream>
using namespace std;

typedef struct {
    int *data;
    int front, rear, size, capacity;
} Queue;

void initQueue(Queue *Q, int capacity){
	Q->data = new int[capacity];
    Q->capacity = capacity;
	Q->front = 0;
    Q->rear= -1;
    Q->size = 0;
}

void freeQueue(Queue *Q) {
    delete[] Q->data;
    Q->data = nullptr;
    Q->capacity = 0;
    Q->front = 0;
    Q->rear = -1;
    Q->size = 0;
}

bool isEmpty(Queue *Q) {
    return Q->size == 0;
}

bool isFull(Queue *Q) {
    return Q->size == Q->capacity;
}

void enqueue(Queue *Q, int value) {
    if (isFull(Q)) {
        cout << "Queue full\n";
    }
    Q->rear++;
    Q->data[Q->rear] = value;
    Q->size++;
}

int dequeue(Queue *Q) {
    if (isEmpty(Q)) {
        cout << "Queue empty\n";
        return -1;
    }
    int value = Q->data[Q->front];
    Q->front++;
    Q->size--;
    return value;
}

int front(Queue *Q){
    if (isEmpty(Q)) {
        cout << "Queue empty\n";
        return -1;
    }
    return Q->data[Q->front];
}

void printQueue(Queue *Q) {
    if (isEmpty(Q)) {
        cout << "Queue empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = Q->front; i <= Q->rear; i++) {
        cout << Q->data[i] << " ";
    }
    cout << "\n";
}
