//#include <iostream>
//#include <vector>
//
//
//std::vector<int> plus_minus_multiply_divide(4);
//int num;
//int index = 0;
//int max = -1000000000;
//int min = 1000000000;
//std::vector<int> data;
//int calculate_value;
//
//
//
//void calculate(int index) {
//
//
//	std::vector<int> plus_minus_multiple_divide_x = plus_minus_multiply_divide;
//	int num_x = num;
//	int index_x = index;
//	int max_x = max;
//	int min_x = min;
//	std::vector<int> data_x = data;
//	int calculate_value_X = calculate_value;
//
//
//
//
//	if (index == num) {
//
//		max = calculate_value > max ? calculate_value : max;
//		min = calculate_value < min ? calculate_value : min;
//		return;
//	}
//
//
//	for (int i = 0; i < 4; i++) {
//		if (plus_minus_multiply_divide[i] != 0) {
//			plus_minus_multiply_divide[i]--;
//			switch (i) {
//			case 0:
//				calculate_value += data[index] ;
//				calculate(index + 1);
//				break;
//			case 1:
//				calculate_value -= data[index] ;
//				calculate(index + 1);
//				break;
//			case 2:
//				calculate_value *= data[index] ;
//				calculate(index + 1);
//				break;
//			case 3:
//				calculate_value /= data[index] ;
//				calculate(index + 1);
//			}
//
//		}
//	}
//
//}
//
//
//
//int main() {
//	scanf("%d", &num);
//	data.resize(num);
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &data[i]);
//	}
//	for (int i = 0; i < 4; i++) {
//		scanf("%d", &plus_minus_multiply_divide[i]);
//	}
//
//
//	/*std::vector<int> plus_minus_multiple_divide_x = plus_minus_multiple_divide;
//	int num_x = num;
//	int index_x = index;
//	int max_x = max;
//	int min_x = min;
//	std::vector<int> data_x = data;
//	int calculate_value_X = calculate_value;*/
//
//	calculate_value = data[0];
//	calculate(1);
//	printf("%d\n%d", max, min);
//
//}

//��Ʋ° Ǯ���µ� ��Ʈ��ŷ�� ������ �Ƿ��� �� ������ �ȵ�.
//�Լ����� ���� ���� �������� �ʴ� ���� �����ؾ���.
//������� void function(index++)�� index�� ���� �����Ű���� void function(index+1)�� �����ϴ°� index�� �״�� ������ ���¿��� ����
#include<iostream>
#include<algorithm>
using namespace std;
int maxN = -100000000, minN = 1000000000;
int n, a[12], p, s, m, d;
void go(int index, int plus, int sub, int multi, int divi, int total) {
	if (index == n) {
		maxN = max(maxN, total);
		minN = min(minN, total);
		return;
	}
	if (plus < p)
		go(index + 1, plus + 1, sub, multi, divi, total + a[index]);
	if (sub < s)
		go(index + 1, plus, sub + 1, multi, divi, total - a[index]);
	if (multi < m)
		go(index + 1, plus, sub, multi + 1, divi, total * a[index]);
	if (divi < d)
		go(index + 1, plus, sub, multi, divi + 1, total / a[index]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> p >> s >> m >> d;
	go(1, 0, 0, 0, 0, a[0]);
	cout << maxN << endl << minN << endl;
	return 0;
}



