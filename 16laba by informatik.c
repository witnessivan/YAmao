#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void qs(int* s_arr, int first, int last)
{
    int i = first, j = last, x = s_arr[(first + last) / 2];
    int far;
    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;
 
        if(i <= j) {
            if (s_arr[i] > s_arr[j]){
                far=s_arr[i];
                s_arr[i]=s_arr[j];
                s_arr[j]=far;
            }
            i++;
            j--;
        }
    } while (i <= j);
 
    if (i < last)
        qs(s_arr, i, last);
    if (first < j)
        qs(s_arr, first, j);
}

int main()
{
	int a, b, c, d, e, p, i, j, max, min;
	e = 0;
	p = 0;
	d = 0;
	printf("Type here number of matrix elements: ");
	scanf("%d", &a);
	srand(time(NULL));
	while (a < 0 || a > 100)
	{
		printf
			("We can not cope with so many elements of the array, please, type something else\nType here number of matrix elements: ",
			 i);
		scanf("%d", &a);
	}
	int massive[a];
	printf
		("Please, choose way you type in elements of matrix: 1 is manually, 2 is automatic random typing\nYour choose is: ");
	scanf("%d", &b);
	while (b < 1 || b > 2)
	{
		printf
			("Sorry, we haven't made a feature with this number yet, please type one of the numbers you see\nPlease, choose way you type in elements of matrix: 1 is manually, 2 is automatic random typing\nYour choose is:  ");
		scanf("%d", &b);
	}
	if (b == 1)
	{
		for (i = 0; i < a; i++)
		{
			printf("massive[%d]: ", i);
			scanf("%d", &massive[i]);
			while (massive[i] < 0)
			{
				printf
					("We can't deal with these number of elements, please, type something else\nmatrix[%d]: ",
					 i);
				scanf("%d", &massive[i]);
			}
		}
	}
	else if (b == 2)
	{
		printf("Your matrix is: ");
		for (i = 0; i < a; i++)
		{
			massive[i] = rand() % 1000;
			printf("%d ", massive[i]);
		}
	}

	printf
		("\nWhat you're going to do next?\n1. Bubble sort\n2. Hoare's QuickSortâ„¢\nSo, what do you choose?  ");
	scanf("%d", &c);
	while (c < 1 || c > 2)
	{
		printf
			("Sorry, we haven't made a feature with this number yet, please type one of the numbers you see\nWhat you're going to do next?\n1. Bubble sort\n2. Hoare's QuickSortâ„¢\nSo, what do you choose?  ");
		scanf("%d", &c);
	}
	
    for(i=1; i<a; i++){
		    if(massive[i]==massive[i-1]){
		        massive[i-1]=2017;
		        p++;
		    }
		}
		
	if (c == 1)
	{
		for (i = 1; i < a; i++)
		{
			for (j = 0; j <= a - 1; j++)
			{
				if (massive[j] > massive[i])
				{
					e = massive[j];
					massive[j] = massive[i];
					massive[i] = e;
				}
			}
		}
	} else if(c==2){
	    qs(massive, 0, a-1);
	}

	for (i = 0; i < a-p; i++)
	{
		printf("%d ", massive[i]);
	}
    printf("\nThis program can help you find the N-th minimum and M-th maximim, just type here!\nN is ");
    scanf("%d", &min);
    printf("M is ");
    scanf("%d", &max);
    printf("%d-th minimum is %d\n%d-th maximum is %d", min, massive[min-1], max, massive[a-p-max]);
}
