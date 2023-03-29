#include<iostream>
#include<vector>
using namespace std;
void getnext(vector<int>& next,string s){
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < s.size(); i++ ){
        while(j>0&&s[i]!=s[j]){
            j = next[j - 1];
        }
        if(s[i]==s[j]){
            j++;
        }
        next[i] = j;
    }
}
int KMP(string s1,string s2){
    int m = s1.size(), n = s2.size();
    vector<int> next(n);
    getnext(next, s2);
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while(j>0&&s1[i]!=s2[j]){
            j = next[j - 1];
        }
        if(s1[i]==s2[j]){
            j++;
        }
        if(j==n){
            return i - n + 1;
        }
    }
    return -1;
}