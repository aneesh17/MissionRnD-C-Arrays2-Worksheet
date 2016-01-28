/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int ten_Pow(int pow)
{
	int index, power = 1;
	for (index = 0; index < pow; index++)
		power *= 10;
	return power;
}


int is_Greater(char *date1, char* date2)
{
	int i, p = 0;
	int temp1 = 0, temp2 = 0, count = 1;
	//checking for year
	for (i = 9, p = 0; i >= 6; i--, p++)
	{
		temp1 += (date1[i] - '0') * ten_Pow(p);
		temp2 += (date2[i] - '0') * ten_Pow(p);
	}
	//printf("%d,%d", temp1,temp2);
	if (temp1>temp2)
		return 1;
	else if (temp1<temp2)
		return -1;
	else
	{
		//checking for month
		for (i = 4, p = temp1 = temp2 = 0; i >= 3; i--, p++)
		{
			temp1 += (date1[i] - '0') * ten_Pow(p);
			temp2 += (date2[i] - '0') * ten_Pow(p);
		}
		if (temp1>temp2)
			return 1;
		else if (temp1<temp2)
			return -1;
		else
		{
			//checking for date
			for (i = 1, p = temp1 = temp2 = 0; i >= 0; i--, p++)
			{
				temp1 += (date1[i] - '0') * ten_Pow(p);
				temp2 += (date2[i] - '0') * ten_Pow(p);
			}
			if (temp1>temp2)
				return 1;
			else if (temp1<temp2)
				return -1;
			else
				return 0;
		}
	}
}


int searchelement(struct transaction *arr, char *key, int len, int low, int high)
{
	//if(key<arr[low] || key>arr[high])
	int temp;
	temp = is_Greater(key, arr[high].date);
	//printf("%d,%d",temp1,temp2);
	if (high >= low)
	{
		//printf("high=%d\nlow=%d",high,low);
		int mid = (low + high) / 2;
		temp = is_Greater(arr[mid].date, key);
		if (temp == 0)
			return mid;
		else if (temp == 1)
			searchelement(arr, key, len, low, mid - 1);
		else
			searchelement(arr, key, len, mid + 1, high);
	}
	else
		return -1;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL || B == NULL)
		return NULL;
	int index, ResIndex = 0;
	int ResLen = (ALen<BLen) ? ALen : BLen;
	struct transaction* result = (struct transaction*) malloc(ResLen * sizeof(struct transaction));
	for (index = 0; index<ALen; index++)
	{
		int temp = searchelement(B, A[index].date, BLen, 0, BLen - 1);
		if (temp != -1)
		{			
			result[ResIndex++] = B[temp];
		}
	}
	if (ResIndex == 0)
		return NULL;
	return result;
}
