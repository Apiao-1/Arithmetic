//1031 Hello World for U (20)https://www.nowcoder.com/pat/5/problem/4112
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <cstring>
using namespace std;

int main(){
    char str[100];
    while (scanf("%s",str) != EOF) {
        int height = 0,bottom,i,k;
        int len = (int)strlen(str);
        for (bottom=3; bottom<len; bottom++) {
            if((len + 2 - bottom)%2 == 0){
                height = (len + 2-bottom)/2;
                if (height <= bottom) {
                    break;
                }
            }
        }
        for (i=0,k=len-1; i<height-1; i++,k--) {
            cout << str[i];
            for (int j=0; j<bottom-2; j++) {
                cout << " ";
            }
            cout << str[k] << endl;
        }
        for (int j=0;j<bottom ; j++) {
            cout << str[i++];
        }
        cout << endl;
    }
    return 0;
}
