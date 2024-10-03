#include <iostream>
#include <string>
using namespace std;

int A[16];
int length, heapsize = 0;

int parents(int i) {
	return i / 2;
}

int left(int i) {
	return 2 * i;
}

int right(int i) {
	return (2 * i) + 1;
}

void Heapify(int A[], int i) {
	int largest;
	int l = left(i);
	int r = right(i);
	
	if (l <= heapsize && A[l] > A[i]) {
		largest = l;
	} else {
		largest = i;
	}
	if (r <= heapsize && A[r] > A[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(A[i], A[largest]);
		Heapify(A,largest);
	}
}

void Build_heap(int A[]) {
	length = heapsize;
	for (int i = length / 2; i >= 1; i--) {
		Heapify(A,i);
	}
}

void Heapsort(int A[]) {
	Build_heap(A);
	cout << "Heap Sort";
	int heaplength = heapsize;
	int index = 1;
	for (int i = length;i >= 2; i--) {
		swap(A[1], A[i]);
		heapsize--;
		cout << "\n#" << index++ << " : ";
		for (int i = 1; i <= heaplength ; i++) {
			cout << A[i] << " ";
		}
		Heapify(A,1);
	}
	cout << "\n#" << index << " : ";
	for (int i = 1; i <= heaplength ; i++) {
		cout << A[i] << " ";
	}
	heapsize = heaplength;
}

int main() {
	int Index = 1; 
    string data, currentValue = "";
    cout << "Input : ";
    getline(cin, data);
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == ' ') {
            if (!currentValue.empty()) {  
                int Value = stoi(currentValue);
                A[Index++] = Value; 
                heapsize++;
                currentValue = "";
            }
        } else {
            currentValue += data[i];
        }
    }
    if (!currentValue.empty()) {  
        int Value = stoi(currentValue);
        A[Index++] = Value;
        heapsize++;
    }
    
	Build_heap(A);
	cout << "Heap : ";
	for (int i = 1; i <= heapsize ; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	Heapsort(A);
	
	return 0;
}

// test case : 8 7 10 14 9 3 2 4 1 16