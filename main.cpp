#include "Calendar.hpp"

int main()
{
    Calendar calendar;
    calendar.draw();
    calendar.printCurrentDay();
    calendar.loadNotes();
    calendar.showNote();
    calendar.run();
    return 0;
}

