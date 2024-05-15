#include <iostream>
#include <vector>
#include <map>

#include <time.h>
#include <stdlib.h>

using namespace std;
std::vector<int> twosum2(std::vector<int> &nums, int target);
std::vector<int> twosum1(std::vector<int> &nums, int target);
int main(int argc, char *argv[])
{

	srand(time(0));
	std::vector<int> nums;
	for (size_t i = 0; i < 16; i++)
	{
		nums.push_back(random() % 16 + 1);
	}
	for (int i : nums)
		std::cout << i << " ";
	std::cout << std::endl;

	std::vector<int> res = twosum1(nums, 19);
	for (int i : res)
		std::cout << i << " ";
	std::cout << std::endl;

	return EXIT_SUCCESS;
}

std::vector<int> twosum2(std::vector<int> &nums, int target)
{
	std::vector<int> res;
	for (size_t i = 0; i < nums.size(); i++)
		for (size_t j = i + 1; j < nums.size(); j++)
			if (nums[i] + nums[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
				return res;
			}
	return std::move(res);
}

std::vector<int> twosum1(std::vector<int> &nums, int target)
{
	std::vector<int> res(2, -1);
	std::map<int, size_t> idx;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (idx.count(target - nums[i]) > 0)
		{
			res[0] = i;
			res[1] = idx[target - nums[i]];
			break;
		}
		idx[nums[i]] = i;
	}
	return std::move(res);
}
