#include <stdio.h>

#define ARR_SIZE 9

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int n) {
    int i, j, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
}

void selectionSort(int array[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&array[i], &array[min]);
        }
    }
}

void numSwaps(int array[], int n, char *sortType) {
    int swapTotal = 0;
    int val[ARR_SIZE] = {0}; 

    if (sortType == "Bubble") {
        bubbleSort(array, n);
    } else if (sortType == "Selection") {
        selectionSort(array, n);
    } else {
        printf("Invalid sort type\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((sortType == "Bubble" && array[j] > array[j + 1]) ||
                (sortType == "Selection" && array[j] > array[i])) {
                swapTotal++;
                val[array[j]]++;
            }
        }
    }

    printf("%s Sort:\n", sortType);
    for (int i = 0; i < ARR_SIZE; i++) {
        if (val[i] > 0) {
            printf("%d: %d times swapped\n", i, val[i]);
        }
    }
    printf("Total number of swaps: %d\n", swapTotal);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    numSwaps(array1, ARR_SIZE, "Bubble");
    printf("\n");
    numSwaps(array2, ARR_SIZE, "Selection");

    return 0;
}

