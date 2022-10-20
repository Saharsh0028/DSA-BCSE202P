#include <iostream>
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node *insertBegin(Node *head,int x){                                            //Insertion at beginning
    Node *node=new Node(x);
    node->next=head;
    return node;
    
}

Node *insertEnd(Node *head,int x){                                              //Insertion at end
    Node *node=new Node(x);
    if(head==NULL)
    return node;
    
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=node;
    return head;
    
}

Node *deleteBegin(Node *head){                                                   //Deletion at beginning
    if(head==NULL)
        return NULL;
    
    else{
        return head->next;

    }
}

Node *deleteEnd(Node *head){                                                    //Deletion at end
    
    if(head==NULL)
        return NULL;
    
    if(head->next==NULL){
        delete(head);
        return NULL;
    }

    Node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    delete (temp->next);
    temp->next=NULL;
    return head;
}

int searchElement(Node * head, int x){                                          //Search an element
    int pos=1;
    Node *curr=head;
    while(curr!=NULL){
        if(curr->data==x)
            return pos;
        else{
            pos++;
            curr=curr->next;
        }
    }
    return -1;
}

Node *reverse(Node *head){                                                      //Reverse the list
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node *insertPosition(Node *head, int pos, int x){                               //Insertion at particular position
    Node *node = new Node(x);
    if(pos==1){
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
    temp->next=node;
    return head;
}

int deleteValue(Node* head, int x)                                              //Deletion of particular value
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

    return 1;
  
}

void deleteNode(Node* head, int position)                                       //Deletion at particular position
{
  
    if (head == NULL)
        return;
  
    Node* temp = head;
  
    if (position == 0) {
  
        head = temp->next;

        return;
    }
  
    for (int i = 0; temp != NULL && i < position - 2; i++)
        temp = temp->next;
  
    if (temp == NULL || temp->next == NULL)
        return;
  
    Node* next = temp->next->next;
  
    temp->next = next;
}

void count(Node* head){                                                         //Count Even and Odd numbers                    
    Node *temp=head;
    int even=0, odd=0;
    while(temp!=NULL){
    if(temp->data%2==0){
        even++;
    }
    else{
        odd++;
    }
    temp=temp->next;
    }
    cout<<"Even Count: "<<even<<"\nOdd Count: "<<odd<<endl;
}

void display(Node *head){                                                       //Display the list
        Node *temp=head;
        while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        }
        cout<<endl;
}


int main() 
{ 
	Node *head=NULL;

    int n,val,pos;
    cout<<"Select the operation:\n1. Insertion in the beginning of the list\n2. Insertion at the end of the list\n3. Insertion in a particular location of the list\n4. Deletion based on a particular value\n5. Deletion based on a particular location\n6. Deleting an element at the beginning\n7. Deleting an element at the end of the list\n8. Search an element\n9. Reverse the list\n10. Count the number of even and odd numbers in the list\n11. Display the contents of the list\nEnter 0 to exit\n";
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
                    cout<<"Enter the position to be deleted: ";
                    cin>>pos;
                    deleteNode(head,pos);
                    cout<<"Element Deleted\n";
                    break;
        }

        case 6:{
                    head = deleteBegin(head);
                    cout<<"Element Deleted\n";
                    break;
        }

        case 7:{
                    head = deleteEnd(head);
                    cout<<"Element Deleted\n";
                    break;
        }

        case 8:{
                    cout<<"Enter the element to be searched: ";
                    cin>>val;
                    pos=searchElement(head,val);
                    if(pos==-1){
                        cout<<"Element Not Found\n";
                    }
                    else{
                        cout<<"The position is "<<pos<<endl;
                    }
                    break;
        }

        case 9:{
                    head=reverse(head);
                    cout<<"List Reversed\n";
                    break;
        }

        case 10:{
                    count(head);
                    break;
        }

        case 11:{
                    display(head);
                    break;
        }
        default:{
            cout<<"Wrong Input... Try Again\n";
        }
    }
    cin>>n;
    }
	return 0;
} 
