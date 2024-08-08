/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:02:18 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/08 10:15:16 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <set>
# include <vector>

class Span {
public:
	Span(void);
	Span(unsigned int n);
	Span(Span const &src);
	 ~Span(void);

	Span &operator=(Span const &rhs);

	unsigned int getN(void) const;
	std::multiset<int> getContainer(void) const;
	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int	shortestSpan(void);
	int	longestSpan(void);

	class SpanFullException : public std::exception {
	public:
		virtual char const *what() const throw();
	};

	class NoSpanFoundException : public std::exception {
	public:
		virtual char const *what() const throw();
	};

private:
	unsigned int _n;
	std::multiset<int> _container;

};
