#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
int i;
string st[100];
char c[1001];


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

//逐个字符读入（忽略空格与回车
void readTxt1(string file){
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
    infile >> noskipws;

    while (!infile.eof())
    {
        infile >> c[i];
        cout<<c[i++]<<endl;
        
    }
    infile.close();             //关闭文件输入流
}

//逐个字符读入（包括空格与回车）
void readTxt2(string file)
{
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
    
    char c;
    while (!infile.eof())
    {
        infile>>c;
        cout<<c<<endl;
        
    }
    infile.close();             //关闭文件输入流
}

//逐个单词读入
void readTxt3(string file)
{
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
    
    while (!infile.eof())
    {
        infile>>st[i];
        cout<<st[i++]<<endl;
        
    }
    infile.close();             //关闭文件输入流
}

//在文件末尾添加
//int main(void){
//    ofstream outfile("A.txt",ios::app);//ios::app表示在原文件末尾追加
//    if(!outfile){
//        cout << "Open the file failure...\n";
//        exit(0);
//    }
//    for(int x=0;x<100;outfile << ' ' << x++);//向文件写数据
//    outfile.close();
//    return 0;
//}

int main(){
    readTxt("/Users/a_piao/Desktop/算法practice_C++/shangjiao/shangjiao/text.txt");
    cout << endl;
    ofstream out("/Users/a_piao/Desktop/算法practice_C++/shangjiao/shangjiao/out.txt");
    int j = 0;
    while(st[j] !="\0"){
        out << st[j++] << endl;
    }


    return 0;
}
