//1136 A Delayed Palindrome（20）
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

string add(string a){
    string ans=a;
    reverse(a.begin(),a.end());
    int len1 = a.length(),c = 0,i;
    for (i =0; i < len1; i++)
    {
        ans[i] += a[i] -'0' + c;
        if (ans[i] > '9')
        {
            c = 1;
            ans[i] -= 10;
        }else
        {
            c = 0;
        }
    }
    if (c == 1)
    {
        ans += '1';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    //freopen("a.txt","r",stdin);
    string str,rev;
    cin >> str;
    int len = str.length(),flag;
    if (len == 0 && str[0] == '0')
    {
        cout << "0 is a palindromic number." << endl;
        return 0;
    }
    for (int cnt = 0; cnt < 10; cnt++)
    {
        flag = 1;
        rev = str;
        reverse(rev.begin(),rev.end());
        for (int i = 0; i < len; i++)
        {
            if (rev[i] != str[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout <<str <<" is a palindromic number."<<endl;
            return 0;
        }else
        {
            cout <<str <<" + " << rev <<" = ";
            str = add(str);
            cout << str << endl;
        }
    }
    cout <<"Not found in 10 iterations." << endl;
    return 0;
}
