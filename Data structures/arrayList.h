#include <iostream>
using namespace std;

typedef struct {
	int *data;
	int size;
	int capacity;
} ArrayList;

void initList(ArrayList *L, int capacity) {
	L->data = new int[capacity];
	L->size = 0;
	L->capacity = capacity;
}

void freeList(ArrayList *L) {
    delete[] L->data;
    L->data = nullptr;
    L->size = 0;
    L->capacity = 0;
}

void resize(ArrayList *L) {
	int newCapacity = L->capacity * 2;
	int *newData = new int[newCapacity];
	for (int i = 0; i < L->size; i++) {
		newData[i] = L->data[i];
	}
	delete[] L->data;
	L->data = newData;
	L->capacity = newCapacity;
}

int get(ArrayList L, int index) {
    if (index < 0 || index >= L.size) {
        cout << "Index out of range\n";
        return -1;
    }
    return L.data[index];
}

void set(ArrayList *L, int index, int value) {
    if (index < 0 || index >= L->size) {
        cout << "Index out of range\n";
        return;
    }
    L->data[index] = value;
}

int find(ArrayList *L, int value) {
    for (int i = 0; i < L->size; i++) {
        if (L->data[i] == value) return i;
    }
    return -1;
}

void push_back(ArrayList *L, int value) {
    if (L->size == L->capacity) {
        resize(L);
    }
    L->data[L->size++] = value;
}

int pop_back(ArrayList *L) {
	if (L->size == 0) {
		cout << "List empty" << endl;
		return -1;
	}
	return L->data[--L->size];
}

void insert(ArrayList *L, int index, int value) {
    if (index < 0 || index > L->size) {
        cout << "Index out of range\n";
        return;
    }
    if (L->size == L->capacity) resize(L);
    for (int i = L->size; i > index; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[index] = value;
    L->size++;
}

int removeAt(ArrayList *L, int index) {
    if (index < 0 || index >= L->size) {
        cout << "Index out of range\n";
        return -1;
    }
    int removed = L->data[index];
    for (int i = index; i < L->size - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->size--;
    return removed;
}

int removeValue(ArrayList *L, int value) {
    int idx = find(L, value);
    if (idx == -1) {
		cout << "Value not found" << endl;
		return -1;
	}
    return removeAt(L, idx);
}

bool contains(ArrayList L, int value) {
    return find(&L, value) != -1;
}

void printList(ArrayList L) {
    for (int i = 0; i < L.size; i++)
		cout << L.data[i] << " ";
    cout << "\n";
}
