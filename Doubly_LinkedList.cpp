#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node*prev;
};
struct node *head=NULL;
struct node *tail=NULL;

void insBeg(int num){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        temp->data=num;
        temp->next=NULL;
        temp->prev=NULL;
        head=tail=temp;
    }
    else{
        ptr->data=num;
        ptr->next=head;
        head->prev=ptr;
        ptr->prev=NULL;
        head=ptr;
    }
}
void insLast(int num){
     struct node *temp=(struct node*)malloc(sizeof(struct node));
     temp->data=num;
     tail->next=temp;
     temp->next=NULL;
     temp->prev=tail;
     tail=temp;
}
void insAny(){
    int num,n;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    cout << "After which node's data you want to insert:";
    cin>>n;
    cout <<"Insert data:";
    cin>>num;
    while(ptr->data!=n){
        ptr=ptr->next;
    }
    temp->data=num;
    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next->prev=temp;
    ptr->next=temp;

}
void delBeg(){
    node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    head=temp->next;
    head->prev=NULL;
    free(temp);
}
void delLast(){
    node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    free(temp->next);
    temp->next=NULL;
    tail->prev=temp->prev->prev;
    tail=temp;
}
void delAny(){
    int n;
    cout << "Which Node you want to delete(Enter data):";
    cin>>n;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->data!=n)
        temp=temp->next;

    temp->next=temp->next->next;
    free(temp->next);
}
void print(){
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL){
        cout<< ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void printrev(){
    struct node *ptr;
    ptr=tail;
    while(ptr!=NULL){
        cout<< ptr->data<<" ";
        ptr=ptr->prev;
    }
    cout<<endl;
}
int main(){
    int n,m,num,num1;
    cout << "Enter Number Of Elements to add at Beginning:";
    cin  >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        insBeg(num);
    }
    cout << "Enter Number Of Elements to add at Last:";
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> num1;
        insLast(num1);
    }
    print();
    delLast();
    print();
    insAny();
    print();
    delLast();
    cout << "\nElements in Reverse Order After Deleting Last Element:\n";
    printrev();
return 0;
}
