virtual bool const operator == (nr const &) const;

virtual bool const operator == (std::string const &) const;
virtual bool const operator == (char const * const) const;
//virtual bool const operator == (unsigned char const []) const;
//virtual bool const operator == (signed char const []) const;
virtual bool const operator == (char const &) const;
//virtual bool const operator == (unsigned char const &) const;
//virtual bool const operator == (signed char const &) const;

virtual bool const operator == (complex const &) const;
virtual bool const operator == (real const &) const;
virtual bool const operator == (rational const &) const;
virtual bool const operator == (integer const &) const;
virtual bool const operator == (_float const &) const;
virtual bool const operator == (short_float const &) const;
virtual bool const operator == (single_float const &) const;
virtual bool const operator == (double_float const &) const;
virtual bool const operator == (long_float const &) const;

virtual bool const operator == (long double const &) const;
virtual bool const operator == (double const &) const;
virtual bool const operator == (float const &) const;

virtual bool const operator == (unsigned long long int const &) const;
virtual bool const operator == (unsigned long int const &) const;
virtual bool const operator == (unsigned int const &) const;
virtual bool const operator == (unsigned short int const &) const;

virtual bool const operator == (signed long long int const &) const;
virtual bool const operator == (signed long int const &) const;
virtual bool const operator == (signed int const &) const;
virtual bool const operator == (signed short int const &) const;
