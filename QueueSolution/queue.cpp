#include <iostream>
#include <string>

#define MAX_TASKS 10

// 1. Define the Task structure
struct Task {
    int id;
    std::string description;
};

// 2. Define the Queue structure
struct Queue {
    Task tasks[MAX_TASKS];
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int count; // Number of elements in the queue
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
    return q->count == MAX_TASKS;
}

// 6. Add a new task to the queue (enqueue)
void enqueue(Queue* q, Task task) {
    if (isFull(q)) {
        std::cout << "Queue is full. Cannot add new task." << std::endl;
        return;
    }
    q->rear = (q->rear + 1) % MAX_TASKS;
    q->tasks[q->rear] = task;
    q->count++;
    std::cout << "Task " << task.id << " added to the queue." << std::endl;
}

// 7. Remove a task from the front of the queue (dequeue)
Task dequeue(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty. No tasks to process." << std::endl;
        return {-1, ""}; // Return an invalid task
    }
    Task processedTask = q->tasks[q->front];
    q->front = (q->front + 1) % MAX_TASKS;
    q->count--;
    return processedTask;
}

// 8. Main function to simulate the task processing system
int main() {
    Queue taskQueue;
    initializeQueue(&taskQueue);

    std::cout << "--- Task Processing System Simulation ---" << std::endl;

    // Add tasks to the queue
    enqueue(&taskQueue, {1, "Process user registration"});
    enqueue(&taskQueue, {2, "Generate daily report"});
    enqueue(&taskQueue, {3, "Send notification emails"});
    enqueue(&taskQueue, {4, "Backup database"});
    enqueue(&taskQueue, {5, "Update system logs"});

    std::cout << "\n--- Processing Tasks ---" << std::endl;

    // Process tasks from the queue
    while (!isEmpty(&taskQueue)) {
        Task processedTask = dequeue(&taskQueue);
        std::cout << "Processing Task " << processedTask.id << ": " << processedTask.description << std::endl;
    }

    std::cout << "\nAll tasks processed. Queue is empty." << std::endl;

    // Try to dequeue from an empty queue
    dequeue(&taskQueue);

    return 0;
}
