#include <iostream>
using namespace std;

/*
void main()
{
	int arr[6][6];//声明矩阵arr
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			arr[i][j] = 0;
	int data[14][2] = { {1,2},{2,1},{1,5},{5,1}, //图形各边的起点值和终点值
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4} };
	int row, col;
	for (int i = 0; i < 14; i++) {
		row = data[i][0];
		col = data[i][1];
		arr[row][col] = 1;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return;
}
*/

/*dfs-深度最优*/
/*
struct Node {
	int val;
	struct Node* next;
};
typedef Node* list;
void print(list head[]);
int run[6] = {0,0,0,0,0,0};
int stack[10];
int top=-1;
void push(int val);
int pop();
void dfs(list head[]);
void main()
{
	int data[14][2] = { {1,2},{2,1},{1,5},{5,1}, //图形各边的起点值和终点值
				{2,3},{3,2},{2,4},{4,2},
				{3,4},{4,3},{3,5},{5,3},
				{4,5},{5,4} };
	Node* head[6];
	for (int i = 1; i < 6; i++) {
		list newnode = new Node;
		newnode->val = i;
		cout << i << "->";
		newnode->next = NULL;
		head[i] = newnode;
		list current = newnode;
		for (int j = 0; j < 14; j++) {
			if (data[j][0] == i) {
				newnode = new Node;
				newnode->val = data[j][1];
				newnode->next = NULL;
				cout << data[j][1] << " ";
				current->next = newnode;
				current = current->next;
			}
		}
		cout << endl;
	}
	print(head);
	dfs(head);
	system("pause");
	return;
}

void print(list head[])
{
	list current = NULL;
	for (int i = 1; i < 6; i++) {
		current = head[i];
		cout << "[" << current->val << "]" << "->";
		current = current->next;
		while (current) {
			cout << current->val << " ";
			current = current->next;
		}
		cout << endl;
	}
	return;
}

void push(int val) {
	stack[++top] = val;
	cout<<top;
	return;
}
int pop() {
	cout << "弹出" << stack[top] << endl;
	return stack[top--];
}

void dfs(list head[])
{
	int temp;
	list cur;
	stack[++top] = head[1]->val;
	while (top != -1) {
		temp = pop();
		run[temp] = 1;
		cur = head[temp]->next;
		while (cur) {
			if (run[cur->val]==0)
				push(cur->val);
			cur = cur->next;
		}
	}
	return;
}
*/

/*bfs-广度最优*/
/*
struct Node {
	int val;
	struct Node* next;
};
typedef Node* list;
int run[6] = {0,0,0,0,0,0};
class Que {
public:
	int q[10] = {};
	int front = -1, rear = -1;
	void push(int num);
	int pop();
	bool isEmpty();
};
void Que::push(int num) {
	q[++rear] = num;
	return;
};
int Que::pop() {
	int a = q[++front];
	cout << "弹出 " << a << endl;
	return a;
};
bool Que::isEmpty() {
	return front == rear ? true : false;
};
void print(list head[]);
void bfs(list head[]);

void main()
{
	int data[14][2] = { {1,2},{2,1},{1,5},{5,1}, //图形各边的起点值和终点值
				{2,3},{3,2},{2,4},{4,2},
				{3,4},{4,3},{3,5},{5,3},
				{4,5},{5,4} };
	Node* head[6];
	for (int i = 1; i < 6; i++) {
		list newnode = new Node;
		newnode->val = i;
		//cout << i << "->";
		newnode->next = NULL;
		head[i] = newnode;
		list current = newnode;
		for (int j = 0; j < 14; j++) {
			if (data[j][0] == i) {
				newnode = new Node;
				newnode->val = data[j][1];
				newnode->next = NULL;
				//cout << data[j][1] << " ";
				current->next = newnode;
				current = current->next;
			}
		}
		//cout << endl;
	}
	print(head);
	bfs(head);
	system("pause");
	return;
}

void print(list head[])
{
	list current = NULL;
	for (int i = 1; i < 6; i++) {
		current = head[i];
		cout << "[" << current->val << "]" << "->";
		current = current->next;
		while (current) {
			cout << current->val << " ";
			current = current->next;
		}
		cout << endl;
	}
	return;
}

void bfs(list head[]) {
	class Que q;
	q.push(head[1]->val);
	int temp;
	while (!q.isEmpty()) {
		temp = q.pop();
		run[temp] = 1;
		list current = head[temp]->next;
		while (current) {
			if (run[current->val] == 0) {
				q.push(current->val);
			}
			current = current->next;
		}
	}
}
*/


/*Floyd*/
/*
[示范]:Floyd算法(所有顶点两两之间的最短距离)
*/
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define INFINITE  99999 //无穷大
#define NUMBER 6
using namespace std;
int Graph_Matrix[SIZE][SIZE];//图的数组
int dist[SIZE][SIZE];		//路径长度的数组
//建立图 
void BuildGraph_Matrix(int* Path_Cost)
{
	int Start_Point;	//边的起点
	int End_Point; 	//边的终点 
	int i, j;
	for (i = 1; i < SIZE; i++)
		for (j = 1; j < SIZE; j++)
			if (i == j)
				Graph_Matrix[i][j] = 0; //对角线设为0
			else
				Graph_Matrix[i][j] = INFINITE;
	//存入图形的边
	i = 0;
	while (i < SIZE)
	{
		Start_Point = Path_Cost[i * 3];
		End_Point = Path_Cost[i * 3 + 1];
		Graph_Matrix[Start_Point][End_Point] = Path_Cost[i * 3 + 2];
		i++;
	}
}
//打印出图
void printGraph_Matrix()
{
	int i, j;
	for (i = 1; i < SIZE; i++)
	{
		cout << "vex" << i;
		for (j = 1; j < SIZE; j++)
			if (Graph_Matrix[i][j] == INFINITE)
				cout << setw(5) << 'x';
			else
				cout << setw(5) << Graph_Matrix[i][j];
		cout << endl;
	}
}
//单点对全部顶点的最短距离 
void shortestPath(int vertex_total)
{
	int i, j, k;
	extern int dist[SIZE][SIZE];		//声明为外部变量 
	//图的长度数组初始化
	for (i = 1; i <= vertex_total; i++)
		for (j = i; j <= vertex_total; j++)
		{
			dist[i][j] = Graph_Matrix[i][j];
			dist[j][i] = Graph_Matrix[i][j];
		}
	//利用Floyd算法找出所有顶点两两之间的最短距离
	for (k = 1; k <= vertex_total; k++)
		for (i = 1; i <= vertex_total; i++)
			for (j = 1; j <= vertex_total; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
}
//主程序
int main(void)
{
	extern int dist[SIZE][SIZE];		//声明为外部变量
	int Path_Cost[7][3] = { {1, 2, 10},
					   {2, 3, 20},
					   {2, 4, 25},
					   {3, 5, 18},
					   {4, 5, 22},
					   {4, 6, 95},
					   {5, 6, 77} };
	int i, j;
	BuildGraph_Matrix(&Path_Cost[0][0]);
	cout << "==================================" << endl;
	cout << "此范例图形的邻接矩阵如下: " << endl;
	cout << "==================================" << endl;
	cout << "顶点 vex1 vex2 vex3 vex4 vex5 vex6" << endl;
	printGraph_Matrix();  //显示图的邻接矩阵
	cout << "==================================" << endl;
	cout << "所有顶点两两之间的最短距离: " << endl;
	cout << "==================================" << endl;
	shortestPath(NUMBER); //计算所有顶点间的最短路径
	//求得两两顶点间的最短路径长度数组后，将其打印出来
	cout << "顶点 vex1 vex2 vex3 vex4 vex5 vex6" << endl;
	for (i = 1; i <= NUMBER; i++)
	{
		cout << "vex" << i;
		for (j = 1; j <= NUMBER; j++)
		{
			cout << setw(5) << dist[i][j];
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
*/