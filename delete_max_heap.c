#include <stdio.h> 
#define MAX 100 
int heap[MAX]; 
int size = 0; 
/* Swap two elements */ 
void swap(int *a, int *b) { 
int temp = *a; 
*a = *b; 
*b = temp; 
} 
/* Heapify down (maintain max heap) */ 
void heapifyDown(int index) { 
int largest = index; 
int left = 2*index + 1; 
int right = 2*index + 2; 
if(left < size && heap[left] > heap[largest]) 
largest = left; 
if(right < size && heap[right] > heap[largest]) 
largest = right; 
if(largest != index) { 
swap(&heap[index], &heap[largest]); 
heapifyDown(largest); 
} 
} 
/* Insert node into Max Heap */ 
void insertHeap(int value) { 
if(size >= MAX) { 
printf("Heap is full!\n"); 
return; 
} 
int i = size; 
heap[size++] = value; 
/* Heapify up */ 
while(i != 0 && heap[i] > heap[(i-1)/2]) { 
swap(&heap[i], &heap[(i-1)/2]); 
i = (i-1)/2; 
} 
} 
/* Delete max element */ 
void deleteMax() { 
if(size <= 0) { 
printf("Heap is empty!\n"); 
return; 
} 
printf("Deleting max element: %d\n", heap[0]); 
heap[0] = heap[size-1];  // Move last element to root 
size--;                   
// Reduce heap size 
heapifyDown(0);           
} 
/* Display Heap */ 
void displayHeap() { 
if(size == 0) { 
// Restore max heap property 
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
printf("2. Delete Max\n"); 
printf("3. Display Heap\n"); 
printf("4. Exit\n"); 
printf("Enter choice: "); 
scanf("%d", &choice); 
 
        switch(choice) { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                insertHeap(value); 
                break; 
            case 2: 
                deleteMax(); 
                break; 
            case 3: 
                displayHeap(); 
                break; 
            case 4: 
                return 0; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
} 
