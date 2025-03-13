#include <iostream>
using namespace std;


struct node {
    int data;
    node* next;
};
class Linkedlist {

private:
    node* head = NULL;
public:
    void insertnode(int value)
    {
        node* newnode;node* last;
        newnode = new node();
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newnode;
        }

    }

    void display()
    {
        node* currentnode = head;
        if (head == NULL)
        {
            cout << "linked list is empty";
        }
        else {
            while (currentnode != NULL)
            {
                cout << currentnode->data << "\t";
                currentnode = currentnode->next;
            }
            cout << endl;
        }
    }

    void deletenode(int value) {
        node* currentnode = head;
        node* perviousnode = NULL;

        if (head == NULL)
        {
            cout << "empty";
            return;

        }

        if (currentnode->data == value)
        {
            head = head->next;
            delete currentnode;
            return;
        }

        while (currentnode != NULL && currentnode->data != value)
        {
            perviousnode = currentnode;
            currentnode = currentnode->next;

        }

        if (currentnode == NULL)
        {
            cout << "Not found" << endl;
            return;
        }

        perviousnode->next = currentnode->next;
        delete currentnode;

    }

    void insertbegging(int value)
    {
        node* newnode = new node;
        newnode->data = value;
        newnode->next = head;
        head = newnode;

    }

    void  deletebigging()
    {
        if (head == NULL)
        {
            cout << "empty" << endl;
            return;
        }

        node* currentnode = head;
        head = currentnode->next;
        delete (currentnode);
    }

    void deleteend()
    {
        if (head == NULL)
        {
            cout << "linked list is empty";
            return;
        }
        if (head->next == NULL) {
            delete(head);
            head = NULL;
        }
        node* ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        delete(ptr->next);
        ptr->next = NULL;
    }
    void sethead(node* newhead) {
        head = newhead;
    }

    node* gethead() {
        return head;
    }
    bool hascycle () {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        node* slow = head;
        node* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;

        }
        return false;

    }
    void makepos(int pos)
    {
        if (pos < 0)
            return;

        node* last = head;
        node* cycle=nullptr;
        int index = 0;
        
        while (last ->next!= NULL)
        {
            if (index == pos) {
                cycle = last;
            }
            last = last->next;
            index++;
        }
        if (cycle != nullptr) {
            last->next = cycle;
       }
    }
};


int main()
{
    Linkedlist list;
    int n;
    cin >> n;
    int x;
    while (n--)
    {
        cin >> x;
        list.insertnode(x);
    }
    int pos;
    cin >> pos;
   list. makepos(pos);
  bool answ=  list.hascycle();
  cout << answ;
    return 0;
}