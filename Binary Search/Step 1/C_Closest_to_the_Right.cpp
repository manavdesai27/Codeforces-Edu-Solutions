#include <bits/stdc++.h>
#include <string>
#include <vector>

#define pushb push_back
#define popb pop_back
#define ld long double
#define ll long long
#define fo(i, n) for (long long i = 0; i < n; i++)
#define w(t)     \
    long long t; \
    cin >> t;    \
    while (t--)
#define endl "\n"

using namespace std;

// ll binarySearch(string arr[], string x, long long int n)
// {
//     ll l = 0;
//     ll r = n - 1;
//     while (l <= r)
//     {
//         ll m = l + (r - l) / 2;

//         ll res;
//         if (x == (arr[m]))
//             res = 0;

//         // Check if x is present at mid
//         if (res == 0)
//             return m;

//         // If x greater, ignore left half
//         if (x > (arr[m]))
//             l = m + 1;

//         // If x is smaller, ignore right half
//         else
//             r = m - 1;
//     }

//     return -1;
// }

void binarySearch(ll arr[], ll x, ll n)
{
    ll l = -1;
    ll r = n;

    if (arr[0] > x)
    {
        cout << -1 << endl;
        return;
    }

    while (l < r + 1)
    {
        ll m = (l + r) / 2;
        if (arr[m] <= x)
        {
            l = m;
        }

        else
            r = m;
    }

    cout << l + 1 << endl;
    return;
}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

void bubbleSort(long long a[], long n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

int power(long long x, unsigned int y, int p)
{
    int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

ll countDistinct(ll arr[], ll n)
{
    // First sort the array so that all
    // occurrences become consecutive
    sort(arr, arr + n);

    // Traverse the sorted array
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {

        // Move the index ahead while
        // there are duplicates
        while (i < n - 1 && arr[i] == arr[i + 1])
            i++;

        res++;
    }

    return res;
}

void manavdesai()
{
    ll n, k;
    cin >> n >> k;

    ll arr[n];

    fo(i, n)
    {
        cin >> arr[i];
    }

    while (k-- > 0)
    {
        ll x;
        cin >> x;

        ll l = -1;
        ll r = n;

        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (arr[m] < x)
            {
                l = m;
            }

            else
                r = m;
        }

        cout << r + 1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    manavdesai();

    return 0;
}