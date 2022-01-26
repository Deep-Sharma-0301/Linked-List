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
node * kFromLast(node * head,int k)
{
    node * fast=head;
    node * slow=head;
    while(k-1>=0 and fast!=NULL)
    {
        fast=fast->next;
        k--;
    }
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
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
    node *last=kFromLast(head,3);
    cout<<last->data;
    return 0;
}