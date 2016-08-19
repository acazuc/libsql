#ifndef LIBSQL_EXCEPTION_H
# define LIBSQL_EXCEPTION_H

# include <stdexcept>
# include <string>

namespace libsql
{

	class Exception : public std::exception
	{

	private:
		std::string err;

	public:
		Exception(std::string str): err(str) {};
		~Exception() throw() {};
		const char *what() const throw() {return (this->err.c_str());};

	};

}

#endif
