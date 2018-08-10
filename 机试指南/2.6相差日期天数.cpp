//相差日期天数
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
    int y1,m1,d1,y2,m2,d2;
    while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF){
        scanf("%4d%2d%2d",&y2,&m2,&d2);
        cout << abs(a[y1][m1][d1]-a[y2][m2][d2])+1 << endl;
    }
    
    return 0;
}
