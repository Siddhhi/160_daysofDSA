/*
    Title: Detect Start of Loop in Singly Linked List (Floyd’s Algorithm)

    Problem Statement:
        - Create a singly linked list.
        - Introduce a cycle manually.
        - Detect whether a cycle exists.
        - If a cycle exists, find the first node where the cycle begins.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Definition of a node
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert a node at the head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Function to find the starting node of a cycle using Floyd’s Algorithm
Node* firstNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Found intersection
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Starting point of the cycle
        }
    }

    return NULL; // No cycle
}

// Driver code
int main() {
    Node* head = NULL;

    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    // Introduce a cycle: Node 5 points to Node 3
    head->next->next->next->next->next = head->next->next;  // 5 -> 3

    Node* startOfCycle = firstNode(head);

    if (startOfCycle) {
        cout << "Cycle detected. First node of the cycle: " << startOfCycle->data << endl;
    } else {
        cout << "No cycle detected in the list." << endl;
    }

    return 0;
}
