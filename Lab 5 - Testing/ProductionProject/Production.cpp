#include "Production.h"

bool Production::someMethod()
{
	bool result = false;
	int temp = 0;
	std::vector<int> nums;
	std::cout << "Enter Number between 1 - 46. It must not have any Duplicates, \nEnter Your Numbers: ";

	while (nums.size() != 6)
	{
		std::cin >> temp;
		nums.push_back(temp);
	}
	for (int i = 0; i < nums.size(); i++)
	{
			if (nums.at(i) < 1 || nums.at(i) > 46)
			{
				std::cout << "Too Big" << std::endl;
				result = false;
			}
	}

	auto it = std::unique(nums.begin(), nums.end());
	if (it == nums.end())
	{
		std::cout << "Correct" << std::endl;
		result = true;
	}
	else
	{
		std::cout << "Duplicates" << std::endl;
		result = false;
	}

	return result;
}