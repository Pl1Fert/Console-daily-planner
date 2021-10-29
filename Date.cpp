#include "Date.hpp"

int Date::m_currentMonth;
int Date::m_currentYear;
int Date::m_currentDay;

//------------------------Constructor & Destructor-------------------------//
Date::Date()
{
    time_t now = time(0);
    struct tm *localTime = localtime(&now);
    
    m_year = localTime -> tm_year + 1900;
    m_month = localTime -> tm_mon + 1;
    m_day = localTime -> tm_mday;
    
    m_currentDay = localTime -> tm_mday;
    m_currentYear = localTime -> tm_year + 1900;
    m_currentMonth = localTime -> tm_mon + 1;
}

Date::~Date()
{
}

//------------------------Getters-------------------------//
int Date::getDay()
{
    return m_day;
}

int Date::getYear()
{
    return m_year;
}

int Date::getMonth()
{
    return m_month;
}

int Date::getCurrentMonth()
{
    return m_currentMonth;
}

//------------------------Setters-------------------------//
void Date::setCurrentDate()
{
    m_day = m_currentDay;
    m_year = m_currentYear;
    m_month = m_currentMonth;
}

void Date::setDay(int day)
{
    m_day = day;
}

void Date::setYear(int year)
{
    m_year = year;
}

void Date::setMonth(int month)
{
    m_month = month;
}

void Date::increaseMonth()
{
    if(m_month < 12)
        m_month++;
    else
    {
        m_month = 1;
        m_year++;
    }
}

void Date::decreaseMonth()
{
    if(m_month > 1)
        m_month--;
    else
    {
        m_month = 12;
        m_year--;
    }
}

std::string Date::dateToString()
{
    std::string str;
    str = std::to_string(m_day) + "-" + std::to_string(m_month) + "-" + std::to_string(m_year);
    return str;
}

//------------------------Data for printing calendar-------------------------//
const std::string Date::dayNames[7] = {
    "Mon",
    "Tue",
    "Wen",
    "Thu",
    "Fri",
    "Sat",
    "Sun"
};

const std::string Date::monthNames[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const int Date::monthDays[12] = {
    31,28,31,30,31,30,
    31,31,30,31,30,31,
};











//void Date::setDate(int day,int month,int year)
//{
//    m_month = month;
//    m_year = year;
//    m_day = day;
//}
