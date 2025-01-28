

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
        Node *temp1=NULL;
        Node *temp2=NULL;
        Node *temp3=NULL;
        Node *temp4=NULL;
       Node *temp5=NULL;
        Node *head2=NULL;

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
    Node *mergeList(Node *n1, Node *n2)
    {
        Node *temp1= n1;
        Node *temp2 = n2;
       Node * head2= NULL;
        Node *temp4 =NULL;

        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data<=temp2->data)
            {
               if(head2==NULL)
          {
              head2= new Node();
              head2->data=temp1->data;
              head2->next= NULL;
              temp4 =head2;
          }
          else
          {
              Node *newitem= new Node();
              newitem->data=temp2->data;
              newitem->next=NULL;
              temp4->next=newitem;
              temp4=newitem;
          }
            }

            else
                {
                    if(head2==NULL)
          {
              head2= new Node();
              head2->data=temp2->data;
              head2->next= NULL;
              temp4 =head2;
          }
          else
          {
              Node *newitem= new Node();
              newitem->data=temp1->data;
              newitem->next=NULL;
              temp4->next=newitem;
              temp4=newitem;
          }
                }
            }
            temp1=temp1->next;
            temp2=temp2->next;
            while(temp1!=NULL)
            {
              Node *newitem= new Node();
              newitem->data=temp1->data;
              newitem->next=NULL;
              temp4->next=newitem;
              temp4=newitem;
            }
               while(temp2!=NULL)
            {
              Node *newitem= new Node();
              newitem->data=temp2->data;
              newitem->next=NULL;
              temp4->next=newitem;
              temp4=newitem;
            }
            return head2;

        }

    void printList()
    {
        Node *temp5= head2;
        while(temp5!=NULL)
        {
            cout<<temp5->data<<endl;
            temp5=temp5->next;

        }
    }
};
int main() {
    work list1, list2, list3;
    cout << "Creating first list:" << endl;
    list1.makeList();
    cout << "Creating second list:" << endl;
    list2.makeList();
    list3.head2 = list3.mergeList(list1.head, list2.head); // Capture the result of merge
    cout << "Merged List:" << endl;
    list3.printList();
    return 0;
}


//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node *next;
//};
//
//class work {
//public:
//    Node *head = NULL; // Head of the first list
//    Node *head2 = NULL; // Head of the merged list
//
//    void makeList() {
//        int n;
//        cout << "Enter the number of elements: ";
//        cin >> n;
//        for (int i = 0; i < n; i++) {
//            Node *newitem = new Node();
//            cout << "Enter element: ";
//            cin >> newitem->data;
//            newitem->next = NULL;
//
//            if (head == NULL) {
//                head = newitem; // First element becomes head
//            } else {
//                Node *temp = head; // Traverse to the end of the list
//                while (temp->next != NULL) {
//                    temp = temp->next;
//                }
//                temp->next = newitem; // Link new item at the end
//            }
//        }
//    }
//
//    Node* mergeList(Node *n1, Node *n2) {
//        Node *temp1 = n1;
//        Node *temp2 = n2;
//        Node *temp4 = NULL; // Pointer for the merged list
//
//        while (temp1 != NULL && temp2 != NULL) {
//            Node *newitem = new Node();
//            if (temp1->data <= temp2->data) {
//                newitem->data = temp1->data; // Assign from list 1
//                temp1 = temp1->next; // Move to the next node in list 1
//            } else {
//                newitem->data = temp2->data; // Assign from list 2
//                temp2 = temp2->next; // Move to the next node in list 2
//            }
//            newitem->next = NULL; // Initialize next pointer
//            if (head2 == NULL) {
//                head2 = newitem; // Set head of merged list
//                temp4 = head2; // Initialize temp4 to head of merged list
//            } else {
//                temp4->next = newitem; // Link new item to merged list
//                temp4 = newitem; // Move temp4 to new last node
//            }
//        }
//
//        // Handle remaining nodes in list 1
//        while (temp1 != NULL) {
//            Node *newitem = new Node();
//            newitem->data = temp1->data;
//            newitem->next = NULL;
//            if (head2 == NULL) {
//                head2 = newitem;
//                temp4 = head2;
//            } else {
//                temp4->next = newitem;
//                temp4 = newitem;
//            }
//            temp1 = temp1->next;
//        }
//
//        // Handle remaining nodes in list 2
//        while (temp2 != NULL) {
//            Node *newitem = new Node();
//            newitem->data = temp2->data;
//            newitem->next = NULL;
//            if (head2 == NULL) {
//                head2 = newitem;
//                temp4 = head2;
//            } else {
//                temp4->next = newitem;
//                temp4 = newitem;
//            }
//            temp2 = temp2->next;
//        }
//
//        return head2; // Return the head of the merged list
//    }
//
//    void printList() {
//        Node *temp5 = head2;
//        while (temp5 != NULL) {
//            cout << temp5->data << endl;
//            temp5 = temp5->next;
//        }
//    }
//};
//
//int main() {
//    work list1, list2, list3;
//    cout << "Creating first list:" << endl;
//    list1.makeList();
//    cout << "Creating second list:" << endl;
//    list2.makeList();
//    list3.head2 = list3.mergeList(list1.head, list2.head); // Capture the result of merge
//    cout << "Merged List:" << endl;
//    list3.printList();
//    return 0;
//}
//
