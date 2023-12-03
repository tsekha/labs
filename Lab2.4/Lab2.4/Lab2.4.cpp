#include <iostream>

int main()
{
	std::cout << "Enter 15 number consistency: ";

	int maxCounter = 0;
	int currentCounter = 0;

	for (int i = 0; i < 15; i++)
	{
		int number;
		std::cin >> number;

		while (number % 5 == 0 && number != 1)
		{
			number /= 5;
		}

		if (number == 1)
		{
			currentCounter++;
		}
		else
		{
			if (maxCounter < currentCounter)
			{
				maxCounter = currentCounter;
			}
			currentCounter = 0;
		}
	}

	std::cout << std::endl << maxCounter;
}