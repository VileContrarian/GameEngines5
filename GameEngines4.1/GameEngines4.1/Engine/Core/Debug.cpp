#include "Debug.h"

MessType Debug::CurrSev = MessType::TYPE_NONE;
std::string Debug::OutName = "";

void Debug::DebugInit() {
	OutName = "GameEngine1EngineLog.txt";
	std::ofstream Out;
	Out.open(OutName.c_str(), std::ios::out);
	Out.close();
	CurrSev = MessType::TYPE_FATAL_ERROR;
}
void Debug::SetSev(MessType Type_) {
	CurrSev = Type_;
}

void Debug::Info(const std::string& Mess_, const std::string& FileName_, const int Line_) {
	Log(MessType::TYPE_INFO, "[INFO]: " + Mess_, FileName_, Line_);
}
void Debug::Trace(const std::string& Mess_, const std::string& FileName_, const int Line_) {
	Log(MessType::TYPE_TRACE, "[TRACE]: " + Mess_, FileName_, Line_);
}
void Debug::Warning(const std::string& Mess_, const std::string& FileName_, const int Line_) {
	Log(MessType::TYPE_WARNING, "[WARNING]: " + Mess_, FileName_, Line_);
}
void Debug::Error(const std::string& Mess_, const std::string& FileName_, const int Line_) {
	Log(MessType::TYPE_ERROR, "[ERROR]: " + Mess_, FileName_, Line_);
}
void Debug::FatalError(const std::string& Mess_, const std::string& FileName_, const int Line_) {
	Log(MessType::TYPE_FATAL_ERROR, "[FATAL ERROR]: " + Mess_, FileName_, Line_);
}

void Debug::Log(const MessType Type_, const std::string& Mess_, const std::string& FileName_, const int Line_) {
	if (Type_ <= CurrSev && CurrSev > MessType::TYPE_NONE) {
		std::ofstream Out;
		Out.open(OutName.c_str(), std::ios::app | std::ios::out);
		Out << Mess_ << " in: " << FileName_ << " on line: " << Line_ << std::endl;
		Out.flush();
		Out.close();
	}
}
