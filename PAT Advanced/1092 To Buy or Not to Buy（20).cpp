//1092 To Buy or Not to Buy（20)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main(){
    string str1,str2;
    int miss=0;
    cin >> str1 >> str2;
    map<char,int> ma;
    int len1 = str1.length(),len2 = str2.length();
    for (int i =0; i<len1; i++) {
        ma[str1[i]]++;
    }
    for (int i =0; i<len2; i++) {
        //        if (ma.count(str2[i]) > 0) //注意map的count用法，返回的是键的个数，所以只有0和1
        //        cout << ma[str2[i]] << " ";若map[str2[i]]不存在则默认为0
        if(ma[str2[i]] > 0)
            ma[str2[i]]--;
        else{
            miss++;
        }
    }
    if (miss != 0) {
        cout <<"No "<<miss << endl;
    }else{
        int sum = 0;
        map<char,int> ::iterator i = ma.begin();
        for (; i!=ma.end(); i++) {
            sum += i->second;
        }
        cout <<"Yes "<<sum << endl;
    }
    return 0;
}
