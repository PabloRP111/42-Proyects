/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:29:46 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/02 10:12:01 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() 
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
             _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
	{
        for (int i = 0; i < 4; i++) {
            if (this->_materias[i]) {
                delete this->_materias[i];
                this->_materias[i] = NULL;
            }
        }

		for (int i = 0; i < 4; i++)
        {
            if (other._materias[i])
               _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i]) {
            delete this->_materias[i];
            this->_materias[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return ;

    for (int i = 0; i < 4; i++)
    {
        if (!this->_materias[i])
        {
            _materias[i] = m;
            return ;
        }
    }
    delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type){
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
