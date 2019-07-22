#include "Hashtable.h"



Hashtable::Hashtable()
{
	head = new hnode * [MAX];
	for (int i = 0; i < MAX; i++)
	{
		head[i] = NULL;
	}
}
Hashtable::~Hashtable()
{
	for (int i = 0; i < MAX; ++i)
	{
		hnode* e = head[i];
		while (e != NULL)
		{
			hnode* p = e;
			e = e->next;
			p->t->~Table();
			delete p;
		}
	}
	delete[] head;
}
int Hashtable::Hashf(string x) {
	const char* ch;
	ch = x.c_str();
	int xlength = x.length();

	int i, sum;
	for (sum = 0, i = 0; i < x.length(); ++i)
		sum += ch[i];
	return sum % MAX;
}
void Hashtable::insert(string k, string v)
{
	int hv = Hashf(k);
	hnode* p = NULL;
	hnode* e = head[hv];
	while (e != NULL)
	{
		p = e;
		e = e->next;
	}
	if (e == NULL)
	{

		e = new hnode(k,v);
		if (p == NULL)
		{
			head[hv] = e;
		}
		else
		{
			p->next = e;
		}
	}
	else
	{
		//e->val = v;
	}
}
Hashtable::hnode* Hashtable::search(string x)
{
	int hv = Hashf(x);
	hnode* e = head[hv];
	while (e != NULL)
	{
		if (x.compare(e->table_name) == 0)
		{
			return e;// e->val;
			
		}
		e = e->next;
	}
	cout << "not found";
	return NULL;
}
void Hashtable::remove(string k)
{
	int hv = Hashf(k);
	hnode* e = head[hv];
	hnode* p = e;
	if (head[hv] != NULL)
	{
		if (k.compare(e->table_name) == 0)
		{
			e = e->next;
			head[hv] = e;
			delete p;
			cout << "deleted in the hashtable" << endl;
			return;
		}
		e = e->next;
		while (e != NULL)
		{
			if (k.compare(e->table_name) == 0)
			{
				p = e->next;
				delete e;
				cout << "deleted in the hashtable" << endl;
				return;
			}
			e = e->next;
		}
	}
	cout << "not found in hashtable" << endl;
}
void Hashtable::INSERT(string tn, string tup )
{
	hnode *tmp = search(tn);
	tmp->t->INSERT(tup);
}
void Hashtable::UPDATE(string, string)
{

}
void Hashtable::DELETE(string, string)
{

}
void Hashtable::SELECT(string tup, string x)
{
	int hv = Hashf(x);
	hnode* e = head[hv];
	while (e != NULL)
	{
		if (x.compare(e->table_name) == 0)
		{
			e->t->SELECT(tup);
			//return e;// e->val;

		}
		e = e->next;
	}
	cout << "not found";
}
void Hashtable::DISPLAY()
{
	for (int i = 0; i < MAX; ++i)
	{
		hnode* e = head[i];
		while (e != NULL)
		{
			//hnode* p = e;
			e->t->DISPLAY();
			e = e->next;
			//p->t->~Table();
			//delete p;
		}
	}
}
void Hashtable::WRITE()
{
	for (int i = 0; i < MAX; ++i)
	{
		hnode* e = head[i];
		while (e != NULL)
		{
			//hnode* p = e;
			e->t->WRITE();
			e = e->next;
			//p->t->~Table();
			//delete p;
		}
	}
}
