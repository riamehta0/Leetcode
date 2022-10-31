#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void push(Node** head,int data)
{
    Node* new_node=new Node;
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}
void insertafter(Node* prev_node,int data)
{
    Node* new_node=new Node;
    new_node->data=data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}
Node* insert_last(Node* head,int data)
{  
    Node* dummy=head;
    while(dummy->next!=NULL)
        dummy=dummy->next;
    Node* new_node=new Node();
    new_node->data=data;
    new_node=NULL;
    dummy->next=new_node;
    return head;
}
void append(Node** head,int data)
{
    Node* new_node=new Node;
    new_node->data=data;
    new_node->next=NULL;
    Node* last=*head;
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
}
void printList(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}
void dlt(Node** head, int delete_data)
{
    Node* last=*head;
    Node* previous;
    while (last->data!=delete_data)
    {
        previous=last;
        last=last->next;   
    } 
    previous->next=last->next;    
}
void dltp(Node** head, int position)
{
    int l=1;
    Node* last=*head;
    Node* previous;
    while(l!=position)
    {
        previous=last;
        last=last->next;
        l++;
    }
    previous->next=last->next;
}
void deletList(Node** head)
{
    Node*last=*head;
    Node* current=last;
    while(last!=NULL)
    {
        current->next=NULL;
        last=last->next;
    }
    *head=NULL;
}
Node* reverse(Node** head)
{
    Node* previous=NULL;
    Node* current=*head;
    Node* agla;
    while(current!=NULL)
    {
        agla=current->next;
        current->next=previous;
        previous=current;
        current=agla;
    }
    *head=previous;
    return previous;
}
Node* reversek(Node* head,int k)
{
    Node* prevptr=NULL;
    Node* currentptr=head;
    Node* nextptr;
    int count=0;
    while(currentptr!=NULL&&count<k)
    {
        nextptr=currentptr->next;
        currentptr->next=prevptr;
        prevptr=currentptr;
        currentptr=nextptr;
        count++;
    }
    if(nextptr!=NULL)
    {
        head->next=reversek(nextptr,k);
    }
    return prevptr;
}
void insertCycle(Node** head,int pos)
{
    Node* ptr=*head;
    Node* locptr;
    int count=1;
    while(ptr->next!=NULL)
    {
        if(count==pos)
        {
            locptr=ptr;
        }
        count++;
        ptr=ptr->next;
    }
    ptr->next=locptr;
}
bool checkCycle(Node** head)
{
    Node* fast=*head;
    Node* slow=*head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
void removeCycle(Node**head)
{
    Node* slow=*head;
    Node* fast=*head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    slow=*head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
}
void printCircularLinkList(Node** head)
{
    Node* p=*head;
    Node* s=p;
    while(p->next!=s)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<p->data;
}
void pushCircluarList(Node **head, int new_data)
{
    Node* last=*head;
    Node *new_node = new Node;
    new_node->data = new_data;
    if (head == NULL)
    {
        *head = new_node;
    }
    else
    {
        new_node->next=*head;
        *head=new_node;
    }
}
Node* appendknode(Node* head,int k)
{
    Node* tail=head;
    Node* newhead;
    Node*newtail; 
    int count=0;
    while(tail->next!=NULL)
    {
        count++;
        if(count==k)
        {
            newtail=tail;
        }
        if(count==k+1)
        {
            newhead=tail;
        }
        tail=tail->next;
    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;
}
void insertionList(Node* head) {

} 
int main() {   
    Node*head=NULL;   
    push(&head,9);
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printList(head);
    cout<<endl;
    // 1 9 2 8 3 7 4 6 5
    Node* node=head;
    while(node->next!=NULL)
        node=node->next;
    insertionList(head);
    printList(head);
    return 0;
}