//6630300394 Teetat Pitanupong
#include <iostream>
using namespace std;

int main() {
	int tmp,score[10];
	for (int i=0; i < 10;i++) {
		score[i] = (i+1)* 10;
	}
	for (int i=0; i < 10 / 2 ;i++){
		tmp = score [i];
		score[i] = score[((sizeof(score) / 4)- 1) - i];
		score[((sizeof(score) / 4)- 1) - i] = tmp;
	}
	for (int i=0; i < 10 ;i++){
		cout << score[i] << " ";
	}
	
	return 0;
}
