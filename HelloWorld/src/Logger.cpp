#include "Logger.h"
#include "String.h"

namespace bear
{
	void Logger::SetLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Logger::Error(const char* message) const
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Logger::Error(const String& message) const
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Logger::Warn(const char* message) const
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Logger::Warn(const String& message) const
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Logger::Info(const char* message) const
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}

	void Logger::Info(const String& message) const
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}

	void Logger::Info(const int number) const
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]: " << number << std::endl;
	}
}