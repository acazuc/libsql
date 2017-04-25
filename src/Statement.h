#ifndef LIBSQL_STATEMENT_H
# define LIBSQL_STATEMENT_H

# include <mariadb/mysql.h>
# include <cstdint>
# include <string>

namespace libsql
{

	class Connection;

	class Statement
	{

	private:
		Connection &connection;
		MYSQL_STMT *statement;
		MYSQL_BIND *params;
		MYSQL_BIND *result;
		MYSQL_RES *meta;
		unsigned int paramsCount;
		unsigned int resultCount;
		unsigned int paramsNb;
		unsigned int resultNb;
		void putValue(MYSQL_BIND *bind, enum enum_field_types type, void *value, size_t length, size_t *len, my_bool *is_null, my_bool is_unsigned, my_bool *error);
		void addValue(enum enum_field_types type, const void *value, size_t length, size_t *len, my_bool is_unsigned);
		void getValue(enum enum_field_types type, void *value, size_t length, size_t *len, my_bool is_unsigned);

	public:
		Statement(Connection &connection, std::string &request);
		~Statement();
		void execute();
		bool fetch();
		void putBool(bool *value);
		void putInt8(int8_t *value);
		void putInt8(int8_t val);
		void putUInt8(uint8_t *value);
		void putUInt8(uint8_t val);
		void putInt16(int16_t *value);
		void putUInt16(uint16_t *value);
		void putInt32(int32_t *value);
		void putUInt32(uint32_t *value);
		void putInt64(int64_t *value);
		void putUInt64(uint64_t *value);
		void putFloat(float *value);
		void putDouble(double *value);
		void putString(const char *value, size_t *len);
		void getBool(bool *value);
		void getInt8(int8_t *value);
		void getUInt8(uint8_t *value);
		void getInt16(int16_t *value);
		void getUInt16(uint16_t *value);
		void getInt32(int32_t *value);
		void getUInt32(uint32_t *value);
		void getInt64(int64_t *value);
		void getUInt64(uint64_t *value);
		void getFloat(float *value);
		void getDouble(double *value);
		void getString(char *value, size_t *size);

	};

}

#endif
