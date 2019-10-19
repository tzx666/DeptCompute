#include"LinkList.h"
#include<iostream>
using namespace std;
LinkList::LinkList() {
	head = new node;
	head->next = nullptr;
}
int LinkList::addAtTail(int n) {
	Lists p = head;
	while (p->next != nullptr)
		p = p->next;
	p->next= new node;
	p->next->value = n;
	p->next->next = NULL;
	return 0;
}
int LinkList::insertNewNode(int n, int value) {
	Lists p = head;
	while (p->next != nullptr) {
		if (p->next->value == value) {
			Lists q = new node;
			q->value = n;
			q->next = p->next;
			p->next = q;
			return 0;
		}
		p = p->next;
	}
	return -1;
}
int LinkList::deletenode(int n) {
	Lists p = head;
	if (p == NULL)
		return -1;
	while (p->next != nullptr) {
		if (p->next->value == n) {
			Lists q = p->next;
			p ->next= p->next->next;
			delete q;
			return 0;
		}
		p = p->next;
	}
	return -1;
}
int LinkList::getIndex(int n) {
	Lists p = head->next;
	int index = 0;
	while (p != nullptr) {
		if (p->value == n)
			return index;
		else {
			index++;
			p = p->next;
		}
	}
	return -1;
}
int LinkList::cleanList() {
	while (head != NULL) {
		Lists p = head;
		head = head->next;
		delete p;
	}
	return 0;
}
void LinkList::show() {
	Lists p = head->next;
	while (p!= NULL) {
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}
int LinkList::get(int index) {
	if (head == NULL)
		return - 1;
	Lists p = head;
	//cout << p->value << endl;
	int count = -1;
	while (p->next != NULL) {
		if (count == index)
			return p->value;
		count++;
		p = p->next;
	}
	if (count == index)
		return p->value;
	else
	return -1;
}
void LinkList::addAtIndex(int index, int val) {
	Lists p = head;
	int count = -1;
	if (index < 0) {
		addAtHead(val);
	}
	else if(index==0)
		addAtHead(val);
	else{
		while (p->next != NULL) {
			if (count == index-1) {
				Lists q = new node;
				q->value = val;
				q->next = p->next;
				p->next = q;
				count++;
		}
		p = p->next; count++;
		//cout << count << endl;
	}
	if (index == count+1) {
		addAtTail(val);
	}
	}
}
void LinkList::deleteAtIndex(int index) {
	Lists p = head;
	//cout << p->value << endl;
	int count = -1;
	while (p->next != NULL) {
		if (count + 1 == index) {
			Lists q = p->next;
			p->next = p->next->next;
			delete q; break;
		}
		count++;
		p = p->next;
	}
}
int LinkList::gets(int index) {
	Lists p = getStructData(head, index);
	if (p != NULL)
		return p->value;
	else
		return -1;
}
int LinkList::addAtHead(int n) {
	Lists p = new node;
	p->value = n;
	p->next = head->next;
	head->next = p;
	return 0;
}