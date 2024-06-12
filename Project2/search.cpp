#include <iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int bin_search(int a[], int val) {
	int low = 0;
	int high = 49;
	int mid;
	while (low <= high && val != -1) {
		mid = (low + high) / 2;
		if (val < a[mid]) {
			cout << val << " 介于位置 " << low + 1 << "[" << setw(3) << a[low] << "]和中间值 " << mid + 1 << "[" << setw(3) << a[mid] << "]，找左半边" << endl;
			high = mid - 1;
		}
		else if (val > a[mid]) {
			cout << val << " 介于中间值位置 " << mid + 1 << "[" << setw(3) << a[mid] << "]和" << high + 1 << "[" << setw(3) << a[high] << "]，找右半边" << endl;
			low = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}

void main() {
	int val, num=1, data[50];
	for (int i = 0; i < 50; i++) {
		data[i] = num;
		num += (rand() % 5 + 1);
	}
	while (1) {
		cout << "请输入查找键值(1-150)，输入-1结束：";
		cin >> val;
		if (val == -1)
			break;
		num = bin_search(data, val);
		if (num == -1)
			cout << "##### 没有找到[" << setw(3) << val << "] #####" << endl;
		else
			cout << "在第 " << setw(2) << num + 1 << "个位置找到 [" << setw(3) << data[num] << "]" << endl;
	}
	cout << "数据内容：" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << setw(3) << i * 10 + j + 1 << "-" << setw(3) << data[i * 10 + j];
		cout << endl;
	}
	cout << endl;
	system("pause");
	return;
}