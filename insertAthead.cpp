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

void intsert_at_head(Node* &head, int x){
    Node* newnode = new Node(x);
    newnode->next = head;
    head = newnode;
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

    head->next = a;
    a->next = b;

    intsert_at_head(head, 100);
    intsert_at_head(head, 200);
    intsert_at_head(head, 300);
    print_link_list(head);
    return 0;
}