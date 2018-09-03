//1112 Stucked Keyboard（20)
//用map的方法会更为简单，就不用getIndex转化了，此题需注意当i= len时，无论str[i] 与 str[i-1]是否相等都需要再做一次
#include <iostream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstdio>
using namespace std;
int mark[100];
vector<char> er,ans;

int getIndex(char c)
{
    if(isdigit(c))
        return c - '0';
    else if(c =='_' )
        return 10;
    else
        return 11+c - 'a';
}

int main()
{
    int k,cnt = 1;
    scanf("%d\n",&k);
    string str;
    getline(cin,str);
    int len = str.length();
    for(int i = 1; i<=len; i++)
    {
        if(i == len){
            if(cnt % k == 0){
                if(mark[getIndex(str[i-1])] == 0 ){
                    er.push_back(str[i-1]);
                    mark[getIndex(str[i-1])] = -1;
                }
            }else{
                mark[getIndex(str[i-1])] = 1;
            }
            cnt = 1;
            break;
        }
        if(str[i] == str[i-1]) cnt++;
        else{
            if(cnt % k == 0){
                if(mark[getIndex(str[i-1])] == 0 ){
                    er.push_back(str[i-1]);
                    mark[getIndex(str[i-1])] = -1;
                }
            }else{
                mark[getIndex(str[i-1])] = 1;
            }
            cnt = 1;
        }
    }
    int len2 = er.size();
    for(int i = 0; i<len2; i++)
    {
        int index = getIndex(er[i]);
        if(mark[index] == -1)
            cout << er[i];
    }
    cout << endl;
    for(int i = 0; i<len; i++)
    {
        cout << str[i];
        if(mark[getIndex(str[i])] == -1)
            i+=k-1;
    }
    cout << endl;
    
    return 0;
}
