#ifndef Calendar_hpp
#define Calendar_hpp

#include "Note.hpp"
#include <vector>
#include <fstream>

class Calendar
{
private:
    Date date;
    std::vector <Note> notes;
public:
    void draw();
    void run();
    void nextMonth();
    void prevMonth();
    void inputDate();
    void printCurrentDay();
    
    void createNote();
    void deleteNote();
    void editNote();
    void deleteAllNotes();
    void saveNotes();
    void loadNotes();
    void showNote();
    void deleteRecords();
    int findNote();
    //void showNotes();
    bool checkCurrentMonth();
    
    Calendar();
    ~Calendar();
};

#endif /* Calendar_hpp */
