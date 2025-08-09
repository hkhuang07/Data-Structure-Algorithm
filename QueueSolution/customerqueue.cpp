#include <iostream>
#include <string>

#define MAX_CUSTOMERS 10

// 1. Define the Customer structure
struct Customer {
    int id;
    int arrivalTime;
};

// 2. Define the Queue structure
struct Queue {
    Customer customers[MAX_CUSTOMERS];
    int front;
    int rear;
    int count;
};

// 3. Initialize the queue
void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// 4. Check if the queue is empty
bool isEmpty(Queue* q) {
    return q->count == 0;
}

// 5. Check if the queue is full
bool isFull(Queue* q) {
    return q->count == MAX_CUSTOMERS;
}

// 6. Add a new customer to the queue (enqueue)
void enqueue(Queue* q, Customer customer) {
    if (isFull(q)) {
        std::cout << "Queue is full. New customer " << customer.id << " cannot be added." << std::endl;
        return;
    }
    q->rear = (q->rear + 1) % MAX_CUSTOMERS;
    q->customers[q->rear] = customer;
    q->count++;
    std::cout << "Customer " << customer.id << " arrived at time " << customer.arrivalTime << " and joined the queue." << std::endl;
}

// 7. Remove a customer from the front of the queue (dequeue)
Customer dequeue(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty. No customers to serve." << std::endl;
        return {-1, -1}; // Return an invalid customer
    }
    Customer servedCustomer = q->customers[q->front];
    q->front = (q->front + 1) % MAX_CUSTOMERS;
    q->count--;
    return servedCustomer;
}

// 8. Main function to simulate the bank teller line
int main() {
    Queue bankQueue;
    initializeQueue(&bankQueue);

    std::cout << "--- Bank Teller Simulation ---" << std::endl;

    // A. Customers arrive and join the queue
    enqueue(&bankQueue, {101, 900}); // Customer 101 arrives at 9:00
    enqueue(&bankQueue, {102, 902}); // Customer 102 arrives at 9:02
    enqueue(&bankQueue, {103, 905}); // Customer 103 arrives at 9:05
    enqueue(&bankQueue, {104, 907}); // Customer 104 arrives at 9:07

    std::cout << "\n--- Serving Customers ---" << std::endl;

    // B. Customers are served in the order they arrived
    while (!isEmpty(&bankQueue)) {
        Customer currentCustomer = dequeue(&bankQueue);
        std::cout << "Serving customer " << currentCustomer.id << " who arrived at " << currentCustomer.arrivalTime << "." << std::endl;
    }

    std::cout << "\nAll customers served. The bank line is now empty." << std::endl;

    // C. Trying to serve a customer when the queue is empty
    dequeue(&bankQueue);

    return 0;
}
