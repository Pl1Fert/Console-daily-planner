#ifndef Date_hpp
#define Date_hpp

#include <string>
#include <ctime>

class Date
{
private:
    int m_day;
    int m_year;
    int m_month;
    static int m_currentDay;
    static int m_currentYear;
    static int m_currentMonth;
public:
    Date();
    ~Date();
    int getDay();
    int getMonth();
    int getYear();
    int getCurrentMonth();
    
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setCurrentDate();
    //void setDate(int,int,int);
    
    void increaseMonth();
    void decreaseMonth();
    
    std::string dateToString();
    
    static const std::string dayNames[7];
    static const std::string monthNames[12];
    static const int monthDays[12];
};

#endif /* Date_hpp */
