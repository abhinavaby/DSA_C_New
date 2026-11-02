#include <stdio.h>
#include <stdlib.h>

static void merge(int values[], int temp[], int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right) {
        if (values[i] <= values[j]) {
            temp[k++] = values[i++];
        } else {
            temp[k++] = values[j++];
        }
    }

    while (i <= middle) {
        temp[k++] = values[i++];
    }

    while (j <= right) {
        temp[k++] = values[j++];
    }

    for (i = left; i <= right; i++) {
        values[i] = temp[i];
    }
}

static void mergeSort(int values[], int temp[], int left, int right)
{
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSort(values, temp, left, middle);
    mergeSort(values, temp, middle + 1, right);
    merge(values, temp, left, middle, right);
}

int main(void)
{
    int count;

    if (scanf("%d", &count) != 1 || count <= 0) {
        return 1;
    }

    int *values = malloc((size_t)count * sizeof(*values));
    int *temp = malloc((size_t)count * sizeof(*temp));
    if (values == NULL || temp == NULL) {
        free(values);
        free(temp);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        if (scanf("%d", &values[i]) != 1) {
            free(values);
            free(temp);
            return 1;
        }
    }

    mergeSort(values, temp, 0, count - 1);

    for (int i = 0; i < count; i++) {
        printf("%d", values[i]);
        if (i + 1 < count) {
            printf(" ");
        }
    }
    printf("\n");

    free(values);
    free(temp);
    return 0;
}
