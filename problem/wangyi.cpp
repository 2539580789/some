// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// void getnext(vector<int>& next,string target){
//     int j = 0;
//     next[0] = 0;
//     for (int i = 1; i < target.size();i++ ){
//         while(j>0&&target[j]!=target[i]){
//             j = next[j - 1];
//         }
//         if(target[i]==target[j]){
//             j++;
//         }
//         next[i] = j;
//     }
// }
// int main(){
//     string source;
//     cin >> source;
//     string target;
//     cin >> target;
//     vector<int> next(target.size());
//     getnext(next,target);
//     if(source.size()==0){
//         return -1;
//     }
//     int j = 0;
//     for (int i = 0; i < source.size();i++){
//         while(j>0&&target[j]!=source[i]){
//             j = next[j - 1];
//         }
//         if(target[j]==source[i]){
//             j++;
//         }
//         if(j==target.size()){
//             cout<< i - target.size() + 1;
//             return 0;
//         }
//     }
//     cout << -1;
//     return 0;
// }
#include <iostream>
#include <vector>

using namespace std;
int longestPalindromeSubseq(string s) {
        int m=s.size();
        vector<int> dp(m);
        for(int i=m-1;i>=0;i--){
            dp[i] = 1;
            for (int j = i + 1, left = 0; j < m;j++){
                int tmp = dp[j];
                if(s[i]==s[j]){
                    dp[j] = left + 2;
                }else{
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                left = tmp;
            }
        }
    return dp[m-1];
}
int main() {
    int n;
    cin >> n;
    string s(n,'.');
    for (int i = 0; i < n; i++)
    {
            cin >> s[i];
    }
    int k = longestPalindromeSubseq(s);
    cout << n - k;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;
int longestPalindromeSubseq(string s) {
        int m=s.size();
        vector<vector<int>>dp(m,vector<int>(m));
        for(int i=0;i<m;i++){
            dp[i][i]=1;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=i+1;j<m;j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
    return dp[0][m-1];
}
int main() {
    int n;
    cin >> n;
    string s(n,'.');
    for (int i = 0; i < n; i++)
    {
            cin >> s[i];
    }
    int k = longestPalindromeSubseq(s);
    cout << n - k;
    return 0;
}

