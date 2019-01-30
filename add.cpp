#include<iostream>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}//constructor function:variable+null pointer
};

class Solution {
public:
	int carry=0;
	ListNode* node=new ListNode(0);//used to move
	ListNode* ptr=node;//record the head pointer of list.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int temp=0;
        while(l1!=NULL&&l2!=NULL)//if both not null
        {
      	if(l1->val+l2->val+carry>=10)//carry
	      	{temp=(l1->val+l2->val+carry)%10;
	        carry=1;}
        else
        	{
        		temp=l1->val+l2->val+carry;
        	    carry=0;
        	}
        l1=l1->next;//move the pointer of input
        l2=l2->next;
        node->val=temp;
        if(l1==NULL&&l2==NULL)
        	break;
        newList();//long and move the pointer of result
        }

        while(l1!=NULL&&l2==NULL)//l1 is longer
        {
	        if((l1->val+carry)==10)
	      			carry=1;
		    else{
				    temp=l1->val+carry;
					node->val=temp;
					carry=0;
				}
			l1=l1->next;
			if(l1!=NULL)
				newList();


	    }

	    while(l1==NULL&&l2!=NULL)//l2 is longer
      	{
      		if((l2->val+carry)==10)
      			carry=1;

	      	else{
			      	temp=l2->val+carry;
				    node->val=temp;
				    carry=0;
				}

			l2=l2->next;

		    if(l2!=NULL)
			     newList();

	   }

	   
	   if(l1==NULL&&l2==NULL&&carry==1)//need to add length for results
	   {
	    	newList();
	    	temp=carry;
	    	node->val=temp;
       }



	   return ptr;
    }

	void newList()
	{
		ListNode* newnode=new ListNode(0);
	    node->next=newnode;
	    node=newnode; 

	}
};

int main()
{
	Solution a;
    ListNode* l1 = new ListNode(2);
    ListNode* l11 = new ListNode(4);
    ListNode* l12 = new ListNode(3);
    l11->next = l12;
    l1->next = l11;

    ListNode* l2 = new ListNode(5);
    ListNode* l21 = new ListNode(6);
    ListNode* l22 = new ListNode(4);
    l21->next = l22;
    l2->next = l21;

    ListNode* l=a.addTwoNumbers(l1, l2);//get result head pointer
    cout<<l->val<<l->next->val<<l->next->next->val<<endl;
    return 0;


}