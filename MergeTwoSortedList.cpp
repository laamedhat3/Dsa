

#include <iostream>
using namespace std;


struct node {
    int data;
    node* next;
};

  class  Linkedlist{
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
    void sethead(node* newhead)
    {
        head = newhead;
    }
    node* gethead() {
        return head;
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
  
};
Linkedlist mergetwolist(Linkedlist& list1, Linkedlist& list2)
{
    Linkedlist mergedlist;
    node* l1 = list1.gethead();
    node* l2 = list2.gethead();
    node* head = nullptr;
    node* tail = nullptr;
    if (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data <= l2->data) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        tail = head;
    }
    else if (l1 != NULL)
    {
        head = l1;
    }
    else if (l2 != NULL)
    {
        head = l2;
    }

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL)
    {
        tail->next = l1;
    }
    else {
        tail->next = l2;
    }
    mergedlist.sethead(head);
    return mergedlist;
};


int main()
{
    Linkedlist list1;
    Linkedlist list2;
    
    int n1, n2;
    cin >> n1;
    int x;
    while (n1--)
    {
        cin >> x;
        list1.insertnode(x);
    }
    cin >> n2;
    while (n2--)
    {
        cin >> x;
        list2.insertnode(x);
    }
    Linkedlist mergedlist = mergetwolist(list1, list2);
    mergedlist.display();
  
    
    return 0;
}
