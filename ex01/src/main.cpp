/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:42:08 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/08 10:40:36 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.hpp"
#include "../include/Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void basicTest(void) {
	std::cout << YELLOW "\n--------Basic test-------" RESET << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--------Basic fail test: Zero size -------" RESET << std::endl;
	try {
		Span sp = Span();
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--------Basic fail test: One number -------" RESET << std::endl;
	try {
		Span sp = Span(1);
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "error: " << e.what() << RESET << std::endl;
	}
}

void	rangeTest(void) {
	std::srand(std::time(NULL));
	std::cout << YELLOW "--------Range test-------" RESET << std::endl;
	try {
		Span sp = Span(10042);
		std::vector<int> vec;
		vec.reserve(sp.getN());
		for (unsigned int i = 0; i < sp.getN(); i++) {
			vec.push_back(std::rand());
		}
		sp.addNumber(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--------Range fail test-------" RESET << std::endl;
	try {
		Span sp = Span(10000);
		std::vector<int> vec;
		vec.reserve(10042);
		for (unsigned int i = 0; i < vec.capacity(); i++) {
			vec.push_back(std::rand());
		}
		sp.addNumber(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "error: " << e.what() << RESET << std::endl;
	}
}

int	main(void) {
	basicTest();
	rangeTest();
	return (0);
}
