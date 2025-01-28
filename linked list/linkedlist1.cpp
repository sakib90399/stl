//Circular Linked List Traversal.cpp
#include <iostream>
using namespace std;
class Node
{
public :
    int data;
    Node *next;
};
class operation
{
public:
      Node *head=NULL;
        Node *temp= NULL;
    void makeList()
    {
        int a;
        cin>>a;

        for(int i=0;i<a;i++)
        {
          if(head==NULL)
          {
              head= new Node();
              cin>>head->data;
              head->next=NULL;
              temp=head;
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
        temp->next=head;
    }
    void printlist()
    {
        Node*curr = head;
      do
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
          while(curr!=head);
    }

};
int main()
{
    operation list1 ;
    list1.makeList();
    list1.printlist();
    return 0;
}