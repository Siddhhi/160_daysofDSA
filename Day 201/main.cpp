/*
    Title: Find the Intersection Point of Two Linked Lists

    Problem Statement:
        - You are given the heads of two singly linked lists.
        - The lists may or may not intersect at some point.
        - If they intersect, return the node where they merge.
        - If they do not intersect, return NULL.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* getIntersection(Node* head1, Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    
    if(ptr1 == nullptr || ptr2 == nullptr){
        return nullptr;
    }
    
    while(ptr1 != ptr2){
        ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
    }
    
    return ptr1;   // intersection node OR nullptr
}

int main(){

    // Create common part
    Node* common = new Node(7);
    common->next = new Node(8);
    common->next->next = new Node(9);

    // List 1: 1->2->3->7->8->9
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    // List 2: 4->5->6->7->8->9
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next = new Node(6);
    head2->next->next = common;

    Node* res = getIntersection(head1, head2);

    if(res != nullptr){
        cout << "The intersection point of these two linked lists is: " << res->data << endl;
    }
    else{
        cout << "The lists do not intersect.\n";
    }

    return 0;
}



