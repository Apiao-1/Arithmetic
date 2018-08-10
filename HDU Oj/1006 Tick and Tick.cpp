////1006 Tick and Tick
//
////角速度
//#define SPEED_S 6.0
//#define SPEED_M 0.1
//#define SPEED_H 1.0/120
////某时刻的角度
////#define ANGLE_S s*6
////#define ANGLE_M m*6+0.1*s
////#define ANGLE_H h*30+m*0.5+s/120.0
//
////方法一，暴力遍历，精度问题WA
//#include <iostream>
//#include <cstdio>
//#include <math.h>
//using namespace std;
//
//bool isHappy(double D,double s,double m,double h){
//    double sm = (fabs(s-m))>180 ?360-(fabs(s-m)) :(fabs(s-m));
//    double sh = (fabs(s-h))>180 ?360-(fabs(s-h)) :(fabs(s-h));
//    double mh = (fabs(m-h))>180 ?360-(fabs(m-h)) :(fabs(m-h));
//    if ( sm >=D && sh >=D && mh >=D)
//        return 1;
//    return 0;
//}
//
//int main(){
//    int count,i;
//    double s=0,m=0,h=0,D;
//    while(scanf("%lf",&D)&&D!=-1){
//        count = 0;
//        s=m=h=0;
//        for(i=0;i<3600*12;i++){
//            if (s>=360){
//               s -= 360;
//            }
//            if (m>=360){
//                m -= 360;
//            }
//            if(isHappy(D,s,m,h))
//                count++;
//            s += SPEED_S;
//            m += SPEED_M;
//            h += SPEED_H;
//        }
//        printf("%.3f\n", count/432.00);
//    }
//    return 0;
//}
//

#include<iostream>
#include<iomanip>
using namespace std;

//const double w_h=1.0/120,w_m=1./10,w_s=6.0;  //角速度
const double hm=11.0/120,hs=719.0/120,sm=59.0/10;    //相对角速度
const double T_hm=43200.0/11,T_hs=43200.0/719,T_sm=3600.0/59;   //相对周期

inline double min(double a,double b,double c)
{
    double temp=(a>b)?b:a;
    
    return (c>temp)?temp:c;
}

inline double max(double a,double b,double c)
{
    double temp=(a>b)?a:b;
    
    return (c>temp)?c:temp;
}

int main()
{
    double degree;
    double x[3],y[3];
    double m[3],n[3];
    double end,begin,sum;
    
    while(cin>>degree , degree!=-1)
    {
        x[0]=degree/hm;
        x[1]=degree/hs;
        x[2]=degree/sm;
        
        y[0]=(360-degree)/hm;
        y[1]=(360-degree)/hs;
        y[2]=(360-degree)/sm;
        
        sum=0.0;
        for(m[0]=x[0],n[0]=y[0];n[0]<=43200.000001;m[0]+=T_hm,n[0]+=T_hm)
        {
            for(m[1]=x[1],n[1]=y[1];n[1]<=43200.000001;m[1]+=T_hs,n[1]+=T_hs)
            {
                if(n[0]<m[1])
                    break;
                if(m[0]>n[1])
                    continue;
                
                for(m[2]=x[2],n[2]=y[2];n[2]<=43200.000001;m[2]+=T_sm,n[2]+=T_sm)
                {
                    if(n[0]<m[2] || n[1]<m[2])
                        break;
                    if(m[0]>n[2] || m[1]>n[2])
                        continue;
                    
                    begin=max(m[0],m[1],m[2]);
                    end=min(n[0],n[1],n[2]);
                    
                    if(end>begin)
                        sum+=end-begin;
                }
            }
        }
        
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<sum*100.0/43200<<endl;
    }  
    
    return 0;  
}
