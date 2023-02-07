#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }     
};


//Adding node data in a vector to display
vector<int> displayList(Node *head)
{
    vector<int>ans;
    Node *temp = head;
    while(temp!=NULL)
    {
        ans.push_back(temp -> data);
        temp = temp ->next;
    }
    return ans;
    
}

//Sum of Nodes in a linked list
int sumOfElements(Node *head)
{
   int sum = 0;
   Node *temp = head;
   while(temp!=NULL)
   {
       sum+=(temp -> data);
       temp = temp -> next;
   }
   return sum;
}

//Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        int c=0;
        Node *temp = head;
        while(temp!=NULL)
        {
            c++;
            temp = temp -> next;
        }
    
        return c;
    }

//Maximum element in a linked list
int maximum(Node *head)
{
    int m = 0;
    Node *t = head;
    while(t!=NULL)
    {
        if(m< t->data) m=t->data;
        t= t->next;
    }
    return m;
}

//Minimum element in a linked list
int minimum(Node *head)
{
   int m = INT_MAX;
    Node *t = head;
    while(t!=NULL)
    {
        if(m>t->data) m=t->data;
        t= t->next;
    }
    return m;
}

//Searching an element in a linked list
bool searchLinkedList(Node *head, int x)
{
    Node *t=head;
    while(t!=NULL)
    {
        if(t->data==x) return true;
        t=t->next;
    }
    return false;
}

 //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       
       Node *N = new Node(x);
       N -> next = head;
       return N;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       
       if(head==NULL) 
         {    
             Node *N = new Node(x);
             N -> next = head;
             return N;
         }
       
       Node *n = new Node(x);
       Node *temp = head;
       while(temp->next)
       {
           temp = temp -> next;
       }
       
       temp ->next = n;
       n->next=NULL;
       return head;
       
    }

//Function to insert a node in the middle of the linked list.
Node* insertInMiddle(Node* head, int x)
{
    Node *newnode = new Node(x);
    Node *temp1 = head;
    Node *temp2 = head;
    
    while(temp2->next!=NULL && temp2->next->next!=NULL){
        temp1 = temp1 -> next;
        temp2 = temp2 -> next -> next;
    }
    newnode -> next = temp1 -> next;
    temp1 -> next = newnode;
    return head;	
}

//Insert after the given position
void insertAtPosition(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    Node *curr = head;
    for(int i=0;i<=pos-2 and curr!=nullptr;i++){
        curr = curr->next;
    }
    if(curr==nullptr) return;
    temp->next = curr->next;
    curr->next = temp;
}

//Insert element in a sorted linked list
Node *insertInSorted(Node *head, int data)
{
    Node *temp = new Node(data);
    if(head==nullptr) return temp;
    if(head->data>data){
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while(curr->next!=nullptr and data>curr->next->data){
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

//Delete tail of linked list
Node * deleteTail(Node *head)
{
    if(head==nullptr) return head;
    Node *curr = head;
    while(curr->next->next!=nullptr){
        curr = curr->next;
    }
    Node *temp = curr->next;
    delete temp;
    curr->next = nullptr;
    return head;
}

//Delete head of linked list
Node * deleteHead(Node *head)
{
    if(head==nullptr) return nullptr;
    Node *temp = head->next;
    delete head;
    return temp;
}

//Delete element at position
Node * deleteAtPosition(Node *head,int pos)
{
    if(head==nullptr) return head;
    Node *curr = head;
    if(pos==1){
        curr = head->next;
        delete head;
        return curr;
    }
    for(int i=1;i<=pos-2 and curr!=nullptr;i++){
        curr = curr->next;
    }
    if(curr==nullptr) return head;
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

//Check if linked list is sorted
bool isSorted(Node * head)
{
    if(head->next==NULL) 
        return true;
   
    Node *curr = head;
    int flag1 = 1, flag2 = 1;
    while(curr->next != NULL)
    {
        if((curr->data) > (curr->next->data))
        {
            flag1 = 0;
            break;
        }
        curr = curr->next;
    }

    curr = head;
    while(curr->next != NULL)
    {
        if((curr->data) < (curr->next->data))
        {
            flag2 = 0;
            break;
        }
        curr = curr->next;
    }
    
    if(flag1 == 0 && flag2 ==0) 
        return false;
    
    return true;
}

//Join two linked lists
Node * joinTheLists(Node * head1, Node * head2)
{
    if(head1==nullptr) return head2;
    if(head2==nullptr) return head1;
    
    Node *curr = head1;
    while(curr->next!=nullptr)
    {
        curr = curr->next;
    }

    curr->next = head2;
    return head1;
}

//Remove duplicates from a linked list
Node *removeDuplicates(Node *head)
{
 Node* prev = head;
 Node* curr = head->next;
 
 while(prev->next != NULL)
 {
     if(prev->data == curr->data)
     {
         prev->next = curr->next;
         curr->next = NULL;
         curr = prev->next;
     }

     else
     {
         prev = prev->next;
         curr = curr->next;
     }
 }
 
 return head;

}

//Check if two linked lists are identical or not
bool areIdentical(struct Node *head1, struct Node *head2)
{
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data!=head2->data) return false;
        head1=head1->next;
        head2=head2->next;
    }

    if(head1==NULL && head2==NULL) 
        return true;
    
    return false;
}

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       Node* start = new Node(-1);
       start->next = head;
       Node* fast = start;
       Node* slow = start;
       
       for(int i=1;i<=n;i++) {
           if(!fast->next) return -1;
           fast = fast->next;
       }
       while(fast->next){
           fast = fast->next;
           slow = slow->next;
       }
       if(!slow->next) return -1;
       return slow->next->data;
}

//Function to reverse the linked list
struct Node* reverseList(struct Node *head)
    {
        Node* q=NULL;
        Node* p=head -> next;
        if(head->next==NULL)
            return head;

        while(p->next !=NULL)
        {
            head->next=q;
            q=head;
            head=p;
            p=p->next;
        }
        
        head->next=q;
        q=head;
        head=p;
        head->next=q;
    
        return head;
    }