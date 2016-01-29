/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>

int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	int index1 = 0, index2 = 0,count=0,resultIndex;
	for (index1 = 0; index1 < len; index1++,count=0)
	{
		for (index2 = 0; index2 < len; index2++)
		{
			if (A[index1] == A[index2])
			{
				count++;
			}
		}
		if (count == 1)
			return A[index1];
	}
	//return count;
}