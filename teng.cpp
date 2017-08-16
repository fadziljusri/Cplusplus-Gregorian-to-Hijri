#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

void PrintCalender(int d, int m, int y);

int main() { 

 const time_t current_time = time(NULL);
 tm * t = localtime(&current_time);
 int d = t -> tm_mday, m = (t -> tm_mon) + 1, y = (t -> tm_year) + 1900;
 PrintCalender(d, m , y);
 
}

int LastDayOfGregorianMonth(int month, int year) {
// Compute the last date of the month for the Gregorian calendar.
  
  switch (month) {
  case 2:
    if ((((year % 4) == 0) && ((year % 100) != 0))
        || ((year % 400) == 0))
      return 29;
    else
      return 28;
  case 4:
  case 6:
  case 9:
  case 11: return 30;
  default: return 31;
  }
}

int calcAbsGregorianDays(int d, int m, int y) {
 int N = d;
 for (int i = m - 1; i > 0; i--)
  N += LastDayOfGregorianMonth(i, y);

 return N + (y - 1) * 365
    + (y - 1) / 4
    - (y - 1) / 100
    + (y - 1) / 400;
}

bool IsIslamicLeapYear(int year) {
// True if year is an Islamic leap year
  
  if ((((11 * year) + 14) % 30) < 11)
    return true;
  else
    return false;
}

int LastDayOfIslamicMonth(int month, int year) {
// Last day in month during year on the Islamic calendar.

  if (((month % 2) == 1) || ((month == 12) && IsIslamicLeapYear(year)))
    return 30;
  else
    return 29;
}

const int IslamicEpoch = 227014; // Absolute date of start of Islamic calendar

int IslamicDate(int month, int day, int year) {
 return (day                      // days so far this month
            + 29 * (month - 1)       // days so far...
            + month/2                //            ...this year
            + 354 * (year - 1)       // non-leap days in prior years
            + (3 + (11 * year)) / 30 // leap days in prior years
            + IslamicEpoch);                // days before start of calendar
}

string getMonthName(int m)
{
 switch (m)
 {
  case 1:
   return "Muharram";
  case 2:
   return "Safar";
  case 3:
   return "Rabi Al-Awwal";
  case 4:
   return "Rabi Al-Akhar";
  case 5:
   return "Jumada Al-Awwal";
  case 6:
   return "Jumada Al-Akhirah";
  case 7:
   return "Rajab";
  case 8:
   return "Shaban";
  case 9:
   return "Ramadan";
  case 10:
   return "Shawwal";
  case 11:
   return "Dhul-Qadah";
  case 12:
   return "Dhul-Hijjah";
 }
 return "";
}
void PrintCalender(int d, int m, int y){
 d = calcAbsGregorianDays(d, m, y);
 int month, day, year;

 // Search forward year by year from approximate year
 year = (d - IslamicEpoch) / 355;
 
 while (d >= IslamicDate(1, 1, year))
  year++;
 
 year--;
 // Search forward month by month from Muharram
 month = 1;
 while (d > IslamicDate(month, LastDayOfIslamicMonth(month, year), year))
  month++;
 
 day = d - IslamicDate(month, 1, year) + 1;   
    
    cout<< "Today is " << day << " "<< getMonthName(month) <<endl;
    
	/* //teng edit kat sini
	if((day==14)&&(getMonthName(month)=="Safar")){
    	
    	cout<<"\tHarini 14 Safar "<<year
		<<"\n\nSo apa nasihat kau teng?";
    	
	}else if(){
		
	}else if(){
		
	}else if(){
		
	}
	*/
	system("pause");
}
