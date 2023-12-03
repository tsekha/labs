#include <string.h>
#include <iostream>
#include <cmath>
#include "Source.h"

using namespace std;

bool is_digit(char c) {
	return c >= '0' && c <= '9';
}

void  main()
{
	setlocale(LC_ALL, "Ru");
	char s[257], s1[257] = { 0 }, s2[257] = { 0 };
	int n, k, l = 0, len = 0;
	cout << "Введите вашу строку: \n";
	cin.getline(s, 256);
	n = strlen(s);
	for (int i = 0; i < n; i++) 
	{
		if (i > 0 && is_digit(s[i - 1])) 
		{
			continue;
		}

		if (!is_digit(s[i])) 
		{
			continue;
		}

		if (is_digit(s[i + 2])) 
		{
			continue;
		}

		int len = 1;
		if (is_digit(s[i + 1])) 
		{
			len = 2;
		}

		int j = 0;
		for (j = 0; j < len; j++) 
		{
			s1[j] = s[i + j];
		}
		s1[j] = '\0';

		k = atoi(s1);
		k = k * k;

		_itoa_s(k, s2, 256, 10);

		Zamena(s, s2, i, len);
		n = strlen(s);

		s1[0] = '\0';
		s1[1] = '\0';
	}
	
	cout << s << '\n';
}