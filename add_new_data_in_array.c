#include <stdio.h>

int main () {
	int scores[4] = {10, 20, 30, 40,};
	int fifth_score = 50;
	
	//make room for the fifth scoreby shifting the existing scores one position to the right.
	for (int i = 3; i >= 0; i --) {
		scores [i + 1] = scores[i];
	}

	// add the 5th score to the 1st positin 
	scores[0] = fifth_score;

	// print the contents of the array 
	for (int i = 0; i < 5; i++){
		printf("%d ", scores[i]);
	}
	return 0;
}
