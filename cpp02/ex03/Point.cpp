/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:05:41 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/16 13:33:15 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	
}

Point::Point(const Point& obj) : _x(obj.getX()), _y(obj.getY()) {
}

Point& Point::operator=(const Point&) {
	
	std::cout << "Warning: Cannot assign to Point with const members" << std::endl;
	return *this;
}

Point::~Point() {
	//std::cout << "Destructor call" << std::endl;
}

std::ostream& operator<<(std::ostream&os, const Point& Point) {
	os << "X :" << Point.getX() << "\nY :" << Point.getY();
	return os;
}
Fixed Point::getY() const {
	return _y;
}

Fixed Point::getX() const {
	return _x;
}
