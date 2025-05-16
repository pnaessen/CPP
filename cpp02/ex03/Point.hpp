/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:06:16 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/16 09:34:18 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
	#define POINT_HPP

	#include "Fixed.hpp"

	class Point {
		private:
			const Fixed _x;
			const Fixed _y;

		public:
			Point(void);
			Point(const float x, const float y);
			Point(const Point& obj);
			~Point(void);
			Point& operator=(const Point& obj);

			Fixed getX() const;
			Fixed getY() const;
	};

#endif

std::ostream& operator<<(std::ostream&os, const Point& Point);
bool bsp(Point const a, Point const b, Point const c, Point const point);