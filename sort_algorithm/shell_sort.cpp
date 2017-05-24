#include<iostream>
using namespace std;

void shell_sort(int *source, int length, int step){
	if(source==NULL || length==0) return;
	while(step > 0){
		// The source is divided by [step] parts
		for(int k=0; k<step; k++){
			// Insertion sort of each part of the source
			for(int i=step+k; i<length; i+=step){
				// Store the first element of the unsort part
				int temp = source[i];
				int j = i-step;
				while(j>=0 && temp<source[j]){
					source[j+step] = source[j];
					j -= step;
				}
				source[j+step] = temp;
			}
			cout << step << endl;
			for(int i=0; i<length; i++) cout << source[i] << " ";
			cout << endl;	
		}
		step = step/2;
	}
	
}

int main(){
	int length = 8;
	int source[length] = {9, 4, 2, 0, 5, 1, 6, 7};
	shell_sort(source, length, length/2);
	for(int i=0; i<length; i++) cout << source[i] << " ";
	cout << endl;
	
	return 0;
}
