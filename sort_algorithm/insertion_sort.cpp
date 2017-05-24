#include <iostream>
using namespace std;

// insertion sort in ascending order
void insertion_sort(int *source, int length){
	if(source==NULL || length==0) return;
	for(int i=1; i<length; i++){
		// Store the selected element in the unsort part
		int temp = source[i];
		int j = i-1;
		for(; j>=0; j--){
			// "=" guaranteed stable
			if(temp>=source[j]) break;
			source[j+1] = source[j];
		}
		source[j+1] = temp;
	}
}

int main(){
	int length = 8;
	int source[length] = {9, 4, 2, 0, 5, 1, 6, 7};
	insertion_sort(source, length);
	for(int i=0; i<length; i++) cout << source[i] << " ";
	cout << endl;
	
	return 0;
}
