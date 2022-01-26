#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node * next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};
node * takeinput()
{
	int data;
	cin>>data;
	node * head=NULL;
	node * tail=NULL;
	while(data!=-1)
	{
		node * n=new node(data);
		if(head==NULL)
		{
			head=tail=n;
		}
		else
		{
			tail->next=n;
			tail=n;
		}
		cin>>data;
	}
	return head;
}
node * middle(node * head)
{
    node * slow=head;
    node * fast=head;
    while(fast->next!=NULL and fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void print(node * head)
{
	node * temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
    node * head=takeinput();
    print(head);
    node *mid=middle(head);
    cout<<mid->data;
    return 0;
}