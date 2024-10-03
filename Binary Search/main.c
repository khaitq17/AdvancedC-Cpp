#include<stdio.h>


void sortArr(int array[], int size){
    if(size > 0){
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                if(array[i] > array[j]){
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    } else {
        printf("Array is empty.\n");
    } 
}


int binarySearch(int array[], int sizeArr, int value){
    if(sizeArr > 0){
        int left = 0;
        int right = sizeArr - 1;

        int mid = (left + right)/2;

        while(value != array[mid]){

            if(value > array[mid]){
                left = mid + 1;
            } else if(value < array[mid]) {
                right = mid - 1;
            }

            mid = (left + right)/2;

            if(left > right){
                printf("Value is not found.\n");
                return -1;
                break;
            }
        }

        return mid;
        
    } else {
        printf("Array is empty.\n");
        return -1;
    }
}


int main(){
    int array[] = {35, 46, 7, 75, 27, 2, 54, 1, 9, 63, 4, 38, 51, 95, 67, 91, 0, 40, 30, 11};
    int size = sizeof(array)/sizeof(array[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sap xep mang theo thu tu tang dan
    sortArr(array, size);
    printf("New array after arrange:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Tim kiem nhi phan
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);

    printf("Value to search for is at position %d in the array.\n", binarySearch(array, size, value));
    
    return 0;
}

