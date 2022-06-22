#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (ll i = a; i <= b; i++)
void print(vi v)
{
    for (auto f : v)
        cout << f << " ";
}
ll m, n;
bool g(ll x, ll v[][3])
{
    ll f = 0;
    rep(i, 0, n - 1)
    {
        ll t = v[i][0];
        ll z = v[i][1];
        ll y = v[i][2];
        ll p = (t * z) + y;
        f += ((x / p) * z + min(z, ((x % p) / t)));
    }
    if (f >= m)
    {
        return 1;
    }
    else
        return 0;
}
vector<ll> good(ll x, ll v[][3])
{
    vector<ll> v1(n, 0);
    ll f = 0;
    // ll f = 0;
    rep(i, 0, n - 1)
    {
        if (f >= m)
            break;
        ll t = v[i][0];
        ll z = v[i][1];
        ll y = v[i][2];
        ll g = 0;
        ll p = t * z + y;
        g = (x / p) * z + min(z, ((x % p) / t));
        
        v1[i] = g;
    }
    return v1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll n;
    // ll n, x, y;
    cin >> m >> n;
    // v.resize(n);

    ll v[n][3];
    rep(i, 0, n - 1)
    {
        ll f, g, h;
        cin >> f >> g >> h;
        v[i][0] = f;
        v[i][1] = g;
        v[i][2] = h;
    }
    ll r = 3000001;
    ll ans = 0;
    ll l = 0;
    vector<ll> f;
    while (r >= l)
    {
        ll mid = r + l;
        mid /= 2;
        // vector<ll> p = good(mid);
        if (g(mid, v))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    f = good(ans, v);
    cout << ans << "\n";
    for (auto g : f)
    {
        cout << g << " ";
    }
}