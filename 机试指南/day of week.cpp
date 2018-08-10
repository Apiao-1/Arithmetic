//https://www.nowcoder.com/practice/a3417270d1c0421587a60b93cdacbca0?tpId=40&tqId=21439&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
using namespace std;
int year[2][12] = {31,29,31,30,31,30,31,31,30,31,30,31,
    31,28,31,30,31,30,31,31,30,31,30,31};
string week[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
string month[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int ans[5001][13][32];

struct date{
    int y,m,d;
    
    void nextday(){
        int flag = 1;
        if((y % 4 == 0 && y%100 !=0) || y %400 == 0 )//是闰年
            flag = 0;
        d++;
        if(d > year[flag][m-1]){
            d = 1;
            m++;
            if(m > 12){
                m = 1;
                y++;
            }
        }
    }
};


void init(){
    ans[0][1][1] = 0;//定义0年1月1日为计数参考基准
    date day{0,1,1};
    int cnt = 0;
    for (;day.y < 5000 ; ) {
        ans[day.y][day.m][day.d] = cnt++;
        day.nextday();
    }
    
}

int main(){
    init();
    date today{2018,7,7};
    int week_today = 6;//今天是week[6]
    int day,ye,mon;
    string rmonth;
    while (cin >> day >> rmonth >> ye) {
        for (int i = 0; i<12; i++) {
            if (month[i] == rmonth) {
                mon = i;
                break;
            }
        }
        int minus = ans[2018][7][7] - ans[ye][++mon][day];
        cout << week[(week_today - minus%7 )%7]<<endl;
    }
    return 0;
}
