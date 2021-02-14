#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::vector<int> index;
	index.resize(2);
	
	bool isTarget = false;

	for (int i = 0; i < nums.size() && false == isTarget; i++) {
		int first = nums[i];
		for (int j = i + 1; j < nums.size() && false == isTarget; j++) {
			int second = nums[j];
			if (first + second == target) {
				index[0] = i;
				index[1] = j;
				isTarget = true;
			}
		}
	}

	if (isTarget == false) {
		std::cout << "There are not target added between two number in nums array!" << std::endl;
		index[0] = 0;
		index[1] = 0;
	}

	return index;
}

void main()
{
	int src[] = {2, 7, 11, 15};
	//int src[] = {3, 2, 4};
	std::vector<int> nums(std::begin(src), std::end(src));
	std::vector<int> index = twoSum(nums, 9);
	std::cout << "[" << index[0] << ", " << index[1] << "]" << std::endl;

	system("pause");
}