/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:57:23 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/26 08:38:39 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <exception>
# include <iostream>
# include <stack>
# include <string>

template <typename T> class MutantStack : public std::stack<T>
{
  private:
  public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator  itc;
	typedef typename std::stack<T>::container_type::reverse_iterator riterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator  ritc;

	MutantStack();
	MutantStack(const MutantStack &obj);
	virtual ~MutantStack();
	MutantStack &operator=(const MutantStack &obj);

	iterator begin();
	iterator end();

	itc begin() const;
	itc end() const;

	riterator rbegin();
	riterator rend();

	ritc rbegin() const;
	ritc rend() const;
};

# include "MutantStack.tpp"

#endif