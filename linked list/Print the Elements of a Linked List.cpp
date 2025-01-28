#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
int main()
{
    int n;
    cout<<"Enter node number:";
    cin>>n;
    Node *head= NULL;
    Node *temp = NULL;
     for(int i=0; i<n; i++)
     {
         if(head == NULL)
         {
             head= new Node();
             cin>>head->data;
             head->next = NULL;
             temp=head;
         }
         else
         {
             Node *newitem= new Node();
             cin>>newitem->data;
             newitem->next= NULL;
             temp->next=newitem;
             temp= newitem;
         }
     }
      Node *curr;
      curr= head;
      while(curr!= NULL)
      {
          cout<<curr->data<<endl;
          curr=curr->next;
      }

}
