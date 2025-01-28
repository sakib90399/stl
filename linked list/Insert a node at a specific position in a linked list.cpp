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
    cout<<"______________";
    node *curr2;
    node *newitem= new node();
    cin>>newitem->data;
    newitem->next=NULL;
    curr2=newitem;

    node *temp2= head;
    int p;
    cin>>p;
    for(int i=0;i<p-1;i++)
    {
       temp2=temp2->next;
    }
    curr2->next=temp2->next;
    temp2->next=curr2;
    cout<<"\nAfter adding new node at position "<<p<<":"<<endl;
      node *curr3=head;
    while(curr3!= NULL)
    {
        cout<<curr3->data<<endl;
       curr3 = curr3->next;
    }
}
