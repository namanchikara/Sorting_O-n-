#include<stdio.h>
#define SIZE 500000
int main(void)
{
    long long int unsorted,hasht[SIZE]={0},sorted[SIZE]={0},top=-1,i,n,largest=0,minimum=0;

    scanf("%lld",&n);     //No of elements to be sorted.
    for(i=0;i<n;i++)
    {
        scanf("%lld",&unsorted);  //Unsorted array input

        if(hasht[unsorted])      //if element entered has already been input earlier, like in array 1 2 3 3 4, 3 is being input twice, in that case:
        hasht[unsorted]++;

        else
        hasht[unsorted]=1;      //First occurence of element in unsorted array.

        if(unsorted>largest)
        largest=unsorted;        //this determines the maximum size of a element in unsorted array.

        if(unsorted<minimum)
        minimum=unsorted;
    }
        printf("Sorted elements are: ");

        for(i=minimum;i<largest+1;i++)
            if(hasht[i])            //If the element existed in unsorted array
            {
                    for(int j=0;j<hasht[i];j++) //In case element exist more than once in that unsorted array
                    {
                        printf("%lld ",i);      //print it upto the times it occured in that unsorted array.

                        ++top; sorted[top]=i;   //A array Sorted is being maintained in case we want to use this sorted array instead of just traversing the unsorted array in sorted manner
                    }
            }
}
