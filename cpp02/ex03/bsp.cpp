/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:05:26 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/19 07:23:15 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {

	float x1 = a.getX().toFloat(), y1 = a.getY().toFloat();
	float x2 = b.getX().toFloat(), y2 = b.getY().toFloat();
	float x3 = c.getX().toFloat(), y3 = c.getY().toFloat();
	float x = point.getX().toFloat(), y = point.getY().toFloat();
	
	float areaABC = std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0);
	
	float areaPBC = std::abs((x*(y2-y3) + x2*(y3-y) + x3*(y-y2))/2.0);
	float areaPAC = std::abs((x1*(y-y3) + x*(y3-y1) + x3*(y1-y))/2.0);
	float areaPAB = std::abs((x1*(y2-y) + x2*(y-y1) + x*(y1-y2))/2.0);
	
	bool onEdge = (areaPBC == 0 || areaPAC == 0 || areaPAB == 0); 
	return std::abs(areaABC - (areaPBC + areaPAC + areaPAB)) <= 0 && !onEdge;
}
