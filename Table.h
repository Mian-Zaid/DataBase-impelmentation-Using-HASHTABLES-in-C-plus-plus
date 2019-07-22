#pragma once
#include <iostream>
#include "link.h"
using namespace std;
class Table
{
	string table_name;
	
	myLinklist<string>*list;
	int cols;

public:
	Table(string,string);
	void INSERT( string);
	void UPDATE(string);
	void DELETE(string);
	void SELECT(string);
	void DISPLAY();
	void WRITE();

	~Table();
};

