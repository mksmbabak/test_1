#include <iostream>

using namespace std;

class Time{
public:
    Time(int hours = 0, int minutes = 0, int seconds = 0) : hours_(hours), minutes_(minutes), seconds_(seconds) {}
    friend std::ostream &operator<<(std::ostream &opr, Time &obj){
        opr << obj.hours_ << "h:" << obj.minutes_ << "m:" << obj.seconds_ << "s";
        return opr;
    }

    Time operator+(const Time &time) const{
        return Time(hours_+time.hours_, minutes_+time.minutes_, seconds_+time.seconds_);
    }

    Time operator-(const Time &time) const{
        return Time(hours_-time.hours_, minutes_-time.minutes_, seconds_-time.seconds_);
    }

    Time operator==(const Time &time) const{
        if (time.hours_ == hours_){
            if (time.minutes_ == minutes_){
                if (time.seconds_ == seconds_){
                    return true;
                }
            }
        }
    }

    operator bool(){
        return (bool)time;
    }

private:
    int hours_, minutes_, seconds_;
};



int main()
{
    Time time1(3, 15, 45);
    Time time2(1, 50, 30);

    cout << "Time 1: " << time1 << endl;
    cout << "Time 2: " << time2 << endl;

    Time sum = time1 + time2;
    cout << "Sum: " << sum << endl;

    Time difference = time1 - time2;
    cout << "Difference: " << difference << endl;

    bool areEqual = time1 == time2;
    cout << "Are equal? " << (areEqual ? "Yes" : "No") << std::endl;
}
