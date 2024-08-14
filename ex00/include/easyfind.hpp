/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:22:57 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/14 14:09:17 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <iostream>

template <typename T>
struct ContainerType {
    static char const *name() { return "Unknown"; }
};

template <typename T>
struct ContainerType< std::vector<T> > {
	static char const *name() { return "Vector"; }
};

template <typename T>
struct ContainerType< std::list<T> > {
	static char const *name() { return "List"; }
};

template <typename T>
struct ContainerType< std::deque<T> > {
	static char const *name() { return "Deque"; }
};

template <typename T>
struct ContainerType< std::set<T> > {
	static char const *name() { return "Set"; }
};

template <typename T>
typename T::iterator easyfind(T &container, int const &value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		std::ostringstream oss;
		oss << value;
		throw std::runtime_error("The value " + oss.str()
				+ " was not found in " + ContainerType<T>::name() + " container.");
	}
			
	return it;
}

template <typename T>
void easyprint(T &container) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << ' ';
	}
}

struct DescendingComparator {
	bool operator()(int const &lhs, int const &rhs) const {
		return lhs > rhs;
	}
};
