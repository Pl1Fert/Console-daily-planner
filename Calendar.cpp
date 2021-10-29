#include "Calendar.hpp"

//------------------------Constructor & Destructor-------------------------//
Calendar::Calendar()
{
}

Calendar::~Calendar()
{
    notes.clear();
}

//------------------------MAIN MENU-------------------------//
void Calendar::run()
{
    while(1)
    {
        std::cout << "\n1: Show next month" << std::endl;
        std::cout << "2: Show previous month" << std::endl;
        std::cout << "3: Show custom date" << std::endl;
        std::cout << "4: Show current month" << std::endl;
        std::cout << "5: Create note" << std::endl;
        std::cout << "6: Show note for custom date" << std::endl;
        std::cout << "7: Delete records" << std::endl;
        std::cout << "8: Edit records" << std::endl;
        std::cout << "9: Save notes" << std::endl;
        std::cout << "10: Load notes" << std::endl;
        std::cout << "0: Exit" << std::endl;
        switch (Input::getInt())
        {
            case 1:
                nextMonth();
                if(checkCurrentMonth())
                {
                    draw();
                    printCurrentDay();
                    showNote();
                }else
                    draw();
                break;
            case 2:
                prevMonth();
                if(checkCurrentMonth())
                {
                    draw();
                    printCurrentDay();
                    showNote();
                }else
                    draw();
                break;
            case 3:
                inputDate();
                draw();
                break;
            case 4:
                date.setCurrentDate();
                draw();
                printCurrentDay();
                showNote();
                break;
            case 5:
                createNote();
                break;
            case 6:
                inputDate();
                showNote();
                break;
            case 7:
                deleteRecords();
                break;
            case 8:
                editNote();
                break;
            case 9:
                saveNotes();
                break;
            case 10:
                loadNotes();
                break;
            case 0:
                return;
            default:
                break;
        }
    }
}

//------------------------Printing Month-------------------------//
void Calendar::draw()
{
    int currentYear = date.getYear();
    int currentMonth = date.getMonth();
    
    int startingDay;
    int day = 1;
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int dayCount = Date::monthDays[currentMonth - 1];
    
    //------------------Printing-------------------//
    std::cout << std::endl << Date::monthNames[currentMonth - 1];
    std::cout << " " << currentYear << std::endl;
    
    for(int i = 0; i < sizeof Date::dayNames / sizeof Date::dayNames[0];i++)
        std::cout << Date::dayNames[i] << " ";
    std::cout << std::endl;
    
    //------------------Calculating-------------------//
    if((currentYear % 400 == 0) || ((( currentYear % 4 == 0) && (currentYear % 100 != 0)) && currentMonth == 2))
        dayCount = 29;
    
    if(currentMonth < 3)
        currentYear--;
    
    startingDay = ((currentYear + currentYear / 4 - currentYear / 100 + currentYear / 400 + t[currentMonth - 1] + day) % 7) - 1;
    if(startingDay < 0)
        startingDay = 6;
    
    //std::cout << startingDay + 1 << std::endl;
    //std::cout << dayCount << std::endl;
    
    //------------------Printing-------------------//
    
    for(int i = 0; i < startingDay; i++)
    {
        std::cout << "    ";
    }
    
    for(int i = 0; i < dayCount; i++)
    {
        if(i < 9)
        {
            std::cout << "0" << i + 1 << "  ";
        }
        else
        {
            std::cout << i + 1 << "  ";
        }
        
        startingDay++;
        if(startingDay >= 7)
        {
            startingDay = 0;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void Calendar::printCurrentDay()
{
    int day = date.getDay();
    
    if(day < 9)
    {
        std::cout << "Today: " << "0" << day << std::endl;
    }
    else
    {
        std::cout << "Today: " << day << std::endl;
    }
    
}

//------------------------Checking current date-------------------------//
bool Calendar::checkCurrentMonth()
{
    if(date.getMonth() == date.getCurrentMonth())
        return true;
    return false;
}

//------------------------Setting custom date-------------------------//
void Calendar::inputDate()
{
    int day,month,year;
    std::cout << "Enter day" << std::endl;
    
    do
    {
        day = Input::getInt();
    }while(day < 1 || day > 31);

    std::cout << "Enter month" << std::endl;
    do
    {
        month = Input::getInt();
    }while(month < 1 || month > 12);

    std::cout << "Enter year" << std::endl;
    do
    {
        year = Input::getInt();
    }while(year < 0);
    
    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);
    //customDate.setDate(day,month,year);
}

//------------------------Display next month-------------------------//
void Calendar::nextMonth()
{
    date.increaseMonth();
}

//------------------------Display previous month-------------------------//
void Calendar::prevMonth()
{
    date.decreaseMonth();
}

//------------------------Creating Note-------------------------//
void Calendar::createNote()
{
    Note note;
    bool run = true;
    inputDate();
    note.setDateStringFromDate();
    while(run)
    {
        std::cout << "1: Add record" << std::endl;
        std::cout << "2: Stop" << std::endl;
        switch (Input::getInt())
        {
            case 1:
                note.addRecord();
                break;
            case 2:
                run = false;
                break;
        }
    }
    
    notes.push_back(note);
    date.setCurrentDate();
    draw();
}

//------------------------Deleting Note-------------------------//
void Calendar::deleteNote()
{
    if(notes.empty())
    {
        std::cout << "No notes" << std::endl;
        return;
    }
    int index = findNote();
    if(index == -1)
        return;
    auto iter = notes.cbegin();
    notes.erase(iter + index);
}

//------------------------Findng Note-------------------------//
int Calendar::findNote()
{
    int i = 0,index = 0;
    bool isFound = false;
    inputDate();
    for(auto & note : notes)
    {
        if(note.getDateString() == date.dateToString())
        {
            index = i;
            isFound = true;
        }
        i++;
    }
    if(!isFound)
    {
        std::cout << "No notes" << std::endl;
        return -1;
    }
    return index;
}

//------------------------Deleting all Notes-------------------------//
void Calendar::deleteAllNotes()
{    
    notes.clear();
}

//------------------------Showing Note-------------------------//
void Calendar::showNote()
{
    bool isPrinted = false;
    if(notes.empty())
    {
        std::cout << "No notes" << std::endl;
        return;
    }
    for(auto & note : notes)
    {
        if(note.getDateString() == date.dateToString())
        {
            note.showRecords();
            isPrinted = true;
        }
    }
    
    if(!isPrinted)
        std::cout << "No notes" << std::endl;
//    int index = findNote();
//    if(index == -1)
//        return;
//    notes[index].showRecords();
}

//------------------------Deleting records-------------------------//
void Calendar::deleteRecords()
{
    if(notes.empty())
    {
        std::cout << "No notes" << std::endl;
        return;
    }
    int index = findNote();
    if(index == -1)
        return;
    notes[index].showRecords();
    while(1)
    {
        std::cout << "1: Delete record" << std::endl;
        std::cout << "2: Delete all records" << std::endl;
        std::cout << "0: Exit" << std::endl;
        switch (Input::getInt())
        {
            case 1:
                notes[index].deleteRecord();
                notes[index].showRecords();
                break;
            case 2:
                notes[index].deleteAllRecords();
                notes[index].showRecords();
                break;
            case 0:
                return;
        }
    }
}

//------------------------Editing Note-------------------------//
void Calendar::editNote()
{
    if(notes.empty())
    {
        std::cout << "No notes" << std::endl;
        return;
    }
    int index = findNote();
    if(index == -1)
        return;
    notes[index].showRecords();
    while(1)
    {
        std::cout << "1: Edit records" << std::endl;
        std::cout << "0: Exit" << std::endl;
        switch (Input::getInt())
        {
            case 1:
                notes[index].editRecord();
                break;
            case 0:
                return;
        }
    }
}

//------------------------Saving Notes-------------------------//
void Calendar::saveNotes()
{
    std::ofstream file;
    
    std::string endString = "EndOfRecord";
    
    if(notes.empty())
    {
        std::cout << "No notes" << std::endl;
        return;
    }
    
    file.open("Notes.txt");
    
    if(!file.is_open())
    {
        std::cout << "Notes.txt could not be opened for reading!" << std::endl;
        return;
    }
    
    std::map<double, std::string> mapForFile;
    //найти менее затратный способ по памяти
    
    for(auto & note : notes)
    {
        file << note.getDateString() << "\n";
        //mapForFile.merge(note.getMap());
        mapForFile = note.getMap();
        std::map<double,std::string> :: iterator it = mapForFile.begin();
        for(int i = 0; it != mapForFile.end(); it++, i++)
        {
            file << std::to_string(it -> first) << "\n";
            file << it -> second << "\n";
        }
    }
    
    file << endString << "\n";
    file.close();
    
    std::cout << "Saved succesfully!" << std::endl;
}

//------------------------Loading Notes-------------------------//
void Calendar::loadNotes()
{
    std::ifstream file;
    Note note;
    notes.clear();
    
    file.open("Notes.txt");
    
    if(!file.is_open())
    {
        std::cout << "Notes.txt could not be opened for reading!" << std::endl;
        return;
    }
    
    std::string dateString;
    std::string timeString;
    std::string record;
    std::string endString;
    double time;
    while(!file.eof())
    {
        std::getline(file, dateString);
        if(file.eof())
            break;
        while(!file.eof())
        {
            std::getline(file,endString);
            if(file.eof())
                break;
            if(endString == "EndOfRecord")
            {
                break;
            }else
            {
                file.seekg(-endString.size()-1,std::ios::cur);
            }
            std::getline(file, timeString);
            std::getline(file, record);
            time = stod(timeString);
            
            note.setMap(time, record);
        }
        note.setDateString(dateString);
        notes.push_back(note);
    }
    
    file.close();
}
