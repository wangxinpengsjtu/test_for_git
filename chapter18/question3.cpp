#include <iostream>
using namespace std;
long double sum_value()
{
	return 0;
}


template <typename T>
long double sum_value(const T& value)
{
	return value;
}

template <typename T, typename... Args>
long double sum_value(const T& value, const Args&... args)
{
	return value + sum_value(args...);
}

int main()
{
	long double sum = 0;
	int a = 1;
	double b = 2.0;
	long double c = 3.2;
	sum = sum_value(a, b, c);
	cout << sum << endl;
	return 0;
}