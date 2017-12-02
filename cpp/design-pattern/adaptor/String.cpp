#include <vector>
#include <stack>
#include <boost/algorithm/string.hpp>
#include <iostream>
using namespace  std;

class String
{
	string s;

public:
	String(const string& cs)
		: s(cs)
	{
	}

	String to_lower() const
	{
		string ss{ s };
		boost::to_lower(ss);
		return { ss };
	}

	vector<string> split(const string& delimiter = " ") const
	{
		vector<string> result;
		boost::split(result, s, boost::is_any_of(delimiter), boost::token_compress_on);
		return result;
	}
};
int main() {

	String s{ "hello   world" };
	auto parts = s.to_lower().split();
	for(const auto& p:parts)
	{
		cout << "<" << p << ">\n";
	}
	/*
	string s{ "hello   world" }; // uniform init
	boost::to_lower(s);
	vector<string> parts;
	boost::split(parts, s, boost::is_any_of(" "));

	for(const auto &p : parts)
	{
		cout << "<" << p << ">\n";
	}

	*/


	return 0;

}