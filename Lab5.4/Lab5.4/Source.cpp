#include <iostream>
#include <cstring>
#include "Source.h"

using namespace std;

char* Zapominanie(char* s, char* s3, int n, int len) {
	int m = strlen(s);
	int l = 0;
	if (n + len != m) 
	{
		for (int i = n + len; i < m; i++) 
		{
			for (int j = l++; j <= m - (n + len) - 1; j++) 
			{
				s3[j] = s[i];
			}
		}
	}
	return s3;
}

char* Udalenie(char* s, int n) 
{
	int l = strlen(s);
	for (int i = n; i <= l; i++) 
	{
		s[i] = '\0';
	}
	return s;
}

char* Vstavka(char* s, char* s2, char* s3) 
{
	int i = strlen(s2);
	int j = strlen(s3);
	strncat_s(s, 256, s2, i);
	strncat_s(s, 256, s3, j);
	return s;
}

char* Zamena(char* s, char* s2, int pos_length, int len) 
{
	char s3[257] = { 0 };
	Zapominanie(s, s3, pos_length, len);
	Udalenie(s, pos_length);
	Vstavka(s, s2, s3);
	s3[256] = { 0 };
	return s;
}