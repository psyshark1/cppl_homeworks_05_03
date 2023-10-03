#include <iostream>
#include <vector>
#include <functional>

class function_get_count
{
public:
	function_get_count() = default;
	~function_get_count();
	int operator()(const std::vector<int>& v)
	{
		count = 0;
		for (const auto& it : v)
		{
			if ((it % 3) != 1)
			{
				++count;
			}
		}
		return count;
	}
private:
	int count{ 0 };
};

function_get_count::~function_get_count()
{
}

int sum(const std::vector<int>& v)
{
	int sum = 0;
	for (const auto& it : v)
	{
		if ((it % 3) != 1)
		{
			sum += it;
		}
	}
	return sum;
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
	std::function<int(const std::vector<int>&)> get_sum{ sum };
	function_get_count get_count;
	std::cout << "[IN]: " << v << std::endl;
	std::cout << "[OUT]: get_sum() = " << get_sum(v) <<std::endl;
	std::cout << "[OUT]: get_count() = " << get_count(v) << std::endl;
	return 0;
}
