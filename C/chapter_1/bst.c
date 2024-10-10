#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO 8


/*Function prototype declaration*/
void bst (int sortedlist[], int start, int end, int searchvalue);


int main()
{
	int sortedlist[NO]={31, 32, 56, 78, 87, 98, 123, 412};
	int start,end, searchvalue;
	
	start=0;
	end=NO-1;
	printf("Enter the search value: ");
	scanf ("%i",&searchvalue);
	bst(sortedlist, start, end, searchvalue);
	return 0;
}

void bst (int sortedlist[], int first, int last, int searchvalue)
{
	int midpoint;
	midpoint = (last + first) /2;
	printf("START:%i MID:%i  END:%i SEARCHVALUE:%i MIDVALUE:%i \n", first, midpoint, last,searchvalue, sortedlist[midpoint] );
	if (first <= last)
	{
		if (sortedlist[midpoint] == searchvalue) 
		{
			printf("Found %i \n", sortedlist[midpoint] );
		} else {
			if (sortedlist[midpoint] < searchvalue)
				first = midpoint+1;
			else
				last = midpoint-1;
			bst(sortedlist, first, last, searchvalue);
		}
	}
}

