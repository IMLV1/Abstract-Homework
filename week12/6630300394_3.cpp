#include <iostream>
#include <string>
using namespace std;

int A[16];
int length, heapsize = 0;

void input_array(int A[]) {
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
}

void print_heap(int A[]) {
	cout << "Heap : ";
	for (int i = 1; i <= heapsize ; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
}

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

void heap_insert(int A[], int key) {
	heapsize++;
	int i = heapsize;
	while(i > 1 && A[parents(i) < key]) {
		A[i] = A[parents(i)];
		i = parents(i);
		A[i] = key;
	}
}

int Heap_Exact_Max(int A[]) {
	if (heapsize < 1) {
		cout << "Heap Underflow\n";
		return 0;
	} 
	int Max = A[1];
	A[1] = A[heapsize];
	heapsize--;
	Heapify(A,1);
	return Max;
}

int main() {
	int select, data;
	do {
		cout << "=======================\n"
				"          MENU\n"
				"=======================\n"
				"1. Input Array\n"
				"2. Print Heap\n"
				"3. Insert Queue\n"
				"4. Service\n"
				"5. Exit\n"
				"   Please choose > ";
		cin >> select;
		cin.ignore();
				
		switch(select) {
			case 1:
				input_array(A);
				break;
			case 2:
				Build_heap(A);
				print_heap(A);
				break;
			case 3:
				cout << "Input : ";
				cin >> data;
				heap_insert(A,data);
				print_heap(A);
				break;
			case 4:
				cout << "Service : " << Heap_Exact_Max(A) << "\n";
				print_heap(A);
				break;
			case 5:
				cout << "Exiting...";
				break;	
			default:
				cout << "Invalid selection. Please try again\n";
		}
	} while(select != 5);
	return 0;
}

/* 
test case : 8 7 10 14 9 3 2 4 1 16
Insert Queue : 200
*/
