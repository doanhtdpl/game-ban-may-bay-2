#include "stringUtilities.h"

#include <sstream>
using namespace std;

std::vector<std::string> StringUtilities::split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

std::vector<std::string>& StringUtilities::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) 
	{
		elems.push_back(item);
	}
	return elems;
}