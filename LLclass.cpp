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
node * insert(node * head,int i,int val)
{
	node * n=new node(val);
	node * temp=head;
	if(i==0)
	{
		n->next=temp;
		head=n;
		return head;
	}
	int count=0;
	while(temp!=NULL and count<i-1)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		n->next=temp->next;
	    temp->next=n;
	    return head;
	}
}
node * deleteNode(node * head,int i)
{
	node * temp=head;
	if(i==0)
	{
		head=temp->next;
		delete temp;
		return head;
	}
	int count=0;
	while(temp!=NULL and count<i-1)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		temp->next=temp->next->next;
		delete temp->next;
	}
	return head;
}
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
	node * head=takeinput();//1 2 3 4 5 -1
	print(head);//1 2 3 4 5
	head=insert(head,5,6);
	print(head); //1 2 3 4 5 6
	head=deleteNode(head,5);
	print(head); //1 2 3 4 5 
	return 0;
}