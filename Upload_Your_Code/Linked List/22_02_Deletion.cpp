#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    printf("inserted data at Head is :- %d\n", val);
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    printf("inserted data at Tail is :- %d\n", val);
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void Display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *&head, int key)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            // printf("Data found!!!\n");
            return true; // op:-1
        }
        temp = temp->next;
    }
    return false; // op:- 0
    // printf("Data Not found!!!\n");
}

void DeleteAtFirst(node *&head)
{
    node *del_first_n = head;
    head = head->next;
    delete del_first_n;
}

void Delete(node *&head, int val)
{
    if(head == NULL){
        return;
    }

    if(head->next==NULL){
        DeleteAtFirst(head);
        return;
    }
    
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *del_n = temp->next;
    temp->next = temp->next->next;
    delete del_n;
}

int main()
{
    int temp;
    int key, val;
    node *head = NULL;
    cout << "Inserted data... " << '\n';
    cout << "Inserted Data At Tail :"
         << "\n";
    insertAtTail(head, 1);
    insertAtTail(head, 10);
    insertAtTail(head, 100);
    insertAtTail(head, 101);
    Display(head);

    cout << "\nInserted Data At HEAD : "
         << "\n";
    cout << "Enter value to be inserted:- " ;
    scanf("%d", &val);
    insertAtHead(head, val);
    Display(head);

    cout << "\nSearch key you want to be :\n";
    scanf("%d", &key);
    cout << search(head, key);

    cout << "\n\nEnter the val to be delete: \n";
    scanf("%d", &val);
    Delete(head, val);
    cout << "After delete display list:\n";
    Display(head);

    cout << "\nAfter delete first node display list:\n";
    DeleteAtFirst(head);
    Display(head);

    return 0;
}