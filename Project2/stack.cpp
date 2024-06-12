#include <iostream>
using namespace std;

/*
class stack
{
public:
	int* st;
	int max, top = -1;
	stack(int num) {
		st = new int[num];
		max = num;
	}
	bool isEmpty();
	void push(int a);
	void pop();

};

bool stack::isEmpty()
{
	if (top == -1)
		return true;
	return false;
}

void stack::push(int a)
{
	if (top == max - 1)
		cout << "stack����" << endl;
	else {
		st[++top] = a;
		cout << "������" << a << endl;
	}
	return;
}

void stack::pop()
{
	if (this->isEmpty())
		cout << "�ѿ�" << endl;
	else
		cout << "����" << st[top--] << endl;
	return;
}

void main()
{
	class stack s(2);
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	s.pop();
	s.pop();
	return;
}
*/

/*
struct Node
{
	int data;
	struct Node* next;
};
typedef Node* link;
class stack
{
public:
	link top, newnode;
	stack() {
		top = NULL;
		newnode = NULL;
	}
	bool isEmpty();
	void push(int num);
	void pop();
};

bool stack::isEmpty()
{
	if (top)
		return false;
	else
		return true;
};

void stack::push(int num)
{
	newnode = new Node;
	newnode->data = num;
	newnode->next = top;
	cout << "����" << newnode->data << endl;
	top = newnode;
	return;
};

void stack::pop()
{
	if (isEmpty())
		cout << "ջ�ѿ�" << endl;
	else {
		link tmp = top;
		cout << "����" << top->data << endl;
		top = top->next;
		delete tmp;
		tmp = NULL;
	}
	return;
};

void main()
{
	class stack a;
	a.push(1);
	a.push(2);
	a.pop();
	a.pop();
	a.pop();
	return;
}
*/


/*
[ʾ��]:����ѧ���ʽ�������ʾ��תΪ�����ʾ��
*/
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define MAX 50
//char infix_q[MAX]; //������������ʾ���Ķ���  
//��������ȼ��ıȽϣ�����������������ȼ�С�ڶ�ջ������������ȼ���
//�򷵻�ֵΪ1������Ϊ0                          
int compare(char stack_o, char infix_o)
{
	//�������ʾ�����к��ݴ��ջ�У�����������ȼ���
	//�����ȼ�ֵΪINDEX/2                               
	char infix_priority[9];
	char stack_priority[8];
	int index_s = 0, index_i = 0;
	infix_priority[0] = 'q'; infix_priority[1] = ')';
	infix_priority[2] = '+'; infix_priority[3] = '-';
	infix_priority[4] = '*'; infix_priority[5] = '/';
	infix_priority[6] = '^'; infix_priority[7] = ' ';
	infix_priority[8] = '(';
	stack_priority[0] = 'q'; stack_priority[1] = '(';
	stack_priority[2] = '+'; stack_priority[3] = '-';
	stack_priority[4] = '*'; stack_priority[5] = '/';
	stack_priority[6] = '^'; stack_priority[7] = ' ';
	while (stack_priority[index_s] != stack_o)
		index_s++;
	while (infix_priority[index_i] != infix_o)
		index_i++;
	return ((int)(index_s / 2) >= (int)(index_i / 2) ? 1 : 0);
}
//����ת����ķ���
void infix_to_postfix(char infix_q[])
{
	int rear = 0, top = 0, flag = 0, i = 0;
	char stack_t[MAX];
	for (i = 0; i < MAX; i++)
		stack_t[i] = '\0';
	//gets(infix_q);
	i = 0;
	while (infix_q[i] != '\0')
	{
		i++;
		rear++;
	}
	infix_q[rear] = 'q';  //�ڶ��м���qΪ��������
	cout << "\t" << "�����ʾ�� : ";
	stack_t[top] = 'q';  //�ڶ�ջ����qΪ��������
	for (flag = 0; flag <= rear; flag++)\
	{
		switch (infix_q[flag])
		{
			//����Ϊ)ʱ���������ջ�ڵ��������ֱ����ջ��Ϊ(
		case ')':
			while (stack_t[top] != '(')
				cout << setw(1) << stack_t[top--];
			top--;
			break;
			//����Ϊq���򽫶�ջ�ڻ�δ�������������
		case 'q':
			while (stack_t[top] != 'q')
				cout << setw(1) << stack_t[top--];
			break;
			//����Ϊ��������������ȼ�С��TOP�ڶ�ջ����ָ����������ȼ���
			//�򽫶�ջ��ָ���������������ȼ����ڵ���TOP�ڶ�ջ����ָ�����
			//�����ȼ���������������ѹ���ջ�� 
		case '(':
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':
			while (compare(stack_t[top], infix_q[flag]) == 1)
				cout << setw(1) << stack_t[top--];
			stack_t[++top] = infix_q[flag];
			break;
			//����Ϊ����������ֱ�����
		default:
			cout << setw(1) << infix_q[flag];
			break;
		}
	}
}
//����������
int main(void)
{
	int i = 0;
	char infix_q[] = "(9+3)*8+7*6-8/4";
	//for (i = 0; i < MAX; i++)
	//	infix_q[i] = '\0';
	cout << "\t==========================================" << endl;
	cout << "\t������Ὣ��ת�ɺ��򷨱��ʽ" << endl;
	cout << "\t���������򷨱��ʽ" << endl;
	cout << "\t����:(9+3)*8+7*6-8/4 " << endl;
	cout << "\t����ʹ�õ����������:^,*,+,-,/,(,)�� " << endl;
	cout << "\t==========================================" << endl;
	cout << "\t�뿪ʼ�������򷨱��ʽ: ";
	infix_to_postfix(infix_q);
	cout << endl;
	cout << "\t==========================================" << endl;
	system("pause");
	return 0;
}
*/
