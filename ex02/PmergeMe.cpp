#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe const	&PmergeMe::operator=(const PmergeMe &copy)
{
	if (this == &copy)
		return (*this);
	this->_dataVec = copy._dataVec;
	this->_dataDeque = copy._dataDeque;
	return (*this);
}

void PmergeMe::add(int value)
{
	this->_dataVec.push_back(value);
	this->_dataDeque.push_back(value);
}

void PmergeMe::insert(std::vector<int>& sorted, int value)
{
    int left = 0, right = sorted.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (value < sorted[mid])
            right = mid;
        else
            left = mid + 1;
    }
    sorted.insert(sorted.begin() + left, value);
}
void PmergeMe::insert(std::deque<int>& sorted, int value)
{
    int left = 0, right = sorted.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (value < sorted[mid])
            right = mid;
        else
            left = mid + 1;
    }
    sorted.insert(sorted.begin() + left, value);
}

std::vector<int> PmergeMe::sortVec(std::vector<int> &container)
{
	size_t n = container.size();
	if (n <= 1)
		return container;

	std::vector<int> larger, smaller;
	larger.reserve(n/2 + n%2);
	smaller.reserve(n/2);
	for (size_t i =0; i + 1 < n; i += 2)
	{
		if (container[i] < container[i + 1])
		{
			smaller.push_back(container[i]);
			larger.push_back(container[i + 1]);
		}
		else
		{
			larger.push_back(container[i]);
			smaller.push_back(container[i + 1]);
		}
	}
	if (n % 2 == 1)
		larger.push_back(container[n - 1]);
	
	std::vector<int> sorted = sortVec(larger);
	
	for (std::vector<int>::iterator it = smaller.begin(); it != smaller.end(); ++it)
		insert(sorted, *it);
	return sorted;
}
std::deque<int> PmergeMe::sortDeque(std::deque<int> &container)
{
	size_t n = container.size();
	if (n <= 1)
		return container;

	std::deque<int> larger, smaller;
	for (size_t i =0; i + 1 < n; i += 2)
	{
		if (container[i] < container[i + 1])
		{
			smaller.push_back(container[i]);
			larger.push_back(container[i + 1]);
		}
		else
		{
			larger.push_back(container[i]);
			smaller.push_back(container[i + 1]);
		}
	}
	if (n % 2 == 1)
		larger.push_back(container[n - 1]);
	
	std::deque<int> sorted = sortDeque(larger);
	
	for (std::deque<int>::iterator it = smaller.begin(); it != smaller.end(); ++it)
		insert(sorted, *it);
	return sorted;
}

void PmergeMe::sort(void)
{
	double elapsedTimeVec;
	double elapsedTimeDeque;
	double startTime;
	double endTime;

	std::cout << "Before: ";
	for (size_t i = 0; i < _dataVec.size() && i < 4; ++i)
		std::cout << _dataVec[i] << " ";
	if (_dataVec.size() > 4)
		std::cout << "[...]";
	std::cout << std::endl;

	startTime = getTime();
	std::vector<int> sortedVec = sortVec(this->_dataVec);
	endTime = getTime();
	elapsedTimeVec = (endTime - startTime);
	startTime = getTime();
	std::deque<int> sortedDeque = sortDeque(this->_dataDeque);
	endTime = getTime();
	elapsedTimeDeque = (endTime - startTime);
	std::cout << "After: ";
	for (size_t i = 0; i < sortedVec.size() && i < 4; ++i)
		std::cout << sortedVec[i] << " ";
	if (sortedVec.size() > 4)
		std::cout << "[...]";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _dataVec.size() << " elements with std::vector : " << elapsedTimeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _dataDeque.size() << " elements with std::deque : " << elapsedTimeDeque << " us" << std::endl;
}

double	getTime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}