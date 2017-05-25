#include <iostream>
using namespace std;

void quick_sort(int *source, int start, int end);
int separate(int *source, int start, int end);
void swap(int *a, int *b);

int main(){
	int length = 8;
	int source[length] = {9, 4, 2, 0, 5, 1, 6, 7};
	quick_sort(source, 0, length-1);
	for(int i=0; i<length; i++) cout << source[i] << " ";
	cout << endl;
	
	return 0;
}

void quick_sort(int *source, int start, int end){
	if(source==NULL || start<0 || end<start) return;
	// When there is no data or just one data, we don't need to seperate it but just return it
	if(start < end){
		// Seperate the array into two part
		int index = separate(source, start, end);
		
		quick_sort(source, start, index-1);
		quick_sort(source, index+1, end);
	}
} 

int separate(int *source, int start, int end){
	int aim = source[start]; // Set the first element to be the pivot
	int index = start; // the position of pivot
	
	// Recursive from the second element to the last one
	for(int i=start+1; i<=end; i++){
		// Throw the elements smaller than pivot to the front of the array
		if(source[i] < aim){
			swap(&source[i], &source[index+1]);
			index++;
		}
	}
	
	// Move the pivot to the pointed situation
	swap(&source[start], &source[index]);
	
	return index;
}

void swap(int *a, int *b){
	if(a==NULL || b==NULL) return;
	int temp = *a;
	*a = *b;
	*b = temp;
}
