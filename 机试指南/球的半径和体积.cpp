//https://www.nowcoder.com/profile/2575579/codeBookDetail?submissionId=28587750
#include <iostream>
#include <math.h>
using namespace std;


int main(){
    double x0,y0,z0,x1,y1,z1;
    double Pi=acos(-1);
    while (cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1) {
        double r = sqrt(pow(x1 - x0,2) +pow(y1 - y0,2)+pow(z1 - z0,2));
        printf("%.3lf %.3lf\n",r,Pi*pow(r,3)*4/3);//注意运算符优先顺序，除放前错误
    }
    return 0;
}
