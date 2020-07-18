// 给出一个序列包含n个正整数的序列A，你可以从中删除若干个数，使得剩下的数字中的最大值和最小值之差不超过x，请问最少删除多少个数字。 

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    while (cin >> n >> k){
        int a[1001]; 
        map<int, int > m; 
        for (int i = 0; i < n; i ++){
            scanf("%d", a + i);
            m[a[i]] ++;
        }
        sort(a, a + n);
        int len = unique(a, a + n) - a;
        int ans[10001];
        for (int i = 0; i <= 10000; i ++){
            ans[i] = ans[i - 1] + m[i];
        }

        int Max = 0;
        for (int i = 0; i < len; i ++){
            Max = max(Max, ans[a[i] + k] - ans[a[i] - k]);
        }
        cout << n - Max << endl;
    }

    return 0;
}