/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:01:09 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/09 12:10:27 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include "../include/colors.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename T, typename C>
void	printWithIterators(typename MutantStack<T, C>::const_iterator it,
		typename MutantStack<T, C>::const_iterator ite) {
	while (it != ite)
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << RESET << std::endl;
}

template<typename T, typename C>
void	printWithIterators(typename MutantStack<T, C>::reverse_iterator it,
		typename MutantStack<T, C>::reverse_iterator ite) {
	while (it != ite)
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << RESET << std::endl;
}

template<typename T, typename C>
void	addOneWithIterators(typename MutantStack<T, C>::iterator it,
		typename MutantStack<T, C>::iterator ite) {
	while (it != ite)
	{
		*it += 1;
		++it;
	}
}

char to_upper_adapter(char c) {
    return std::toupper(static_cast<unsigned char>(c));
}

template<typename T, typename C>
void stringUpperCaseWithIterators(typename MutantStack<T, C>::iterator it,
		typename MutantStack<T, C>::iterator ite) {
	while (it != ite)
	{
		std::transform(it->begin(), it->end(), it->begin(), to_upper_adapter);
		++it;
	}
}

void	basicTest(void) {
	{
		std::cout << YELLOW "\n--------Basic Test-------\n" RESET << std::endl;
		std::cout << YELLOW "With MutantStack:\n" RESET;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Last-in:\t";
		std::cout << GREEN << mstack.top() << RESET << std::endl;
		mstack.pop();
		std::cout << "Size after pop:\t";
		std::cout << GREEN << mstack.size() << RESET << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		std::cout << "Print Stack:\t" << GREEN;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		printWithIterators<int, std::deque<int> >(it, ite);
		std::stack<int> s(mstack);
		std::cout << "Copy Stack:\t" << GREEN;
		MutantStack<int>::iterator it2 = mstack.begin();
		MutantStack<int>::iterator ite2 = mstack.end();
		++it2;
		--it2;
		printWithIterators<int, std::deque<int> >(it2, ite2);
	}
	{
		std::cout << YELLOW "With std::list:\n" RESET;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "Last-in:\t";
		std::cout << GREEN << lst.back() << RESET << std::endl;
		lst.pop_back();
		std::cout << "Size after pop:\t";
		std::cout << GREEN << lst.size() << RESET << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		std::cout << "Print List:\t" << GREEN;
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		printWithIterators<int, std::list<int> >(it, ite);
		std::list<int> l(lst);
		std::cout << "Copy List:\t" << GREEN;
		std::list<int>::iterator it2 = l.begin();
		std::list<int>::iterator ite2 = l.end();
		++it2;
		--it2;
		printWithIterators<int, std::list<int> >(it2, ite2);
	}
}

void	charWithVectorTest(void) {
	std::cout << YELLOW "\n--------Char MuntantStack with Vector Container Test-------\n" RESET << std::endl;
	std::cout << YELLOW "Inizialize and Push alphabet...\n" RESET;
	MutantStack<char, std::vector<char> > mstack;
	for (char c = 'a'; c <= 'z'; c++)
		mstack.push(c);
	std::cout << "Last-in:\t";
	std::cout << GREEN << mstack.top() << RESET << std::endl;
	mstack.pop();
	std::cout << "Size after pop:\t";
	std::cout << GREEN << mstack.size() << RESET << std::endl;
	std::cout << "Print Stack:\t" << GREEN;
	MutantStack<char, std::vector<char> >::iterator it = mstack.begin();
	MutantStack<char, std::vector<char> >::iterator ite = mstack.end();
	printWithIterators<char, std::vector<char> >(it, ite);
	std::cout << "+1 to Stack:\t" << GREEN;
	addOneWithIterators<char, std::vector<char> >(it, ite);
	printWithIterators<char, std::vector<char> >(it, ite);
	std::cout << "Reverse Stack:\t" << GREEN;
	MutantStack<char, std::vector<char> >::reverse_iterator rit = mstack.rbegin();
	MutantStack<char, std::vector<char> >::reverse_iterator rite = mstack.rend();
	printWithIterators<char, std::vector<char> >(rit, rite);
}

void floatWithListTest(void) {
	std::cout << YELLOW "\n--------Float MuntantStack with List Container Test-------\n" RESET << std::endl;
	std::cout << YELLOW "Inizialize and Push floats...\n" RESET;
	MutantStack<float, std::list<float> > mstack;
	for (float f = 0.25; f <= 2.25; f += 0.25)
		mstack.push(f);
	std::cout << "Last-in:\t";
	std::cout << GREEN << mstack.top() << RESET << std::endl;
	mstack.pop();
	std::cout << "Size after pop:\t";
	std::cout << GREEN << mstack.size() << RESET << std::endl;
	std::cout << "Print Stack:\t" << GREEN;
	MutantStack<float, std::list<float> >::iterator it = mstack.begin();
	MutantStack<float, std::list<float> >::iterator ite = mstack.end();
	printWithIterators<float, std::list<float> >(it, ite);
	std::cout << "+1 to Stack:\t" << GREEN;
	addOneWithIterators<float, std::list<float> >(it, ite);
	printWithIterators<float, std::list<float> >(it, ite);
	std::cout << "Reverse Stack:\t" << GREEN;
	MutantStack<float, std::list<float> >::reverse_iterator rit = mstack.rbegin();
	MutantStack<float, std::list<float> >::reverse_iterator rite = mstack.rend();
	printWithIterators<float, std::list<float> >(rit, rite);
}

void stringWithMultiSetTest(void) {
	std::cout << YELLOW "\n--------String MuntantStack with Deque Container Test-------\n" RESET << std::endl;
	std::cout << YELLOW "Inizialize and Push strings...\n" RESET;
	MutantStack<std::string, std::deque<std::string> > mstack;
	mstack.push("Hello");
	mstack.push(",");
	mstack.push("42");
	mstack.push("see");
	mstack.push("you");
	mstack.push(";)");
	std::cout << "Last-in:\t";
	std::cout << GREEN << mstack.top() << RESET << std::endl;
	mstack.pop();
	std::cout << "Size after pop:\t";
	std::cout << GREEN << mstack.size() << RESET << std::endl;
	std::cout << "Print Stack:\t" << GREEN;
	MutantStack<std::string, std::deque<std::string> >::iterator it = mstack.begin();
	MutantStack<std::string, std::deque<std::string> >::iterator ite = mstack.end();
	printWithIterators<std::string, std::deque<std::string> >(it, ite);
	std::cout << "Upper Stack:\t" << GREEN;
	stringUpperCaseWithIterators<std::string, std::deque<std::string> >(it, ite);
	printWithIterators<std::string, std::deque<std::string> >(it, ite);
	std::cout << "Reverse Stack:\t" << GREEN;
	MutantStack<std::string, std::deque<std::string> >::reverse_iterator rit = mstack.rbegin();
	MutantStack<std::string, std::deque<std::string> >::reverse_iterator rite = mstack.rend();
	printWithIterators<std::string, std::deque<std::string> >(rit, rite);
}

int	main(void) {
	basicTest();
	charWithVectorTest();
	floatWithListTest();
	stringWithMultiSetTest();
	return 0;
}
