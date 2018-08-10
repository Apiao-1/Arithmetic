//打印日期
#include <iostream>
#include <cstdio>
using namespace std;

#define isYear(x) x%4 == 0 && x%100 !=0 || x%400 == 0 ? 1:0

int DATE[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

struct date {
    int year;
    int month;
    int day;
    void nextDay(){
        day++;
        if (day > DATE[isYear(year)][month]){
            day = 1;
            month++;
            if(month > 12){
                month =1;
                year++;
            }
        }
    }
};
int abs(int x){
    return x<0 ? -x:x ;
}

int main(){
    int a[5001][13][32],cnt = 0;
    date tmp;
    tmp.year=0;
    tmp.month=1;
    tmp.day=1;
    while (tmp.year <= 5000) {
        a[tmp.year][tmp.month][tmp.day] = cnt;
        cnt++;
        tmp.nextDay();
    }
    int y1,num,changeNum;
    while(cin >> y1 >> num){
        changeNum = a[y1][1][1] + num -1;
        for (int j=num/31+1; j<13; j++) {
            for (int i=1; i<32; i++) {
                if(a[y1][j][i] == changeNum){
                    printf("%4d-%02d-%02d\n",y1,j,i);
                    break;
                }
            }
        }
    }
    
    return 0;
}
