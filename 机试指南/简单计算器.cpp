//https://www.nowcoder.com/practice/5759c29a28cb4361bc3605979d5a6130?tpId=40&tqId=21460&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;


//定义优先级矩阵，依次表示：人为定义符号（优先级最低），+，——，*，/；
//第i行第j列为1表示，i行所在的运算符优先级大于j列所在优先符
//运算符相同时，先进入的更大
int prior[5][5]={
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,1,1,0,0},
    {1,1,1,0,0}
};

int main(){
    char ori[501];
    int buff,opera;
    double n1,n2,numPush;
    stack<double> num;
    stack<int> op;
    while (gets(ori))
    {//scanf 与 cin 遇到空格/制表符/回车 会停止
        if(ori[0] == '0' && ori[1] == '\0' )
            break;
        buff = 0;
        while (!num.empty())
            num.pop();
        while (!op.empty())
            op.pop();
        for (int i =0; ori[i] != '\0'; i++) {
            if (ori[i] >= '0' && ori[i] <= '9') {//入数字栈
                numPush = ori[i] - '0';
                while (ori[i+1] != ' ' && ori[i+1] != '\0' ) {
                    numPush = numPush*10 + ori[i+1]-'0';
                    i++;
                }
                num.push(numPush);
            }
            else if (ori[i] == ' ')//忽略空格
                continue;
            else{//处理符号栈
                if(ori[i] == '+')
                    buff = 1;
                else if (ori[i] == '-')
                    buff = 2;
                else if (ori[i] == '*')
                    buff = 3;
                else if (ori[i] == '/')
                    buff = 4;
                if (op.size()==0 || prior[buff][op.top()]){
                    op.push(buff);//当前符号优先级高于栈顶则入栈
                }else{
                    while (!op.empty() && !prior[buff][op.top()]) {
                        opera = op.top();
                        op.pop();
                        n2 = num.top();
                        num.pop();
                        n1 = num.top();
                        num.pop();
                        switch (opera) {
                            case 1:
                                numPush = n1 + n2;
                                break;
                            case 2:
                                numPush = n1 - n2;
                                break;
                            case 3:
                                numPush = n1 * n2;
                                break;
                            case 4:
                                numPush = n1 / n2;
                                break;
                        }
                        num.push(numPush);
                        
                    }op.push(buff);
                    
                }
                
            }
        }
        while (!op.empty()) {
            opera = op.top();
            op.pop();
            n2 = num.top();
            num.pop();
            n1 = num.top();
            num.pop();
            switch (opera) {
                case 1:
                    numPush = n1 + n2;
                    break;
                case 2:
                    numPush = n1 - n2;
                    break;
                case 3:
                    numPush = n1 * n2;
                    break;
                case 4:
                    numPush = n1 / n2;
                    break;
            }
            num.push(numPush);
        }
        printf("%.2f\n",num.top());
    }
    return 0 ;
    
}
