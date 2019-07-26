#include <iostream>
#include <queue>


#include <utililty>


using namespace std;


typedef pair<double, double> student;

struct student
{
    double arrival_time, service_len;
    student(double at, double sl)
    {
        arrival_time = at;
        service_len = sl;
    }
};

int main(int argc, char *argv[])
{

    student s;

    s.first = 3.5;
    s.second = 6.0;

    queue<student> q;

    q.push(s);


    cout << "Hello World!" << endl;
    return 0;
}

