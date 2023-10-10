#include <stdlib.h>
#include "fila.h"

void initializeQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // handle error
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear != NULL) {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    if (q->front == NULL) {
        q->front = newNode;
    }
}

void *dequeue(Queue *q) {
    if (q->front == NULL) {
        // handle error or return an indicator
        return NULL;
    }
    Node *tempNode = q->front;
    void *data = tempNode->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(tempNode);
    return data;
}

int queueIsEmpty(Queue *q) {
    return (q->front == NULL);
}

void printQueue(Queue *q, printFunction printFunc) {
    Node *current = q->front;
    while (current != NULL) {
        printFunc(current->data);
        current = current->next;
    }
}

void freeQueue(Queue *q, freeFunction freeFunc) {
    Node *current = q->front;
    Node *next;
    while (current != NULL) {
        next = current->next;
        freeFunc(current->data);
        free(current);
        current = next;
    }
}
