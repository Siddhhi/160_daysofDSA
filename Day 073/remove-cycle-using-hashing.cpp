/*
    Title: Remove Cycle from Singly Linked List (using Hashing)

    Problem Statement:
        - Create a singly linked list.
        - Introduce a cycle manually.
        - Detect whether a cycle exists.
        - If a cycle exists, remove the cycle.

    Author: Siddhi
*/


#include <iostream>
#include<unordered_map>
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
void removeCycle(Node* &head) {
    unordered_map<Node*,int> mp;
    // Detect cycle
    
    Node* temp = head;
    Node* p = NULL;
    while(temp!=NULL){
        if(mp.count(temp)){
            if(p!=NULL){
                p->next=NULL;
            }
            break;
        }
        
        mp[temp]=1;
        p=temp;
        temp=temp->next;
    }
}

bool detectCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void printList(Node* head){
    Node* temp=head;
    bool flag=detectCycle(head);
    // cout<<flag;
    if(flag){
        cout<<"Cycle is present inside loop , Hence there is an infinte traversal to list.";
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }   
    }
    
    cout<<"\n";
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

    removeCycle(head);
    if(detectCycle(head)){
        cout<<"Cycle detected.\n";
    }else{
        cout<<"No cycle in this linked list\n";
    }
    
    printList(head);

    return 0;
}
