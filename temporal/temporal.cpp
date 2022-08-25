#include "temporal.hpp"

#define LOG_MODULE "tempral"
#include "log.h"

namespace ww::temporal {

static uint32_t _date_to_days(uint8_t year, uint8_t month, uint8_t day) {
    uint8_t a = (14 - month) / 12;
    uint8_t y = year - a;
    uint32_t m = month + 12 * a - 3;

    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 30;
};

int32_t Date::span_get(const Date &end, TEMPORAL_UNIT_TYPE unitType) const {
    int32_t rst = _date_to_days(end.year, end.month, end.day) -
                  _date_to_days(year, month, day);
    if (unitType == TEMPORAL_UNIT_TYPE_DAY) {
        return rst;
    }
    rst = rst * 24;
    if (unitType == TEMPORAL_UNIT_TYPE_HOUR) {
        return rst;
    }
    rst = rst * 60;
    if (unitType == TEMPORAL_UNIT_TYPE_MINUTE) {
        return rst;
    }
    rst = rst * 60;
    if (unitType == TEMPORAL_UNIT_TYPE_SECOND) {
        return rst;
    }

    LOG_E("unsupported unit type: %d", unitType);
    return 0 - 1;
};
uint32_t Date::to_number(TEMPORAL_UNIT_TYPE unitType) const {
    uint32_t rst = _date_to_days(year, month, day);
    if (unitType == TEMPORAL_UNIT_TYPE_DAY) {
        return rst;
    }
    rst = rst * 24;
    if (unitType == TEMPORAL_UNIT_TYPE_HOUR) {
        return rst;
    }
    rst = rst * 60;
    if (unitType == TEMPORAL_UNIT_TYPE_MINUTE) {
        return rst;
    }
    rst = rst * 60;
    if (unitType == TEMPORAL_UNIT_TYPE_SECOND) {
        return rst;
    }

    LOG_E("unsupported unit type: %d", unitType);
    return 0 - 1;
};
bool Date::equals(const Date &other, TEMPORAL_UNIT_TYPE unitType) const {
    return year == other.year && month == other.month && day == other.day;
};

int32_t Time::span_get(const Time &end, TEMPORAL_UNIT_TYPE unitType) const {
    int32_t rst = 0;
    if (unitType == TEMPORAL_UNIT_TYPE_DAY) {
        return 0;
    }
    rst = end.hour - hour;
    if (unitType == TEMPORAL_UNIT_TYPE_HOUR) {
        return rst;
    }
    rst = rst * 60 + end.minute - minute;
    if (unitType == TEMPORAL_UNIT_TYPE_MINUTE) {
        return rst;
    }
    rst = rst * 60 + end.second - second;
    if (unitType == TEMPORAL_UNIT_TYPE_SECOND) {
        return rst;
    }

    LOG_E("unsupported unit type: %d", unitType);
    return 0 - 1;
};
uint32_t Time::to_number(TEMPORAL_UNIT_TYPE unitType) const {
    uint32_t rst = 0;
    if (unitType == TEMPORAL_UNIT_TYPE_DAY) {
        return rst;
    }
    rst = hour;
    if (unitType == TEMPORAL_UNIT_TYPE_HOUR) {
        return rst;
    }
    rst = rst * 60 + minute;
    if (unitType == TEMPORAL_UNIT_TYPE_MINUTE) {
        return rst;
    }
    rst = rst * 60 + second;
    if (unitType == TEMPORAL_UNIT_TYPE_SECOND) {
        return rst;
    }
    LOG_E("unsupported unit type: %d", unitType);
    return 0 - 1;
};
bool Time::equals(const Time &other, TEMPORAL_UNIT_TYPE unitType) const {
    bool rst = hour == other.hour;
    if (unitType == TEMPORAL_UNIT_TYPE_HOUR) {
        return rst;
    }
    rst = rst && (minute == other.minute);
    if (unitType == TEMPORAL_UNIT_TYPE_MINUTE) {
        return rst;
    }
    rst = rst && (second == other.second);
    if (unitType == TEMPORAL_UNIT_TYPE_SECOND) {
        return rst;
    }

    LOG_E("unsupported unit type: %d", unitType);
    return false;
};

int32_t DateTime::span_get(const DateTime &end,
                           TEMPORAL_UNIT_TYPE unitType) const {
    int32_t rst = _date_to_days(end.year, end.month, end.day) -
                  _date_to_days(year, month, day);
    if (unitType == TEMPORAL_UNIT_TYPE_DAY) {
        return rst;
    }
    rst = rst * 24 + end.hour - hour;
    if (unitType == TEMPORAL_UNIT_TYPE_HOUR) {
        return rst;
    }
    rst = rst * 60 + end.minute - minute;
    if (unitType == TEMPORAL_UNIT_TYPE_MINUTE) {
        return rst;
    }
    rst = rst * 60 + end.second - second;
    if (unitType == TEMPORAL_UNIT_TYPE_SECOND) {
        return rst;
    }

    LOG_E("unsupported unit type: %d", unitType);
    return 0 - 1;
};
uint32_t DateTime::to_number(TEMPORAL_UNIT_TYPE unitType) const {
    uint32_t rst = _date_to_days(year, month, day);
    if (unitType == TEMPORAL_UNIT_TYPE_DAY) {
        return rst;
    }
    rst = rst * 24 + hour;
    if (unitType == TEMPORAL_UNIT_TYPE_HOUR) {
        return rst;
    }
    rst = rst * 60 + minute;
    if (unitType == TEMPORAL_UNIT_TYPE_MINUTE) {
        return rst;
    }
    rst = rst * 60 + second;
    if (unitType == TEMPORAL_UNIT_TYPE_SECOND) {
        return rst;
    }

    LOG_E("unsupported unit type: %d", unitType);
    return 0 - 1;
};
bool DateTime::equals(const DateTime &other,
                      TEMPORAL_UNIT_TYPE unitType) const {
    bool rst = year == other.year && month == other.month && day == other.day;
    if (unitType == TEMPORAL_UNIT_TYPE_DAY) {
        return rst;
    }
    rst = rst && (hour == other.hour);
    if (unitType == TEMPORAL_UNIT_TYPE_HOUR) {
        return rst;
    }
    rst = rst && (minute == other.minute);
    if (unitType == TEMPORAL_UNIT_TYPE_MINUTE) {
        return rst;
    }
    rst = rst && (second == other.second);
    if (unitType == TEMPORAL_UNIT_TYPE_SECOND) {
        return rst;
    }

    LOG_E("unsupported unit type: %d", unitType);
    return false;
};
} // namespace ww::temporal