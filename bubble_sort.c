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

    for (int end = count - 1; end > 0; end--) {
        int swapped = 0;

        for (int i = 0; i < end; i++) {
            if (values[i] > values[i + 1]) {
                int temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }
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
