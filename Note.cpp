#include "Note.hpp"

//------------------------Setters-------------------------//
void Note::setDateStringFromDate()
{
    m_dateString = date.dateToString();
}

void Note::setDateString(std::string dateString)
{
    m_dateString = dateString;
}

void Note::setMap(double time, std::string record)
{
    map[time] = record;
}

//------------------------Getters-------------------------//
std::string Note::getDateString()
{
    return m_dateString;
}

std::map <double, std::string> Note::getMap()
{
    return map;
}

//void Note::recordMenu()
//{
//    bool run = true;
//    int choice = 0;
//    while(run)
//    {
//        std::cout << "\n1: Add record" << std::endl;
//        std::cout << "2: Delete record" << std::endl;
//        std::cout << "3: Delete all records" << std::endl;
//        //std::cout << "4: Show current month" << std::endl;
//        std::cout << "0: Exit" << std::endl;
//        choice = Input::getInt();
//        switch (choice)
//        {
//            case 1:
//                addRecord();
//                break;
//            case 2:
//                deleteRecord();
//                break;
//            case 3:
//                deleteAllRecords();
//                break;
//            case 0:
//                run = false;
//            default:
//                break;
//        }
//    }
//}

//------------------------Adding Record-------------------------//
void Note::addRecord()
{
    double time;
    std::string record;
    
    std::cout << "Enter time" << std::endl;
    time = Input::getTime();
    std::cout << "Enter record" << std::endl;
    record = Input::getString();
    
    map[time] = record;
}

//------------------------Deletin all Records-------------------------//
void Note::deleteAllRecords()
{
    map.clear();
}

//------------------------Deleting Record-------------------------//
void Note::deleteRecord()
{
    double time;
    std::cout << "Enter time of record to delete" << std::endl;
    
    time = Input::getTime();
    map.erase(time);
}

//------------------------Showing records-------------------------//
void Note::showRecords()
{
    if(map.empty())
    {
        std::cout << "No records" << std::endl;
        return;
    }
    
    std::map<double,std::string> :: iterator it = map.begin();
    
    std::cout << "\nNotes: " << std::endl;
    for(int i = 0; it != map.end(); it++, i++)
    {
        std::cout.precision(4);
        std::cout << it -> first << " : " << it -> second << std::endl;
    }
}

//------------------------Editing records-------------------------//
void Note::editRecord()
{
    double time;
    std::string record,buf;

    while(1)
    {
        std::cout << "1: Enter time of record to edit record" << std::endl;
        std::cout << "2: Enter time to change time for record" << std::endl;
        std::cout << "0: Exit" << std::endl;
        time = Input::getTime();
        switch (Input::getInt())
        {
            case 1:
                std::cout << "Enter record" << std::endl;
                record = Input::getString();
                map[time] = record;
                break;
            case 2:
                buf = map[time];
                map.erase(time);
                std::cout << "Enter a new time" << std::endl;
                time = Input::getDouble();
                map[time] = buf;
                break;
            case 0:
                return;
        }
    }
}

//void Note::saveNote()
//{
//
//}


