/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:06:16 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/15 15:57:33 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
	#define POINT_HPP

	#include "Fixed.hpp"

	class Point {
		private:
			const Fixed x;
			const Fixed y;

		public:
			Point(void);
			Point(const float x, const float y);
			Point(const Point&);
			~Point(void);
			Point& operator=(const Point& obj);
	};

#endif