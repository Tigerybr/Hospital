// #include "stl.cpp"
//#include "linkedlist.cpp"
#include "heap.cpp"
#include <sstream>
#include <fstream>
#include <chrono>

using namespace chrono;

int main()
{
	int i=0;
	string name[881];
	int priority[881];
	int treatment[881];

	ifstream file;
	file.open("patientData2270.csv");

	if(file.is_open())
	{
		string line;
		while(getline(file,line, '\r'))
		{

			string words[3];
			int j=0;
			int start=0;
			int count=0;

			for(int k=0; k<(int)line.length(); k++)
			{
				if(line[k]!=',')
				{
					count++;
				}
				else
				{
					words[j]=line.substr(start, count);
					start=k+1;
					count=0;
					j++;
				}

			}
			words[j]=line.substr(start, count);

			stringstream ss1(words[1]);
			stringstream ss2(words[2]);

			name[i]=words[0];
			ss1>>priority[i];
			ss2>>treatment[i];

			i++;


		}
	}
	// stl test;
	//linkedlist test;
	heap test;
	auto start=system_clock::now();

	for(int x=0; x<500; x++)
	{
		for(int j=1; j<801; j++)
		{
			test.enqueue(name[j], priority[j], treatment[j]);
		}

		//test.print();
		test.dequeue();
	}

	auto end=system_clock::now();
	auto duration=duration_cast<microseconds>(end-start);

	cout<<"time use: "<<double(duration.count())*microseconds::period::num/500<<" microseconds."<<endl;
	return 0;
}