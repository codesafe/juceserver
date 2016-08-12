#ifndef _LOGGER_
#define _LOGGER_

#include "../JuceLibraryCode/JuceHeader.h"

class Log
{
public:
	static Log *	instance;
	static Log *getInstance()
	{
		if (instance == NULL)
			instance = new Log();
		return instance;
	};

	void log(juce::String log);
	std::vector<juce::String>	loglist;

private:
	Log();
	~Log();
};


#endif