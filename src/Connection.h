#ifndef LIBSQL_CONNECTION_H
# define LIBSQL_CONNECTION_H

# include "Statement.h"
# include <mariadb/mysql.h>
# include <string>

namespace libsql
{

	class Connection
	{

	private:
		MYSQL *connection;

	public:
		Connection(std::string sock, std::string user, std::string password, std::string database);
		Connection(std::string host, std::string user, std::string password, std::string database, unsigned short port);
		~Connection();
		void setAutocommit(bool autocommit);
		void commit();
		Statement *prepare(std::string &request);
		std::string getServerInfos();
		std::string getClientInfos();
		std::string getHostInfos();
		inline MYSQL *getConnection() {return (this->connection);};

	};

}

#endif
