#include <iostream>
using namespace std;

/*
class Queue
{
public:
	int q[5];
	int front = -1, rear = -1;
	bool isEmpty();
	bool isFull();
	void push(int a);
	void pop();
};

bool Queue::isEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
};

bool Queue::isFull()
{
	if ((rear + 1) % 5 == front || front==-1&&rear==4) {
		cout << "��������" << endl;
		return true;
	}
	else
		return false;
};

void Queue::push(int a)
{
	if (!isFull()) {
		q[(++rear) % 5] = a;
		cout << "�Ѵ���" << a << endl;
		cout << rear << endl;
	}
	return;
};

void Queue::pop()
{
	if (!isEmpty()) {
		front = (front + 1) % 5;
		cout << "����" << q[front] << endl;
	}
	else 
		cout << "�����ѿ�" << endl;
	
	return;
};

void main()
{
	class Queue a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	a.push(7);
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	return;
};
*/

/*
struct Node
{
	int num;
	struct Node* next;
};

typedef Node* link;
class Queue
{
public:
	link front=NULL, rear=NULL;
	bool isEmpty();
	void push(int a);
	void pop();
};

bool Queue::isEmpty()
{
	if (front)
		return false;
	return true;
}

void Queue::push(int a)
{
	link newnode = new Node;
	newnode->num = a;
	newnode->next = NULL;
	if (isEmpty()) {
		front = newnode;
		rear = newnode;
		cout << "������" << newnode->num << endl;
	}
	else {
		rear->next = newnode;
		rear = newnode;
		cout << "������" << newnode->num << endl;
	}
}

void Queue::pop()
{
	if (isEmpty()) {
		cout << "�ѿ�" << endl;
		return;
	}
	link a = front;
	cout << "����" << a->num << endl;
	front = front->next;
	delete a;
	a = NULL;
}

void main()
{
	class Queue a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	a.push(7);
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	return;
}
*/