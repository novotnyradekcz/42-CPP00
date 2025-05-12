/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:48:02 by rnovotny          #+#    #+#             */
/*   Updated: 2025/05/11 21:58:22 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

void	Contact::displayContact()
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

std::string	Contact::getFirstName()
{
	return (this->_firstName);
}

std::string	Contact::getLastName()
{
	return (this->_lastName);
}

std::string	Contact::getNickname()
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (this->_darkestSecret);
}

std::string	Contact::trimString(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}
