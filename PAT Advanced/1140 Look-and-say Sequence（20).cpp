//1140 Look-and-say Sequence（20)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
using namespace std;

int main(){
    int d,j,n;
    cin >> d>> n;
    string str="",ans="";
    str = d+'0';
    for (int i = 0; i < n-1; i++)
    {
        int len = str.length(),cnt=1;
        if (len ==1)
        {
            str += '1';
            continue;
        }
        for (j = 0; j < len-1; j++)
        {
            if (str[j] == str[j+1])cnt++;
            else
            {
                ans +=  str[j];
                ans += (cnt+'0');
                cnt=1;
            }
        }
        if (j == len-1) {ans +=  str[j];ans += (cnt+'0');}
        str = ans;
        ans = "";
    }
    cout << str << endl;
    
    return 0;
}
