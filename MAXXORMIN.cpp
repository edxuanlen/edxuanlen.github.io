# include <bits/stdc++.h>

using namespace std;


int main(){

    

    int n, x;
    while (cin >> n){
        stack <int > s1; // min
        stack <int > s2; // max
        int sum = 0;
        for (int i = 0; i < n; i ++){
            cin >> x;
            if ( !s1.size() ){
                s1.push(x);
            } else {
                while (s1.size() && s1.top() >= x){
                    s1.pop();
                }
                s1.push(x);
            }

            if ( !s2.size() ){
                s2.push(x);
            } else {
                while (s2.size() && s2.top() <= x){
                    s2.pop();
                }
                s2.push(x);
            }

            int temp = (s1.top() ^ s2.top());
            sum = sum ^ temp;
        }
        cout << sum << endl;
    }


    return 0;
}