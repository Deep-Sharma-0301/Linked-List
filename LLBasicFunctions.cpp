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
node * insertRecursive(node * head,int i,int val)
{
	node * n=new node(val);
	if(head==NULL)
	{
		return head;
	}
	if(i==0)
	{
		node * temp=head;
		n->next=temp;
		head=n;
		return head;
	}
	node * x=insertRecursive(head->next,i-1,val);
	head->next=x;
	return head;
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
node * deleteNodeRecusive(node * head,int i)
{
	if(head==NULL)
	{
		return NULL;
	}
	if(i==0)
	{
		node * temp=head;
		head=temp->next;
		delete temp;
		return head;
	}
	node * x=deleteNodeRecusive(head->next,i-1);
	head->next=x;
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
int Search(node * head,int n)
{
	node * temp=head;
	int ans=0;
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->data==n)
		{
			flag=1;
			break;
		}
		temp=temp->next;
		ans++;
	}
	if(flag==1)
	{
		return ans;
	}
	return -1;
}
int length(node * head)
{
	node * temp=head;
	int ans=0;
	while(temp!=NULL)
	{
		ans++;
		temp=temp->next;
	}
	return ans;
}
int lengthRecursive(node * head)
{
	node * temp=head;
	if(temp==NULL)
	{
		return 0;
	}
	return 1+lengthRecursive(temp->next);
}
node * Append(node * head,int n)
{
	int l=lengthRecursive(head);
	node * temp=head;
	node * newHead=head;
	node * newTAIL=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	int count=0;
	while(newTAIL!=NULL and count<l-n-1)
	{
		newTAIL=newTAIL->next;
		count++;
	}
	newHead=newTAIL->next;
	newTAIL->next=NULL;
	temp->next=head;
	return newHead;
}
node * reverseLL(node * head)
{
	node * curr=head;
	node * prev=NULL;
	node * nextptr;
	while(curr!=NULL)
	{
		nextptr=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextptr;
	}
	head=prev;
	return head;
}
node * reverseLLrecursive(node * head)
{
	if(head==NULL or head->next==NULL)
	{
		return head;
	}
	node * newHead=reverseLLrecursive(head->next);
	head->next->next=head;
	head->next=NULL;
	return newHead;
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
	cout<<length(head)<<endl;//5
	head=insertRecursive(head,4,6);//if we need to insert at the last of LL then we have to write a new function for that
	print(head);//1 2 3 4 6 5 
	head=deleteNodeRecusive(head,4);
	print(head);//1 2 3 4 5 
	cout<<lengthRecursive(head)<<endl;//5
	cout<<Search(head,99)<<endl;
	//head=Append(head,3);
	print(head);
	head=reverseLL(head);
	print(head);
	head=reverseLLrecursive(head);
	print(head);
	return 0;
}