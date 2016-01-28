/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int TenPow(int pow)
{
	int index, power = 1;
	for (index = 0; index < pow; index++)
		power *= 10;
	return power;
}

int IsGreater(char *date1, char* date2)
{
	int i, p = 0;
	int temp1 = 0, temp2 = 0, count = 1;
	//checking for year
	for (i = 9, p = 0; i >= 6; i--, p++)
	{
		temp1 += (date1[i] - '0') * TenPow(p);
		temp2 += (date2[i] - '0') * TenPow(p);
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
			temp1 += (date1[i] - '0') * TenPow(p);
			temp2 += (date2[i] - '0') * TenPow(p);
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
				temp1 += (date1[i] - '0') * TenPow(p);
				temp2 += (date2[i] - '0') * TenPow(p);
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


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *result = (struct transaction*) malloc((ALen+BLen) * sizeof(struct transaction));

	int ResIndex = 0, AIndex = 0, BIndex = 0;
	while (AIndex<ALen && BIndex < BLen)
	{
		if (IsGreater(A[AIndex].date, B[BIndex].date) == 1)
		{
			result[ResIndex++] = B[BIndex++];
		}
		else
			result[ResIndex++] = A[AIndex++];
	}
	while (AIndex < ALen)
	{
		result[ResIndex++] = A[AIndex++];
	}
	while (BIndex < BLen)
	{
		result[ResIndex++] = B[BIndex++];
	}

	/*for (ResIndex = 0; ResIndex<5; ResIndex++)
		printf("%s\n", result[ResIndex].date);*/
	return result;
}