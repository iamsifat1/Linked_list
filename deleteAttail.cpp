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

void delete_at_tail(Node* &head, Node* &tail){
        Node* tmp = head;
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        
        Node* deletenode = tmp->next;
        tmp->next = tmp->next->next;
        delete deletenode;
        tail = tmp;


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
    Node* c = new Node(40);
    Node* tail = new Node(50);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = tail;

    cout << "tail before" << tail->val << "\n";
    delete_at_tail(head, tail);
    cout << "tail after" << tail->val << "\n";
    print_list(head);
}