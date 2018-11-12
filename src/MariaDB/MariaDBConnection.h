#ifndef MARIADB_CONNECTION_H
# define MARIADB_CONNECTION_H

# include "../Connection.h"
# include "../Statement.h"
# include <mariadb/mysql.h>
# include <string>

namespace libsql
{

	class MariaDBConnection : public Connection
	{

	private:
		MYSQL *connection;

	public:
		MariaDBConnection(std::string sock, std::string user, std::string password, std::string database);
		MariaDBConnection(std::string host, std::string user, std::string password, std::string database, unsigned short port);
		~MariaDBConnection();
		void setAutocommit(bool autocommit);
		void commit();
		void rollback();
		Statement *prepare(std::string &request);
		std::string getServerInfos();
		std::string getClientInfos();
		std::string getHostInfos();
		inline MYSQL *getConnection() {return this->connection;};

	};

}

#endif
