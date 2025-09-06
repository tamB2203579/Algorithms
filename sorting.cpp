#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble_sort(vector<int> A) {
	int high = A.size() - 1;
	bool swapping = true;
	while (swapping == true) {
		swapping = false;
		for (int i = 1; i <= high; i++) {
			if (A[i-1] > A[i]) {
				int temp = A[i];
				A[i] = A[i-1];
				A[i-1] = temp;
				swapping = true;
			}
		}
		high--;
	}
	return A;
}

vector<int> insertion_sort(vector<int> A) {
	for (int i = 0; i < A.size(); i++) {
		int j = i;
		while (j > 0 && A[j-1] > A[j]) {
			int temp = A[j-1];
			A[j-1] = A[j];
			A[j] = temp;
			j--;
		}
	}
	return A;
}

vector<int> merge(vector<int> left, vector<int> right) {
	int i = 0, j = 0;
	int l_size = left.size();
	int r_size = right.size();
	vector<int> result;
	while (i < l_size && j < r_size) {
		if (left[i] < right[j])
			result.push_back(left[i++]);
		else
			result.push_back(right[j++]);
	}
	while (i < l_size) result.push_back(left[i++]);
	while (j < r_size) result.push_back(right[j++]);
	return result;
}

vector<int> merge_sort(vector<int> A) {
	int n = A.size();
	if (n < 2)
		return A;
	int mid = n/2;
	vector<int> left = merge_sort(vector<int>(A.begin(), A.begin() + mid));
	vector<int> right = merge_sort(vector<int>(A.begin() + mid, A.end()));
	return merge(left, right);
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// Median approach: Avoid the worst case of sorted array input O(n^2)
int choosePivot(vector<int> &A, int low, int high) {
	int pivot_index = (low + high) / 2;
	int pivot_val = A[pivot_index];
	swap(A[pivot_index], A[low]);
	return pivot_val;
}

int partition_lomuto(vector<int> &A, int low, int high) {
	int pivot = choosePivot(A, low, high);
	int i = low - 1;
	for (int j = low; j <= high; j++) {
		if (A[j] < pivot)
			swap(A[++i], A[j]);
	}
	swap(A[i+1], A[high]);
	return i + 1;
}

int partition_hoare(vector<int> &A, int low, int high) {
	int pivot = choosePivot(A, low, high);
	int i = low, j = high;
	while (true) {
		do { i++; } while (A[i] < pivot);
		do { j--; } while (A[j] > pivot);
		if (i >= j)
			return j;
			
		swap(A[i], A[j]);
	}
}

void quick_sort(vector<int> &A, int low, int high) {
	if (low < high) {
		int index = partition_hoare(A, low, high);
		quick_sort(A, low, index);
		quick_sort(A, index + 1, high);
	}
}

void selection_sort(vector<int> &A) {
	for (int i = 0; i < A.size(); i++) {
		int smallest_idx = i;
		for (int j = i + 1; j < A.size(); j++) {
			if (A[j] < A[smallest_idx])
				smallest_idx = j;
		}
		int temp = A[i];
		A[i] = A[smallest_idx];
		A[smallest_idx] = temp;
	}
}
