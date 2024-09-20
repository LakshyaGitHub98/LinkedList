#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*back;
    Node(int data){
        this->data=data;
        next=nullptr;
        back=nullptr;
    }
    Node(int data,Node*next,Node*back){
        this->data=data;
        this->next=next;
        this->back=back;
    }
};
Node* convert_Arr_to_dll(vector<int>arr){
    Node*head=new Node(arr[0]);
    Node*prev=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        temp->next=nullptr;
        temp->back=prev;
        prev->next=temp;
        prev=temp;
    }
    return head;
}
Node * deleteHead(Node *head) {
    if(head==NULL)return head;
    Node*prev=head;
    head=head->next;
    delete prev;
    return head;
}
void print(Node* head) {
    if(head==NULL)cout<<"NULL";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node*delete_tail(Node*head){
    if(head==NULL){
        delete head;
        return NULL;
    }
    Node*temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node*tail=temp;
    temp=temp->next;
    tail->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
}
Node*delete_kthNode(Node*head, int k){
    Node*temp=head;
    int i=0;
    while(temp!=NULL){
        i++;
        if(i==k)break;
        temp=temp->next;
    }
    Node*prev=temp->back;
    Node*front=temp->next;
    if(prev==NULL and front==NULL){
        delete temp;
        return NULL;
    }
    else if(prev==NULL){
        Node*current=deleteHead(head);
        return current;
    }
    else if(front==NULL){
        Node*current=delete_tail(head);
        return current;
    }
    else{
        prev->next=front;
        front->back=prev;
        temp->back=nullptr;
        temp->next=nullptr;
        delete temp;
    }
    return NULL;
}
Node* insert_h(Node*head,int k){
    if(head==NULL)
    {
        head=new Node(k);
    }
    Node*newNode=new Node(k);
    head->back=newNode;
    newNode->next=head;
    head=head->back;
    return head;
}
Node* insert_t(Node* head, int k){
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node*newNode=new Node(k);
    temp->next=newNode;
    newNode->back=temp;
    return head;
}
/*Node* insert(Node*head, int k){
    int i=0;
    Node* temp=head;
    while(temp!=NULL){
        i++;
        if(i==k)break;
        temp=temp->next;
    }
    
    
}*/
Node* reverse_dll(Node*head){
    stack<int>st;
    Node*temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int>arr={4,7,8,1,20};
    Node*head=convert_Arr_to_dll(arr);
    //head=deleteHead(head);
    //Node *k=delete_kthNode(head,6);
    head=reverse_dll(head);
    print(head);
    return 0;
}