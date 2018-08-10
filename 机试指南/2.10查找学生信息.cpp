#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

struct student{
    string num;
    string name;
    string sex;
    int age;
};

int main(){
    int n,i=0,m;
    string findNum;
    student a[1001];
    map<string,student> stuMap;
    while(scanf("%d",&n)!=EOF){
        for (i=0; i<n; i++) {
//            scanf("%s %s %s %d",&a[i].num,&a[i].name,&a[i].sex,&a[i].age);
            cin >> a[i].num >>a[i].name>>a[i].sex>>a[i].age;
            stuMap[a[i].num] = a[i];
        }
        scanf("%d",&m);
        for (int j=0; j<m; j++) {
            cin >> findNum;
            if (stuMap.count(findNum)>0) {
                cout << stuMap[findNum].num << " "<< stuMap[findNum].name << " "<< stuMap[findNum].sex << " "<< stuMap[findNum].age <<endl;
            }else
                cout << "No Answer!" <<endl;
            
        }
        
        
    }
    return 0;
}
