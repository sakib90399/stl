#include<iostream>
using namespace std;
class node
{public:

    int data;
    node * next;
};
int main()
{
    int n;
    cout<<"Enter node size:";
    cin>>n;
    node *head=NULL;
    node *temp=NULL;
    for (int i=0; i<n; i++)
    {
        if(head== NULL)
        {
            head = new node();
            cin>>head->data;
            head->next = NULL;
            temp=head;
        }
        else
        {
            node * newitem=new node();
            cin>>newitem-> data;
            newitem->next= NULL;
            temp->next=newitem;
            temp=newitem;
        }
    }
    cout<<"\nInitial linked list:"<<endl;
    node *curr=head;
    while(curr!= NULL)
    {
        cout<<curr->data<<endl;
       curr = curr->next;
    }

    node *newitem= new node();
    cin>>newitem->data;
    newitem->next=head;
    head=newitem;

    cout<<"\nAfter adding new node at head:"<<endl;
      node *curr2=head;
    while(curr2!= NULL)
    {
        cout<<curr2->data<<endl;
       curr2 = curr2->next;
    }
}
