#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

void merge_sort(struct node *(*first));
struct node *findmiddle(struct node *(*first));
struct node *merge(struct node *(*first), struct node *(*second_first));
void print_list(struct node *first);
void free_list(struct node *first);

int main(){
	int situation;
    while(scanf("%d", &situation) != EOF) {     
        for(int j = 0; j < situation; j++) {
            int amount;  // number of the nodes       
            scanf("%d", &amount);

            struct node *first = NULL; 
            for(int i = 0; i < amount; i++) {
                struct node *new_node = (node *) malloc (sizeof(node));
                scanf("%d", &(new_node->value));
                new_node->next = first;
                first = new_node;
            }
            merge_sort(&first);
            print_list(first);
            free_list(first);
        }
    }
	
	return 0;
} 

void merge_sort(struct node *(*first)){
	// When there is no data or just one data we don't need to separate it but just return it
	if(*first != NULL && (*first)->next != NULL){
		// Find the middle node and separate
		struct node *middle = findmiddle(&*first);
		// Merge sort the first part of the list
		merge_sort(first);
		// Merge sort the second part of the list
		merge_sort(&middle);
		// Merge these two separated lists
		*first = merge(&*first, &middle);
	}
}

struct node *findmiddle(struct node *(*first)){
	// For safety(may not be used)
	if(*first == NULL)
		return NULL;
		
	struct node *middle = *first;       // The pointer move with one step
	struct node *temp = (*first)->next; // The pointer move with two steps
	while(temp != NULL){ // For safety move
		temp = temp->next;
		if(temp != NULL){ // For safety move
			temp = temp->next;
			middle = middle->next;
		}
	}
	// Store the start pointer of the second part of the list
	struct node *second = middle->next;
	// Separate the list into two parts
	middle->next = NULL;
	// Return the pointer of the head of the second part of the list
	return second;
}

struct node *merge(struct node *(*first), struct node *(*second_first)){
	// The dump node, which it's convenient for us to link the list
	struct node *final_first = (node *)malloc(sizeof(struct node));
	struct node *final_last = &*final_first; // The pointer for the last node of the result list
	
	// Merge these two lists when these two lists are not empty
	while(*first != NULL && *second_first != NULL){
		// The head of first list not bigger than the head of second list
		if((*first)->value <= (*second_first)->value){
			final_last->next = *first; // Link the head of the first list to the result list
			final_last = *first; // Renew the pointer for the last node of the result list
			*first = (*first)->next; // Delete the head of the first list
		}
		// The head of first list bigger than the head of second list
		else{
			final_last->next = *second_first; // Link the head of the second list to the result list
			final_last = *second_first; // Renew the pointer for the last node of the result list
			*second_first = (*second_first)->next; // Delete the head of the second list
		}
	}
	// Merge the extra part of the list
	if(*first == NULL)
		final_last->next = *second_first;
	else
		final_last->next = *first;
		
	// Return the real first node
	return final_first->next;
}

void print_list(struct node *first) {
    for(struct node *temp = first->next; temp != NULL; temp = temp->next) {
        printf("%d\n", first->value);
        first = temp;
    }
    printf("%d\n", first->value);
}

void free_list(struct node *first) {
    for(struct node *temp = first->next; temp != NULL; temp = temp->next) {
        free(first);
        first = temp;
    }
    free(first);
}    
