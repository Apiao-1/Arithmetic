//https://www.nowcoder.com/practice/f7eba38f7cd24c45982831e0f38518f9?tpId=40&tqId=21486&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 99999;

struct City{
    double dist;
    double price;
};

bool cmp(City a,City b){
    if (a.dist != b.dist) {
        return a.dist < b.dist;
    }else
        return a.price < b.price;
}

int main(){
    int Cmax,D,Davg,n,i,pre,after,has_min;
    double money,maxDist,min,curDist,curOil;
    City city[1001];
    while (cin >> Cmax >> D >> Davg >> n) {
        maxDist = pre = money = curDist = after = curOil = 0;
        for (i = 0; i<n; i++) {
            scanf("%lf %lf",&city[i].price,&city[i].dist);
        }
        //按距离升序排列
        sort(city, city+n, cmp);
        
//        for (i = 0; i<n; i++) {
//            printf("%.2f %.0f\n",city[i].price,city[i].dist);
//        }
        
        
        while (curDist < D) {
            pre = after;
            maxDist = curDist + Cmax*Davg;
            min = city[pre].price;
            has_min = 0;
            for (i = pre+1; city[i].dist <= maxDist && i <n; i++) {
                if(city[i].price <= min){
                    min = city[i].price;
                    after = i;
                    has_min = 1;
                    break;//只要该加油站比其便宜就行驶到那（出现问题一：不需要找到最小价格的那个加油站）
                }
            }
            //在下一段路程中找到一个加油站比其便宜时，则刚好行驶至该加油站
            if (has_min) {
                money += city[pre].price*((city[after].dist-city[pre].dist)/Davg - curOil);
                curDist = city[after].dist;
                curOil = 0;
            }
            //若未找到，则在该加油站加满，行驶至下一个最便宜的加油站（首先判断该站是否能直接到达目的地）
            else if(city[pre].dist + Cmax*Davg >= D){
                money += city[pre].price * (D-city[pre].dist)/Davg;
                break;
            }
            else{
                min = MAX;
                for (i = pre+1; city[i].dist <= maxDist && i <n; i++) {
                    if(city[i].price < min){
                        min = city[i].price;
                        after = i;
                        has_min = 1;
                    }
                }
                if(!has_min && maxDist >= D){
                    money += city[pre].price * (D-city[pre].dist)/Davg;
                    break;
                }
                else if(!has_min){
                    printf("The maximum travel distance = %.2f\n",city[pre].dist + Cmax*Davg);
                    break;
                }
                else{
                    money += city[pre].price * (Cmax-curOil);
                    curOil = Cmax - (city[after].dist-city[pre].dist)/Davg;
                    curDist = city[after].dist;
                }
            }
        }
        if ( maxDist>=D) {
            printf("%.2f\n",money);
        }
        
    }
    return 0;
}
