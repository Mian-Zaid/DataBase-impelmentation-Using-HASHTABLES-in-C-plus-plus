#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"
#include<iostream>
#include<fstream>
using namespace std;
Table::Table(string k,string v)
{
	table_name = k;
	cols = 0;
	cout << "v = " << v << endl;
	for (int i = 0; i < v.length();++i) 
	{
		if (v[i] == ',') {

			++cols;
		}
	}
	++cols;
	list = new myLinklist<string>[cols];
	string c;
	char* t1, * t2;
	int i = 0;
	t1 = (char*)v.c_str();
	t2 = strtok(t1, ",");
	//list[i].setname(t2);
	while(t2!=NULL)
	{
		
		list[i].setname(t2);
		++i;
		t2= strtok(NULL, ",");
	}
	for (int i = 0; i < cols; ++i)
	{
		//cout << list[i].getname() << " ";
	}
	
}
void Table::INSERT( string tup)
{
	//cout << tup;
	char* t1, * t2;
	int i = 0;
	t1 = (char*)tup.c_str();
	t2 = strtok(t1, "|");
	//list[i].setname(t2);
	while (t2 != NULL)
	{
		//cout << t2 << "--";
		list[i].insert(t2);
		
		++i;
		t2 = strtok(NULL, "|");
	}
	cout << "";
}
void Table::UPDATE(string)
{

}
void Table::DELETE(string)
{

}
void Table::SELECT(string tup)
{
	if (list[0].contains(tup))
	{
		int n = list[0].getn(tup);
		for (int i = 0; i < cols; ++i)
		{
			list[i].displayAt(n);
		}
	}
}
void Table::DISPLAY()
{
	cout << endl << table_name << endl;
	for (int i = 0; i < cols; ++i)
	{
		cout << list[i].getname();
		if (i < cols - 1)
		{
			cout << ",";
		}
		else
		{
			cout << endl;
		}
	}
	for (int i = 0; i < list[0].getSize(); ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			list[j].displayAt(i);
			if (j != cols - 1)
			{
				cout << "|";
			}
			//cout << left << setw(10);
		}
		cout  << endl;
	}
}
void Table::WRITE() 
{
	fstream out;
	out.open("out.txt", ios::out);
	out << endl << table_name << endl;
	for (int i = 0; i < cols; ++i)
	{
		out << list[i].getname();
		if (i < cols - 1)
		{
			out << ",";
		}
		else
		{
			out << endl;
		}
	}
	for (int i = 0; i < list[0].getSize(); ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			list[j].displayAt(i);
			if (j != cols - 1)
			{
				out << "|";
			}
			//cout << left << setw(10);
		}
		out << endl;
	}
	out.close();
}


Table::~Table()
{
	for(int i=0;i<cols;++i)
	{
		list[i].~myLinklist();
	}
}
