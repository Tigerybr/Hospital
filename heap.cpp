#include "heap.hpp"

heap::heap(){
	size = 0;
}

heap::~heap(){

}

void heap::enqueue(string a, int b, int c){
	enhelp(a, b, c, size+1);
	size++;
}

void heap::dequeue(){
	while(size!=0)
	{
		array[1]=array[size];
		size--;	

		down(1);
	}
}

void heap::print(){
	cout<<"Rank	"<<"patient,  "<<"Priority,  "<<"Treatment"<<endl;
	int i=1;
	while(size!=0)
	{
		cout<<i<<":	"<<array[1].name<<",  "<<array[1].priority<<",  "<<array[1].treatment<<endl;
		array[1]=array[size];
		size--;	
		i++;

		down(1);
	}
}

void heap::enhelp(string a, int b, int c, int i){
	patient tem(a, b, c);
	array[i] = tem;

	up(i);
}

void heap::down(int i){
	if( 2*i <= size && (2*i)+1 <= size)
	{
		if(array[2*i].priority == array[(2*i)+1].priority)
		{
			if(array[2*i].treatment < array[(2*i)+1].treatment)
			{
				patient tem = array[i];
				array[i] = array[2*i];
				array[2*i] = tem;
				down(2*i);
			}
			else
			{
				patient tem = array[i];
				array[i] = array[(2*i)+1];
				array[(2*i)+1] = tem;
				down((2*i)+1);
			}
		}
		
		else{
			if(array[2*i].priority < array[(2*i)+1].priority)
			{
				patient tem = array[i];
				array[i] = array[2*i];
				array[2*i] = tem;
				down(2*i);
			}
			else
			{
				patient tem = array[i];
				array[i] = array[(2*i)+1];
				array[(2*i)+1] = tem;
				down((2*i)+1);
			}
		}
	}
	else{
		if(2*i <= size)
		{
			patient tem = array[i];
			array[i] = array[2*i];
			array[2*i] = tem;
			down(2*i);
		}
	}

}

void heap::up(int i){
	if(i > 1){
		int parent = (int)(i / 2);

		if(array[i].priority == array[parent].priority)
		{ 
			if(array[i].treatment < array[parent].treatment)
			{ 
				patient tem = array[i];
				array[i] = array[parent];
				array[parent] = tem;
				up(parent);
			}
		}

		else{ 
			if(array[i].priority < array[parent].priority)
			{
				patient tem = array[i];
				array[i] = array[parent];
				array[parent] = tem;
				up(parent);
			}
		}
	}
}

