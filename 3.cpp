#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val);
void print_link_list(Node* head);
void remove_duplicate(Node* &head);
int find_middle(Node* head);
void even_before_odd(Node* &head, Node* &tail);
void reorder_list(Node* &head);
Node* reverse_list(Node* head);


/********************** MAIN ************************/

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter values for list. Or enter -1 to stop :  ";
    int x;
    while(true){
        cin >> x;
        if(x == -1) break;
        insert_at_tail(head, tail, x);
    }

    print_link_list(head);

    int q;

    do{
        cout << "***************************************************\n";
        cout << "1. remove duplicates\n";
        cout << "2. find middle\n";
        cout << "3. even before odd\n";
        cout << "4. reorder list (A0..An)\n";
        cout << "0 to exit\n";
        cout << "***************************************************\n";

        cin >> q;

        switch(q){

        case 1:
            remove_duplicate(head);
            cout << "After removing duplicates:\n";
            print_link_list(head);
            break;

        case 2:
            {
                int mid = find_middle(head);
                if(mid != -1) cout << "Middle value: " << mid << "\n";
                else cout << "List is empty\n";
            }
            break;

        case 3:
            even_before_odd(head, tail);
            cout << "After arranging even before odd:\n";
            print_link_list(head);
            break;

        case 4:
            reorder_list(head);
            cout << "After reordering list:\n";
            print_link_list(head);
            break;

        default:
            if(q != 0) cout << "Invalid input\n";
        }

    } while(q != 0);

    cout << "Exit Success\n";
    return 0;
}


void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}


void print_link_list(Node* head){
    int cnt = 0;
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        cnt++;
        tmp = tmp->next;
    }
    cout << "\nLength : " << cnt << "\n";
}

void remove_duplicate(Node* &head){
    if(head == NULL) return;

    unordered_set<int> st;
    Node* tmp = head;
    Node* prev = NULL;

    while(tmp != NULL){
        if(st.count(tmp->val)){
            prev->next = tmp->next;
            delete tmp;
            tmp = prev->next;
        } else {
            st.insert(tmp->val);
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

int find_middle(Node* head){
    if(head == NULL) return -1;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

void even_before_odd(Node* &head, Node* &tail){
    if(head == NULL) return;

    Node* evenH = NULL;
    Node* evenT = NULL;
    Node* oddH = NULL;
    Node* oddT = NULL;

    Node* tmp = head;

    while(tmp != NULL){
        if(tmp->val % 2 == 0){
            if(evenH == NULL) evenH = evenT = tmp;
            else { evenT->next = tmp; evenT = tmp; }
        }
        else{
            if(oddH == NULL) oddH = oddT = tmp;
            else { oddT->next = tmp; oddT = tmp; }
        }
        tmp = tmp->next;
    }

    if(evenH != NULL){
        evenT->next = oddH;
        head = evenH;
        tail = (oddT != NULL ? oddT : evenT);
    } else {
        head = oddH;
        tail = oddT;
    }

    tail->next = NULL;
}

Node* reverse_list(Node* head){
    Node* prev = NULL;
    Node* cur = head;

    while(cur != NULL){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

void reorder_list(Node* &head){
    if(head == NULL || head->next == NULL) return;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = NULL;

    second = reverse_list(second);

    Node* first = head;

    while(first != NULL && second != NULL){
        Node* t1 = first->next;
        Node* t2 = second->next;

        first->next = second;
        if(t1 == NULL) break;
        second->next = t1;

        first = t1;
        second = t2;
    }
}
