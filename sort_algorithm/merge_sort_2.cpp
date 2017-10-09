#include <iostream>
using namespace std;

void mergeSort(int* source, int start, int end){
	if(source==NULL || start<0 || end<=start) return;
	
	// 切分为两堆
	int middle = (end-start)/2+start; 
	// 分别进行排序
	mergeSort(source, start, middle);
	mergeSort(source, middle+1, end);
	
	// 合并 
	int sorted[end-start+1];
	int index=0, leftPos=start, rightPos=middle+1;
	while(leftPos<=middle && rightPos<=end) {
		if(source[leftPos]<=source[rightPos]){
			sorted[index++] = source[leftPos++];
		}
		else{
			sorted[index++] = source[rightPos++];
		}
	} 
	if(leftPos>middle && rightPos<=end){
		for(; rightPos<=end; rightPos++)
			sorted[index++] = source[rightPos];
	}
	if(leftPos<=middle && rightPos>end){
		for(; leftPos<=middle; leftPos++)
			sorted[index++] = source[leftPos];
	}
	for(int i=start; i<=end; i++){
		source[i] = sorted[i-start];
	}
}

int main(){
	int test[10] = {2, 1, 6, 3, 0, 4, 8, 5, 7, 9};
	mergeSort(test, 0, 9);
	for(int i=0; i<10; i++) cout << test[i] << " ";
	cout << endl;
	
	return 0;
}
