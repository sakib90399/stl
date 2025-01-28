#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class operation
{
public:
    node *head=NULL;
    node *temp=NULL;
    node *curr=NULL;
    node *prev=NULL;
    node *nextNode=NULL;

    void makeList(int a)
    {
      for(int i=0;i<a;i++)
      {
          if(head==NULL)
          {
              head= new node();
              cin>>head->data;
              head->next= NULL;
              temp=head;
          }
          else
            {
              node *newitem= new node();
              cin>>newitem->data;
              newitem->next=NULL;
              temp->next= newitem;
              temp= newitem;
            }
      }
    }
    void reverseList()
    {
        curr=head;
        //curr->next=nullptr;
        while(curr!=NULL)
        {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        head=prev;
    }
    void printList()
    {
        curr= head;
       while (curr!=NULL)
       {
           cout<<curr->data<<endl;
           curr=curr->next;
       }
    }


};
int main()
{
    operation list1;
    list1.makeList(5);
    list1.reverseList();
    list1.printList();
    return 0;
}
