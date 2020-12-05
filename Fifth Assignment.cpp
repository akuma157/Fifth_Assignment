#include<bits/stdc++.h>
#include<string>
using namespace std;

class Node{ // A linked list node
	public:
		int data;
		Node *next;
};
void showstack(stack <int> s) // the function that shows the stack to the user
{
    while (!s.empty())
    {
        cout<<"["<<s.top()<<"]";
        s.pop();
    }
    cout<<endl;
}
void deleteMid(stack<int> &s, int n, // the deletion function
			int curr=0)
{
	if (s.empty() || curr == n) 
		return; 
	int x = s.top(); 
	s.pop(); 
	deleteMid(s, n, curr+1); 
	if (curr != n/2) 
		s.push(x); 
}

void push(Node** head_ref, int new_data) // the add at first function
{
	Node* new_node = new Node(); // allocate node
	new_node->data = new_data; // put in the data
	new_node->next = (*head_ref); // Make next of new node as head
	(*head_ref) = new_node; // move the head to point to the new node
}
void insertAfter(Node* prev_node, int new_data) // the add at middle function
{
	if (prev_node == NULL)
	{
		cout<<"the given previous node cannot be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
void append(Node** head_ref, int new_data) // the add at last function
{  
    Node* new_node = new Node(); 
    Node *last = *head_ref;
    new_node->data = new_data;  
    new_node->next = NULL;  
    if (*head_ref == NULL)  
    {  
        *head_ref = new_node;  
        return;  
    }  
    while (last->next != NULL)  
        last = last->next;  
    last->next = new_node;  
    return;  
}
void deleteNode(Node** head_ref, int key) // the delete function
	{
    Node* temp = *head_ref; 
    Node* prev = NULL; 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;
        delete temp;
        return; 
    } 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) // If key was not present in linked list 
        return; 
    prev->next = temp->next; // Unlink the node from linked list
    delete temp;
	}
int getCount(Node* head) // the length counter function
{
	int count = 0;
	Node* current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}
bool search(Node* head, int x) // the search function
{
	Node* current = head;
	while (current != NULL)
	{
		if (current->data == x)
			return true;
		current = current->next;
	}
	return false;
}
void printList(Node *node) // this function shows the linked list saved
{
    while (node != NULL)
    {
        cout<<"| "<<node->data<<" |>";
        node = node->next;
    }
    
}
  
int main()
{
	int CHOICE;
    
    cout<<"Enter 1 for Linked List\nEnter 2 for Stack\nEnter 3 for Queue\n";
    cin>>CHOICE;
    switch(CHOICE){
    	case 1:{
    		int i=0, a, b, c, d, s, choice, choAdd; // all the integers
			Node* head = NULL; // making node null
			push(&head, 1); // inserting the integer 1 into the list
		    append(&head, 5); // inserting the integer 5 into the list
		    insertAfter(head->next, 3); // inserting the integer 3 into the list
		    cout<<"The Linked list: ";
		    printList(head); // the linked list show is for editing
    
			cout<<"\nEnter 1 to Add An Element\nEnter 2 to Delete An Element\n";
			cin>>choice;
			switch (choice){ // choosing between adding or deleting elements
					case 1:{ // first adding elements
						do{
							i=i+1;
							cout<<"\nEnter 1 to Add First\nEnter 2 to Add at Middle\nEnter 3 to Add Last\n";
							cin>>choAdd;
							
							switch (choAdd){ // the adding choice is between three ways 
								case 1:{cout<<"Enter An Element to Add: ";cin>>a;
									push(&head, a); // the first element addition from the push function
									break;}
								case 2:{cout<<"Enter An Element to Add: ";cin>>b;
									insertAfter(head->next, b); // the middle element addition from the insertAfter function
									break;}
								case 3:{cout<<"Enter An Element to Add: ";cin>>c;
									append(&head, c); // the last element addition from the append function
									break;}
								default :{cout<<"";break;}
							break;}
						cout<<"The Linked list after Addition: ";
			    		printList(head);} // printList function is detected for showing the last list edited
						while (i<3);}
					case 2:{cout<<"\nEnter The Element You Want to Delete: ";cin>>d;
						deleteNode(&head, d); // the element deletion function
					    cout<<"\nThe Linked list after Deletion: ";
					    printList(head);break;}
					default :{cout<<"";break;}
					}
			cout<<"\nThe List Length is: "<<getCount(head); // getCount function counts the number of elements in the list
			cout<<"\nEnter the Element You Want to Find: ";cin>>s;
			search(head, s)? cout<<"The value is included" : cout<<"There's no such a value"; // the search function finds the elements you enter
			break;}
		case 2:{
			int j=0, se, xs;
			stack <int> s; // the stack is defined as an integer
		    cout<<"Elements number you want to enter: ";cin>>se; // making the stack from the scratch
		    cout<<"Enter Each Element:\n";
		    do
		    {
		    	j++;
		    	cin>>xs;
		    	s.push(xs);
			}
			while (j<se);
			cout<<"The stack is: ";
    		showstack(s); // showing the last edited stack
		    cout<<"The stack after deletion is: ";
		    deleteMid(s, s.size()); // deletMid is a function deletes the middle stack element
		    while (!s.empty())
		    {
		    	int p=s.top(); // the integer p contains every element didn't get deleted
		    	s.pop();
		    	cout<<"["<<p<<"]";
			}
			break;
		}
		default :{cout<<"";break;}
	}
    return 0;
}
