
#include<iostream>
using namespace std;
class Node
{public:
    int data;
    Node *next;
};
class operation
{public:
   // Node *head=nullptr;
    Node *tail=nullptr;

 void makeList(int n)
 {
     for(int i=0;i<n;i++)
     {
         if(tail==nullptr)
         {
             tail= new Node();
             cin>>tail->data;
             tail->next=NULL;

         }
         else
            {
            Node *newitem= new Node();
            cin>>newitem->data;
            newitem->next= tail;
            tail=newitem;

            }
     }
 }
 void printList()
 {
     Node *curr=tail;
     while(curr!=nullptr)
     {
         cout<<curr->data<<endl;
         curr=curr->next;
     }
 }
};
int main()
{
   operation list1;
   operation list2;
   operation list3;
   list1.makeList(5);
   list2.makeList(3);
   list3.makeList(5);
   list1.printList();
   list2.printList();
   list3.printList();
   return 0;
}
