#include <stdio.h>

int binsearch(int x, int v[], int n);
int main()
{
    int v[17] = {1,4,7,9,21,23,34,45,56,76,88,89,123,123,345,567,789};
    int k = 17;

    printf("%i\n", binsearch(345,v,k));
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
   }
    mid = (low + high) / 2;
    if ( x == v[mid])
        return mid;
    else
        return -1;
}