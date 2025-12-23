#include <iostream>
#include <algorithm>

using namespace std;

struct Student
{
    int id;
    int score;
    int chinese;
    int math;
    int english;
};

bool compare(Student a, Student b)
{
    if (a.score != b.score) return a.score > b.score;
    if (a.chinese != b.chinese) return a.chinese > b.chinese;
    return a.id < b.id;   
}

int main()
{
    int n;
    cin >> n;
    Student students[300];
    for (int i = 0; i < n; i++)
    {
        students[i].id = i + 1;
        cin >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].score = students[i].chinese + students[i].math + students[i].english;
    }    
        sort(students, students + n, compare);
        for (int j = 0; j < 5; j++)
            cout << students[j].id << " " << students[j].score << endl;
    return 0;
}