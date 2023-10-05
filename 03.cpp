#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class function_get_count
{
public:
	function_get_count() = default;
	~function_get_count();
	int get_count();
	int get_sum();
	void operator()(const int& v)
	{
		if ((v % 3) != 1)
		{
			++count;
			sum += v;
		}
	}
private:
	int count{ 0 };
	int sum{ 0 };
};

int function_get_count::get_count()
{
	return count;
}

int function_get_count::get_sum()
{
	return sum;
}

function_get_count::~function_get_count()
{
}

std::ostream& operator << (std::ostream& l, std::vector<int>& r)
{
	for (const auto& it : r)
	{
		l << it << ' ';
	}
	return l;
}


int main()
{
	std::vector<int> v{ 4, 1, 3, 6, 25, 54 };
	function_get_count get_count;
	std::cout << "[IN]: " << v << std::endl;
	get_count = std::for_each(v.begin(), v.end(), get_count);
	
	std::cout << "[OUT]: get_sum() = " << get_count.get_sum() <<std::endl;
	std::cout << "[OUT]: get_count() = " << get_count.get_count() << std::endl;
	return 0;
}
