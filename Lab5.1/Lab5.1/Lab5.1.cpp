#include <iostream>

using namespace std;

double my_abs(double x) {

	if (x < 0)
	{
		x = x * -1;
	}
	return x;
}

double enter_x() {
	double x;
	setlocale(LC_ALL, "Russian");
	cout << "Введите x(0 < x <= 1):" << endl;
	cin >> x;

	return x;
}

double calculate_sum(double* x, int& k, const double eps = 1e-6) {
	double t = 1, l = 1, z = 1;
	double u = -1 * (2 * *x) / 3;
	double s = u;
	double p = 1;
	k = 1;
	for (k = 2; abs(u) > eps; k++) {
		for (int i = 0; i < k; i++) {
			t *= *x;
			l *= -1;
			z *= 3;
		}
		t = t * l * (k + 1);
		p *= 2 * k - 1;
		u = t / (p * z);
		s += u;
	}

	return s;
}

int main() {
	setlocale(LC_ALL, "Rus");
	const double eps = 1e-6;

	double x = enter_x();
	int k = 0;
	double result = calculate_sum(&x, k, eps);

	cout << "Сумма = " << result << endl;
	cout << "Количество слагаемых = " << k << endl;
	return 0;
}