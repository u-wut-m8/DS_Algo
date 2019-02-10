#include<bits/stdc++.h>
using namespace std;

int solve (string s) {
//    // Write your code here
//    std::vector<int> v(s.size(), 1);
//    for(int i=0;i<s.size()-1;i++){
//        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
//         v[i] = 0;
//        else
//         for(int j=i+1;j<s.size();j++)
//             if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
//                 v[i]++;
//             else
//                 break;
//    }
//    for(std::vector<int>::iterator it=v.begin();it!=v.end();++it)
//     std::cout<<(*it)<<' '<<std::endl;
// return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        string S;
        // getline(cin, S);
        cin >> S;
        int out_;
        out_ = solve(S);
        cout << out_;
        cout << "\n";
    }
    return 0;
}