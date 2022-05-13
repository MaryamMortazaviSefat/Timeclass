#include <iostream>
void menu();
using namespace std;

class Time
{
    friend istream & operator>>( istream &, Time &);
    friend ostream & operator<<( ostream &,const Time &);
public:
    Time(int hour=0,int minute=0);
    Time(int hour=0);
     void setTime(int,int);
     int gethour() const;
     int getminute() const;
     bool compare(const Time &);
     bool comparee(const Time &);
     bool change(Time &);
     string dailyTime() ;
private:
     bool check( Time &, Time &);
protected:
    int _hour;
    int _minute;
};

int main()
{
   menu();
    return 0;
}

Time::Time(int hour,int minute){
   setTime(hour,minute);
}

Time::Time(int hour)
{
    setTime(hour,0);
}

void Time::setTime(int h, int m)
{
    _hour=(h<0 || h>23) ?0:h;
    _minute=(m<0 || m>59) ?0:m;

}

int Time::gethour() const
{
    return _hour;
}

int Time::getminute() const
{
    return  _minute;
}

istream & operator>>( istream & in, Time & t){
    in>> t._hour;
    in>> t._minute;
     t.setTime(t._hour,t._minute);
    return in;
}

ostream & operator<<( ostream & out,const Time & t){
    out<< t._hour<<":"<< t._minute <<"\n";
    return out;
}

bool Time::compare(const Time &t)
{
    if(_hour==t._hour){
        if(_minute==t._minute){
                return 0;
                }else if (_minute>>t._minute){
            return 1;
        }else return -1;
    }else if (_hour>>t._hour){
        return 1;
    }else return -1;
}


bool Time::change(Time &t)
{
    _hour=t._hour;
    _minute=t._minute;
    return true;
}

bool Time::check( Time & start, Time & end){

    bool check_start=false;
    bool check_end=false;

    // check start
    if(_hour>start._hour)
    {
        check_start=true;
    }

    else if(_hour==start._hour)
    {
        if(_minute<start._minute)
       {
           check_start=false;
           return false;
       }

       else if(_minute>=start._minute)
       {
           check_start=true;
       }
    }

    else if(_hour<start._hour)
    {
        check_start=false;
        return false;
    }

    // check end
    if(_hour<end._hour)
     {
       check_end=true;
     }

    else if(_hour==end._hour)
    {
         if(_minute<=end._minute)
         {
             check_end=true;
         }
         else if(_minute>end._minute)
         {
             check_end=false;
             return false;
         }
    }

    else if(_hour>end._hour)
    {
        check_end=false;
        return false;
    }

    if(check_start && check_end)
    {
        return true;
    }

     return false;
}

string Time::dailyTime()
{
    Time s(0,0);
    Time e(11,59);
    if(this->check(s,e)==1)
    {return "morning";}

    s.setTime(12,1);
    e.setTime(16,59);
    if(this->check(s,e)==1)
    {return "afternoon";}

    s.setTime(17,0);
    e.setTime(19,59);
    if(this->check(s,e)==1)
    {return "evening";}

    s.setTime(12,0);
    if(this->compare(s)==0)
    {return "noon";}

    return "night";
}



void menu(){
    Time t(0,0);
    Time t1(0,0);
    string cnt="yes";
    while(cnt=="yes" || cnt=="Yes" || cnt=="YES" || cnt=="YEs" || cnt=="yES"  || cnt=="yeS" || cnt=="yEs" || cnt=="YeS"){

    int option=-1;
    cout<<"enter the number "<<"\n";
    cout<<"1.enter time"<<"\n";
    cout<<"2.change the end time:"<<"\n";
    cout<<"3.compare two times:"<<"\n";
    cout<<"4.check daily time:"<<"\n";

    cin>>option;

    if(option==1){
       cout<<"enter the hour & minute of time:"<<"\n";
       cin>>t;
       cout<<"the time is "<<t;
    }

    if(option==2){
       cout<<"this time is:"<<t<<"enter the new time"<<"\n";
       cin>>t;
       cout<<t;
    }

    if(option==3){
        cout<<"enter the first time:"<<"\n";
        cin>>t;
        cout<<"the first time is : "<<t<<"\n";
        cout<<"enter the second time:"<<"\n";
        cin>>t1;
        cout<<"the second time is : "<<t<<"\n";
        if(t.compare(t1)==0){
            cout<<"these are equal"<<"\n";}
        else if(t.compare(t1)==1){
            cout<< t1 <<"is sooner than "<< t <<"\n";}
        else if(t.compare(t1)==-1){
            cout<< t <<" is sooner than "<< t1 <<"\n";}
    }

    if(option==4){
        cout<<"enter the hour & minute of time:"<<"\n";
        cin>>t;
        cout<<"your time is:"<<t;
        cout<<t.dailyTime()<<"\n";
    }

    cout<<"if you whant to continu enter yes"<<"\n";
    cin>>cnt;

    }


    cout<<"good job"<<"\n";
}
