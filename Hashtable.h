#pragma once
#include <iostream>
#include "Table.h"

using namespace std;
const int MAX = 128;

class Hashtable
{
	struct hnode
	{
		string table_name;
		string cl;
		Table* t;
		hnode* next;
		hnode(string k,string v)
		{
			this->table_name = k;
			t = new Table(k,v);
			this->next = NULL;
		}
		/*void INSERT(string, string)
		{}
		void UPDATE(string, string) {}
		void DELETE(string, string) {}
		void SELECT(string, string) {}
		void DISPLAY() {}
		void WRITE() {}*/
	};
	hnode** head;
	
public:
	Hashtable();
	
	~Hashtable();
	
	//Hash Function is defined here
	int Hashf(string x);
	
	void insert(string k, string);
private:
	hnode* search(string x);
	
	void remove(string k);
public:
	void INSERT(string, string);
	void UPDATE(string, string);
	void DELETE(string, string);
	void SELECT(string, string);
	void DISPLAY();
	void WRITE();
	
};
