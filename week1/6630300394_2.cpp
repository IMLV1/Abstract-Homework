//6630300394 Teetat Pitanupong
#include <iostream>
using namespace std;

int main () {
	int n;
	cout << "input : ";
	cin >> n;
	
	bool Prime = true;
	
	if (n <= 1){
		Prime = false;
	} else {
		for (int i=2 ; i <= n / 2; ++i)
			if (n % i == 0){
				Prime = false;
			}
	}
	cout << (Prime ? "Prime" : "Not Prime");
	
	return 0;
}


