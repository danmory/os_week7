#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void* ptr, size_t newSize, size_t oldSize){
	
    // If ptr is NULL, the call is equivalent to malloc(size)
	if(ptr == NULL){
		return malloc(newSize);
    }
	
    // If size is equal to zero, the call is equivalent to free(ptr)
    if(newSize == 0){
		free(ptr);
		return NULL;
	}

	void* NewPtr = malloc(newSize);

	if(NewPtr == NULL){
		return NULL;
    }
	
	size_t minSize = oldSize < newSize? oldSize : newSize;
	memcpy(NewPtr, ptr, minSize);

	free(ptr);
	
	return NewPtr;
}


int main(){
    /* TESTING */
    int* arr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++){
        *(arr + i) = i;
        printf("%d ", *(arr + i));
    }
    printf("\n");

    my_realloc(arr, 7*sizeof(int), 5*sizeof(int));
    
    for (int i = 5; i < 7; i++){
        *(arr + i) = i;
    }

    for (int i = 0; i < 7; i++){
        printf("%d ", *(arr + i));
    }
	return 0;
}