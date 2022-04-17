#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int fixed_int_value;
		static const int frac_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();

		Fixed &operator=(const Fixed &copy);

		void setRawBits(int const raw);
		int getRawBits(void) const;
};

#endif
