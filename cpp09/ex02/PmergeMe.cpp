#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>


template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe const &) {}

template <typename T>
PmergeMe<T>	&PmergeMe<T>::operator=(PmergeMe const &) { return *this; }

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
void	PmergeMe<T>::merge(T &seq)
{
	if (seq.size() <= 1)
		return ;

	std::vector<typename T::value_type> small;
	std::vector<typename T::value_type> large;
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
	PmergeMe<T>::merge(small);
	for (typename std::vector<typename T::value_type>::iterator it= large.begin(); it != large.end(); it++)
	{
		typename std::vector<typename T::value_type>::iterator	pos;
		pos = std::upper_bound(small.begin(), small.end(), *it);
		small.insert(pos, *it);
	}
	seq = small;
}
