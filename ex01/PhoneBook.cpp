/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:03:06 by rnovotny          #+#    #+#             */
/*   Updated: 2025/05/15 14:52:10 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_id = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (this->_id >= MAX_CONTACTS)
		this->_id = 0;
	
	do
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
	} while (!this->_validateField(firstName));
	do
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
	} while (!this->_validateField(lastName));
	do
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickname);
	} while (!this->_validateField(nickname));
	do
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
	} while (!this->_validateField(phoneNumber));
	do
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
	} while (!this->_validateField(darkestSecret));

	this->_contacts[this->_id] = Contact(firstName, lastName, nickname,
			phoneNumber, darkestSecret);
	this->_id++;
}

void	PhoneBook::searchContact()
{
	std::string	index;
	int		i;

	if (this->_id == 0)
	{
		std::cout << "No contacts to display. Try ADDing some!" << std::endl;
		return ;
	}
	this->_displayContacts();
	std::cout << "Enter index of contact to display: ";
	
	std::getline(std::cin, index);
	if (index.empty())
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	
	std::istringstream iss(index);
	if (iss >> i && iss.eof() && i >=0 && i < this->_id)
		this->_contacts[i].displayContact();
	else
		std::cout << "Invalid index." << std::endl;
}

bool	PhoneBook::_validateField(std::string field)
{
	if (field.empty())
	{
		std::cout << "Field cannot be empty. Please try again." << std::endl;
		return false;
	}
	return true;
}

void	PhoneBook::_displayContacts(void)
{
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < this->_id; i++)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << Contact::trimString(this->_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << Contact::trimString(this->_contacts[i].getLastName()) << "|"
			<< std::setw(10) << Contact::trimString(this->_contacts[i].getNickname()) << "|" << std::endl;
	}
}
