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
	Lists getStructData(Lists &l,int index) {
		Lists p = l->next;
		int count = 0;
		if (index < 0)
			return NULL;
		if (l ==NULL)
			return NULL;
		while (p != NULL) {
			if (count == index)
				return p;
			count++; p = p->next;
		}
		return NULL;
	}//寻找链表全局返回某个给定索引
public:
	LinkList();
	int addAtTail(int n);//在链表末端插入一节点
	int insertNewNode(int n, int value);//在给定值后面插入节点
	int deletenode(int n);//删除给定节点
	int getIndex(int n);//查询该节点是否存在，如果存在则返回该节点
	int gets(int index) {
		Lists p = getStructData(head, index);
		if (p != NULL)
			return p->value;
		else
			return -1;
	}
	int cleanList();//清空链表
	int get(int index);//获取第index个节点，如果节点无效则返回-1
	int addAtHead(int n) {
		Lists p = new node;
		p->value = n;
		p->next = head->next;
		head->next = p;
		return 0;
	}//前插入链表
	void addAtIndex(int index, int val);//向index前的某个插入节点
	void deleteAtIndex(int index);//删除有效地址的节点
	void show();//显示链表
};
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
int main() {
	LinkList list = LinkList();
	list.addAtHead(1);
	list.addAtTail(3);
	list.addAtIndex(1,2);
	list.show();
	cout << list.gets(0) << endl;
	cout << list.gets(1) << endl;
	cout << list.gets(2) << endl;
	cout << list.gets(3) << endl;
	return 0;
}