#include <iostream>

using namespace std;

double my_abs(double x) {

	if (x < 0)
	{
		x = x * -1;
	}
	return x;
}

double CalculateDegree(double x, int k)
{
	for (int i = 1; i < k; i++)
	{
		x *= x;
	}

	return x;
}

int CalculateFactorial(int x)
{
	int i;
	for (i = 1; i <= x; i++)
	{
		i *= i;
	}
	return i;
}

double calculate_subsum(double x, int k)
{
	int equationSymbol = CalculateDegree(-1, k);
	double xDegree = CalculateDegree(x, k);
	double bottomPart = CalculateFactorial((2 * k - 1));
	int threeDegree = CalculateDegree(3, k);

	return (equationSymbol * xDegree * (k+1)) / (bottomPart * threeDegree);
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	double eps = 1e-6;
	double sum = 0;
	double sumPart = 0;
	
	double x;
	int k = 1;

	std::cout << "Enter x: ";
	std::cin >> x;

	do
	{
		sumPart = calculate_subsum(x, k);
		sum += sumPart;
		k++;
	} 
	while (my_abs(sumPart) > eps);

	std::cout << sum << " " << k;
}