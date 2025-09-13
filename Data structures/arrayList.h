#include <iostream>
using namespace std;

typedef struct {
	int *data;		// pointer to dynamic array
	int size;		// current number of elements
	int capacity;	// maximum capacity
} ArrayList;

// Initialize the list with given capacity
void initList(ArrayList &L, int capacity) {
	L.data = new int[capacity];
	L.size = 0;
	L.capacity = capacity;
}

// Free memory and reset list
void freeList(ArrayList &L) {
    delete[] L.data;
    L.data = nullptr;
    L.size = 0;
    L.capacity = 0;
}

// Double the capacity of the list when it’s full
void resize(ArrayList &L) {
	int newCapacity = L.capacity * 2;
	int *newData = new int[newCapacity];
	for (int i = 0; i < L.size; i++) {
		newData[i] = L.data[i];
	}
	delete[] L.data;		//free old memory
	L.data = newData;
	L.capacity = newCapacity;
}

// Get element by index
int get(ArrayList L, int index) {
    if (index < 0 || index >= L.size) {
        cout << "Index out of range\n";
        return -1;
    }
    return L.data[index];
}

// Set value at index
void set(ArrayList &L, int index, int value) {
    if (index < 0 || index >= L.size) {
        cout << "Index out of range\n";
        return;
    }
    L.data[index] = value;
}

// Find index of value (return -1 if not found)
int find(ArrayList L, int value) {
    for (int i = 0; i < L.size; i++) {
        if (L.data[i] == value) return i;
    }
    return -1;
}

// Add element at the end
void push_back(ArrayList &L, int value) {
    if (L.size == L.capacity) {
        resize(L);
    }
    L.data[L.size++] = value;
}

// Remove and return last element
int pop_back(ArrayList &L) {
	if (L.size == 0) {
		cout << "List empty" << endl;
		return -1;
	}
	return L.data[--L.size];
}

// Insert element at index
void insert(ArrayList &L, int index, int value) {
    if (index < 0 || index > L.size) {
        cout << "Index out of range\n";
        return;
    }
    if (L.size == L.capacity) resize(L);
    for (int i = L.size; i > index; i--) {
        L.data[i] = L.data[i - 1];		//shift values to the right
    }
    L.data[index] = value;
    L.size++;
}

// Remove element at index
int removeAt(ArrayList &L, int index) {
    if (index < 0 || index >= L.size) {
        cout << "Index out of range\n";
        return -1;
    }
    int removed = L.data[index];
    for (int i = index; i < L.size - 1; i++) {
        L.data[i] = L.data[i + 1];		//shift values to the left
    }
    L.size--;
    return removed;
}

// Remove first occurrence of a value
int removeValue(ArrayList &L, int value) {
    int idx = find(L, value);
    if (idx == -1)
		cout << "Value not found" << endl;
		return -1;
    return removeAt(L, idx);
}

// Check if value exists in the list
bool contains(ArrayList L, int value) {
    return find(L, value) != -1;
}

// Print all elements
void printList(ArrayList L) {
    for (int i = 0; i < L.size; i++)
		cout << L.data[i] << " ";
    cout << "\n";
}
