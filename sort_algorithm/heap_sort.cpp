#include <iostream>
using namespace std;

void heap_sort(int *source, int length);
// Recursive version: Recover the property of heap
void insert_heap(int *source, int root_index, int end_index);
// Non-recursive version: Recover the property of heap
void insert_heap_non_recursive(int *source, int root_index, int end_index); 
// Build heap
void build_heap(int *source, int length);
void swap(int *a, int *b);

int main(){
	int length = 8;
	int source[length] = {9, 4, 2, 0, 5, 1, 6, 7};
	heap_sort(source, length);
	for(int i=0; i<length; i++) cout << source[i] << " ";
	cout << endl;
	
	return 0;
}

void heap_sort(int *source, int length){
	// Build the heap
	build_heap(source, length);
	// Recursive for n-1 times for n unsorted numbers
	for(int i=length-1; i>0; i--){
		// Swap the top node and the end node
		swap(&source[0], &source[i]);
		// One element is deleted from unsorted part
		insert_heap(source, 0, i-1);
	}
}

void insert_heap(int *source, int root_index, int end_index){
	int left_child_index = root_index*2+1;  // position of the left child
	int right_child_index = root_index*2+2; // position of the right child
	int largest_node_index = root_index;    // Initial the largest node to be the root
	
	// Check the whether the root is the largest. If not, change it.
	// Check if the left child is in the unsorted part and bigger than the current largest node
	if(left_child_index<=end_index && source[largest_node_index]<source[left_child_index])
		largest_node_index = left_child_index;
	// Check if the right child is in the unsorted part and bigger than the current largest node
	if(right_child_index<=end_index && source[largest_node_index]<source[right_child_index])
		largest_node_index = right_child_index;	
	
	// If the largest node is not the root exchange the position and continue to check the next level
	if(largest_node_index != root_index){
		// Exchange the position
		swap(&source[root_index], &source[largest_node_index]);
		// Check the next level
		insert_heap(source, largest_node_index, end_index);
	}
}

void insert_heap_non_recursive(int *source, int root_index, int end_index){
	int left_child_index = root_index*2+1;  // position of the left child
	int right_child_index = root_index*2+2; // position of the right child
	int largest_node_index = root_index;    // Initial the largest node to be the root
	bool first = true;
	while(first || largest_node_index != root_index){
		first = false;
		// If the largest node is not the root exchange the position and continue to check the next level
		swap(&source[root_index], &source[largest_node_index]);
		root_index = largest_node_index;
		left_child_index = root_index*2+1;
		right_child_index = root_index*2+2;
		
		// Check the whether the root is the largest. If not, change it.
		// Check if the left child is in the unsorted part and bigger than the current largest node
		if(left_child_index<=end_index && source[largest_node_index]<source[left_child_index])
			largest_node_index = left_child_index;
		// Check if the right child is in the unsorted part and bigger than the current largest node
		if(right_child_index<=end_index && source[largest_node_index]<source[right_child_index])
			largest_node_index = right_child_index;	
	}
}

void build_heap(int *source, int length){
	// Skip the leaf node
	for(int i=(length-1)/2; i>=0; i--){
		// recover the heap from the lowest level of the tree
		insert_heap(source, i, length-1);
	}
}

void swap(int *a, int *b){
	if(a==NULL || b==NULL) return;
	int temp = *a;
	*a = *b;
	*b = temp;
}
