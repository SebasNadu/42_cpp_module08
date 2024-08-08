/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:41:44 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/08 10:15:40 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <limits>

Span::Span(void) : _n(0), _container() {};

Span::Span(unsigned int n) : _n(n), _container() {};

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span(void) {};

Span &Span::operator=(Span const &rhs) {
	 if (this != &rhs) {
    this->_n = rhs.getN();
    this->_container = rhs.getContainer();
  }
  return *this;
}

unsigned int Span::getN(void) const { return this->_n; }

std::multiset<int> Span::getContainer(void) const { return this->_container; }

char const *Span::SpanFullException::what() const throw() {
	return "The container is full!";
}

char const *Span::NoSpanFoundException::what() const throw() {
	return "No span can be found!";
}

void Span::addNumber(int n) {
	if (this->_container.size() >= this->_n)
		throw SpanFullException();
	this->_container.insert(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	for (std::vector<int>::iterator it = begin; it != end; it++)
		this->addNumber(*it);
}

int	Span::shortestSpan(void) {
	if (this->_container.size() <= 1)
		throw NoSpanFoundException();

	int shortest = std::numeric_limits<int>::max();
	int diff(0);
	std::multiset<int>::iterator it = this->_container.begin();
	std::multiset<int>::iterator next = it;
	next++;

	while (next != this->_container.end()) {
		diff = *next - *it;
		if (diff < shortest)
			shortest = diff;
		++it;
		++next;
	}
	return shortest;
}

int Span::longestSpan(void)	{
	if (this->_container.size() <= 1)
		throw NoSpanFoundException();
	return (*this->_container.rbegin() - *this->_container.begin());
}
