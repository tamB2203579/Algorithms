#include <iostream>
using namespace std;

typedef struct {
    int data;
    Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

void initList(LinkedList *L) {
    L->head = nullptr;
    L->size = 0;
}

bool isEmpty(LinkedList *L) {
    return L->head == nullptr;
}

void freeList(LinkedList *L) {
    Node *current = L->head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    L->head = nullptr;
    L->size = 0;
}

int getAt(LinkedList *L, int index) {
    if (index < 0 || index >= L->size) {
        cout << "Index out of range" << endl;
        return -1;
    }
    Node *current = L->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void setAt(LinkedList *L, int index, int value) {
    if (index < 0 || index >= L->size) {
        cout << "Index out of range" << endl;
        return;
    }
    Node *current = L->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;
}

void insertFirst(LinkedList *L, int value) {
    Node *newNode = new Node{value, L->head};
    L->head = newNode;
    L->size++;
}

void insertLast(LinkedList *L, int value) {
    Node *newNode = new Node{value, nullptr};
    if (isEmpty(L)) {
        L->head = newNode;
    } else {
        Node *current = L->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    L->size++;
}

void insertAt(LinkedList *L, int value, int index) {
    if (index < 0 || index > L->size) {
        cout << "Index out of range" << endl;
        return;
    }
    if (index == 0) {
        insertFirst(L, value);
        return;
    }
    Node *current = L->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node *newNode = new Node{value, current->next};
    current->next = newNode;
    L->size++;
}

int popFirst(LinkedList *L) {
    if (isEmpty(L)) {
        cout << "List is empty" << endl;
        return - 1;
    }
    Node *temp = L->head;
    int value = temp->data;
    L->head = L->head->next;
    delete temp;
    L->size--;
    return value;
}

int popLast(LinkedList *L) {
    if (isEmpty(L)) {
        cout << "List is empty" << endl;
        return -1;
    }
    if (L->head->next == nullptr) {
        int value = L->head->data;
        delete L->head;
        L->head = nullptr;
        L->size--;
        return value;
    }
    Node *current = L->head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    int value = current->next->data;
    delete current->next;
    current->next = nullptr;
    L->size--;
    return value;
}

int popAt(LinkedList *L, int index) {
    if (index < 0 || index >= L->size) {
        cout << "Index out of range" << endl;
        return -1;
    }
    if (index == 0) {
        return popFirst(L);
    }
    Node *current = L->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node *temp = current->next;
    int value = temp->data;
    current->next = temp->next;
    delete temp;
    L->size--;
    return value;
}

int find(LinkedList *L, int value) {
    Node *current = L->head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == value) return index;
        current = current->next;
        index++;
    }
    return -1;
}

bool contains(LinkedList *L, int value) {
    return find(L, value) != -1;
}

void printList(LinkedList *L) {
    Node *current = L->head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}