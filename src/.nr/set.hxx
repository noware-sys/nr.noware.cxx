virtual nr const & operator = (nr const &);

virtual nr const & operator = (std::string const &);
virtual nr const & operator = (char const * const);
//virtual nr const & operator = (const unsigned char []);
//virtual nr const & operator = (const signed char []);
virtual nr const & operator = (char const &);
//virtual nr const & operator = (const unsigned char &);
//virtual nr const & operator = (const signed char &);

virtual nr const & operator = (complex const &);
virtual nr const & operator = (real const &);
virtual nr const & operator = (rational const &);
virtual nr const & operator = (integer const &);
virtual nr const & operator = (_float const &);
virtual nr const & operator = (short_float const &);
virtual nr const & operator = (single_float const &);
virtual nr const & operator = (double_float const &);
virtual nr const & operator = (long_float const &);

virtual nr const & operator = (long double const &);
virtual nr const & operator = (double const &);
virtual nr const & operator = (float const &);

virtual nr const & operator = (unsigned long long int const &);
virtual nr const & operator = (unsigned long int const &);
virtual nr const & operator = (unsigned int const &);
virtual nr const & operator = (unsigned short int const &);

virtual nr const & operator = (signed long long int const &);
virtual nr const & operator = (signed long int const &);
virtual nr const & operator = (signed int const &);
virtual nr const & operator = (signed short int const &);
