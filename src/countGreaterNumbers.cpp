/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int tenPow(int pow)
{
	int index, power = 1;
	for (index = 0; index < pow; index++)
		power *= 10;
	return power;
}


int isGreater(char *date1, char* date2)
{
	int i, p = 0;
	int temp1 = 0, temp2 = 0, count = 1;
	//checking for year
	for (i = 9, p = 0; i >= 6; i--, p++)
	{
		temp1 += (date1[i] - '0') * tenPow(p);
		temp2 += (date2[i] - '0') * tenPow(p);
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
			temp1 += (date1[i] - '0') * tenPow(p);
			temp2 += (date2[i] - '0') * tenPow(p);
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
				temp1 += (date1[i] - '0') * tenPow(p);
				temp2 += (date2[i] - '0') * tenPow(p);
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


int search_element(struct transaction *arr, char *key, int len, int low, int high)
{
	//if(key<arr[low] || key>arr[high])
	int temp1, temp2;
	temp1 = isGreater(key, arr[low].date);
	temp2 = isGreater(key, arr[high-1].date);
	//printf("%d,%d",temp1,temp2);
	if (temp1 == -1 || temp2 == 1)
		return -1;
	if (high >= low)
	{
		//printf("high=%d\nlow=%d",high,low);
		int mid = (low + high) / 2;
		temp1 = isGreater(arr[mid + 1].date, key);
		temp2 = isGreater(arr[mid].date, key);
		if ((mid == 0 || temp1 == 1) && temp2 == 0)
			return mid;
		else if (temp2 == 1)
			search_element(arr, key, len, low, mid-1);
		else
			search_element(arr, key, len, mid+1, high);
	}
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{	
	int temp = search_element(Arr, date, len, 0, len-1);
	if (temp == -1)
		return 0;
	return (len - temp - 1);
}