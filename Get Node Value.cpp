#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class work
{public:
    node *head=NULL;
        node *temp=NULL;
    void makelist(int n)
    {

        for(int i=0; i<n;i++)
        {
            if(head==NULL)
            {
                head=new node();
                cin>>head->data;
                head->next=NULL;
                temp=head;
            }
            else
            {
                node *newitem= new node();
                cin>>newitem->data;
                newitem->next=NULL;
                temp->next= newitem;
                temp=newitem;
            }
        }
    }
    void searchNodeValue()
    {
        int Count=0;
        temp=head;
      while(temp!=NULL)
        {
            temp=temp->next;
            Count++;
        }
        cout<<"Enter desired position:";
        int a;
        cin>>a;
        if(a>Count)
            cout<<"Invalid input";

        int p= Count-a-1;
        temp=head;
        for(int j=0;j<p;j++)
        {
            temp=temp->next;
        }
        cout<<temp->data;

    }
};
int main()
{
    work list1;
    list1.makelist(5);
    list1.searchNodeValue();
    return 0;
}
