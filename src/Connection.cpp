#include "Connection.h"
#include "Exception.h"
#include <climits>

namespace libsql
{

	Connection::Connection(std::string sock, std::string user, std::string password, std::string database)
	{
		this->connection = NULL;
		if (!(this->connection = mysql_init(NULL)))
		{
			throw Exception("Failed to init mysql client");
		}
		if (mysql_optionsv(this->connection, MYSQL_SET_CHARSET_NAME, "utf8"))
		{
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(error);
		}
		if (mysql_optionsv(this->connection, MYSQL_INIT_COMMAND, "SET NAMES utf8"))
		{
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(error);
		}
		if (mysql_optionsv(this->connection, MYSQL_OPT_RECONNECT, "1"))
		{
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(error);
		}
		if (!(mysql_real_connect(this->connection, NULL, user.c_str(), password.c_str(), database.c_str(), 0, sock.c_str(), 0)))
		{
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(error);
		}
	}

	Connection::Connection(std::string host, std::string user, std::string password, std::string database, unsigned short port)
	{
		this->connection = NULL;
		if (!(this->connection = mysql_init(NULL)))
		{
			throw Exception("Failed to init mysql client");
		}
		if (mysql_optionsv(this->connection, MYSQL_SET_CHARSET_NAME, "utf8"))
		{
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(error);
		}
		if (mysql_optionsv(this->connection, MYSQL_INIT_COMMAND, "SET NAMES utf8"))
		{
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(error);
		}
		if (mysql_optionsv(this->connection, MYSQL_OPT_RECONNECT, "1"))
		{
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(error);
		}
		if (!(mysql_real_connect(this->connection, host.c_str(), user.c_str(), password.c_str(), database.c_str(), port, NULL, 0)))
		{
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(error);
		}
	}

	Connection::~Connection()
	{
		mysql_close(this->connection);
	}

	void Connection::setAutocommit(bool autocommit)
	{
		if (mysql_autocommit(this->connection, autocommit ? 1 : 0))
		{
			std::string error = mysql_error(this->connection);
			throw Exception(error);
		}
	}

	Statement *Connection::prepare(std::string &request)
	{
		return (new Statement(*this, request));
	}

}
