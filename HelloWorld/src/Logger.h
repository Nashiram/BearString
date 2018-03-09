#ifndef LOGGER_H
#define LOGGER_H

#include "String.h"

namespace bear
{
	class Logger
	{
	public:
		enum Level
		{
			LevelError = 0, LevelWarning, LevelInfo
		};

	private:
		Level m_LogLevel = LevelInfo;

	public:

		void SetLevel(Level level);

		/// <summary><c>Error</c> is a method in the <c>Logger</c> class.  
		/// </summary>
		void Error(const char* message) const;

		void Error(const String& message) const;

		/// <remarks>Here is an example of a bulleted list:  
		/// <list type="bullet">  
		/// <item>  
		/// <description>Item 1.</description>  
		/// </item>  
		/// <item>  
		/// <description>Item 2.</description>  
		/// </item>  
		/// </list>  
		/// </remarks> 
		void Warn(const char* message) const;

		void Warn(const String& message) const;

		void Info(const char* message) const;

		void Info(const String& message) const;

		void Info(const int number) const;

	};
}

#endif // LOGGER_H