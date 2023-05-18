#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.hpp"

const int MIN_PER_HR = 60;

bool new_customer(double x);

int main(int argc, char const *argv[])
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;

    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;

    long cycle_limit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double per_hour;
    cin >> per_hour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / per_hour;

    Item temp;
    long turn_aways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cycle_limit; cycle++)
    {
        if (new_customer(min_per_cust)) // 按照设定速率均值随机新增顾客
        {
            if (line.isfull())
                // 如果队列满了就离开
                turn_aways++;
            else
            {
                // 新增一个顾客
                customers++;
                temp.set(cycle);    // 设置编号和随机服务时间
                line.enqueue(temp);
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp); // 服务完毕
            wait_time = temp.ptime();   // 下一位要等待的时间
            line_wait += cycle - temp.when();   // 记录总的等待时间
            served++;   // 服务人数加一
        }
        if (wait_time > 0)
            // 等待1分钟
            wait_time--;
        sum_line += line.queue_conut(); // 记录队列长度
    }
    
    // reporting result
    if (customers > 0)
    {
        cout << "customers accpeted: " << customers << endl;
        cout << "   customer served: " << served << endl;
        cout << "        turn aways: " << turn_aways << endl;
        cout << "average quene size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cycle_limit << endl;
        cout << " average wait time: " << (double) line_wait / served <<" minutes.\n";
    }
    else
        cout << "No customers.\n";
    cout << "Done.\n";
    return 0;
}

bool new_customer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

