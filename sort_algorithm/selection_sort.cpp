#include <iostream>
using namespace std;

void SWAP(int *a, int *b){
	if(a==NULL || b==NULL) return;
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int *source, int length){
	if(source==NULL || length==0) return;
	for(int sorted = 0; sorted<length-1; sorted++){
		int min = source[sorted]; // Store the first unsorted element
		int index = sorted;
		
		// Select the minimum element in the unsorted set
		for(int i=sorted+1; i<length; i++){
			if(source[i]<min){
				min = source[i];
				index = i;
			}
		}
		
		// Swap ant put the minimum to the tail of the sorted set
		SWAP(&source[sorted], &source[index]);
	}
}

int main(){
	int length = 8;
	int source[length] = {9, 4, 2, 0, 5, 1, 6, 7};
	selection_sort(source, length);
	for(int i=0; i<length; i++) cout << source[i] << " ";
	cout << endl;
	
	return 0;
}
