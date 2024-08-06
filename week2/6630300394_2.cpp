//6630300394 teetat Pitanupong
#include <iostream>
using namespace std;

int a[10], size = 0;

int Menu(int choose) {
    cout << "========MENU========" << endl;
    cout << "+     1) Insert    +" << endl;
    cout << "+     2) Delete    +" << endl;
    cout << "+     3) Print     +" << endl;
    cout << "+     4) Exit      +" << endl;
    cout << "====================" << endl;
    cout << " Please Choose > ";
    cin >> choose;
    return choose;
}
void output () {
	cout << "Output :";
	for (int i = 0; i < size; i++) {
            cout << " " << a[i];
        } 
    cout << endl << endl;
}

void print() {
    if (size == 0) {
        cout << "No List" << endl << endl;
        return;
    } else {
        int mid = (size + 1) / 2;
        cout << "Print             :";   
        for (int i = 0; i < size; i++) {
            cout << " " << a[i];
        }   
        cout << endl << "Print First Half  :";
        for (int i = 0; i < mid; i++) {
            cout << " " << a[i];
        }
        cout << endl << "Print Second Half :";
        for (int i = mid; i < size; i++) {
            cout << " " << a[i];
        }
        cout << endl << endl;
    } 
}

void insert(int data) {
    if (size >= 10) {
        cout << "List Full" << endl << endl;
        return;
    }
    int i = size - 1;
    while (i >= 0 && a[i] > data) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = data;
    size++;
    output();
}

void del(int data) {
	if (size == 0) {
        cout << "No List" << endl << endl;
        return;
    } else {
    	int found = 0;
	    for (int i = 0; i < size; i++) {
	        if (a[i] == data) {
	            found = 1;
	            for (int j = i; j < size - 1; j++) {
	                a[j] = a[j + 1];
	            }
	            size--;
	            output();
	            break;
	        }
	    }
	    if (found == 0) {
	        cout << "Not Found" << endl << endl;
	    }
	}
}

int main() {
    int choose, data;
    while (1) {
        switch (Menu(choose)) {
            case 1:
                cout << "Enter : ";
                cin >> data;
                insert(data);
                break;
            case 2:
            	cout << "Delete : ";
                cin >> data;
                del(data);
                break;
            case 3:
                print();
                break;
            case 4:
            	cout << "Bye bye";
                return 0;
            default:
                cout << "No Choice!" << endl;
                break; 
        }
    }
    return 0;
}

