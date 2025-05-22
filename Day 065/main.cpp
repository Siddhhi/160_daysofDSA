/*
    Title: Reverse a Singly Linked List (Iterative Approach)

    Problem Statement:
        - Create a singly linked list.
        - Implement functionality to reverse the list iteratively.
        - Print the list before and after reversal.

    Author: Siddhi
*/

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at head
void insertAthead(node*& head, int val) {
    node* newnode = new node(val);
    newnode->next = head;
    head = newnode;
}

// Reverse the linked list iteratively
void reverse(node*& list) {
    node* prev = NULL;
    node* curr = list;

    while (curr != NULL) {
        node* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    list = prev;
}

// Print the linked list
void printList(node* list) {
    node* temp = list;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    node* l = NULL; // Initialize head to NULL

    insertAthead(l, 1);
    insertAthead(l, 7);
    insertAthead(l, 2);
    insertAthead(l, 3);
    insertAthead(l, 4);

    cout << "Original list: ";
    printList(l);

    reverse(l);

    cout << "Reversed list: ";
    printList(l);

    return 0;
}
