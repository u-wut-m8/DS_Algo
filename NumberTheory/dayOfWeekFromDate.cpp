/*Tomohiko Sakamoto Algorithm*/

#include <iostream>

/*Number of days from last day of previous month to the end of the year
int daysToEndOfTheYear[] = {365, 334, 306, 275, 245, 214, 184, 153, 122, 92, 61, 31};
    // notice: we use our modulo formula here (a-b)%c = (a + (c - (b%c)))%c
    // days[i] = 7-(daysToTheEndOfTheYear[i]%7)
    // thanks to this we may write later
    // (lastDay + days[i]) % 7 instead of
    // (lastDay - daysToEndOfTheYear[i]) % 7
*/

int dayOfWeek(int day, int month, int year) {
    int days[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= (month <= 2) ? 1 : 0;
    return (365*year + year/4 - year/100 + year/400 + days[month-1] + day)%7;
}

int main(int argc, char const *argv[])
{
    std::cout<<dayOfWeek(13, 9, 2016)<<std::endl;
    return 0;
}
