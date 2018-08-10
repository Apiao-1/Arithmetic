//https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=40&tqId=21333&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
//该题涉及到同分时按输入先后处理，固不能用map存储，（map还需考虑同名情况，map默认是按key的值进行排序）
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <climits>
#include <vector>
#include <map>
using namespace std;

struct student{
    string name;
    int score;
    int cnt;
};

bool cmp(student a, student b){
    if (a.score != b.score) {
        return a.score < b.score;
    }
    else
        return a.cnt < b.cnt;
    
}

bool cmp1(student a, student b){
    if (a.score != b.score) {
        return a.score > b.score;
    }
    else
        return a.cnt > b.cnt;}

int main(){
    int n,way,score,cnt;
    string str;
    while (cin >> n >> way) {
        student vec[n+1];
        cnt = 0;
        for (int i=0; i<n; i++) {
            cin >> vec[i].name >> vec[i].score;
            vec[i].cnt = cnt++;
        }
        if (way == 1) {
            sort(vec, vec+n,cmp);//升序排列
        }
        else
            sort(vec, vec+n,cmp1);//降序排列
        //        for (auto i = vec.begin(); i!=vec.end(); i++) {
        //            cout << i->name << " " << i->score << endl;
        //        }
        for (int i = 0; i<n; i++) {
            cout << vec[i].name << " " << vec[i].score << endl;
        }
    }
    return 0;
}
