/*
    Title: Merge K Sorted Linked Lists (Divide and Conquer)

    Problem Statement:
        - You are given K singly linked lists, each of which is sorted in non-decreasing order.
        - The task is to merge all K linked lists into a single sorted linked list and
          return its head.

    Author: Vishal Singhaniya
*/



#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* mergeTwo(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    
    while(head1!=nullptr && head2 != nullptr){
        if(head1->data <= head2->data){
            curr->next = head1;
            head1 = head1->next;
        }
        else{
            curr->next = head2;
            head2 = head2->next;
        }
        
        curr = curr->next;
    }
    
    if(head1!=nullptr){
        curr->next = head1;
    }
    else{
        curr->next = head2;
    }
    
    return dummy->next;
}

Node* mergeListsRecur(int i, int j, vector<Node*>& arr){
    if(i==j){
        return arr[i];
    }
    int mid = (i+j)/2;
    
    Node* head1 = mergeListsRecur(i,mid,arr);
    
    Node* head2 = mergeListsRecur(mid+1,j,arr);
    
    Node* head = mergeTwo(head1,head2);
    return head;
}

Node* mergeKLists(vector<Node*>& arr) {
    if(arr.size()==0){
        return nullptr;
    }
    return mergeListsRecur(0,arr.size()-1,arr);
}

void printList(Node* head){
    Node* temp = head;
    
    while(temp){
        cout<<temp->data;
        if(temp->next){
            cout<<"->";
        }
        temp=temp->next;
    }
}

int main() {
    int k = 3; 
  
    vector<Node*> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    
    Node* head = mergeKLists(arr);

    printList(head);

    return 0;
}



