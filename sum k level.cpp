#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int k;cin>>k;
    string s;cin>>s;
    int level=-1;
    int sum=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i] == '(') level++;
        else if(s[i] == ')') level--;
        else if(level == k){
            string tmp;
            while(i<n && s[i] != '(' && s[i] != ')'){
                tmp.push_back(s[i]);
                i++;
            }
            i--;
            sum+=stoi(tmp);
        }
    }
    cout<<sum<<endl;
    return 0;
}