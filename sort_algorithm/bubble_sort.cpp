#include <iostream>
using namespace std;

void swap(int *a, int *b){
	if(a==NULL || b==NULL) return;
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *source, int length){
	if(source==NULL || length==0) return;
	for(int i=0; i<length; i++)
		// From the first to the end of the unsorted part
		for(int j=0; j<length-i-1; j++)
			if(source[j]>source[j+1])
				swap(&source[j], &source[j+1]);
}

int main(){
	int length = 8;
	int source[length] = {9, 4, 2, 0, 5, 1, 6, 7};
	bubble_sort(source, length);
	for(int i=0; i<length; i++) cout << source[i] << " ";
	cout << endl;
	
	return 0;
} 
