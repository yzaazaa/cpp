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
		static void insertionSort(T &seq, int left, int right);
		static void	mergeSort(T &seq, int left, int mid, int right);
		static void fordJohnsonMergeInsertionSort(T &seq, int left, int right);
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
		static void insertionSort(std::vector<int> &seq, int left, int right)
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

		static void mergeSort(std::vector<int> &seq, int left, int mid, int right)
		{
			if (seq[mid] <= seq[mid + 1])
				return ;
			
			std::vector<int> temp(seq.begin() + left, seq.begin() + right + 1);

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

		static void fordJohnsonMergeInsertionSort(std::vector<int> &seq, int left, int right)
		{
			if (right - left + 1 <= 16)
			{
				PmergeMe<std::vector<int> >::insertionSort(seq, left, right);
				return ;
			}

			int mid = left + (right - left) / 2;
			fordJohnsonMergeInsertionSort(seq, left, mid);
			fordJohnsonMergeInsertionSort(seq, mid + 1, right);
			PmergeMe<std::vector<int> >::mergeSort(seq, left, mid, right);
		}
	public:
		PmergeMe() {}
		PmergeMe(PmergeMe const &) {}
		PmergeMe &operator=(PmergeMe const &) { return *this; }
		~PmergeMe() {}
		static void	merge(std::vector<int> &seq)
		{
			if (seq.size() <= 1 || std::is_sorted(seq.begin(), seq.end()))
				return ;

			fordJohnsonMergeInsertionSort(seq, 0, seq.size() - 1);
		}
};

template <>
class PmergeMe<std::deque<int> >
{
	private:
		static void	insertionSort(std::deque<int> &seq, int left, int right)
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

		static void mergeSort(std::deque<int> &seq, int left, int mid, int right)
		{
			if (seq[mid] <= seq[mid + 1])
				return ;
			
			std::deque<int> temp(seq.begin() + left, seq.begin() + right + 1);

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

		static void fordJohnsonMergeInsertionSort(std::deque<int> &seq, int left, int right)
		{
			if (right - left + 1 <= 16)
			{
				PmergeMe<std::deque<int> >::insertionSort(seq, left, right);
				return ;
			}

			int mid = left + (right - left) / 2;
			fordJohnsonMergeInsertionSort(seq, left, mid);
			fordJohnsonMergeInsertionSort(seq, mid + 1, right);
			PmergeMe<std::deque<int> >::mergeSort(seq, left, mid, right);
		}

	public:
		PmergeMe() {}
		PmergeMe(PmergeMe const &) {}
		PmergeMe &operator=(PmergeMe const &) { return *this; }
		~PmergeMe() {}
		static void	merge(std::deque<int> &seq)
		{
			if (seq.size() <= 1 || std::is_sorted(seq.begin(), seq.end()))
				return ;

			fordJohnsonMergeInsertionSort(seq, 0, seq.size() - 1);
		}
};
