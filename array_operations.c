#include <stdio.h>
int main() {
    int arr[10], n, choice, pos, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while(1) {
        printf("\nMenu");
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);

                for(i = n; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos - 1] = value;
                n++;
                printf("Element inserted successfully.\n");
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                for(i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Element deleted successfully.\n");
                break;

            case 3:
                printf("Array elements are:\n");
                for(i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
