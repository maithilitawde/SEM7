#include <bits/stdc++.h>
using namespace std;

int partition(int start, int end, vector<int> &arr)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start;
    int j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        if (arr[i] <= pivot)
        {
            i++;
        }

        if (arr[j] > pivot)
        {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++] , arr[j--]);
        }
    }
    return pivotIndex;
}

int generateRandomPivot(int start , int end)
{
     return start + rand() % (end-start+1);
}

int randomised_partition(int start , int end , vector<int>&arr)
{
    int pivotIndex = generateRandomPivot(start , end);
    swap(arr[pivotIndex] , arr[start]);

    int pivot = arr[start];
    int i = start+1;
    for(int j = start+1 ; j<=end ;j++)
    {
        if(arr[j]<=pivot)
        {
            swap(arr[i] , arr[j]);
            i++;

        }
    }
    swap(arr[start] , arr[i-1]);
    return (i-1);

}
void quicksort(int start, int end, vector<int> &arr, bool rand)
{
    if (start >= end)
    {
        return;
    }

    int p;
    if (rand)
    {
        p = randomised_partition(start, end, arr);
    }
    else
    {
        p = partition(start, end, arr);
    }

    quicksort(start, p - 1, arr, rand);
    quicksort(p + 1, end, arr, rand);
}
int main()
{
    srand(time(0));
    cout << "Enter the size of the array";
    int n;
    cin >> n;

    vector<int> arr(n);

    cout << "Taking input for deterministic pivot" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(0, n - 1, arr, false);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;

    cout << "Taking input for randomised pivot" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(0, n - 1, arr, true);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}