#include <stdio.h>
#include <stdlib.h>

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

    for (int i = 0; i < count - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < count; j++) {
            if (values[j] < values[smallest]) {
                smallest = j;
            }
        }

        int temp = values[i];
        values[i] = values[smallest];
        values[smallest] = temp;
    }

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
