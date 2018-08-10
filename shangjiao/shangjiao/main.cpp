//计算相似度矩阵Smith-Waterman法
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
int a[30],i;
string x,y,st[100];

int findMax(int a,int b,int c, int d){
    int max = a;
    if (b > max) {
        max = b;
    }
    if(c > max){
        max = c;
    }
    if(d > max){
        max = d;
    }
    return max;
}

//逐行读入
void readTxt(string file)
{
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
    
    //    string s;
    while(getline(infile,st[i]))
    {
        cout<<st[i++]<<endl;
    }
    infile.close();             //关闭文件输入流
}

int main()
{
    int dp[20][20],rdp[20][20];
    int lenx,leny,s;
    while (cin >> y >> x) {
        lenx = (int)x.length();
        leny = (int)y.length();
        for (int i = 0; i<=lenx ; i++) {//初始化，已包括（i=0或j=0时，最长公共子序列为0）
            for (int j = 0; j<=leny ; j++) {
                dp[i][j] = 0;
                rdp[i][j] = 0;
            }
        }
        
        //直接二分
        for (int i = 1; i<=lenx; i++) {
            for (int j = 1; j <=leny; j++) {
                if (x[i-1] == y[j-1]) {//注意string是从0开始放置的，但dp数组是从1开始放的
                    s = 3;
                    //注意i,j需从1开始，否则数组会越界
                }else{
                    s = -1;
                }
                dp[i][j] = findMax(dp[i-1][j-1] +s,dp[i-1][j]-1, dp[i][j-1]-1,0);
            }
        }
        for (int i = 0; i<=lenx; i++) {
            for (int j = 0; j <=leny; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        //对称二分
        reverse(x.begin(), x.end());
        for (int i = 1; i<=lenx; i++) {
            for (int j = 1; j <=leny; j++) {
                if (x[i-1] == y[j-1]) {//注意string是从0开始放置的，但dp数组是从1开始放的
                    s = 3;
                    //注意i,j需从1开始，否则数组会越界
                }else{
                    s = -1;
                }
                rdp[i][j] = findMax(rdp[i-1][j-1] +s,rdp[i-1][j]-1, rdp[i][j-1]-1,0);
            }
        }
        for (int i = 0; i<=lenx; i++) {
            for (int j = 0; j <=leny; j++) {
                cout << rdp[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}
