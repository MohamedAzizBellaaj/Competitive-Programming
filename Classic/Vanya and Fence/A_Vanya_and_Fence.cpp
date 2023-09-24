#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, h, x, result = 0;
    cin >> n >> h;
    for (int i=0; i<n; i++){
        cin >> x;
        if(x<=h){
            result++;
        }
        else{
            result+=2;
        }
    }
    cout<<result<<endl;
    return 0;
}