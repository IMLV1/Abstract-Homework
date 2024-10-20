#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#define DATA_SIZE 3000000 
#define MAX_VALUE 10000
using namespace std;

int size = 0;

void Create_file() {
	srand(time(0));
	ofstream myfile;
	myfile.open("outfile.txt");
	for (int i = 0; i < DATA_SIZE; i++) {
	    myfile << rand() % MAX_VALUE << "\n";
	}
	myfile.close();
	cout << "File created\n";
}

void Read_file(int data[]) {
	try {
		ifstream myfile;
	    myfile.open("outfile.txt"); 
	    size = 0;
	    for (int i = 0; i < DATA_SIZE; i++) {
	        myfile >> data[i];
	        size++;
		}
	    myfile.close();
	} catch (const exception& e) {
        cout << "Exception " << e.what() << "\n";
	}
}

void Write_data(int data[], string filename) {
    ofstream outfile(filename);
    for (int i = 0; i < size; i++) {
        outfile << data[i] << "\n";
    }
    outfile.close();
    cout << "Sorted data saved to " << filename << "\n";
}

void Selection_Sort(int data[]) {
    Read_file(data);
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(data[i], data[minIndex]);
        }
    }
    Write_data(data, "Selection.txt");
}

void Bubble_Sort(int data[]) {
    Read_file(data);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    Write_data(data, "Bubble.txt");
}

void Insertion_Sort(int data[]) {
	Read_file(data);
	for (int p = 1 ; p < size; p++) {
		int j, tmp = data[p];
		for (j = p; j > 0 && data[j - 1] > tmp; j--) {
			data[j] = data[j - 1];
		}
		data[j] = tmp;
	}
	Write_data(data, "Insertion.txt");
}

void Shell_Sort(int data[]) {
	Read_file(data); 
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for(int i = gap; i < size ; i++) {
			int j, tmp = data[i];
			for (j = i; j >= gap && data[j - gap] > tmp; j -= gap) {
				data[j] = data[j - gap];
			}
			data[j] = tmp;
		}
	}
	Write_data(data, "Shell.txt");
}

void merge(int data[], int tmparray[], int lpos, int rpos, int rightend) {
    int i, leftend, numelements, tmppos;
    leftend = rpos - 1;
    tmppos = lpos;
    numelements = rightend - lpos + 1;
    
    while (lpos <= leftend && rpos <= rightend) {
        if (data[lpos] <= data[rpos]) {
            tmparray[tmppos++] = data[lpos++];
        } else {
            tmparray[tmppos++] = data[rpos++];
        }
    }
    
    while (lpos <= leftend) {
        tmparray[tmppos++] = data[lpos++];
    }
    
    while (rpos <= rightend) {
        tmparray[tmppos++] = data[rpos++];
    }
    
    for (i = 0; i < numelements; i++, rightend--) {
        data[rightend] = tmparray[rightend];
    }
}

void msort(int data[], int tmparray[], int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        msort(data, tmparray, left, center);
        msort(data, tmparray, center + 1, right);
        merge(data, tmparray, left, center + 1, right);
    }
}

void Merge_Sort(int data[]) {
    Read_file(data);
    int *tmparray = new int[size];
    msort(data, tmparray, 0, size - 1);
    Write_data(data, "Merge.txt");
}

void heapify(int data[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && data[left] > data[largest])
        largest = left;

    if (right < n && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
}

void Heap_Sort(int data[]) {
    Read_file(data);
    int n = size;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(data[0], data[i]);
        heapify(data, i, 0);
    }
    Write_data(data, "Heap.txt");
}

int partition(int data[], int low, int high) {
    int pivot = data[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (data[j] < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return (i + 1);
}

void QuickSort(int data[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(data, low, high);
        QuickSort(data, low, pivotIndex - 1);
        QuickSort(data, pivotIndex + 1, high);
    }
}

void Quick_Sort(int data[]) {
    Read_file(data);
    QuickSort(data, 0, size - 1);
    Write_data(data, "Quick.txt");
}

struct Node {
    int value;
    Node* next;
};

class queue {
private:
	Node *head;
	Node *tail;
	
public:
	queue() {
		head = NULL;
		tail = NULL;
	}
	
	void push(int value) {
        Node *newNode = new Node{value, NULL}; 
        if (tail != NULL) {
            tail -> next = newNode; 
        }
        tail = newNode;
        if (head == NULL) {
            head = newNode; 
        }
    }
    
    int front() { 
        if (head == NULL) {
            return -1; 
        }
        return head -> value; 
    }

    int pop() {
        if (head == NULL) {
            return -1; 
        }
        int data = head -> value; 
        Node* tmp = head; 
        head = head -> next; 
        if (head == NULL) {
            tail = NULL; 
        }
        delete tmp; 
        return data; 
    }

    bool empty() {
        return head == NULL;
    }
};

void Radix_Sort(int data[]) {
	Read_file(data);
	int max = data[0], timesSorted = 0;
    for (int i = 1; i < size; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }
    
    while (max != 0) {
        ++timesSorted;
        max /= 10;
    }
    
    queue head[10];
    int mod = 10, div = 1;
    for (int i = 0; i < timesSorted; i++) {
    	int headIndex=0;
        for (int j = 0; j < size; j++) {
            head[(data[j] % mod / div) % mod].push(data[j]); 
        }
        for(int k = 0; k < size; k++){
			while(head[headIndex].empty()) {
				++headIndex;
			}
			data[k] = head[headIndex].front();
			head[headIndex].pop();
		}
		mod *= 10;
		div *= 10;
	}
	Write_data(data, "Radix.txt");
}

int main() {
    int *data = new int[DATA_SIZE]; 
    int select;
    do {
        cout << "========================\n"
                "          MENU\n"
                "========================\n"
                "1.  Create random file\n"
                "2.  Selection Sort\n"
                "3.  Bubble Sort\n"
                "4.  Insertion Sort\n"
                "5.  Shell Sort\n"
                "6.  Merge Sort\n"
                "7.  Heap Sort\n"
                "8.  Quick Sort\n"
                "9.  Radix Sort\n"
                "10. Exit\n"
                "    Please choose > ";
        cin >> select;
        
        switch (select) {
            case 1:
                Create_file();
                break;
            case 2:
                Selection_Sort(data);
                break;
            case 3:
                Bubble_Sort(data);
                break;
            case 4:
                Insertion_Sort(data);
                break;
            case 5:
                Shell_Sort(data);
                break;
            case 6:
                Merge_Sort(data);
                break;
            case 7:
                Heap_Sort(data);
                break;
            case 8:
                Quick_Sort(data);
                break;
            case 9:
                Radix_Sort(data);
                break;
            case 10:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice! Please choose again\n";
        }
    } while (select != 10);

    return 0;
}
