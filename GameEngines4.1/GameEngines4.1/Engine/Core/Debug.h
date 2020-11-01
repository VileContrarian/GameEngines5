#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <fstream>

enum class MessType : unsigned short {
	TYPE_NONE,
	TYPE_FATAL_ERROR,
	TYPE_ERROR,
	TYPE_WARNING,
	TYPE_TRACE,
	TYPE_INFO
};

class Debug {
public:
	Debug(const Debug&) = delete;
	Debug(Debug&&) = delete;
	Debug& operator = (const Debug&) = delete;
	Debug& operator = (Debug&&) = delete;
	
	Debug() = delete;

	static void DebugInit();
	static void SetSev(MessType Type_);

	static void Info(const std::string& Mess_, const std::string& FileName_, const int Line_);
	static void Trace(const std::string& Mess_, const std::string& FileName_, const int Line_);
	static void Warning(const std::string& Mess_, const std::string& FileName_, const int Line_);
	static void Error(const std::string& Mess_, const std::string& FileName_, const int Line_);
	static void FatalError(const std::string& Mess_, const std::string& FileName_, const int Line_);

private:
	static void Log(const MessType Type_, const std::string& Mess_, const std::string& FileName_, const int Line_);
	static MessType CurrSev;
	static std::string OutName;
};

#endif DEBUG_H