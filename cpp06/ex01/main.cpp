/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:04:13 by pn                #+#    #+#             */
/*   Updated: 2025/07/09 14:51:29 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Serializer.hpp"

int main() {
	
	std::cout << "=== TEST SERIALIZER ===" << std::endl;
	
	Data original;
	original.id = 42;
	original.name = "Test Object";
	
	std::cout << "   Address: " << &original << std::endl;
	
	uintptr_t serialized = Serializer::serialize(&original);
	
	std::cout << "\n Serialization:" << std::endl;
	std::cout << "   Original pointer: " << &original << std::endl;
	std::cout << "   Serialized value: " << serialized << std::endl;
	
	Data* deserialized = Serializer::deserialize(serialized);
	
	std::cout << "\n Deserialization:" << std::endl;
	std::cout << "   Deserialized pointer: " << deserialized << std::endl;
	std::cout << "   Original address: " << &original << std::endl;
	
	std::cout << "\n Verification:" << std::endl;
	if (deserialized == &original) {
		std::cout << "   ✅ SUCCESS!" << std::endl;
	} else {
		std::cout << "   ❌ ERROR!" << std::endl;
		return 1;
	}
	
	std::cout << "\n Access to deserialized data:" << std::endl;
	std::cout << "   ID via deserialized: " << deserialized->id << std::endl;
	std::cout << "   Name via deserialized: " << deserialized->name << std::endl;
	
	std::cout << "\n Modification test:" << std::endl;
	deserialized->id = 100;
	deserialized->name = "Modified";
	
	std::cout << "   ID: " << original.id << std::endl;
	std::cout << "   Name: " << original.name << std::endl;
	
	std::cout << "\n Test with multiple objects:" << std::endl;
	
	Data obj1, obj2, obj3;
	obj1.id = 1; obj1.name = "first";
	obj2.id = 2; obj2.name = "second";
	obj3.id = 3; obj3.name = "third";
	
	uintptr_t ser1 = Serializer::serialize(&obj1);
	uintptr_t ser2 = Serializer::serialize(&obj2);
	uintptr_t ser3 = Serializer::serialize(&obj3);
	
	std::cout << "   obj1: " << &obj1 << " (serialized: " << ser1 << ")" << std::endl;
	std::cout << "   obj2: " << &obj2 << " (serialized: " << ser2 << ")" << std::endl;
	std::cout << "   obj3: " << &obj3 << " (serialized: " << ser3 << ")" << std::endl;
	
	Data* deser1 = Serializer::deserialize(ser1);
	Data* deser2 = Serializer::deserialize(ser2);
	Data* deser3 = Serializer::deserialize(ser3);
	
	std::cout << "   Deserialized addresses:" << std::endl;
	std::cout << "   deser1: " << deser1 << " (" << deser1->name << ")" << std::endl;
	std::cout << "   deser2: " << deser2 << " (" << deser2->name << ")" << std::endl;
	std::cout << "   deser3: " << deser3 << " (" << deser3->name << ")" << std::endl;
	
	bool all_correct = (deser1 == &obj1) && (deser2 == &obj2) && (deser3 == &obj3);
	
	std::cout << "\n Final result:" << std::endl;
	if (all_correct) {
		std::cout << "   ✅ ALL TESTS PASSED!" << std::endl;
	} else {
		std::cout << "   ❌ TESTS FAILED!" << std::endl;
		return 1;
	}
	
 std::cout << "\n Reference test with try-catch:" << std::endl;
	try {
		Data test_obj;
		test_obj.id = 999;
		test_obj.name = "Reference Test";
		
		uintptr_t ref_serialized = Serializer::serialize(&test_obj);
		Data* ref_deserialized = Serializer::deserialize(ref_serialized);
		
		Data& ref = *ref_deserialized;
		std::cout << "   Reference access - ID: " << ref.id << ", Name: " << ref.name << std::endl;
		
		ref.id = 777;
		ref.name = "Modified via ref";
		
		std::cout << "   Original after ref modification - ID: " << test_obj.id << ", Name: " << test_obj.name << std::endl;
		std::cout << "   ✅ Reference test SUCCESS!" << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "   ❌ Exception caught: " << e.what() << std::endl;
	} catch (...) {
		std::cout << "   ❌ WTF DID U DO!" << std::endl;
	}
	
	return 0;
}