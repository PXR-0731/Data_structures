#include <iostream>
#include <iomanip>
using namespace std;
/*bubble*/
/*
int* bubble_function(int a[], int len) {
	for (int i = len-1; i > 0; i--)
		for (int j = 0; j < i; j++) 
			if (a[j] > a[j+1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
	return a;
};

int main() {
	int a[] = { 2, 6, 1, 3, 0 };
	int* b = bubble_function(a, 5);
	for (int i = 0; i < 5; i++)
		cout << setw(3) << b[i];
	cout << endl;
	system("pause");
	return 1;
}
*/

/*Quick*/
/*
void quick(int a[], int lf, int rt) {
	int tmp, lf_index, rt_index;
	int st = a[lf];
	if (lf < rt) {
		lf_index = lf + 1;
		rt_index = rt;
		while (true) {
			for (int i = lf + 1; i <= rt; i++) {
				if (a[i] > st) {
					lf_index = i;
					break;
				}
				lf_index++;
			}
			for (int j = rt; j >= lf+1; j--) {
				if (a[j] <= st) {
					rt_index = j;
					break;
				}
				rt_index--;
			}
			if (lf_index < rt_index) {
				tmp = a[lf_index];
				a[lf_index] = a[rt_index];
				a[rt_index] = tmp;
			}
			else
				break;
		}
		if (lf_index > rt_index) {
			tmp = a[rt_index];
			a[rt_index] = st;
			a[lf] = tmp;
		}
		quick(a, lf, rt_index - 1);
		quick(a, rt_index + 1, rt);
	}
}

void main() {
	int a[] = { 2, 9, 1, 3, 6, 10, 4, 0, 2};
	quick(a, 0, 8);
	for (int i = 0; i < 9; i++)
		cout << setw(3) << a[i];
	cout << endl;
	system("pause");
	return;
}
*/