#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <list>
#include <algorithm>

template <typename T>
class PmergeMe
{
	private:
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &);
		PmergeMe &operator=(PmergeMe const &);
		~PmergeMe();
		static void	merge(T &seq);
};

template <>
class PmergeMe<std::vector<int> >
{
	private:

	public:
		PmergeMe() {}
		PmergeMe(PmergeMe const &) {}
		PmergeMe &operator=(PmergeMe const &) { return *this; }
		~PmergeMe() {}
		static void	merge(std::vector<int> &seq)
		{
			if (seq.size() <= 1)
				return ;

			std::vector<int> small;
			std::vector<int> large;
			for (size_t i = 0; i + 1 < seq.size(); i += 2)
			{
				if (seq[i] < seq[i + 1])
				{
					small.push_back(seq[i]);
					large.push_back(seq[i + 1]);
				}
				else
				{
					small.push_back(seq[i + 1]);
					large.push_back(seq[i]);
				}
			}
			if (seq.size() % 2 != 0)
				small.push_back(seq.back());
			PmergeMe<std::vector<int> >::merge(small);
			for (std::vector<int>::iterator it= large.begin(); it != large.end(); it++)
			{
				std::vector<int>::iterator	pos;
				pos = std::upper_bound(small.begin(), small.end(), *it);
				small.insert(pos, *it);
			}
			seq = small;
		}
};

template <>
class PmergeMe<std::deque<int> >
{
	private:

	public:
		PmergeMe() {}
		PmergeMe(PmergeMe const &) {}
		PmergeMe &operator=(PmergeMe const &) { return *this; }
		~PmergeMe() {}
		static void	merge(std::deque<int> &seq)
		{
			if (seq.size() <= 1)
				return ;

			std::deque<int> small;
			std::deque<int> large;
			for (std::deque<int>::size_type i = 0; i + 1 < seq.size(); i += 2)
			{
				if (seq[i] < seq[i + 1])
				{
					small.push_back(seq[i]);
					large.push_back(seq[i + 1]);
				}
				else
				{
					small.push_back(seq[i + 1]);
					large.push_back(seq[i]);
				}
			}
			if (seq.size() % 2 != 0)
				small.push_back(seq.back());
			PmergeMe<std::deque<int> >::merge(small);
			for (std::deque<int>::iterator it= large.begin(); it != large.end(); it++)
			{
				std::deque<int>::iterator	pos;
				pos = std::upper_bound(small.begin(), small.end(), *it);
				small.insert(pos, *it);
			}
			seq = small;
		}
};
