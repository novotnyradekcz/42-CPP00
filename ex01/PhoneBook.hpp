/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:17:25 by rnovotny          #+#    #+#             */
/*   Updated: 2025/05/15 14:28:37 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8

# include <iostream>
# include <limits>
# include <sstream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
	private:
		int	_id;
		Contact	_contacts[MAX_CONTACTS];
		bool	_validateField(std::string field);
		void	_displayContacts(void);
};

#endif
