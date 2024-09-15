#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;//creating a var for storing data
    Node* next;// creating a pointer which points to next data which helps in creating a link
    Node(int data)//A constructor for assigning the value
    {
        this->data=data;
        this->next=nullptr;//its automatically direct to nullptr
    }
};
class LinkedList
{
    Node* head;//creating a node as head(pointer)
    public:
    LinkedList()// constructor for assigning head as null which means a varibale only
    {
        head=nullptr;
    }
    void append(int data)//for assigning the data in the linked list
    {
        Node* newNode=new Node(data);// Creating a new node for appending the list
        if(head==nullptr) head=newNode;//creating head to new node if it does not point to any other node
        else{
            Node* temp=head;//Creating a temp pointer which is a copy of  head(we don't have to tamper with head)
            while(temp->next!=nullptr) //iterate while temp is not assign as nullptr wich means tail of the LL
            {
                temp=temp->next;//temp pointer is assign as next to iterate through LL
            }
            temp->next=newNode;//after completion it assign as new node for further applications
        }
    }
    void printlist()
    {
        Node* temp=head;// Starting from head which points to start of LL
        while(temp!=nullptr) //iterate while temp is not assign as nullptr wich means tail of the LL
        {
            cout<<temp->data<<" ";// prints the data which pointed by temp pointer
            temp=temp->next;//assign temp to next for further priting
        }
        cout<<endl;
    }
    void search(int data)
    {
        Node* temp=head;
        while(temp!=nullptr)
        {
            if(temp->data==data)cout<<"YES"<<endl;
            temp=temp->next;
        }        
    }
};
int main()
{
    LinkedList list;//craeting a linked list
    list.append(1);//input the data in LL
    list.append(2);
    list.append(3);
    list.append(4);
    //list.printlist();// Using the function for printing the list
    list.search(3);
    return 0;
}