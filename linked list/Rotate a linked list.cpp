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
//        Node *temp2=head;
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
    void rotateList()
        {
//         Node *temp2=head;
//         Node *temp3=NULL;

        if (head == NULL)

        return;

        int k;
        cin >> k;


        Node *current = head;
        int length = 1;

        while (current->next != NULL)
        {
            current = current->next;
            length++;
        }


        k = k % length;
        if (k == 0)

        return;
else
    {



         Node *prev=NULL;

         for(int i=0; i<k;i++)  // 1 2 3 4 5

        {
            Node *temp2=head;
            while (temp2->next!=NULL)
            {
                prev=temp2;
                temp2=temp2->next;

            }
            prev->next->next=head;
            head=prev->next;
            prev->next=NULL;

        }
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
    list1.rotateList();
    list1.printList();
    return 0;
}

