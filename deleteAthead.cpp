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

void delete_head(Node* &head){
        Node* deletenode = head;
        head = head->next;
        delete deletenode;
}

void print_list(Node* head){
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    head->next = a;
    a->next = b;

    delete_head(head);

    print_list(head);
}