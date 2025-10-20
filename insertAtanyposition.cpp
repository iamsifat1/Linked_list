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

void intsert_at_anyPos(Node* head, int pos, int val){
    Node* newnode = new Node(val);

    Node* tmp = head;

    for (int i = 1; i < pos && tmp != NULL; i++)
    {
        tmp =tmp->next;
    }
    if(tmp == NULL)return;
    newnode->next = tmp->next;
    tmp->next = newnode;

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

    intsert_at_anyPos(head,2, 100);
    intsert_at_anyPos(head,2, 200);
    intsert_at_anyPos(head,5, 300);
    print_link_list(head);
    return 0;
}