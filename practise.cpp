#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
class ll
{
    public:
    Node* head;
    ll()
    {
        head = nullptr;
    }
    void arr2ll(vector<int> arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            Node* newNode=new Node(arr[i]);
            if(head==nullptr) head=newNode;
            else
            {   
                Node* temp=head;
                while(temp!=nullptr)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
            }
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
};
int main()
{
    ll a;
    vector<int>arr={9,10,1,3,5};
    a.arr2ll(arr);
    a.removehead();
    return 0;
}