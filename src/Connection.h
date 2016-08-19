#ifndef LIBSQL_CONNECTION_H
# define LIBSQL_CONNECTION_H

# include "Statement.h"
# include <mysql.h>
# include <string>

namespace libsql
{

	class Connection
	{

	private:
		MYSQL *connection;

	public:
		Connection(std::string host, std::string user, std::string password, std::string database, unsigned short port = 3306);
		~Connection();
		void setAutocommit(bool autocommit);
		Statement *prepare(std::string request);
		inline MYSQL *getConnection() {return (this->connection);};

	};

}

#endif
