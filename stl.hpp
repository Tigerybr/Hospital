#ifndef STL_H
#define STL_H

#include <iostream>
#include <queue>
using namespace std;

struct patient
{
	string name;
	int priority;
	int treatment;

	bool operator <(const patient& a)const{
		if(priority == a.priority){
			return treatment > a.treatment;
		}
		else{
			return priority > a.priority;
		}
	}
	
	patient(){};
	patient(string a, int b, int c){
		name = a;
		priority = b;
		treatment = c;
	}
};

class stl
{
	public:
		stl();
		~stl();
		void enqueue(string a, int b, int c);
		void dequeue();
		void print();

	private:

		priority_queue<patient> Q;

};
#endif