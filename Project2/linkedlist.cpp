#include <iostream>
using namespace std;

//linkedlist
/*
struct node
{
	int score;
	char name[10];
	struct node* next;
};
typedef struct node* link;

class LinkedList
{
public:
	link front, rear;
	LinkedList() {
		front = NULL;
		rear = NULL;
	}
	void add(link newnode);
	void insert(char name[10], link newnode);
	void del(char name[10]);
	void reverse();
	void print();
};

void LinkedList::add(link newnode)
{
	if (!front) {
		front = newnode;
		rear = newnode;
	}
	else {
		rear->next = newnode;
		rear = newnode;
	}
	return;
};
#include "string.h"
void LinkedList::insert(char name[10], link newnode)
{
	link current = front;
	while (current) {
		if (strcmp(name, current->name) == 0) {
			newnode->next = current->next;
			current->next = newnode;
			break;
		}
	}
	return;
}

void LinkedList::del(char name[10])
{
	link next = NULL;
	if (strcmp(name, front->name) == 0)
		if (front == rear) {
			delete front, rear;
			front = NULL;
			rear = NULL;
		}
		else {
			next = front->next;
			delete front;
			front = next;
		}
	else {
		link current_1 = front;
		while (current_1->next) {
			if (strcmp(name, current_1->next->name) == 0) {
				next = current_1->next;
				current_1->next = current_1->next->next;
				delete next;
				next = NULL;
				break;
			}
			current_1 = current_1->next;
		}
	}
	return;
}

void LinkedList::reverse()
{
	link previous = NULL, next = NULL, current = front;
	while (current) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	current = rear;
	while (current) {
		cout << current->name << '\t' << current->score << endl;
		current = current->next;
	}
	return;
}

void LinkedList::print()
{
	link current = front;
	while (current) {
		cout << current->name << '\t' << current->score << endl;
		current = current->next;
	}
	return;
}

int main()
{
	class LinkedList linkedlist;
	link newnode = NULL;
	cout << "������3λͬѧ������" << endl;
	for (int i = 0; i < 3; i++) {
		newnode = new node;
		if (!newnode) {
			cout << "error" << endl;
			exit(1);
		}
		cout << "����������" << endl;
		cin >> newnode->name;
		cout << "���������" << endl;
		cin >> newnode->score;
		newnode->next = NULL;
		linkedlist.add(newnode);
	}
	linkedlist.print();

	cout << "ɾ��aa" << endl;
	char aa[10] = "aa";
	linkedlist.del(aa);
	linkedlist.print();
	cout << "��bb�����dd" << endl;
	char bb[10] = "bb";
	newnode = new node;
	char dd[10] = "dd";
	for (int i = 0; i < 10; i++)
		newnode->name[i] = dd[i];
	newnode->score = 150;
	newnode->next = NULL;
	linkedlist.insert(bb, newnode);
	linkedlist.print();
	return 0;
	
	//cout << "��ת" << endl;
	//linkedlist.reverse();
	//system("pause");
	
}
*/

/*int main()
{
	link current, newnode, front, rear;
	cout << "������2λͬѧ������" << endl;
	front = new node;
	if (!front) {
		cout << "error" << endl;
		exit(1);
	}
	cout << "����������" << endl;
	cin >> front->name;
	cout << "���������" << endl;
	cin >> front->score;
	front->next = NULL;
	rear = front;
	for (int i = 0; i < 1; i++) {
		newnode = new node;
		if (!newnode) {
			cout << "error" << endl;
			exit(1);
		}
		cout << "����������" << endl;
		cin >> newnode->name;
		cout << "���������" << endl;
		cin >> newnode->score;
		newnode->next = NULL;
		rear->next = newnode;
		rear = newnode;
	}
	current = front;
	link del;
	while (current) {
		cout << current->name << "\t" << current->score << endl;
		del = current;
		current = current->next;
		delete del;
	}


	system("pause");
}*/


/*
[ʾ��]:����ʽ���
*/

/*
struct node //��������ṹ
{
    int coef, exp;
	struct node* next;
};

typedef node* link;
link creat_link(int data[4]);
void print_link(link head);
link sum_link(link a, link b);

int main()
{
	link a, b, c;
	int data1[4] = { 3,0,4,2 }; //����ʽA��ϵ��
	int data2[4] = { 6,8,6,9 }; //����ʽB��ϵ��
	cout << "ԭʼ����ʽ��" << endl << "A=";
	a = creat_link(data1);    //��������ʽA
	b = creat_link(data2);    //��������ʽB
	print_link(a);          //��ӡ����ʽA
	cout << "B=";
	print_link(b);          //��ӡ����ʽB
	cout << "����ʽ��ӵĽ����\nC=";
	c = sum_link(a, b);        //CΪA��B����ʽ��ӵĽ��
	print_link(c);          //��ӡ����ʽC
	system("pause");
	return 0;
}
link creat_link(int data[4])//��������ʽ�ӳ���
{
	link head=NULL, newnode=NULL, ptr=NULL;
	for (int i = 0; i < 4; i++)
	{
		newnode = new node;
		if (!newnode)
		{
			cout << "Error!! �ڴ����ʧ��!!" << endl;
			exit(1);
		}
		if (i == 0)
		{
			newnode->coef = data[i];
			newnode->exp = 3 - i;
			newnode->next = NULL;
			head = newnode;
			ptr = head;
		}
		else if (data[i] != 0)
		{
			newnode->coef = data[i];
			newnode->exp = 3 - i;
			newnode->next = NULL;
			ptr->next = newnode;
			ptr = newnode;
		}
	}
	return head;
}
void print_link(link head) //��ӡ����ʽ�ӳ���
{
	while (head != NULL)
	{
		if (head->exp == 1 && head->coef != 0)	//X^1ʱ����ʾָ��
			cout << head->coef << "X + ";
		else if (head->exp != 0 && head->coef != 0)
			cout << head->coef << "X^" << head->exp << " + ";
		else if (head->coef != 0)           	//X^0ʱ����ʾ����
			cout << head->coef;
		head = head->next;
	}
	cout << endl;
}
link sum_link(link a, link b) //����ʽ����ӳ���
{
	int sum[4];
	while (a != NULL || b != NULL)
	{
		if (a->exp == b->exp)	//ָ����ȣ�ϵ�����
		{
			sum[3 - a->exp] = a->coef + b->coef;
			a = a->next;
			b = b->next;
		}
		else if (b->exp > a->exp)	//Bָ���ϴ�ָ��ϵ����C
		{
			sum[3 - b->exp] = b->coef;
			b = b->next;
		}
		else if (a->exp > b->exp)	//Aָ���ϴ�ָ��ϵ����C
		{
			sum[3 - a->exp] = a->coef;
			a = a->next;
		}
	}
	return creat_link(sum);	//������ӽ��������C
}
*/