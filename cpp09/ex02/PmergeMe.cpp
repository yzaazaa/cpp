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
void	PmergeMe<T>::insertionSort(T &seq, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int j = i;
		while (j > left && seq[j] < seq[j - 1])
		{
			std::swap(seq[j], seq[j - 1]);
			j--;
		}
	}
}

template <typename T>
void	PmergeMe<T>::mergeSort(T &seq, int left, int mid, int right)
{
	if (seq[mid] <= seq[mid + 1])
		return ;
	
	T temp(seq.begin() + left, seq.begin() + right + 1);

	int i = left;
	int j = mid + 1;
	for (int k = left; k <= right; k++)
	{
		if (i > mid)
			seq[k] = temp[j++ - left];
		else if (j > right)
			seq[k] = temp[i++ - left];
		else if (temp[i - left] <= temp[j - left])
			seq[k] = temp[i++ - left];
		else
			seq[k] = temp[j++ - left];
	}
}


template <typename T>
void	PmergeMe<T>::fordJohnsonMergeInsertionSort(T &seq, int left, int right)
{
	if (right - left + 1 <= 16)
	{
		insertionSort(seq, left, right);
		return ;
	}

	int mid = left + (right - left) / 2;
	fordJohnsonMergeInsertionSort(seq, left, mid);
	fordJohnsonMergeInsertionSort(seq, mid + 1, right);
	mergeSort(seq, left, mid, right);
}

template <typename T>
void	PmergeMe<T>::merge(T &seq)
{
	if (seq.size() <= 1 || std::is_sorted(seq.begin(), seq.end()))
		return ;

	fordJohnsonMergeInsertionSort(seq, 0, seq.size() - 1);
}
