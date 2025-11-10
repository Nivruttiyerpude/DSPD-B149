#include <stdio.h>

#define SIZE 7

int main()
{
    int hashTable[SIZE];
    int n, key;
    int i, hash, start;

    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);

        hash = key % SIZE;
        start = hash;

        while (hashTable[hash] != -1) {
            hash = (hash + 1) % SIZE;
            if (hash == start) {
                printf("Hash table is full!\n");
                return 0;
            }
        }

        hashTable[hash] = key;
    }

    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Slot %d: empty\n", i);
        else
            printf("Slot %d: %d\n", i, hashTable[i]);
    }

    return 0;
}