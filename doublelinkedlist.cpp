#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;
    node (int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertAtHead(node* &head,int new_data)
{
    node*n =new node(new_data);
    n->next=head;
    if(head!=NULL)
    {
        head->prev=n;
    }
    head=n;
}
void insertAtTail(node* head,int new_data)
{
    if(head==NULL)
    {
        insertAtHead(head,new_data);
    }
    node* n=new node(new_data);
    node* last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=n;
    n->prev=last;
}
void display(node* head)
{
    node* last=head;
    while(last!=NULL)
    {
        cout<<last->data<<" ";
        last=last->next;
    }
}
void deleteTail(node* head)
{
    node*last=head;
    while(last->next->next!=NULL)
    {
        last=last->next;
    }
    last->next=NULL;
    
}
void deleteHead(node* &head)
{
    head->next->prev=NULL;
    head=head->next;
}
void deletenode(node* head,int loc)
{

    node* previ=head;
    node* next;
    int count=1;
    while(previ!=NULL&&count!=loc)
    {
        previ=previ->next;
        count++;
    }
    previ->prev->next=previ->next;
    previ->next->prev=previ->prev;
    delete previ;
}
int main()
{
    node* head=new node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtHead(head,0);
    // deleteTail(head);
    // deleteTail(head);
    // deleteHead(head);
    deletenode(head,7);
    display(head);
}