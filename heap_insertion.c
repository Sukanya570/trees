#include <stdio.h> 
#define MAX 100 
int heap[MAX]; 
int size = 0; 
/* Function to swap two integers */ 
void swap(int *a, int *b) { 
int temp = *a; 
*a = *b; 
*b = temp; 
} 
/* Heapify up (maintain max heap property) */ 
void heapifyUp(int index) { 
int parent = (index - 1) / 2; 
if(index > 0 && heap[index] > heap[parent]) { 
swap(&heap[index], &heap[parent]); 
heapifyUp(parent); 
} 
} 
/* Insert node into Max Heap */ 
void insertHeap(int value) { 
if(size >= MAX) { 
printf("Heap is full! Cannot insert.\n"); 
return; 
} 
printf("Inserting %d into the heap...\n", value); 
heap[size] = value;  // insert at the end 
heapifyUp(size);     
size++; 
} 
// maintain heap property 
/* Display Heap as array */ 
void displayHeap() { 
if(size == 0) { 
printf("Heap is empty!\n"); 
return; 
} 
printf("Heap elements: "); 
for(int i = 0; i < size; i++) 
printf("%d ", heap[i]); 
printf("\n"); 
} 
/* Main program */ 
int main() { 
int choice, value; 
while(1) { 
printf("\n--- MAX HEAP OPERATIONS ---\n"); 
printf("1. Insert Node\n"); 
printf("2. Display Heap\n"); 
printf("3. Exit\n"); 
printf("Enter choice: "); 
scanf("%d", &choice); 
switch(choice) { 
case 1: 
printf("Enter value to insert: "); 
scanf("%d", &value); 
insertHeap(value); 
break; 
case 2: 
displayHeap(); 
break; 
case 3: 
return 0; 
default: 
printf("Invalid choice!\n"); 
} 
} 
return 0; 
} 
