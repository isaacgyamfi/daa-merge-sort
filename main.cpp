#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

void merge(int a[], int lowerIndex, int middleIndex, int higherIndex)
{
    int i, j, k, b[20];
    i = lowerIndex;
    j = middleIndex + 1;
    k = lowerIndex;
    while (i <= middleIndex && j <= higherIndex)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= middleIndex)
        b[k++] = a[i++];
    while (j <= higherIndex)
        b[k++] = a[j++];
    for (k = lowerIndex; k <= higherIndex; k++)
        a[k] = b[k];
}
void mergeSort(int a[], int lowerIndex, int higherIndex)
{
    int middleIndex;
    if (lowerIndex >= higherIndex)
        return;
    middleIndex = (lowerIndex + higherIndex) / 2;
    mergeSort(a, lowerIndex, middleIndex);
    mergeSort(a, middleIndex + 1, higherIndex);
    merge(a, lowerIndex, middleIndex, higherIndex);
}

void
int main()
{
    int num, a[2000];
    clock_t st, et;
    double ts;
    cout<<endl<<"Enter the number of values to generate: ";
    cin>>num;
    cout<<endl<<"Random Numbers: "<<endl;
    for (int x = 1; x <= num; x++)
    {
        a[x] = rand() % 10;
        cout<<endl<<"\t"<<a[x];
    }
    st = clock();
    mergeSort(a, 1, num);
    et = clock();
    ts = (double)(et - st) / CLOCKS_PER_SEC;
    cout<<endl<<"Sorted Numbers are :"<<endl;
    for (int y = 1; y <= num; y++)
        cout<<"\t"<< a[y];
    cout<<endl<<"The time taken is "<<ts<<"seconds";
    return 0;
}
