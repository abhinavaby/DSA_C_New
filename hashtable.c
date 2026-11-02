#include <stdio.h>

#define TABLE_SIZE 101

typedef struct {
    int key;
    int state;
} Entry;

static Entry table[TABLE_SIZE];

static int hash(int key)
{
    int index = key % TABLE_SIZE;
    return index < 0 ? index + TABLE_SIZE : index;
}

static int findKey(int key)
{
    int start = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int index = (start + i) % TABLE_SIZE;
        if (table[index].state == 0) {
            return -1;
        }
        if (table[index].state == 1 && table[index].key == key) {
            return index;
        }
    }

    return -1;
}

static int insertKey(int key)
{
    int start = hash(key);
    int firstDeleted = -1;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int index = (start + i) % TABLE_SIZE;

        if (table[index].state == 1 && table[index].key == key) {
            return 0;
        }
        if (table[index].state == 2 && firstDeleted == -1) {
            firstDeleted = index;
        }
        if (table[index].state == 0) {
            if (firstDeleted != -1) {
                index = firstDeleted;
            }
            table[index].key = key;
            table[index].state = 1;
            return 1;
        }
    }

    if (firstDeleted != -1) {
        table[firstDeleted].key = key;
        table[firstDeleted].state = 1;
        return 1;
    }

    return -1;
}

static int deleteKey(int key)
{
    int index = findKey(key);
    if (index == -1) {
        return 0;
    }

    table[index].state = 2;
    return 1;
}

static void displayTable(void)
{
    int found = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].state == 1) {
            printf("%d: %d\n", i, table[i].key);
            found = 1;
        }
    }

    if (!found) {
        printf("Table is empty\n");
    }
}

int main(void)
{
    int choice;

    while (scanf("%d", &choice) == 1 && choice != 0) {
        int key;

        switch (choice) {
            case 1: {
                if (scanf("%d", &key) != 1) {
                    return 1;
                }
                int result = insertKey(key);
                if (result == 1) {
                    printf("Inserted\n");
                } else if (result == 0) {
                    printf("Key already exists\n");
                } else {
                    printf("Table is full\n");
                }
                break;
            }
            case 2:
                if (scanf("%d", &key) != 1) {
                    return 1;
                }
                if (findKey(key) != -1) {
                    printf("Found\n");
                } else {
                    printf("Not found\n");
                }
                break;
            case 3:
                if (scanf("%d", &key) != 1) {
                    return 1;
                }
                if (deleteKey(key)) {
                    printf("Deleted\n");
                } else {
                    printf("Not found\n");
                }
                break;
            case 4:
                displayTable();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
