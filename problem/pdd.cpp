#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int main() {
//     string s;
//     cin >> s;
//     string ans;
//     int idx = 0;
//     int num = 0;
//     while(idx<s.size()){
//         if (isdigit(s[idx]))
//         {
//             num = num * 10 + s[idx] - '0';
//             idx++;
//         }
//         else if(isalpha(s[idx]))
//         {
//             for (int j = 0; j < num;j++){
//                 ans += s[idx];
//             }
//             num = 0;
//             idx++;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }
// int main() {
//     int t, n;
//     cin >> t>>n;
//     vector<int> ans(t);
//     for (int i = 0; i < t;i++){
//         vector<int> tmp(n);
//         int an = 0;
//         int a = 0, b = 0;
//         for (int j = 0; j < n; j++)
//         {
//             cin >> tmp[j];
//             if(tmp[j]==1){
//                 a++;
//             }
//         }
//         an += n - a;
//         an += a / 2;
//         an += a % 2 ? 1 : 0;
//         ans[i] = an;
//     }
//         for (int i = 0; i < t; i++)
//         {
//             cout << ans[i] << endl;
//         }
//         return 0;
// }

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;

double sum;

priority_queue<ll> q1;
priority_queue<ll, vector<ll>, greater<ll> > q2;
ll a[maxn];

int main()
{
    int n;
    scanf("%d%lld", &n, &a[1]);

    vector<ll> v1, v2;
    q1.push(a[1]);
    v1.push_back(a[1]);
    v2.push_back(a[1]);
    sum += a[1];

    for(int i = 2; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
        double t = (double)(sum)/(double)i;
        ll tt = (ll)(t+0.5);
        v1.push_back(tt);

        int x = a[i];
        if(x > q1.top()) q2.push(x);
		else q1.push(x);

		while(abs((int)q1.size() - (int)q2.size()) > 1)
		{
			if(q1.size() > q2.size())
			{
				q2.push(q1.top());
				q1.pop();
			}
			else
			{
				q1.push(q2.top());
				q2.pop();
			}
		}
		if(i&1) v2.push_back(q1.size() > q2.size() ? q1.top() : q2.top());
        else
        {
            double aa = (double)q1.top()+(double)q2.top();
            ll aaa = (ll)((aa/2.0)+0.5);
            v2.push_back(aaa);
        }
    }
    for(auto x : v1)
        printf("%d ", x);
    puts("");
    for(auto x : v2)
        printf("%d ", x);
    puts("");
    return 0;
}
/*
5
1 2 3 4 10
*/
