#include <iostream>
#include <fstream>
#include  <string>
#include "Hashtable.h"
using namespace std;

int main()
{
	fstream file1;
	string id,name,loc,ldr,badge;
	Hashtable ht;
	string file2;
	int qw = 1;
	while (qw == 1)
	{
		cout << "\nEnter the name of file without extension: ";
		cin >> file2;


		file1.open(file2 + ".txt");
		if (file1.is_open())
		{
			//getline(file1, id);
			getline(file1, id);
			//getline(file1, id);
			ht.insert(file2, id);
			while (getline(file1, id))
				//scout << id << endl;
			{
				ht.INSERT(file2, id);
			}
			//cout << "";
		}
		file1.close();
		cout << "\nWant to enter another file?\n press 1 for yes, any else number for no: "; cin >> qw;
	}
	//exit(0);
	string gpt = "", tmp,tb;
	bool f = true;
	while(f)
	{
		char m;
		cout << "\nEnter \nd to display \ni to insert \nu to update \ns to select \nx to delete \nw to write\nq to exit\n";
		cin >> m;
		switch (m)
		{
		case'i':
			char i;
			cout << "Enter \ng to insert a gym \np to insert a pokemen \nt to insert a trainer\n";
			cin >> i;
			
			switch (i)
			{
				
			case'g':
				gpt = "";
				cout << "Enter Gym ID: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Location: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Leader: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Badge: "; cin >> tmp; gpt.append(tmp);
				cout << "Enter the table name: "; cin >> tb;
				ht.INSERT(tb, gpt);
				break;
			case'p':
				gpt = "";
				cout << "Enter Pokemon ID: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Type: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Strong to(with commas): "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Weak to(with commas): "; cin >> tmp; gpt.append(tmp);
				cout << "Enter the table name: "; cin >> tb;
				ht.INSERT(tb, gpt);
				break;
			case't':
				gpt = "";
				cout << "Enter First name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Last Name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Age: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Badges held(with commas): "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon owned(with commas): "; cin >> tmp; gpt.append(tmp);
				cout << "Enter the table name: "; cin >> tb;
				ht.INSERT(tb, gpt);
				break;
			default:

				break;
			}
			break;
		case'u':
			char u;
			cout << "Enter \ng to update a gym \np to update a pokemen \nt to update a trainer\n";
			cin >> u;
			switch (u)
			{
			case'g':
				gpt = "";
				cout << "Enter Gym ID: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Location: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Leader: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Badge: "; cin >> tmp; gpt.append(tmp);
				cout << "Enter the table name: "; cin >> tb;
				ht.UPDATE(gpt, tb);
				break;
			case'p':
				gpt = "";
				cout << "Enter Pokemon ID: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Type: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Strong to: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Weak to: "; cin >> tmp; gpt.append(tmp);
				cout << "Enter the table name: "; cin >> tb;
				ht.UPDATE(gpt, tb);
				break;
			case't':
				gpt = "";
				cout << "Enter First name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Last Name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Age: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Badges held(with commas): "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon owned(with commas): "; cin >> tmp; gpt.append(tmp);
				cout << "Enter the table name: "; cin >> tb;
				ht.UPDATE(gpt, tb);
				break;
			default:

				break;
			}
			break;
		case's':
			char s;
			cout << "Enter \ng to select a gym \np to select a pokemen \nt to select a trainer\n";
			cin >> s;
			switch (s)
			{
			case'g':
				gpt = "";
				cout << "Enter Gym ID: "; cin >> tmp; gpt.append(tmp); 
				cout << "Enter the table name: "; cin >> tb;
				ht.SELECT(gpt, tb);
				break;
			case'p':
				gpt = "";
				cout << "Enter Pokemon ID: "; cin >> tmp; gpt.append(tmp); 
				cout << "Enter the table name: "; cin >> tb;
				ht.SELECT(gpt, tb);
				break;
			case't':
				gpt = "";
				cout << "Enter First name: "; cin >> tmp; gpt.append(tmp); 
				cout << "Enter the table name: "; cin >> tb;
				ht.SELECT(gpt, tb);
				break;
			default:

				break;
			}
			break;
		case'x':
			char x;
			cout << "Enter \ng to delete a gym \np to delete a pokemen \nt to delete a trainer\n";
			cin >> x;
			switch (x)
			{
			case'g':
				gpt = "";
				cout << "Enter Gym ID: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Location: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Leader: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Gym Badge: "; cin >> tmp; gpt.append(tmp);
				cout << "Enter the table name: "; cin >> tb;
				ht.DELETE(gpt, tb);
				break;
			case'p':
				gpt = "";
				cout << "Enter Pokemon ID: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Type: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Strong to: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon Weak to: "; cin >> tmp; gpt.append(tmp);
				cout << "Enter the table name: "; cin >> tb;
				ht.DELETE(gpt, tb);
				break;
			case't':
				gpt = "";
				cout << "Enter First name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Last Name: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Age: "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Badges held(with commas): "; cin >> tmp; gpt.append(tmp); gpt.append("|");
				cout << "Enter Pokemon owned(with commas): "; cin >> tmp; gpt.append(tmp);
				cout << "Enter the table name: "; cin >> tb;
				ht.DELETE(gpt, tb);
				break;
			default:

				break;
			}
			break;
		case'd':
			ht.DISPLAY();
			break;
		case'w':
			break;
		default:
			//cout << "\nturniong it false";
			f=false;
			break;
		}
	}
	

	return 0;
}