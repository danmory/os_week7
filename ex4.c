#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* myRealloc(void* ptr, size_t newSize, size_t oldSize){
	
    // If ptr is NULL, the call is equivalent to malloc(size)
	if(ptr == NULL){
		return malloc(newSize);
    }
	
    // If size is equal to zero, the call is equivalent to free(ptr)
    if(newSize == 0){
		free(ptr);
		return NULL;
	}

	void* newPtr = malloc(newSize);

	if(newPtr == NULL){
		return NULL;
    }
	
	size_t minSize = oldSize < newSize? oldSize : newSize;
	memcpy(newPtr, ptr, minSize);

	free(ptr);
	
	return newPtr;
}


int main(){
    /* TESTING */
    int* arr = (int*)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++){
        *(arr + i) = i;
        printf("%d ", *(arr + i));
    }
    printf("\n");

    arr = myRealloc(arr, 7*sizeof(int), 5*sizeof(int));
    
    for (int i = 5; i < 7; i++){
        *(arr + i) = i;
    }

    for (int i = 0; i < 7; i++){
        printf("%d ", *(arr + i));
    }

    free(arr);

	return 0;
}