#include <stdio.h>


int display(int arr[], int *n) {
    int i;
    for (i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int insert(int arr[], int *n) {
    int i, p, k;
    printf("Enter the number to be inserted: ");
    scanf("%d", &k);
    printf("Enter the position to insert the number: ");
    scanf("%d", &p);

    if (p < 1 || p > *n + 1) {
        printf("Invalid position!\n");
        return 1;
    }

    for (i = *n; i >= p; i--) {
        arr[i] = arr[i - 1];
    }
    arr[p - 1] = k;
    (*n)++;

    display(arr, n);
    return 0;
}

int delete(int arr[], int *n) {
    int i, p;
    printf("Enter the position to delete the number: ");
    scanf("%d", &p);

    if (p < 1 || p > *n) {
        printf("Invalid position!\n");
        return 1;
    }

    for (i = p - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;

    display(arr, n);
    return 0;
}

int search(int arr[], int n) {
    int i, p;
    printf("Enter the number to find: ");
    scanf("%d", &p);

    for (i = 0; i < n; i++) {
        if (arr[i] == p) {
            printf("Number found at position %d\n", i + 1);
            return 0;
        }
    }
    printf("Number not found\n");
    return 0;
}

int sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    display(arr, &n);
    return 0;
}

int main() {
    int n, i, choice;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[100];

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("Enter the choice 1-print 2-insert 3-delete 4-search 5-sort 6-exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display(arr, &n);
                break;
            case 2:
                insert(arr, &n);
                break;
            case 3:
                delete(arr, &n);
                break;
            case 4:
                search(arr, n);
                break;
            case 5:
                sort(arr, n);
                break;
            case 6:
                printf("\nProgram exited\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
