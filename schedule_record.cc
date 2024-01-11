#include "schedule_record.h"
#include <sstream>
#include <ctime>

ScheduleRecord::ScheduleRecord(const char* start_date, const char* end_date, bool completed) : MyString(), completed_(completed),
		start_date_(String2TimeT(start_date)), end_date_(String2TimeT(end_date)) {
	SetString(c_str());
}

time_t ScheduleRecord::GetStartDate() const {
	return start_date_;
}

time_t ScheduleRecord::GetEndDate() const {
	return end_date_;
}

bool ScheduleRecord::IsCompleted() const {
	return completed_;
}

void ScheduleRecord::SetStartDate(const char* new_start_date) {
	start_date_ = String2TimeT(new_start_date);
	SetString(c_str());
}

void ScheduleRecord::SetEndDate(const char* new_end_date) {
	end_date_ = String2TimeT(new_end_date);
	SetString(c_str());
}

void ScheduleRecord::SetCompleted(bool completed) {
	this->completed_ = completed;
	SetString(c_str());
}

char* ScheduleRecord::c_str() {
	std::stringstream stream;
	stream << std::boolalpha << "Start Date: \"" << TimeT2String(start_date_) << "\"; End Date: \"" << TimeT2String(end_date_) << "\"; Completed: " << completed_ ? "Yes" : "No";
	char* str = new char[strlen(stream.str().c_str())];
	sprintf(str, "%s", stream.str().c_str());
	return str;
}

time_t ScheduleRecord::String2TimeT(const char* dateStr) const {
	if (dateStr != nullptr) {
		int day, month, year;
		if (sscanf(dateStr, "%d.%d.%d", &day, &month, &year) == 3) {
			struct tm timeinfo = {};
			timeinfo.tm_year = year - 1900;
			timeinfo.tm_mon = month - 1;
			timeinfo.tm_mday = day;
			timeinfo.tm_hour = 0;
			timeinfo.tm_min = 0;
			timeinfo.tm_sec = 0;

			return mktime(&timeinfo);
		}

		std::stringstream stream;
		stream << "Invalid date format. Correct date format: \"day.month.YEAR\"";
		throw std::invalid_argument(stream.str().c_str());
	}
	throw null_ptr(&dateStr);
}

char* ScheduleRecord::TimeT2String(time_t date) const {
	tm* timeinfo = localtime(&date);
	char* buffer = new char[20];
	strftime(buffer, 20, "%d.%m.%Y", timeinfo);
	return buffer;
}