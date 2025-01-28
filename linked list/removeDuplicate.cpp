
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
    void removeDuplicate()
    {
        Node *current = head;
        while(current!=NULL)
        {
            Node *temp3=NULL;
            Node *temp2=current;
            while(temp2->next!=NULL)
            {
                if(temp2->next->data==current->data)
                {
                   temp3=temp2->next->next;
                   delete(temp2->next);
                   temp2->next=temp3;

                }
                else
                    {
                    temp2=temp2->next;
                    }
            }
            current=current->next;
        }



    }


    void printList()
    {
        Node *curr=head;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
};
int main()
{
    work list1;
    list1.makeList();
    list1.removeDuplicate();
    list1.printList();
    return 0;
}
