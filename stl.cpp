#include "stl.hpp"

stl::stl(){

}

stl::~stl(){}

void stl::enqueue(string a, int b, int c){
	patient tem(a,b,c);
	Q.push(tem);
}

void stl::dequeue(){
	while(!Q.empty())
	{
		Q.pop();
	}
}

void stl::print(){
	cout<<"Rank	"<<"patient,  "<<"Priority,  "<<"Treatment"<<endl;
	int i=1;
	while(!Q.empty())
	{
		cout<<i<<":	"<<Q.top().name<<",  "<<Q.top().priority<<",  "<<Q.top().treatment<<endl;
		Q.pop();
		i++;
	}
}

