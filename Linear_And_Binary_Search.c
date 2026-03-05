#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;  
        }
    }
    return -1;        
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[100], n, key, i, result, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter element to search: ");
    scanf("%d", &key);

    if(choice == 1) {
        result = linearSearch(arr, n, key);
    }
    else if(choice == 2) {
        result = binarySearch(arr, n, key);
    }
    else {
        printf("Invalid choice");
        return 0;
    }

    if(result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at position %d\n", result + 1);

    return 0;
}