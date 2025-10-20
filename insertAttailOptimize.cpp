#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }

};

void intsert_at_tail(Node* &head, Node* &tail, int x){
    Node* newnode = new Node(x);

    if(head == NULL){
        head = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print_link_list(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    
    cout << "\n";
}

int main(){

    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* tail = new Node(40);

    head->next = a;
    a->next = b;
    b->next = tail;

    intsert_at_tail(head, tail, 100);
    intsert_at_tail(head, tail, 200);
    intsert_at_tail(head, tail, 300);
    print_link_list(head);
    return 0;
}