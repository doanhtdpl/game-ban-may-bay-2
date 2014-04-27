#ifndef __STRING_UTILITIES_H_
#define	__STRING_UTILITIES_H_

#include <string>
#include <vector>

class StringUtilities
{
public:
	static std::vector<std::string> split(const std::string &s, char delim);

protected:
	static std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems);
};

#endif