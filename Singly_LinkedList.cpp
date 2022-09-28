#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void insBeg(int num){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        temp->data=num;
        temp->next=NULL;
        head=tail=temp;
    }
    else{
        ptr->data=num;
        ptr->next=head;
        head=ptr;
    }
}
void insLast(int num){
     struct node *temp=(struct node*)malloc(sizeof(struct node));
     temp->data=num;
     tail->next=temp;
     temp->next=NULL;
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
    ptr->next=temp;
}
void delBeg(){
    node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    head=temp->next;
    free(temp);
}
void delLast(){
    node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    free(temp->next);
    temp->next=NULL;
    tail=temp;
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
    cout << "\nList After deleting Last Element:\n";
    print();

return 0;
}
