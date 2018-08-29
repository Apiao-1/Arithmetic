//1036 Boys vs Girls（25） https://pintia.cn/problem-sets/994805342720868352/problems/994805453203030016
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
using namespace std;

struct node{
    string name;
    string ID;
    int grade;
}s;
vector<node> male,female;

bool cmp(node a,node b){
    return a.grade < b.grade;
}

int main() {
    int n,m;
    char gender;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> s.name >> gender >> s.ID >> s.grade;
        if (gender == 'M') {
            male.push_back(s);
        }else
            female.push_back(s);
    }
    int flag = 0;
    if(female.size() == 0){
        cout << "Absent" << endl;
        flag = 1;
    }else{
        sort(female.begin(), female.end(),cmp);
        m = female.size()-1;
        cout << female[m].name << " " << female[m].ID << endl;
    }
    
    if (male.size() == 0) {
        cout << "Absent" << endl;
        flag = 1;
    }else{
        sort(male.begin(), male.end(),cmp);
        cout << male[0].name << " " << male[0].ID << endl;
    }
    
    if (flag) {
        cout << "NA" << endl;
    }else
        cout << female[m].grade - male[0].grade << endl;
    return 0;
}
