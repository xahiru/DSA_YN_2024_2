#include <stdio.h>

#define MAX 5  // Maximum orders in the queue

// Define the order structure
struct Order {
    int orderID;
    float amount;
};

// Define the queue structure
struct OrderQueue {
    struct Order orders[MAX];
    int front, rear;
};

// Initialize the order queue
void initializeQueue(struct OrderQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Place an order in the queue
void placeOrder(struct OrderQueue* queue, int orderID, float amount) {
    if (queue->rear == MAX - 1) {
        printf("Queue is full. Cannot place more orders.\n");
        return;
    }
    if (queue->front == -1) queue->front = 0;
    queue->rear++;
    queue->orders[queue->rear].orderID = orderID;
    queue->orders[queue->rear].amount = amount;
    printf("Order %d placed with amount %.2f.\n", orderID, amount);
}

// Process the next order in the queue
void processOrder(struct OrderQueue* queue) {
    if (queue->front == -1) {
        printf("No orders to process.\n");
        return;
    }
    printf("Processing order %d with amount %.2f.\n", queue->orders[queue->front].orderID, queue->orders[queue->front].amount);
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
}

// View the first order in the queue
void viewOrder(struct OrderQueue* queue) {
    if (queue->front == -1) {
        printf("No orders to view.\n");
        return;
    }
    printf("First order: %d with amount %.2f.\n", queue->orders[queue->front].orderID, queue->orders[queue->front].amount);
}

int main() {
    struct OrderQueue queue;
    initializeQueue(&queue);

    placeOrder(&queue, 101, 250.50);
    placeOrder(&queue, 102, 350.75);
    viewOrder(&queue);

    processOrder(&queue);
    processOrder(&queue);
    processOrder(&queue);  // Empty queue case

    return 0;
}
