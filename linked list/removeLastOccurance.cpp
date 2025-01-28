
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class work
{
    public:
        Node *head=NULL;
        Node *temp= NULL;

    void makeList()
    {
      int n;
      cin>>n;
      for(int i=0; i<n;i++)
      {
          if(head==NULL)
          {
              head= new Node();
              cin>>head->data;
              head->next= NULL;
              temp =head;
          }
          else
          {
              Node *newitem= new Node();
              cin>>newitem->data;
              newitem->next=NULL;
              temp->next=newitem;
              temp=newitem;
          }
      }
    }

    void removeLastOccurance ()
    {
        int searchkey;
        cin>>searchkey;
       Node *last_occur;
       Node *prev1=NULL;
       Node *prev2=NULL;
        temp= head;
        while(temp!=NULL)
        {
            if(temp->data==searchkey)
            {
              prev2=prev1;
              last_occur=temp;
            }
            prev1=temp;
            temp=temp->next;
        }
        prev2->next=last_occur->next;
        delete(last_occur);
    }
    void printList()
    {
        Node *curr;
        curr=head;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
};
int main ()
{
    work list1;
    list1.makeList();
    list1.removeLastOccurance();
    list1.printList();


}
