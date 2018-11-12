#ifndef LIBSQL_CONNECTION_H
# define LIBSQL_CONNECTION_H

# include <string>

namespace libsql
{

	class Statement;

	class Connection
	{

	private:

	public:
		virtual ~Connection() {};
		virtual void setAutocommit(bool autocommit) {(void)autocommit;};
		virtual void commit() {};
		virtual void rollback() {};
		virtual Statement *prepare(std::string &request) {(void)request;return nullptr;};
		virtual std::string getServerInfos() {return "";};
		virtual std::string getClientInfos() {return "";};
		virtual std::string getHostInfos() {return "";};

	};

}

#endif
