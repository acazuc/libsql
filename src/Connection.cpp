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
			throw Exception(0, "Failed to init mysql client");
		}
		if (mysql_optionsv(this->connection, MYSQL_SET_CHARSET_NAME, "utf8mb4"))
		{
			unsigned int err = mysql_errno(this->connection);
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(err, error);
		}
		if (mysql_optionsv(this->connection, MYSQL_INIT_COMMAND, "SET NAMES utf8mb4"))
		{
			unsigned int err = mysql_errno(this->connection);
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(err, error);
		}
		if (mysql_optionsv(this->connection, MYSQL_OPT_RECONNECT, "1"))
		{
			unsigned int err = mysql_errno(this->connection);
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(err, error);
		}
		if (!(mysql_real_connect(this->connection, NULL, user.c_str(), password.c_str(), database.c_str(), 0, sock.c_str(), 0)))
		{
			unsigned int err = mysql_errno(this->connection);
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(err, error);
		}
	}

	Connection::Connection(std::string host, std::string user, std::string password, std::string database, unsigned short port)
	{
		this->connection = NULL;
		if (!(this->connection = mysql_init(NULL)))
		{
			throw Exception(0, "Failed to init mysql client");
		}
		if (mysql_optionsv(this->connection, MYSQL_SET_CHARSET_NAME, "utf8mb4"))
		{
			unsigned int err = mysql_errno(this->connection);
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(err, error);
		}
		if (mysql_optionsv(this->connection, MYSQL_INIT_COMMAND, "SET NAMES utf8mb4"))
		{
			unsigned int err = mysql_errno(this->connection);
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(err, error);
		}
		if (mysql_optionsv(this->connection, MYSQL_OPT_RECONNECT, "1"))
		{
			unsigned int err = mysql_errno(this->connection);
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(err, error);
		}
		if (!(mysql_real_connect(this->connection, host.c_str(), user.c_str(), password.c_str(), database.c_str(), port, NULL, 0)))
		{
			unsigned int err = mysql_errno(this->connection);
			std::string error = mysql_error(this->connection);
			mysql_close(this->connection);
			throw Exception(err, error);
		}
	}

	Connection::~Connection()
	{
		mysql_close(this->connection);
	}

	void Connection::setAutocommit(bool autocommit)
	{
		if (mysql_autocommit(this->connection, autocommit ? 1 : 0))
			throw Exception(mysql_errno(this->connection), mysql_error(this->connection));
	}

	void Connection::commit()
	{
		if (mysql_commit(this->connection))
			throw Exception(mysql_errno(this->connection), mysql_error(this->connection));
	}

	void Connection::rollback()
	{
		if (mysql_rollback(this->connection))
			throw Exception(mysql_errno(this->connection), mysql_error(this->connection));
	}

	Statement *Connection::prepare(std::string &request)
	{
		return (new Statement(*this, request));
	}


	std::string Connection::getServerInfos()
	{
		const char *serverVersion = mysql_get_server_info(this->connection);
		if (!serverVersion)
			return ("");
		return (std::string(serverVersion));
	}

	std::string Connection::getClientInfos()
	{
		const char *serverVersion = mysql_get_client_info();
		if (!serverVersion)
			return ("");
		return (std::string(serverVersion));
	}

	std::string Connection::getHostInfos()
	{
		const char *serverVersion = mysql_get_host_info(this->connection);
		if (!serverVersion)
			return ("");
		return (std::string(serverVersion));
	}

}
