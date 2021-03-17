#include "linkedlist.hpp"

linkedlist::linkedlist(){
	head=nullptr;
	end=nullptr;
}

linkedlist::~linkedlist(){
	patient *node=head;
	while(node!=nullptr)
	{
		patient *next = node->next;
		delete node;
		node = next;
	}

	head=nullptr;
	end=nullptr;
}

void linkedlist::enqueue(string a, int b, int c){
	if(head == nullptr)
	{
		head = new patient(a, b, c);

		end = head;
	}
	else
	{
		end->next = new patient(a, b, c);

		end = end->next;
	}
}

void linkedlist::dequeue(){

	while(head!=nullptr)
	{
		patient *next = head->next;
		delete head;
		head = next;
	}

	head=nullptr;
	end=nullptr;
	
}

void linkedlist::print(){
	cout<<"Rank	"<<"patient,  "<<"Priority,  "<<"Treatment"<<endl;
	int i=1;
	patient *node = head;

	while(node!=nullptr)
	{
		cout<<i<<":	"<<node->name<<",  "<<node->priority<<",  "<<node->treatment<<endl;
		node = node->next;
		i++;
	}
}

void linkedlist::sort(){
	patient *insert = head -> next;
	head -> next = nullptr;
	end = head;

	while(insert != nullptr){
		patient *tem = head;
		patient *parent = nullptr;

		patient *p = insert;
		insert = insert -> next;

		while(tem != nullptr){
			if(p->priority == tem->priority){
				if(p->treatment >= tem->treatment){
					parent = tem;
					tem = tem->next;
				}
				else{
					break;
				}
			}
			else{
				if(p->priority > tem->priority){
					parent = tem;
					tem = tem->next;
				}
				else{
					break;
				}
			}
		}

		if(parent == nullptr){
			p -> next = head;
			head = p;
		}
		else{
			if(parent == end){
				p -> next = nullptr;
				end -> next = p;
				end = p;
			}
			else{
				p -> next = parent -> next;
				parent -> next = p;
			}
		}
	}
}