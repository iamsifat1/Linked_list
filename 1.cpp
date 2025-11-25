#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

Node *head = NULL, *tail = NULL;
int len = 0;
char md;

void insert_at_head(int x);
void insert_at_tail(int val);
void delete_head();
void delete_at_tail();
void print_link_list();

int main()
{
    int sz, ch, mode;

    cout << "List management system by stack & queue\n";
    cout << "Enter max size: ";
    cin >> sz;
    do
    {
        while (1)
        {
            cout << "1. Stack mode (s)\n2. Queue mode (q)\n0.Exit\n";
            cin >> mode;
            if (mode == 1)
            {
                cout << "Stack mode selected\n";
                md = 's';
                break;
            }
            else if (mode == 2)
            {
                cout << "Queue mode selected\n";
                md = 'q';
                break;
            }
            else
                cout << "Invalid input, try again\n";
        }
        do
        {
            cout << "Operations: \n";
            cout << "1. Insert int(push)\n2. Pop\n3.isEmpty ?\n4. Top/Front\n5.Size\n6. Quit\n";
            cout << "Enter choice: ";
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                int val;
                cout << "1 Selected, mode " << md << "\n ";
                if (len == sz)
                {
                    cout << "No space for new data\n";
                    break;
                }
                cout << "Enter data: ";
                cin >> val;
                if (md == 's')
                    insert_at_tail(val);
                else
                    insert_at_head(val);
                len++;
                break;
            }
            case 2:
            {
                cout << "2 Selected, mode " << md << "\n ";
                if (len == 0)
                {
                    cout << "No data for deletion\n";
                    break;
                }
                if (md == 's')
                    delete_at_tail();
                else
                    delete_head();
                len--;
                break;
            }
            case 3:
            {
                cout << "3 Selected.\n";
                if (len == 0)
                    cout << "YES, list is empty.\n";
                else
                    cout << "NO, list is not empty\n";
                break;
            }
            case 4:
            {
                if (md == 's')
                    cout << "top : " << tail->val << "\n";
                else
                    cout << "Front : " << head->val << "\n";
                break;
            }
            case 5:
            {
                cout << "List size : " << len << "\n";
                break;
            }
            case 6:
                print_link_list();
                break;
            default:
                if (ch != 0)
                    cout << "Invalid input, try again\n";
                break;
            }
        } while (ch != 0);
    } while (mode != 0);
}

void insert_at_head(int x)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void insert_at_tail(int val)
{
    Node *newnode = new Node(val);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

void delete_head()
{
    Node *deletenode = head;
    if (head == NULL)
    {
        cout << "List has no data\n";
        return;
    }
    head = head->next;
    delete deletenode;
}
void delete_at_tail()
{
    Node *tmp = head;
    if (tmp == NULL)
    {
        cout << "List has no data\n";
        return;
    }
    if (tmp->next == NULL)
    {
        Node *deletenode = tmp;
        head = NULL;
        tail = NULL;
        delete deletenode;
        return;
    }
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    Node *deletenode = tmp->next;
    tmp->next = tmp->next->next;
    delete deletenode;
    tail = tmp;
}

void print_link_list()
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        cnt++;
        temp = temp->next;
    }
    cout << "\n"
         << "Length : " << cnt << "\n";
}