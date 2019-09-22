#include<iostream>
using namespace std;

class LinkList {
	//内部封装一个链表，实现链表的增删查改
private:
	struct node {
		int value;
		struct node* next;
	};
	typedef struct node* Lists;
	node* head;
public:
	LinkList();
	int insertnode(int n);//在链笔末端插入一节点
	int insertNewNode(int n, int value);//在给定值后面插入节点
	int deletenode(int n);//删除给定节点
	int getIndex(int n);//查询该节点是否存在，如果存在则返回该节点
	int cleanList();//清空链笔
	void show();
};
LinkList::LinkList() {
	head = new node;
	head->next = nullptr;
}
int LinkList::insertnode(int n) {
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
int main() {
	LinkList list = LinkList();
	list.insertnode(1);
	list.insertnode(2);
	list.insertnode(3);
	list.insertNewNode(7, 2);
	list.show();
	list.deletenode(3);
	list.show();
	cout << list.getIndex(7)+1 << endl;;
	return 0;
}