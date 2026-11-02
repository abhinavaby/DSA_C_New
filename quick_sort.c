#include <stdio.h>
#include <stdlib.h>

static int partition(int values[], int low, int high)
{
    int pivot = values[high];
    int smallerEnd = low;

    for (int i = low; i < high; i++) {
        if (values[i] <= pivot) {
            int temp = values[i];
            values[i] = values[smallerEnd];
            values[smallerEnd] = temp;
            smallerEnd++;
        }
    }

    int temp = values[smallerEnd];
    values[smallerEnd] = values[high];
    values[high] = temp;
    return smallerEnd;
}

static void quickSort(int values[], int low, int high)
{
    if (low >= high) {
        return;
    }

    int pivotIndex = partition(values, low, high);
    quickSort(values, low, pivotIndex - 1);
    quickSort(values, pivotIndex + 1, high);
}

int main(void)
{
    int count;

    if (scanf("%d", &count) != 1 || count <= 0) {
        return 1;
    }

    int *values = malloc((size_t)count * sizeof(*values));
    if (values == NULL) {
        return 1;
    }

    for (int i = 0; i < count; i++) {
        if (scanf("%d", &values[i]) != 1) {
            free(values);
            return 1;
        }
    }

    quickSort(values, 0, count - 1);

    for (int i = 0; i < count; i++) {
        printf("%d", values[i]);
        if (i + 1 < count) {
            printf(" ");
        }
    }
    printf("\n");

    free(values);
    return 0;
}
