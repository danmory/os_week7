#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 0;
    printf("Enter N: ");
    scanf("%d", &N);
    int* arr = (int*) malloc(N*sizeof(int));

    for (int i = 0; i < N; i++){
        *(arr + i) = i;
    }

    for (int i = 0; i < N; i++){
        printf("%d ", *(arr + i));
    }

    free(arr);

    return 0;
}