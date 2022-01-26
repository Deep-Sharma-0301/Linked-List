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
node * merge(node * head,node * head1)
{
    if(head==NULL)
    {
        return head1;
    }
    if(head1==NULL)
    {
        return head;
    }
    node * c;
    if(head1->data<=head->data)
    {
        c=head1;
        c->next=merge(head,head1->next);
    }
    else{
        c=head;
        c->next=merge(head->next,head1);
    }
    return c;
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
    node * head1=takeinput();
    print(head1);
    node * head2=merge(head,head1);
    print(head2);
    return 0;
}