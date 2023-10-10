typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

typedef void (*printFunction)(void*);
typedef void (*freeFunction)(void*);

void initializeQueue(Queue *q);
void enqueue(Queue *q, void *data);
void *dequeue(Queue *q);
int queueIsEmpty(Queue *q);
void printQueue(Queue *q, printFunction printFunc);
void freeQueue(Queue *q, freeFunction freeFunc);
