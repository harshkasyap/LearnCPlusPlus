#include <iostream>
using namespace std;

struct list 
{
    int data;
    list *next;
}*head, *temp, *temp1;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        temp1 = new list();
        temp1->data = ++i;
        if(head == NULL)
        {
            head = temp1; 
            temp = head;
            continue;  
        }
        temp->next = temp1;
        temp = temp1;
    }

    temp = head;
    while(temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }

    delete(head);
    delete(temp);
    delete(temp1);
}