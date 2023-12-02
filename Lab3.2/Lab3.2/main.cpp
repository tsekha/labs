#include <iomanip>
#include <iostream>

int main() 
{
	srand(time(NULL));
	int n;
	std::cout << "Enter n for matrix ";
	std::cin >> n;

	int** matrixA = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrixA[i] = new int[n];
	}

	int** matrixB = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrixB[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrixA[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << std::setw(5) << matrixA[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << "Matrix B: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		int maxValue;

		for (int j = 0; j < n; j++)
		{
			maxValue = matrixA[i][j];

			for (int k = 0; k < n; k++)
			{
				for (int m = 0; m < n; m++)
				{
					if (k >= m - (j - i) && k >= -m + (j+i))
					{
						if (matrixA[k][m] > maxValue)
						{
							maxValue = matrixA[k][m];
						}
					}
				}
			}

			matrixB[i][j] = maxValue;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << std::setw(5) << matrixB[i][j] << " ";
		}

		std::cout << std::endl;
	}
}