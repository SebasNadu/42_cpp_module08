/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:22:22 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/05 14:37:28 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "colors.hpp"
#include <iostream>

void	testVector(void) {
	std::cout << YELLOW "\n--------Testing vectors -------\n" RESET;
	std::vector<int> vec(8);
	int newValue = 8;
	for (int i = 0; i < 8; i++)
		vec[i] = newValue--;
	std::sort(vec.begin(), vec.end());
	std::cout << "Vector: " GREEN;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	vec.push_back(42);
	vec.push_back(42);
	vec.push_back(42);
	vec.push_back(42);
	std::cout << "Vector: " GREEN;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(vec.begin(), it) << RESET << std::endl;
		it = easyfind(vec, 42);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(vec.begin(), it) << RESET << std::endl;
		it = easyfind(vec, 99);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(vec.begin(), it) << RESET << std::endl;
	} catch (std::exception const &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
}

void	testList(void) {
	std::cout << YELLOW "\n--------Testing List -------\n" RESET;
	std::list<int> lst(8);
	int newValue = 8;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		*it = newValue--;
	lst.sort();
	std::cout << "List: " GREEN;
	std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	lst.push_front(42);
	lst.push_front(42);
	lst.push_back(42);
	lst.push_back(42);
	std::cout << "List: " GREEN;
	std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	try {
		std::list<int>::iterator it = easyfind(lst, 5);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(lst.begin(), it) << RESET << std::endl;
		it = easyfind(lst, 42);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(lst.begin(), it) << RESET << std::endl;
		it = easyfind(lst, 99);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(lst.begin(), it) << RESET << std::endl;
	} catch (std::exception const &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
}

void	testDeque(void) {
	std::cout << YELLOW "\n--------Testing Deque -------\n" RESET;
	std::deque<int> deq(8);
	int newValue = 8;
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
		*it = newValue--;
	std::sort(deq.begin(), deq.end());
	std::cout << "Deque: " GREEN;
	std::copy(deq.begin(), deq.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	deq.push_front(42);
	deq.push_front(42);
	deq.push_back(42);
	deq.push_back(42);
	std::cout << "Deque: " GREEN;
	std::copy(deq.begin(), deq.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	try {
		std::deque<int>::iterator it = easyfind(deq, 5);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(deq.begin(), it) << RESET << std::endl;
		it = easyfind(deq, 42);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(deq.begin(), it) << RESET << std::endl;
		it = easyfind(deq, 99);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(deq.begin(), it) << RESET << std::endl;
	} catch (std::exception const &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
}

void	testSet(void) {
	std::cout << YELLOW "\n--------Testing Set -------\n" RESET;
	std::set<int> set;
	for (int i = 8; i > 0; i--)
		set.insert(i);
	std::cout << "Set: " GREEN;
	std::copy(set.begin(), set.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	set.insert(42);
	set.insert(42);
	std::cout << "Set: " GREEN;
	std::copy(set.begin(), set.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	try {
		std::set<int>::iterator it = easyfind(set, 5);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(set.begin(), it) << RESET << std::endl;
		it = easyfind(set, 42);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(set.begin(), it) << RESET << std::endl;
		it = easyfind(set, 99);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(set.begin(), it) << RESET << std::endl;
	} catch (std::exception const &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}

	std::set<int, DescendingComparator> set2;
	for (int i = 8; i > 0; i--)
		set2.insert(i);
	std::cout << "\nSet2: " GREEN;
	std::copy(set2.begin(), set2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::set<int>::iterator it = set2.begin(); it != set2.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	set2.insert(42);
	set2.insert(42);
	std::cout << "Set2: " GREEN;
	std::copy(set2.begin(), set2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
	std::cout << "Address: " GREEN;
	for (std::set<int>::iterator it = set2.begin(); it != set2.end(); it++)
		std::cout << &(*it) << "\n\t ";
	std::cout << RESET << std::endl;
	try {
		std::set<int>::iterator it = easyfind(set2, 5);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(set2.begin(), it) << RESET << std::endl;
		it = easyfind(set2, 42);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(set2.begin(), it) << RESET << std::endl;
		it = easyfind(set2, 99);
		std::cout << "Value found: " GREEN << *it << RESET << " at position: " GREEN
			<< std::distance(set2.begin(), it) << RESET << std::endl;
	} catch (std::exception const &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	testVector();
	testList();
	testDeque();
	testSet();
	return (0);
}
