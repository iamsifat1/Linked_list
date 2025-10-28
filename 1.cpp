#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node*next;
    Node(int data){
        this->val = data;
        this->next = NULL;
        }
};

void insert_at_head(Node* &head, Node* &tail, int x);
void insert_at_tail(Node* &head, Node* &tail, int val);
void insert_at_anyPos(Node* &head, Node* &tail, int pos, int val);
void delete_head(Node* &head);
void delete_at_tail(Node* &head, Node* &tail);
void delete_anypos(Node* &head, Node* &tail, int x);
void print_link_list(Node* head);

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    cout << "Enter values for list. Or enter -1 to stop :  ";
    while (true)
    {
        int x;  cin >> x;
        if(x == -1)break;
        insert_at_tail(head, tail, x);
    }

    print_link_list(head);
    int q, x;
    do
    {
        cout << "***************************************************\n1. insert at head\n2. insert at tail\n3. insert at any position\n4. delete at head\n5. delete at tail\n6. delete at any position\n      0 to exit\n***************************************************\n";
        cin >> q;
        switch (q)
        {
        case 1:
            cout << "1 selected . Enter value :";
            cin >> x;
            insert_at_head(head,tail,x);
            print_link_list(head);
            break;
        case 2:
            cout << "2 selected . Enter value :";
            cin >> x;
            insert_at_tail(head, tail, x);
            print_link_list(head);
            break;
        case 3:
            cout << "3 selected . Enter value and position:";
            cin >> x;
            int pos;  cin >> pos;
            insert_at_anyPos(head,tail,pos,x);
            print_link_list(head);
            break;
        case 4:
            cout << "4 selected.\n";
            delete_head(head);
            print_link_list(head);
            break;
        case 5:
            cout << "5 selected.\n";
            delete_at_tail(head,tail);
            print_link_list(head);
            break;
        case 6:
            cout << "6 selected. Enter position to delete: ";
            cin >> x;
            delete_anypos(head,tail, x);
            print_link_list(head);
            break;
        default:
            if(q != 0)cout << "Invalid input. Try again\n";
            break;
        }
    } while (q != 0);
    cout << "Exit Success\n";
    print_link_list(head);
    return 0;
}



void insert_at_tail(Node* &head, Node* &tail, int val){
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

void insert_at_head(Node* &head,Node* &tail, int x){
    Node* newnode = new Node(x);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void insert_at_anyPos(Node* &head, Node* &tail, int pos, int val) {
    if (pos == 0) {
        insert_at_head(head, tail, val);
        return;
    }

    Node* tmp = head;
    for (int i = 1; i < pos && tmp != NULL; i++) {
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        cout << "Out of the boundary.\n";
        return;
    }

    Node* newnode = new Node(val);
    newnode->next = tmp->next;
    tmp->next = newnode;

    if (newnode->next == NULL) tail = newnode;
}



void delete_head(Node* &head){
        Node* deletenode = head;
        if(head == NULL){
            cout <<"List has no data\n";
            return;
        }
        head = head->next;
        delete deletenode;
}


void delete_at_tail(Node* &head, Node* &tail){
        Node* tmp = head;
        if(tmp == NULL){
            cout << "List has no data\n";
            return;
        }
        if(tmp->next == NULL){
            Node* deletenode = tmp;
            head = NULL;
            tail = NULL;
            delete deletenode;
            return;
        }
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        
        Node* deletenode = tmp->next;
        tmp->next = tmp->next->next;
        delete deletenode;
        tail = tmp;


}
void delete_anypos(Node* &head, Node* &tail, int pos) {
    if (head == NULL) {
        cout << "List has no data\n";
        return;
    }
    if (pos == 0) {
        delete_head(head);
        if (head == NULL) tail = NULL;
        return;
    }

    Node* tmp = head;
    for (int i = 1; i < pos && tmp->next != NULL; i++) {
        tmp = tmp->next;
    }

    if (tmp->next == NULL) {
        cout << "Out of the boundary.\n";
        return;
    }

    Node* deletenode = tmp->next;
    tmp->next = tmp->next->next;

    if (tmp->next == NULL) tail = tmp;
    delete deletenode;
}

void print_link_list(Node* head){
    int cnt = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        cnt++;
        temp = temp->next;
    }
    cout << "\n" << "Length : " << cnt << "\n";
}