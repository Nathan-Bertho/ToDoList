#include "date.h"

string creation_date() 
{
    time_t temps;
    struct tm datetime;
    char  format[32];
    time(&temps);
    datetime = *localtime(&temps);
    strftime(format, 32, "%d%m%Y", &datetime);
    return format;
};