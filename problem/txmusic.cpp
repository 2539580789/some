#include<iostream>
using namespace std;
int v[30];
typedef long long ll;
void clear()
{
    for(int i = 0; i < 29; i++)
        v[i] = 0;
}
bool check(string str, ll mid, int k)
{
    int cnt = 0;
    ll num = 0, qz = 0, sz = 0;
    clear();
    for(int i = 0; i < str.size(); i++)
    {
        if(v[str[i]-'a'] == 0) 
        {
            qz++;
            v[str[i]-'a'] = 1;
        }
        sz++; num = qz*sz;
        if(num == mid)
        {
            qz = sz = 0;
            clear();
            num = 0;
            cnt++;
        }
        else if(num > mid)
        {
            clear();
            qz = sz = 1;
            v[str[i]-'a'] ++;
            cnt++;
            num = qz*sz;
        }
    }
    if(num != 0) cnt++;
    
    
    if(k < cnt) return true;
    else return false;
    
}
int getMaxValue(string str, int k){
    
    ll l = 0, r = str.size()*26;
    ll ans = 0;
    while(l < r)
    {
        ll mid = (l+r)/2;
        if(check(str, mid, k)) 
            l = mid+1;
        else r = mid;
    }
    return l;
}
