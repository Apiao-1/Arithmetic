//1083 List Grades（25) https://pintia.cn/problem-sets/994805342720868352/problems/994805383929905152
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct stu
{
    string name;
    string ID;
    int score;
};

bool Cmp(struct stu & a, struct stu & b)
{
    return a.score > b.score;
}

int main(int argc, char** argv) {
    int N;
    cin >> N;
    vector<struct stu> students;
    students.resize(N);
    for(int i=0; i<N; i++)
    {
        cin >> students[i].name >> students[i].ID >> students[i].score;
    }
    int gradeMin,gradeMax;
    cin >> gradeMin >> gradeMax;
    sort(students.begin(), students.end(), Cmp);
    bool count = false;
    for(int i=0; i<N; i++)
    {
        if(students[i].score >= gradeMin && students[i].score <= gradeMax)
        {
            cout << students[i].name << " " << students[i].ID << endl;
            count = true;
        }
    }
    if(!count)
    {
        cout << "NONE" << endl;
    }
    return 0;
}
