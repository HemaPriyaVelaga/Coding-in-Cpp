#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Functions to add: Reverse the linked list, Print the elements in recerse order.

class Node
{
    public:
        int data;
        Node* next;
};


// Function to Find length of the linked list
int LL_length(Node * head)
{
    if(head==NULL) return 0;
    Node * temp = new Node();
    temp = head;
    int count  = 0;
    while(temp->next)
    {
        //cout<<temp->data<<" ";
        temp = temp->next;
        count++;
    }
    count++;
    
    return count;
}


// Function to print the data in all the nodes of LL
void print_LL_nodes(Node * head)
{
    
    if(head == NULL) 
    {
        cout<<"The LL is empty."<<endl;
        return;
    }
    Node * temp = new Node();
    temp = head;
      
    cout<<"The current LL is: ";
    while(temp->next)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
      
    cout<<temp->data<<endl;
}


// Function to insert node at the beginning of the list
void insert_at_head(Node** head_ptr, int val)
{
    
    Node * temp = new Node();
    temp->data = val;
    
    temp->next = (*head_ptr);
    (*head_ptr) = temp;
}


// insert is usually inserting at the end of a linked list
// Function to insert a node at the end of the LL
void insert_at_end(Node** head_ptr, int val)
{
    Node * temp = new Node();
    temp->data = val;
    
    Node * temp2 = new Node();
    temp2 = (*head_ptr);
    
    while(temp2->next)
    {
        temp2 = temp2->next;
    }
    
    temp2->next = temp;
}


// Function to insert a node at a desired position in the LL.
// After insertion, the new node will be at the position pos.
void insert_in_middle(Node** head_ptr, int val, int pos)
{
    Node * temp = new Node();
    temp->data = val;
    
    Node * temp2 = new Node();
    temp2 = (*head_ptr);
    if(pos==1)
    {
        insert_at_head(head_ptr, val);
        return;
    }
    
    int len = LL_length(*head_ptr);
    
    if(pos>len)
    {
        cout<<"The given position exceeds the length of the linked list."<<endl;
        return;
    }
    int loc = 1;
    
    while(temp2->next && loc<pos-1)
    {
        temp2 = temp2->next;
        loc++;
    }
    
    temp->next = temp2->next;
    temp2->next = temp;
}


// Function to delete the first (head) node of the LL
void delete_at_beginning(Node** head_ptr)
{
    if((*head_ptr) == NULL)
    {
        cout<<"The LL is empty. So no deletion."<<endl;
        return;
    }
    Node * temp2 = new Node();
    temp2 = (*head_ptr);
    (*head_ptr) = temp2->next;
    delete(temp2);
}


// Functiont to delete the last node of the linked list.
void delete_at_end(Node** head_ptr)
{
    
    Node * temp2 = new Node();
    temp2 = (*head_ptr);
    
    Node * temp = new Node();
    temp = (*head_ptr);
    
    //Getting to the last node to delete it from the memory
    while(temp2->next)
    {
        temp2 = temp2->next;
    }
    
    // Keeping track of the last but one node to make its next pointer NULL;
    while(temp->next->next)
    {
        temp = temp->next;
    }
    
    temp->next = NULL;
    delete(temp2);
}


// Function to delete the node present at a desired position in the LL.
// After deletion, its next node will be at that position pos.
void delete_in_middle(Node** head_ptr, int pos)
{
    Node * temp = new Node();
    temp = (*head_ptr);
    
    Node * temp2 = new Node();
    temp2 = (*head_ptr);
    
    if(pos==1)
    {
        delete_at_beginning(head_ptr);
        return;
    }
    
    int len = LL_length(*head_ptr);
    
    if(pos>len)
    {
        cout<<"The given position exceeds the length of the linked list."<<endl;
        return;
    }
    
    int prev_loc = 1;
    
    while(temp && prev_loc<pos)
    {
        prev_loc++;
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    delete(temp);
}


// Function to delete the Linked List completely.
void delete_full_LL(Node** head_ptr)
{
    //store current node in temp node, and free the current node.
    //repeat for the nodes next to the current node
    
    Node* temp = new Node();
    Node* current = new Node();
    
    current = (*head_ptr);
    
    while(current)
    {
        temp = current->next;
        delete(current);
        current = temp;
    }
    
    (*head_ptr) = NULL;
}



int main() {
	
	// Creating Head node
	Node* head = new Node();
    head->next = NULL;
    
    insert_at_head(&head, 1);
	//head->data = 1;
	
	Node * second = new Node();
	second->data = 2;
	second->next = NULL;
	head->next = second;
	
	Node * third = new Node();
	third->data = 3;
	third->next = NULL;
    second->next = third;
    
    print_LL_nodes(head);
    
    insert_at_head(&head, 4);
    
    insert_at_end(&head, 5);
    
    print_LL_nodes(head);
    
    insert_in_middle(&head, 6, 5);
    
    print_LL_nodes(head);
    
    cout<<"Length of the current Linked list is: "<<LL_length(head)<<endl;
    
    delete_at_beginning(&head);
    
    print_LL_nodes(head);
    
    delete_at_end(&head);
    
    print_LL_nodes(head);
    
    delete_in_middle(&head, 3);
    
    print_LL_nodes(head);
    
    delete_in_middle(&head, 5);
    
    print_LL_nodes(head);
    
    cout<<"Finally, deleting the entire linked list:"<<endl;
    
    delete_full_LL(&head);
    
    cout<<"Length of the current Linked list is: "<<LL_length(head)<<endl;
    
    print_LL_nodes(head);
    return 0;
}
