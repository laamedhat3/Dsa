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
    Linkedlist traverse() {

        Linkedlist list1;
        node* current = head;

        while (current != nullptr) {
            list1.insertbegging(current->data);
            current = current->next;
        }
        return list1;
    }
    void removenth(Linkedlist list,int val) {

        if (val == 1 && list.head->next=nullptr)
        {
           delete(head);
          
             cout <<"[]";

        }
        else if (val == 2) {
            list.deletebigging();
            list.display();
        }
        else if (val == 0) {
             list.display();
        }
        else {
            Linkedlist list1 = list.traverse();
            node* current = list1.head;
            node* previous = list1.head;
            val -= 1;
            while (val--)
            {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete(current);
            list1 = list1.traverse();
             list1.display();
        }
     
      
    }
};


int main()
{
    Linkedlist list;
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        list.insertnode(t);
    }
    int val;
    cin >> val;
  list.removenth(list, val);

  
    return 0;
}