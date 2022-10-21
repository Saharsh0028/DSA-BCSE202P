#include <iostream>
using namespace std; 

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
};

Node *insertBegin(Node *head,int data){
    Node *temp=new Node(data);
    
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    
    return temp;   
}

Node *insertEnd(Node *head,int data){
    Node *temp=new Node(data);
    if(head==NULL)
    return temp;
    
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}

int deleteValue(Node* head, int x)                                  //Deletion of particular value
{
  
    if (head == NULL)
        return 0;
  
    Node* temp = head;
    if (temp->data == x) {
        head = temp->next;
        return 1;
    }
    
    Node* curr=temp->next;
    while(curr->data!=x&&curr->next!=NULL){
        curr=curr->next;
        temp=temp->next;
    }
    
    if(curr->next==NULL&&curr->data==x){
        temp->next=NULL;
        return 1;
    }
    else if(curr->next==NULL&&curr->data!=x){
        return 0;
    }
    
    temp->next=curr->next;
    curr->next->prev=temp;

    return 1;
  
}

Node *insertPosition(Node *head, int pos, int x){                //Insertion at particular position
    Node *node = new Node(x);
    if(pos==1){
        head->prev=node;
        node->next=head;
        return node;
    }

    Node *temp=head;

    for(int i=1;i<=pos-2&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        return head;
    }

    node->next=temp->next;
    temp->next->prev=node;
    temp->next=node;
    node->prev=temp;
    return head;
}

void display(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

int main() 
{ 
	Node *head=NULL;
    int n, val, pos;
    cout<<"Select the operation\n1. Insertion in the beginning of the list\n2. Insertion at the end of the list\n3. Insertion in a particular location of the list\n4. Deletion based on a particular value\n5. Display the contents of the list\nEnter 0 to exit\n";
    cin>>n;
    while(n){
        switch(n){
            case 1:{
                        cout<<"Enter the element to be entered: ";
                        cin>>val;
                        head=insertBegin(head,val);
                        cout<<"Element Inserted\n";
                        break;
            }

            case 2:{
                        cout<<"Enter the element to be entered: ";
                        cin>>val;
                        head=insertEnd(head,val);
                        cout<<"Element Inserted\n";
                        break;  
            }

            case 3:{
                        cout<<"Enter the element to be entered: ";
                        cin>>val;
                        cout<<"Enter the position to be entered at: ";
                        cin>>pos;
                        head=insertPosition(head,pos,val);
                        cout<<"Element Inserted\n";
                        break;     
            }

            case 4:{
                        cout<<"Enter the value to be deleted: ";
                        cin>>val;
                        if(deleteValue(head,val)){
                            cout<<"Element Deleted\n";
                        }
                        else{
                            cout<<"Element Not present / List Empty\n";
                        }
                        break;     
            }

            case 5:{
                        display(head);
                        break;
            }

            default:{
                        cout<<"Wrong Input... Try Again\n";
        }
        }
        cout<<"Select The operation :";
        cin>>n;
    }
	return 0;
}