#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack const &mutantStack);
	MutantStack	&operator=(MutantStack const &rhs);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin();
	iterator	end();
};

#include "MutantStack.tpp"