#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Some corner cases have to be taken care of in all the functions
// ex: When the DLL is empty or when the position for deletion is 1, go to delete_at_beginning function, etc.


class dll_node
{
    public:
        int data;
        dll_node * prev;
        dll_node * next;
};

int DLL_length(dll_node * head)
{
    if(head==NULL) return 0;
    dll_node * temp = new dll_node();
    temp = head;
    int count  = 0;
    while(temp->next)
    {
        temp = temp->next;
        count++;
    }
    count++;
    
    return count;
}


// Function to print the data in all the nodes of LL
void print_DLL_nodes(dll_node * head)
{
    
    if(head == NULL) 
    {
        cout<<"The LL is empty."<<endl;
        return;
    }
    
    dll_node * temp = new dll_node();
    temp = head;
      
    cout<<endl<<"The current LL is: ";
    while(temp->next)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
      
    cout<<temp->data<<endl;
    
    cout<<"The DLL in reverse order is: ";
    
    while(temp->prev)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    
    cout<<temp->data<<endl;
}



void insert_at_beginning(dll_node ** head_ptr, int data)
{
    dll_node * temp = new dll_node();
	temp->prev = NULL;
	temp->next = (*head_ptr);
	temp->data = data;
	cout<<"Inserting at the beginning of DLL...."<<endl;
	(*head_ptr)->prev = temp;
	
	(*head_ptr) = temp;
}


void insert_at_end(dll_node ** head_ptr, int data)
{

    dll_node * temp = new dll_node();
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = data;
	
	dll_node * temp2 = new dll_node();
    temp2 = (*head_ptr);
    
    while(temp2->next)
    {
        temp2 = temp2->next;
    }
    cout<<"Inserting a node at the end of DLL: "<<endl;
    temp2->next = temp;
    temp->prev = temp2;
}

void insert_in_middle(dll_node ** head_ptr, int data, int pos)
{
    dll_node * temp = new dll_node();
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = data;
	int k = 1;
	
	dll_node * temp2 = new dll_node();
    temp2 = (*head_ptr);
    
    if(pos==1)
    {
        insert_at_beginning(head_ptr, data);
        return;
    }
    
    int len = DLL_length(*head_ptr);
    
    if(pos>len)
    {
        cout<<"The given position exceeds the length of the linked list."<<endl;
        return;
    }
    
    while(temp2->next && k<pos-1)
    {
        temp2 = temp2->next;
        k++;
    }
    
    temp->next = temp2->next;
    temp2->next = temp;
    temp->prev = temp2;
    temp->next->prev = temp;
}


void delete_at_beginning(dll_node ** head_ptr)
{
    if((*head_ptr) == NULL)
    {
        cout<<"The LL is empty. So no deletion."<<endl;
        return;
    }
    dll_node * temp2 = new dll_node();
    temp2 = (*head_ptr);
    (*head_ptr) = temp2->next;
    (*head_ptr)->prev = NULL;
    delete(temp2);
}


void delete_at_end(dll_node ** head_ptr)
{
    dll_node * temp2 = new dll_node();
    temp2 = (*head_ptr);
    
    dll_node * temp = new dll_node();
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


void delete_in_middle(dll_node ** head_ptr, int pos)
{
     dll_node * temp = new dll_node();
    temp = (*head_ptr);
    
    dll_node * temp2 = new dll_node();
    temp2 = (*head_ptr);
    
    if(pos==1)
    {
        delete_at_beginning(head_ptr);
        return;
    }
    
    int len = DLL_length(*head_ptr);
    
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
    temp2->next->prev = temp2;
    delete(temp);
    
}


void delete_full_dLL(dll_node** head_ptr)
{
    //store current node in temp node, and free the current node.
    //repeat for the nodes next to the current node
    
    dll_node* temp = new dll_node();
    dll_node* current = new dll_node();
    
    current = (*head_ptr);
    
    while(current)
    {
        temp = current->next;
        delete(current);
        current = temp;
    }
    cout<<"Deleting the DLL completely... "<<endl;
    (*head_ptr) = NULL;
}


int main() {
    
	dll_node * head = new dll_node();
	head->prev = NULL;
	head->next = NULL;
	head->data = 10;
	
	dll_node * second = new dll_node();
	second->prev = head;
	second->next = NULL;
	second->data = 20;
	
	head->next = second;
	
	dll_node * third = new dll_node();
	third->prev = second;
	third->next = NULL;
	third->data = 30;
	
	second->next = third;
	
	print_DLL_nodes(head);
	
	insert_at_beginning(&head, 40);
	
	print_DLL_nodes(head);
	
	insert_at_end(&head, 50);
	
	print_DLL_nodes(head);
	
	insert_in_middle(&head, 60, 8);
	
	print_DLL_nodes(head);
	
	insert_in_middle(&head, 60, 3);
	
	print_DLL_nodes(head);
	
	delete_at_beginning(&head);
	
	print_DLL_nodes(head);
	
	delete_at_end(&head);
	
	print_DLL_nodes(head);
	
	delete_in_middle(&head, 2);
	
	print_DLL_nodes(head);
	
	delete_full_dLL(&head);
	
	print_DLL_nodes(head);
	
	return 0;
}
