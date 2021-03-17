#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct patient
{
	string name;
	int priority;
	int treatment;
	
	patient(){};
	patient(string a, int b, int c){
		name = a;
		priority = b;
		treatment = c;
	}
};

class heap
{
	public:
		heap();
		~heap();
		void enqueue(string a, int b, int c);
		void dequeue();
		void print();

	private:
		void enhelp(string a, int b, int c, int i);
		void down(int i);
		void up(int i);
		patient array[881];
		int size;

};
#endif