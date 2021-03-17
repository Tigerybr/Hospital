#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct patient
{
	string name;
	int priority;
	int treatment;

	patient *next;
	
	patient(){};
	patient(string a, int b, int c){
		name = a;
		priority = b;
		treatment = c;
		next=nullptr;
	}
};

class linkedlist
{
	public:
		linkedlist();
		~linkedlist();
		void enqueue(string a, int b, int c);
		void dequeue();
		void print();
		void sort();
	private:
		patient *head;
		patient *end;	
	
};
#endif
