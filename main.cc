#include "digits.hh"

#include <iostream>
#include <vector>
#include <thread>

std::string combineDigits(const std::vector<int>& digits)
{
	std::string str;

	for (int i = 0; i < DIGIT_HEIGHT; ++i)
	{
		for (int digit : digits)
			str += DIGITS[digit][i] + "  ";

		str += '\n';
	}

	return str;
}

int main()
{
	while (true)
	{
		std::time_t time = std::time(nullptr);
		std::tm* t = std::localtime(&time);

		int h1 = t->tm_hour / 10;
		int h2 = t->tm_hour % 10;

		int m1 = t->tm_min / 10;
		int m2 = t->tm_min % 10;

		int s1 = t->tm_sec / 10;
		int s2 = t->tm_sec % 10;

		static std::string lastDigits;

		constexpr const char* clearScreen = "\033[2J";
		std::string digits = combineDigits({ h1, h2, COLON_POS, m1, m2, COLON_POS, s1, s2 });
		if (lastDigits != digits)
			std::cout << clearScreen << digits << std::endl;

		lastDigits = digits;

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return 0;
}
