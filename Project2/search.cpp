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
			cout << val << " ����λ�� " << low + 1 << "[" << setw(3) << a[low] << "]���м�ֵ " << mid + 1 << "[" << setw(3) << a[mid] << "]��������" << endl;
			high = mid - 1;
		}
		else if (val > a[mid]) {
			cout << val << " �����м�ֵλ�� " << mid + 1 << "[" << setw(3) << a[mid] << "]��" << high + 1 << "[" << setw(3) << a[high] << "]�����Ұ��" << endl;
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
		cout << "��������Ҽ�ֵ(1-150)������-1������";
		cin >> val;
		if (val == -1)
			break;
		num = bin_search(data, val);
		if (num == -1)
			cout << "##### û���ҵ�[" << setw(3) << val << "] #####" << endl;
		else
			cout << "�ڵ� " << setw(2) << num + 1 << "��λ���ҵ� [" << setw(3) << data[num] << "]" << endl;
	}
	cout << "�������ݣ�" << endl;
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