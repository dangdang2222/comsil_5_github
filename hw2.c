#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
int first_try(char*, char*);
int kmp(int*, char*, char*);
void makefailfunc(int* farr, char* pat);
int main(void)
{
	char* string, * pat;
	string = (char*)malloc(sizeof(char) * MAX_SIZE);
	pat = (char*)malloc(sizeof(char) * MAX_SIZE);

	scanf("%s", string);
	scanf("%s", pat);

	int farr[MAX_SIZE];


	if (first_try(string, pat) != -1)
		printf("Yes %d\n", first_try(string, pat));
	else
		printf("No\n");

	makefailfunc(farr, pat);

	
	if (kmp(farr,string,pat) != -1)
		printf("Yes %d\n", kmp(farr, string, pat));
	else
		printf("No\n");

}

int first_try(char* string, char* pat)
{
	int st = 0;
	int i, j;
	int sum;
	int lens = strlen(string);
	int lenp = strlen(pat);
	for (i = 0; i <= lens-lenp; i++)
	{
		sum = 0;
		for (j = 0; j < lenp ; j++)
		{
			st++;
			if (string[i + j] == pat[j])
			{
				sum++;
			}
		}
		if (sum == strlen(pat))
			return st;
	}
	return -1;
}
int kmp(int* farr, char* string, char* pat)
{
	int i = 0;
	int j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);
	int st = 0;
	while (i < lens && j < lenp)
	{
		st++;
		if (string[i] == pat[j])
		{
			i++;
			j++;
		}
		else if (j == 0) i++;
		else
			j = farr[j - 1];
	}
	if (j == lenp)
		return st;
	else
		return -1;
}
void makefailfunc(int* farr, char* pat)
{
	int len = 0;
	int i=1;
	int j = 0;
	farr[0] = 0;

	int m;
	m = strlen(pat);

	while (i < m)
	{
		if (pat[i] == pat[len])
		{
			len++;
			farr[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
				len = farr[len - 1];
			else
			{
				farr[i] = 0;
				i++;
			}
		}
	}
}