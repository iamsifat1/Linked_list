#include<bits/stdc++.h>
using namespace std;



class Node{
    public:
        int val;
        Node*next;
    Node(int val){
        this->val = val;
        this->next = NULL;
        }
};

void insert_tail(Node* &head, Node* &tail, int val){
    Node* newnode = new Node(val);

        if(head == NULL){
            head = newnode;
            tail = newnode;
            return;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
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

    Node* head = NULL;
    Node* tail = NULL;

    while (true)
    {
        int x;
        cin >> x;
        if(x == -1)break;

        insert_tail(head, tail, x);
    }
    print_link_list(head);
    return 0;
}