// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;
// bool check(vector<int>& s1,vector<int>& s2){
//     stack<int> s;
//     int idx1 = 0, idx2 = 0;
//     while(idx2<s2.size()){
//         while(s.empty()||s.top()!=s2[idx2]){
//             if(idx1<s1.size()){
//                 s.push(s1[idx1++]);
//             }else{
//                 return false;
//             }
//         }
//         idx2++;
//         s.pop();
//     }
//     return true;
// }
// int main(){
//     int T;
//     cin >> T;
//     vector<string> ans;
//     for (int i = 0; i < T; i++)
//     {
//         int n;
//         cin >> n;
//         vector<int> s1(n), s2(n);
//         for (int i = 0; i < n;i++){
//             cin >> s1[i];
//         }
//         for (int i = 0; i < n;i++){
//             cin >> s2[i];
//         }
//         if(check(s1,s2)){
//             ans.push_back("Yes");
//         }
//         else
//         {
//             ans.push_back("No");
//         }
//     }
//     for(auto a:ans){
//         cout << a << endl;
//     }
//     return 0;
// }
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     vector<int> dp(n); 
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     dp[0] = a[0];
//     dp[1] = max(a[0], a[1]);
//     dp[2] = max(dp[1],a[2]);
//     for (int i = 3; i < n; i++) {
//         dp[i] = max(dp[i - 3] + a[i], dp[i - 1]);
//     }
//     cout << dp[n - 1];
//     return 0;
// } 
#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,k,a[N],dp[N][N][2];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);   //今天不吃
            if(j) dp[i][j][1]=max(dp[i-1][j-1][0],dp[i-1][j-1][1])+a[i];    //k次机会
            dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][0]+a[i]);//今天吃 昨天不吃
        }
    }
    printf("%d\n",max(dp[n][k][0],dp[n][k][1]));
    return 0;
} 