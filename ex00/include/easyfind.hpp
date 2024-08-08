/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:22:57 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/07 09:35:33 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <stdexcept>

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
	if (it == container.end())
		throw std::runtime_error("The value " + std::to_string(value)
			+ " was not found in " + ContainerType<T>::name() + " container.");
			
	return it;
}

struct DescendingComparator {
	bool operator()(int const &lhs, int const &rhs) const {
		return lhs > rhs;
	}
};
