#ifndef Note_hpp
#define Note_hpp

#include <map>
#include "Date.hpp"
#include "Input.hpp"

class Note
{
private:
    std::string m_dateString;
    std::map <double,std::string> map;
    Date date;
public:    
    void setDateStringFromDate();
    void setDateString(std::string dateString);
    void setMap(double time, std::string record);
    //void recordMenu();
    void addRecord();
    void showRecords();
    void deleteRecord();
    void deleteAllRecords();
    void editRecord();
    
    //void saveNote();
    //void loadNote();
    std::string getDateString();
    std::map<double, std::string> getMap();
    
};

#endif /* Note_hpp */
