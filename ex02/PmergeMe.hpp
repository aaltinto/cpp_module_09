#pragma once

#include <vector>
#include <deque>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int> _dataVec;
		std::deque<int> _dataDeque;
		std::vector<int>	sortVec(std::vector<int> &container);
		std::deque<int>		sortDeque(std::deque<int> &container);
		void insert(std::deque<int>& sorted, int value);
		void insert(std::vector<int>& sorted, int value);

	public:
		/* Constructors & Destructors */
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);

		/* Basic Operators */
		PmergeMe const	&operator=(PmergeMe const &copy);

		/* Member Functions */
		void			add(int value);
		void			sort(void);
};


double	getTime(void);