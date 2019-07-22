/*
 * myLinkList.h
 *
 *  Created on: Oct 10, 2018
 *      Author: lab
 */

#ifndef MYLINKLIST_H_
#define MYLINKLIST_H_
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// *********************LINKLIST CLASS****************************

template<typename DT>
class Node {
public:
	DT data;
	Node<DT>* next;
};

template<typename DT>
class myLinklist {
	Node<DT>* head;
	Node<DT>* cursor;
	int size;
	string name;
public:
	string getname() 
	{
		return name;
	}
	void setname(string n)
	{
		name = n;
	}
	myLinklist(int ignored = 0) :
		head(0), cursor(0), size(ignored) {
		if (size <= 0) {
			head = 0;
		}
		else {
			int iter = 1;
			head = new Node<DT>;
			Node<DT>* temp = head;
			while (iter < size) {
				Node<DT>* newNode = new Node<DT>;
				temp->next = newNode;
				temp = temp->next;
				++iter;
			}
			temp->next = 0;
		}
		cursor = head;
	}

	myLinklist(const myLinklist& arg) //copy constructor
		:
		head(0), cursor(0), size(arg.size) {
		Node<DT>* temparg = arg.head;
		if (size <= 0) {
			head = 0;
		}
		else {
			head = new Node<DT>;
			//Node<DT>* temp = head;
			head->data = arg.head->data;
			Node<DT>* tempthis = head;
			if (arg.cursor == temparg) {
				cursor = tempthis;
			}
			temparg = temparg->next;
			while (temparg != 0) {
				Node<DT>* newNode = new Node<DT>;
				tempthis->next = newNode;
				tempthis = tempthis->next;
				tempthis->data = temparg->data;
				if (arg.cursor == temparg) {
					cursor = tempthis;
				}
				temparg = temparg->next;
			}
			tempthis->next = 0;
		}
	}

	void insert(const DT& newDataItem) {
		if (size == 0) {
			head = new Node<DT>;
			head->data = newDataItem;
			head->next = 0;
			++size;
		}
		else {
			Node<DT>* temp = head;
			while (temp->next != 0) {
				temp = temp->next;
			}
			temp->next = new Node<DT>;
			temp = temp->next;
			temp->data = newDataItem;
			temp->next = 0;
			++size;
		}
		cursor = head;
	}

	void insertAt(const DT& newDataItem, int index) {
		Node<DT>* temp = head;
		int iter = 1;
		if (index <= 0 && index > size) {
			return;
		}
		while (temp != 0) {
			if (iter == index) {
				Node<DT>* save = temp->next;
				temp->next = new Node<DT>;
				++size;
				temp->next->next = save;
				temp->next->data = newDataItem;
			}
			temp = temp->next;
			++iter;
		}
		cursor = head;
	}

	void replace(const DT& newDataItem) {
		if (isEmpty()) {
			return;
		}
		else {
			cursor->data = newDataItem;
		}
	}

	DT remove() {
		if (isEmpty()) {
			DT garbage;
			return garbage;
		}
		else {
			DT retval;
			if (cursor == head) {
				retval = head->data;
				head = head->next;
				delete cursor;
				cursor = head;
				--size;
			}
			else {
				Node<DT>* temp = head;
				while (temp->next != cursor) {
					temp = temp->next;
				}
				retval = cursor->data;
				temp->next = cursor->next;
				delete cursor;
				cursor = temp;
				--size;
			}
			return retval;
		}
	}

	DT removeAt(int index) {
		if (isEmpty()) {
			DT garbage;
			return garbage;
		}
		else if (index < 1 || index > size) {
			DT garbage;
			return garbage;
		}
		else if (index == 1) {
			DT retval;
			Node<DT>* temp = head;
			retval = temp->data;
			head = head->next;
			delete temp;
			--size;
			return retval;
		}
		else {
			Node<DT>* del = head->next;
			Node<DT>* temp = head;
			int iter = 2;
			while (iter < index) {
				temp = temp->next;
				del = del->next;
				++iter;
			}
			temp->next = del->next;
			DT retval;
			retval = del->data;
			delete del;
			--size;
			return retval;
		}
	}

	void replaceAt(const DT& newDataItem, int index) {
		if (isEmpty()) {
			return;
		}
		else {
			int iter = 1;
			Node<DT>* temp = head;
			if (index > 0 && index <= size) {
				while (iter < index) {
					temp = temp->next;
					iter++;
				}
				temp->data = newDataItem;
			}
			else {
				return;
			}
		}
	}

	void clear() {
		Node<DT>* temp = head;
		while (temp != 0) {
			temp->data = 0;
			temp = temp->next;
		}
	}

	bool isEmpty() const {
		if (head == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	bool gotoNext() {
		if (isEmpty()) {
			return 0;
		}
		else if (cursor != 0) {
			cursor = cursor->next;
			if (cursor == 0)
				cursor = head;
			return 1;
		}
		else {
			return 0;
		}
	}

	bool gotoPrior() {
		if (isEmpty()) {
			return 0;
		}
		else if (cursor != head) {
			Node<DT>* temp = head;
			while (temp->next != cursor) {
				temp = temp->next;
			}
			cursor = temp;
			return 1;
		}
		else {
			return 0;
		}

	}

	DT getCursor() {
		if (isEmpty()) {
			DT garbage;
			return garbage;
		}
		else {
			return cursor->data;
		}
	}

	Node<DT>* getNode() {
		return cursor;
	}

	bool moveCursor(int index) {
		if (isEmpty()) {
			return 0;
		}
		else if (index < 1 && index > size) {
			return 0;
		}
		else {
			int iter = 1;
			Node<DT>* temp = head;
			while (iter < index) {
				temp = temp->next;
				iter++;
			}
			cursor = temp;
			return 1;
		}
	}

	int getSize() {
		return size;
	}

	bool moveCursortoEnd() {
		if (isEmpty()) {
			return 0;
		}
		else {
			Node<DT>* temp = head;
			while (temp->next != 0) {
				temp = temp->next;
			}
			cursor = temp;
			return 1;
		}
	}

	void display() {
		Node<DT>* temp = head;
		while (temp != 0) {
			cout << temp->data;
			temp = temp->next;
		}
	}
	bool contains(string a)
	{
		Node<DT> *temp = head;
		while (temp != NULL)
		{
			if (temp->(string)data.equals(a))
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	void displayAt(int n)
	{
		//cout << endl << name << endl;
		int i = 1;
		if (n < size)
		{
			Node<DT>* temp = head;
			while (i<n+1) {
				
				temp = temp->next;
				++i;
			}
			cout << temp->data;
			if (n!=size-1)
			{
				//cout << ",";
			}
		}
	}
	int getn(string st)
	{
		int i = 1;
		Node<DT>* temp = head;
		while (temp != 0) 
		{
			//cout << temp->data;
			if (st._Equal(temp->data))
			{
				return i;
			}
			++i;
			temp = temp->next;
		}
		return -1;
	}
	myLinklist<DT> operator =(const myLinklist<DT>& arg) {
		//emptying to avoid memory leaks
		while (head != 0) {
			Node<DT>* temp = head;
			head = head->next;
			delete temp;
		}
		//copying
		size = arg.size;
		Node<DT>* temparg = arg.head;
		if (size <= 0) {
			head = 0;
		}
		else {
			head = new Node<DT>;
			head->data = arg.head->data;
			Node<DT>* tempthis = head;
			if (arg.cursor == temparg) {
				cursor = tempthis;
			}
			temparg = temparg->next;
			while (temparg != 0) {
				Node<DT>* newNode = new Node<DT>;
				tempthis->next = newNode;
				tempthis = tempthis->next;
				tempthis->data = temparg->data;
				if (arg.cursor == temparg) {
					cursor = tempthis;
				}
				temparg = temparg->next;
			}
			tempthis->next = 0;
			size = arg.size;
		}
		return *this;
	}

	~myLinklist() {
		while (head != 0) {
			Node<DT>* temp = head;
			head = head->next;
			delete temp;
		}

	}

};

// *******************LINKLIST CLASS END**************************
#endif /* MYLINKLIST_H_ */