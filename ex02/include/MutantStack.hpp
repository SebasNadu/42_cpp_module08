/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:57:59 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/08 12:57:55 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template < typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
public:
	MutantStack<T, C>(void) : std::stack<T, C>() {};
	MutantStack<T, C>(MutantStack<T, C> const &src) : std::stack<T, C>(src) {};
	~MutantStack<T, C>(void) {};

MutantStack<T, C> &operator=(MutantStack<T, C> const &rhs) {
	if (this != &rhs)
		this->c = rhs.c;
	return *this;
}

	typedef typename std::stack<T, C>::container_type::iterator 							iterator;
	typedef typename std::stack<T, C>::container_type::reverse_iterator 			reverse_iterator;
	typedef typename std::stack<T, C>::container_type::const_iterator					const_iterator;
	typedef typename std::stack<T, C>::container_type::const_reverse_iterator	const_reverse_iterator;

	MutantStack<T, C>::iterator begin(void) { return this->c.begin(); }
  MutantStack<T, C>::iterator end(void) { return this->c.end(); }
	MutantStack<T, C>::reverse_iterator rbegin(void) { return this->c.rbegin(); }
	MutantStack<T, C>::reverse_iterator rend(void) { return this->c.rend(); }
	MutantStack<T, C>::const_iterator begin(void) const { return this->c.cbegin(); }
	MutantStack<T, C>::const_iterator end(void) const { return this->c.cend(); }
	MutantStack<T, C>::const_reverse_iterator rbegin(void) const { return this->c.crbegin(); }
	MutantStack<T, C>::const_reverse_iterator rend(void) const { return this->c.crend(); }
};
