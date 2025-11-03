#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int data) {
        this->val = data;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val);
void print_link_list(Node* head);
bool search_element(Node* head, int key);
void display_greater_less(Node* head, int val);
void reverse_traversal(Node* head);
void find_max_min(Node* head);

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter values for the list (enter -1 to stop): ";
    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;
        insert_at_tail(head, tail, x);
    }

    cout << "\nLinked list created successfully:\n";
    print_link_list(head);

    int q;
    do {
        cout << "\n***************************************************\n";
        cout << "1. Search for an element\n";
        cout << "2. Display all elements greater/less than a given value\n";
        cout << "3. Reverse traversal (using recursion)\n";
        cout << "4. Find and display maximum and minimum values\n";
        cout << "0. Exit\n";
        cout << "***************************************************\n";
        cout << "Enter your choice: ";
        cin >> q;

        switch (q) {
        case 1: {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            if (search_element(head, key))
                cout << key << " found in the list.\n";
            else
                cout << key << " not found in the list.\n";
            break;
        }
        case 2: {
            int val;
            cout << "Enter value to compare: ";
            cin >> val;
            display_greater_less(head, val);
            break;
        }
        case 3: {
            cout << "Reverse traversal: ";
            reverse_traversal(head);
            cout << "\n";
            break;
        }
        case 4: {
            find_max_min(head);
            break;
        }
        case 0:
            cout << "Exit success.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (q != 0);

    return 0;
}


void insert_at_tail(Node* &head, Node* &tail, int val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print_link_list(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
        cnt++;
    }
    cout << "\nLength: " << cnt << "\n";
}

bool search_element(Node* head, int key) {
    Node* temp = head;
    int ind = 1;
    while (temp != NULL) {
        if (temp->val == key){
            cout << ind << " ";
        }
        ind++;
        temp = temp->next;
    }
    return false;
}

void display_greater_less(Node* head, int val) {
    Node* temp = head;
    bool found = false;

    cout << "Elements greater than " << val << ": ";
    while (temp != NULL) {
        if (temp->val > val) {
            cout << temp->val << " ";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "None";
    cout << "\n";

    temp = head;
    found = false;
    cout << "Elements less than " << val << ": ";
    while (temp != NULL) {
        if (temp->val < val) {
            cout << temp->val << " ";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "None";
    cout << "\n";
}

void reverse_traversal(Node* head) {
    if (head == NULL) return;
    reverse_traversal(head->next);
    cout << head->val << " ";
}

void find_max_min(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    int mx = head->val, mn = head->val;
    Node* temp = head->next;
    while (temp != NULL) {
        mx = max(mx, temp->val);
        mn = min(mn, temp->val);
        temp = temp->next;
    }
    cout << "Maximum value: " << mx << "\n";
    cout << "Minimum value: " << mn << "\n";
}
