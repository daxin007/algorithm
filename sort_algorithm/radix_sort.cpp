// It's suitable for radix less or equal than 10
#include <iostream>
using namespace std;

// Help function get the max bit of data
int max_bit(int radix, int *source, int length){
	if(radix<=0 || source==NULL || length<=0) return 0;
	int maxbit = 1;
	int base = radix;
	for(int i=0; i<length; i++){
		while(source[i] >= base){
			base *= radix;
			maxbit++;
		}
	}
	return maxbit;
}
void radix_sort(int radix, int *source, int length){
	if(radix<=0 || source==NULL || length<=0) return;
	
	// Construct a set of bins determined by radix
	int *radixBins = new int[radix];
	int *collectData = new int[length];
	int maxbit = max_bit(radix, source, length);
	int base = 1;
	for(int i=0; i<maxbit; i++){ // Allocate [maxbit] times
		for(int j=0; j<radix; j++)// Empty all the bins
			radixBins[j] = 0; 
		for(int j=0; j<length; j++){ // Count the number of records in every bins
			int k = (source[j]/base)%10;
			radixBins[k]++;
		}
		for(int j=1; j<radix; j++) // Allocate the position 
			radixBins[j] = radixBins[j-1]+radixBins[j];
		for(int j=length-1; j>=0; j--){ // Collect the data from bins
			int k = (source[j]/base)%10;
			collectData[radixBins[k]-1] = source[j];
			radixBins[k]--;
		}
		for(int j=0; j<length; j++){ // Copy to the source array
			source[j] = collectData[j];
		}
		base = base*10;
	}
	delete []collectData;
	delete []radixBins;
}

int main(){
	int length = 9;
	int source[length] = {21, 12, 55, 11, 34, 11, 9, 2, 25};
	radix_sort(10, source, length);
	for(int i=0; i<length; i++) cout << source[i] << " ";
	cout << endl;
	
	return 0;
}
