#include <bits/stdc++.h>
using namespace std;

// function to find first index >= x
int lowerIndex(int arr[], int n, int x)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] >= x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

// function to find last index <= y
int upperIndex(int arr[], int n, int y)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] <= y)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}

// function to count elements within given range
int countInRange(int arr[], int n, int x, int y)
{
    // initialize result
    int count = 0;
    count = upperIndex(arr, n, y) - lowerIndex(arr, n, x) + 1;
    return count;
}

// driver function
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Preprocess array
    sort(arr, arr + n);

    // Answer queries
    
    int q;
    cin >> q;

    while (q-- > 0)
    {
        int x, y;
        cin >> x >> y;
        cout << countInRange(arr, n, x, y) << " ";
    }
    return 0;
}