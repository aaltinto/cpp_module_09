#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip> 

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
	clock_t startTime;
	clock_t endTime;

	std::cout << "Before: ";
	for (size_t i = 0; i < _dataVec.size(); ++i)
	{
		if (i == 4 && _dataVec.size() > 5)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << _dataVec[i] << " ";
	}
	std::cout << std::endl;

	startTime = clock();
	std::vector<int> sortedVec = sortVec(this->_dataVec);
	endTime = clock();
	elapsedTimeVec = (endTime - startTime) / (double)CLOCKS_PER_SEC;
	startTime = clock();
	std::deque<int> sortedDeque = sortDeque(this->_dataDeque);
	endTime = clock();
	elapsedTimeDeque = (endTime - startTime) / (double)CLOCKS_PER_SEC;
	std::cout << "After: ";
	for (size_t i = 0; i < sortedVec.size(); ++i)
	{
		if (i == 4 && sortedVec.size() > 5)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << sortedVec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _dataVec.size() << " elements with std::vector : " << elapsedTimeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _dataDeque.size() << " elements with std::deque : " << elapsedTimeDeque << " us" << std::endl;
}
