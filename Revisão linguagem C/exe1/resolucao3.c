#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 100000

typedef struct HashTable {
    int keys[TABLE_SIZE];
    bool values[TABLE_SIZE];
} HashTable;

void initTable(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->values[i] = false;
    }
}

int hashFunction(int key) {
    return abs(key) % TABLE_SIZE;
}

void insert(HashTable *table, int key) {
    int index = hashFunction(key);
    table->keys[index] = key;
    table->values[index] = true;
}

bool search(HashTable *table, int key) {
    int index = hashFunction(key);
    return table->values[index];
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Uso: ./resolucao1 <n>\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int * array = malloc(sizeof(int) * n);

    printf("Escreva os numeros:\n");

    for(int i = 0; i < n; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nEscreva o valor de k: ");
    int k = 0;
    scanf("%d", &k);

    HashTable table;
    initTable(&table);

    for(int i = 0; i < n; i++) {
        int complement = k - array[i];
        if(search(&table, complement)) {
            printf("Soma encontrada entre %d e %d.\n", array[i], complement);
            free(array);
            return 0;
        }
        insert(&table, array[i]);
    }

    printf("Valor k nao encontrado como a soma de um par.\n");

    free(array);

    return 0;
}
