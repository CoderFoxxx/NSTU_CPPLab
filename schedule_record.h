#pragma once
#include "my_string.h"
#include "null_ptr.h"
#include <time.h>

class ScheduleRecord : public MyString
{
public:
	ScheduleRecord(const char* start_date, const char* end_date, bool completed);
	time_t GetStartDate() const;
	time_t GetEndDate() const;
	bool IsCompleted() const;

	void SetStartDate(const char* new_start_date);
	void SetEndDate(const char* new_end_date);
	void SetCompleted(bool completed);

	char* c_str();
private:
	time_t start_date_;
	time_t end_date_;
	bool completed_;
	time_t String2TimeT(const char* str) const;
	char* TimeT2String(time_t date) const;
};