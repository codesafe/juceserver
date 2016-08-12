#include <stdarg.h>
#include <stdlib.h>
#include "logger.h"

Log * Log::instance = NULL;

Log::Log()
{
}

Log::~Log()
{

}

void Log::log(juce::String log)
{
	loglist.push_back(log);
}