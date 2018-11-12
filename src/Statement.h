#ifndef LIBSQL_STATEMENT_H
# define LIBSQL_STATEMENT_H

# include <cstdint>
# include <cstdlib>

namespace libsql
{

	class Statement
	{

	public:
		virtual ~Statement() {};
		virtual void execute() {};
		virtual bool fetch() {return false;};
		virtual void putBool(bool *value) {(void)value;};
		virtual void putInt8(int8_t *value) {(void)value;};
		virtual void putUInt8(uint8_t *value) {(void)value;};
		virtual void putInt16(int16_t *value) {(void)value;};
		virtual void putUInt16(uint16_t *value) {(void)value;};
		virtual void putInt32(int32_t *value) {(void)value;};
		virtual void putUInt32(uint32_t *value) {(void)value;};
		virtual void putInt64(int64_t *value) {(void)value;};
		virtual void putUInt64(uint64_t *value) {(void)value;};
		virtual void putFloat(float *value) {(void)value;};
		virtual void putDouble(double *value) {(void)value;};
		virtual void putString(const char *value, size_t *len) {(void)value;(void)len;};
		virtual void getBool(bool *value) {(void)value;};
		virtual void getInt8(int8_t *value) {(void)value;};
		virtual void getUInt8(uint8_t *value) {(void)value;};
		virtual void getInt16(int16_t *value) {(void)value;};
		virtual void getUInt16(uint16_t *value) {(void)value;};
		virtual void getInt32(int32_t *value) {(void)value;};
		virtual void getUInt32(uint32_t *value) {(void)value;};
		virtual void getInt64(int64_t *value) {(void)value;};
		virtual void getUInt64(uint64_t *value) {(void)value;};
		virtual void getFloat(float *value) {(void)value;};
		virtual void getDouble(double *value) {(void)value;};
		virtual void getString(char *value, size_t *size) {(void)value;(void)size;};

	};

}

#endif
