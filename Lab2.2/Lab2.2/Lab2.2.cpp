#include <iostream>
int main() 
{
	using namespace std;
	double x0 = -3;
	double xn = 4;
	double deltaX = 1;
	double epsilon = 0.000001;
	
	for (x0; x0 <= xn; x0 += deltaX)
	{
		double chx = 1;
		double chxPart = 1;
		for (int i = 2; chxPart > epsilon; i += 2)
		{
			double factorial = 1;
			double xtemp = 1;
			for (int k = 1; k <= i; k ++)
			{
				factorial *= k;
				xtemp *= x0;
			}
			chxPart = xtemp / factorial;
			chx += chxPart;
		}

		cout << "Chx = " << chx << " y= " << chx - 1 << endl;
	}
}
