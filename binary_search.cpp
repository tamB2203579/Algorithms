#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int> A, int target) {
	int low = 0;
	int high = A.size() - 1;
	while (low <= high) {
		int medium = (low + high) / 2;
		if (A[medium] == target)
			return true;
		else if (A[medium] < target)
			low = medium + 1;
		else
			high = medium - 1;
	}
	return false;
}
