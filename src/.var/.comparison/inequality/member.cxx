// operator !=

const bool noware::any::operator != (const any & other) const
{
	return !(*this == other);
}
/*
const bool noware::any::operator != (const text & other) const
{
	return *this != any (other);
}
*/
const bool noware::any::operator != (const std::string & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const char other []) const
{
	return *this != any (other);
}
/*
const bool noware::any::operator != (const char *& other) const
{
	return *this != any (other);
}
*/
const bool noware::any::operator != (const char & other) const
{
	return *this != any (other);
}
/*
const bool noware::any::operator != (const signed char & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const unsigned char & other) const
{
	return *this != any (other);
}
*/
const bool noware::any::operator != (const nr & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const long double & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const double & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const float & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const signed long long int & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const unsigned long long int & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const signed long int & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const unsigned long int & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const signed int & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const unsigned int & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const signed short int & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const unsigned short int & other) const
{
	return *this != any (other);
}

const bool noware::any::operator != (const bool & other) const
{
	return *this != any (other);
}

