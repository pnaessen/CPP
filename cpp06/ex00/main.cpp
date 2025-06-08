/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:19:55 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/08 16:22:07 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class CBase {
public:
    virtual ~CBase() {}
};

class CDerived : public CBase {
public:
    void sayHello() {
        std::cout << "Bonjour, je suis CDerived !" << std::endl;
    }
};

int main() {
    CBase* pBase = new CBase;
    CDerived* pDerived1 = dynamic_cast<CDerived*>(pBase);
    if (pDerived1 == NULL) {
        std::cout << "dynamic_cast a échoué : pBase n'est pas un CDerived." << std::endl;
    }

    CBase* pBase2 = new CDerived;
    CDerived* pDerived2 = dynamic_cast<CDerived*>(pBase2);
    if (pDerived2 != NULL) {
        std::cout << "dynamic_cast a réussi : pBase2 est un CDerived." << std::endl;
        pDerived2->sayHello();
    } else {
        std::cout << "dynamic_cast a échoué : pBase2 n'est pas un CDerived." << std::endl;
    }

    delete pBase;
    delete pBase2;

    return 0;
}
