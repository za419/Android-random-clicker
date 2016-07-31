// Android random clicker.cpp : Defines the entry point for the console application.
// This should not be trusted with high access: it accepts the path to adb and executes it without verification.

#include "stdafx.h"
#define chdir _chdir

void usage(const char* prog);
unsigned randint(unsigned max);

int main(int argc, char* argv[])
{
	if (argc != 5)
		usage(argv[0]);
	_chdir(argv[1]);
	unsigned x_max(atoi(argv[2]));
	unsigned y_max(atoi(argv[3]));
	unsigned num(atoi(argv[4]));
	for (unsigned i = 0; i < num; ++i)
	{
		unsigned x(randint(x_max));
		unsigned y(randint(y_max));
		std::stringstream formatter;
		formatter << "adb shell input tap " << x << ' ' << y;
		system(formatter.str().c_str());
	}
    return 0;
}

