static void SetYearAndDayOfYear(RtcTime* time)
{
     int days = time->daysSince1980;
     int year = STARTING_YEAR;

     while (days > 365)
     {
	  if (IsLeapYear(year))
	  {
	       if (days > 366)
	       {
		    days -= 366;
		    year += 1;
	       }
	  }
	  else
	  {
	       days -= 365;
	       year += 1;
	  }
     }

     time->dayOfYear = days;
     time->year = year;
}

TEST(RtcTime, 2008_12_31_last_day_of_leap_year)
{
     int yearStart = daysSince1980ForYear(2008);
     rtcTime = RtcTime_Create(yearStart + 366);
     assertDate(2008, 12, 31, Wednesday);
}
