/**
 * Question 12: What is a priority queue? Explain its types and working with a suitable example. 
 * Also discuss any four real-world applications of queues.
 *
 * Answer:
 * What is a Priority Queue?
 * A priority queue is a special type of queue in which each element is associated with a 
 * priority value. Elements are dequeued based on their priority rather than their order 
 * in the queue. If two elements have the same priority, they are served according to 
 * their order in the queue (FIFO).
 *
 * Types of Priority Queues:
 * 1. Ascending Priority Queue:
 *    Elements can be inserted arbitrarily, but the element with the smallest value 
 *    (highest priority) is removed first.
 * 2. Descending Priority Queue:
 *    Elements can be inserted arbitrarily, but the element with the highest value 
 *    (highest priority) is removed first.
 *
 * Working with an Example:
 * Imagine a hospital emergency room. Patients arrive in a certain order. 
 * A normal queue would treat them FIFO. But in a priority queue, a patient with a 
 * life-threatening condition (high priority) is treated before a patient with a minor 
 * cut (low priority), regardless of who arrived first.
 * Let elements be (value, priority): (A, 3), (B, 1), (C, 2).
 * If 1 is the highest priority, the removal order will be: B, C, A.
 *
 * Four Real-World Applications of Queues:
 * 1. Operating System Scheduling: Process scheduling (Round Robin, Priority Scheduling) 
 *    where tasks are queued for CPU time.
 * 2. Print Spooling: When multiple print jobs are sent to a printer, they are queued 
 *    and printed in a FIFO order.
 * 3. Call Centers: Customers calling a helpline are placed in an audio queue and 
 *    answered by the next available representative in the order they called.
 * 4. Network Routers: Data packets arriving at a router are placed in a queue and 
 *    transmitted in order to manage network traffic and congestion.
 */

#include <stdio.h>

int main() {
    printf("Priority Queue theory and real-world applications documented in comments.\n");
    return 0;
}
