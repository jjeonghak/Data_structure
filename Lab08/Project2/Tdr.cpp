#include <iostream>

using namespace std;

/*
����� �Լ��� ȿ�����̴�.
��� �Լ��� ����� ��� �ߺ��� ����� ������ ȣ�� �������� ���� �޸� ������ �߻��� ����� �ִ�.
�ߺ��� ����� ���̳��� ���α׷��ְ� �޸������̼��� ���� �ذᰡ�������� �� ��쵵 �������� ���� �޸𸮸� ����Ѵ�.
*/

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int main() {

	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_recursive(10) << endl;
	return 0;
}

int Fibonacci_recursive(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
}

int Fibonacci_non_recursive(int n) {
	int cnt = 0, prev1 = 0, prev2 = 1;

	while (cnt < n) {
		if (cnt % 2 == 0)
			prev1 += prev2;
		else
			prev2 += prev1;
		cnt++;
	}
	if (n <= 0)
		return 0;
	else if (n % 2 == 0)
		return prev1;
	else
		return prev2;
}
