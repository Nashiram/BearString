#include "String.h"
#include "Logger.h"

namespace bear
{
	String::String()
	{
		m_Length = NULL;
		m_Buffer = nullptr;
	}

	String::String(char c)
	{
		m_Length = 1;
		m_Buffer = new char[2];
		m_Buffer[0] = c;
		m_Buffer[1] = '\0';
	}

	String::String(const char* string)
	{

		m_Length = strlen(string);
		m_Buffer = new char[m_Length + 1];
		memcpy(m_Buffer, string, m_Length);
		m_Buffer[m_Length] = 0;
	}

	String::String(const String& string)
	{

		m_Length = string.length();
		m_Buffer = new char[m_Length + 1];
		memcpy(m_Buffer, string.m_Buffer, m_Length);
		m_Buffer[m_Length] = 0;
	}

	String::~String()
	{
		delete[] m_Buffer;
	}

	unsigned int String::length() const
	{
		return m_Length;
	}

	char& String::front() const
	{
		return m_Buffer[0];
	}

	char& String::back() const
	{
		return m_Buffer[m_Length - 1];
	}

	int String::indexOf(char c) const
	{
		for (unsigned int i = 0; i < m_Length; i++)
		{
			if (m_Buffer[i] == c)
				return i;
		}
		return -1;
	}

	int String::indexOf(char c, unsigned int offset) const
	{
		for (unsigned int i = offset; i < m_Length; i++)
		{
			if (m_Buffer[i] == c)
				return i;
		}
		return -1;
	}

	unsigned int String::countOf(char c) const
	{
		unsigned int count = 0;
		for (unsigned int i = 0; i < m_Length; i++)
			if (m_Buffer[i] == c)
				count++;
		return count;
	}

	unsigned int String::countOf(char c, unsigned int offset) const
	{
		unsigned int count = 0;
		for (unsigned int i = offset; i < m_Length; i++)
			if (m_Buffer[i] == c)
				count++;
		return count;
	}

	String String::toUpperCase() const
	{
		String upper = String(*this);
		for (unsigned int i = 0; i < m_Length; i++)
		{
			if (upper.m_Buffer[i] >= 'a' && upper.m_Buffer[i] <= 'z')
				upper.m_Buffer[i] -= 'a' - 'A';
		}
		return upper;
	}

	String& String::toUpperCase(unsigned int start, unsigned int end)
	{
		if (start >= end || start < 0 || end > m_Length)
			throw 1;
		for (unsigned int i = start; i < end; i++)
		{
			if (m_Buffer[i] >= 'a' && m_Buffer[i] <= 'z')
				m_Buffer[i] -= 'a' - 'A';
		}
		return *this;
	}

	String String::toLowerCase() const
	{
		String lower = String(*this);
		for (unsigned int i = 0; i < m_Length; i++)
		{
			if (lower.m_Buffer[i] >= 'A' && lower.m_Buffer[i] <= 'Z')
				lower.m_Buffer[i] += 'a' - 'A';
		}
		return lower;
	}

	String& String::toLowerCase(unsigned int start, unsigned int end)
	{
		if (start >= end || start < 0 || end > m_Length)
			throw 1;
		for (unsigned int i = 0; i < m_Length; i++)
		{
			if (m_Buffer[i] >= 'A' && m_Buffer[i] <= 'Z')
				m_Buffer[i] += 'a' - 'A';
		}
		return *this;
	}

	String String::toggleCase() const
	{
		String toggled = String(*this);
		for (unsigned int i = 0; i < m_Length; i++)
		{
			if (toggled.m_Buffer[i] >= 'a' && toggled.m_Buffer[i] <= 'z')
				toggled.m_Buffer[i] -= 'a' - 'A';
			else if (toggled.m_Buffer[i] >= 'A' && toggled.m_Buffer[i] <= 'Z')
				toggled.m_Buffer[i] += 'a' - 'A';
		}
		return toggled;
	}

	String& String::toggleCase(unsigned int start, unsigned int end)
	{
		if (start >= end || start < 0 || end > m_Length)
			throw 1;
		for (unsigned int i = 0; i < m_Length; i++)
		{
			if (m_Buffer[i] >= 'a' && m_Buffer[i] <= 'z')
				m_Buffer[i] -= 'a' - 'A';
			else if (m_Buffer[i] >= 'A' && m_Buffer[i] <= 'Z')
				m_Buffer[i] += 'a' - 'A';
		}
		return *this;
	}

	String& String::append(const char* other)
	{
		unsigned int otherLength = strlen(other);
		unsigned int newLength = m_Length + otherLength;
		char* newBuffer = new char[newLength + 1];
		for (unsigned int i = 0; i < m_Length; i++)
			newBuffer[i] = m_Buffer[i];
		for (unsigned int i = 0; i < otherLength; i++)
			newBuffer[m_Length + i] = other[i];
		delete[] m_Buffer;
		m_Length = newLength;
		m_Buffer = newBuffer;
		m_Buffer[m_Length] = 0;
		return *this;
	}

	String& String::append(const String& other)
	{
		unsigned int otherLength = other.length();
		unsigned int newLength = m_Length + otherLength;
		char* newBuffer = new char[newLength + 1];
		for (unsigned int i = 0; i < m_Length; i++)
			newBuffer[i] = m_Buffer[i];
		for (unsigned int i = 0; i < otherLength; i++)
			newBuffer[m_Length + i] = other.m_Buffer[i];
		delete[] m_Buffer;
		m_Length = newLength;
		m_Buffer = newBuffer;
		m_Buffer[m_Length] = 0;
		return *this;
	}

	String& String::prepend(const char* other)
	{
		unsigned int otherLength = strlen(other);
		unsigned int newLength = m_Length + otherLength;
		char* newBuffer = new char[newLength + 1];
		for (unsigned int i = 0; i < otherLength; i++)
			newBuffer[i] = other[i];
		for (unsigned int i = 0; i < m_Length; i++)
			newBuffer[otherLength + i] = m_Buffer[i];
		delete[] m_Buffer;
		m_Length = newLength;
		m_Buffer = newBuffer;
		m_Buffer[m_Length] = 0;
		return *this;
	}

	String& String::prepend(const String& other)
	{
		unsigned int otherLength = other.length();
		unsigned int newLength = m_Length + otherLength;
		char* newBuffer = new char[newLength + 1];
		for (unsigned int i = 0; i < otherLength; i++)
			newBuffer[i] = other.m_Buffer[i];
		for (unsigned int i = 0; i < m_Length; i++)
			newBuffer[otherLength + i] = m_Buffer[i];
		delete[] m_Buffer;
		m_Length = newLength;
		m_Buffer = newBuffer;
		m_Buffer[m_Length] = 0;
		return *this;
	}

	void String::resize(unsigned int size)
	{
		char* newBuffer = new char[size + 1];
		if(size < m_Length)
			for (unsigned int i = 0; i < size; i++)
				newBuffer[i] = m_Buffer[i];
		else
		{
			for (unsigned int i = 0; i < m_Length; i++)
				newBuffer[i] = m_Buffer[i];
			for (unsigned int i = m_Length; i < size; i++)
				newBuffer[i] = '~';
		}
		delete[] m_Buffer;
		m_Length = size;
		m_Buffer = newBuffer;
		m_Buffer[m_Length] = 0;
	}

	void String::resize(unsigned int size, char fillChar)
	{
		char* newBuffer = new char[size + 1];
		if (size < m_Length)
			for (unsigned int i = 0; i < size; i++)
				newBuffer[i] = m_Buffer[i];
		else
		{
			for (unsigned int i = 0; i < m_Length; i++)
				newBuffer[i] = m_Buffer[i];
			for (unsigned int i = m_Length; i < size; i++)
				newBuffer[i] = fillChar;
		}
		delete[] m_Buffer;
		m_Length = size;
		m_Buffer = newBuffer;
		m_Buffer[m_Length] = 0;
	}

	String& String::insert(unsigned int index, const char* other)
	{
		if (index == 0)
			this->prepend(other);
		else if (index >= m_Length)
			this->append(other);
		else
		{
			unsigned int otherLength = strlen(other);
			unsigned int newLength = m_Length + otherLength;
			char* newBuffer = new char[newLength + 1];
			for (unsigned int i = 0; i < index; i++)
				newBuffer[i] = m_Buffer[i];
			for (unsigned int i = index; i < index + otherLength; i++)
				newBuffer[i] = other[i - index];
			for (unsigned int i = index; i < m_Length; i++)
				newBuffer[i + otherLength] = m_Buffer[i];
			delete[] m_Buffer;
			m_Length = newLength;
			m_Buffer = newBuffer;
			m_Buffer[m_Length] = 0;
		}	
		return *this;
	}

	String& String::insert(unsigned int index, const String& other)
	{
		if (index == 0)
			this->prepend(other);
		else if (index >= m_Length)
			this->append(other);
		else
		{
			unsigned int otherLength = other.length();
			unsigned int newLength = m_Length + otherLength;
			char* newBuffer = new char[newLength + 1];
			for (unsigned int i = 0; i < index; i++)
				newBuffer[i] = m_Buffer[i];
			for (unsigned int i = index; i < index + otherLength; i++)
				newBuffer[i] = other.m_Buffer[i - index];
			for (unsigned int i = index; i < m_Length; i++)
				newBuffer[i + otherLength] = m_Buffer[i];
			delete[] m_Buffer;
			m_Length = newLength;
			m_Buffer = newBuffer;
			m_Buffer[m_Length] = 0;
		}
		
		return *this;
	}

	char String::operator[](unsigned int index) const
	{
		if (index >= m_Length)
		{
			bear::Logger().Error("Array index out of bounds!");
			return '~';
		}
		return m_Buffer[index];
	}
	//TODO: IMPORTANT SHIT!

	//TODO: WHAT ERROR SHOULD THIS SHIT RETURN??
	//	char& String::operator[] (unsigned int index)
	//	{
	//		if (index >= m_Length)
	//		{
	//			bear::Logger().Error("Array index out of bounds!");
	//			throw 1;
	//		}
	//		return m_Buffer[index];
	//	}

	std::ostream& operator<<(std::ostream& stream, const String& string)
	{
		stream << string.m_Buffer;
		return stream;
	}

	std::istream& operator>>(std::istream& stream, String& string)
	{
		stream >> string.m_Buffer;
		return stream;
	}

	String& String::operator= (const char* other)
	{
		if (m_Buffer == other)
			return *this;

		delete[] m_Buffer;
		m_Length = strlen(other);
		m_Buffer = new char[m_Length + 1];
		memcpy(m_Buffer, other, m_Length);
		m_Buffer[m_Length] = 0;
		return *this;
	}

	String& String::operator= (const String& other)
	{
		if (this == &other)
			return *this;

		delete[] m_Buffer;
		m_Length = other.length();
		m_Buffer = new char[m_Length + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Length);
		m_Buffer[m_Length] = 0;
		return *this;
	}

	String& String::operator+= (const char* other)
	{
		return this->append(other);
	}

	String& String::operator+= (const String& other)
	{
		return this->append(other);
	}

	String operator+ (const String& lhs, const String& rhs)
	{
		return String(lhs).append(rhs);
	}

	String operator+ (const String& lhs, const char* rhs)
	{
		return String(lhs).append(rhs);
	}

	String operator+ (const char* lhs, const String& rhs)
	{
		return String(lhs).append(rhs);
	}

	String operator+ (const String& lhs, char rhs)
	{
		return String(lhs).append(rhs);
	}

	String operator+ (char lhs, const String& rhs)
	{
		return String(lhs).append(rhs);
	}

	bool operator==(const String & lhs, const String & rhs)
	{
		if (lhs.length() != rhs.length())
			return false;
		unsigned int cap = lhs.length();
		for (unsigned int i = 0; i < cap; i++)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}

	bool operator==(const String & lhs, const char * rhs)
	{
		return lhs == String(rhs);
	}

	bool operator==(const char * lhs, const String & rhs)
	{
		return String(lhs) == rhs;
	}

	bool operator==(const String & lhs, char rhs)
	{
		return lhs == String(rhs);
	}

	bool operator==(char lhs, const String & rhs)
	{
		return String(lhs) == rhs;
	}	

	bool operator!=(const String & lhs, const String & rhs)
	{
		return !(lhs == rhs);
	}

	bool operator!=(const String & lhs, const char * rhs)
	{
		return !(lhs == rhs);
	}

	bool operator!=(const char * lhs, const String & rhs)
	{
		return !(lhs == rhs);
	}

	bool operator!=(const String & lhs, char rhs)
	{
		return !(lhs == rhs);
	}

	bool operator!=(char lhs, const String & rhs)
	{
		return !(lhs == rhs);
	}

	bool operator>(const String & lhs, const String & rhs)
	{
		if (lhs.length() != rhs.length())
			return lhs.length() > rhs.length();
		unsigned int cap = lhs.length();
		for(unsigned int i = 0; i < cap; i++)
		{
			if (lhs[i] != rhs[i])
				return lhs[i] > rhs[i];
		}
		return false;
	}

	bool operator>(const String & lhs, const char * rhs)
	{
		return lhs > String(rhs);
	}

	bool operator>(const char * lhs, const String & rhs)
	{
		return String(lhs) > rhs;
	}

	bool operator>(const String & lhs, char rhs)
	{
		return lhs > String(rhs);
	}

	bool operator>(char lhs, const String & rhs)
	{
		return String(lhs) > rhs;
	}

	bool operator<(const String & lhs, const String & rhs)
	{
		return !(lhs > rhs) && !(lhs == rhs);
	}

	bool operator<(const String & lhs, const char * rhs)
	{
		return !(lhs > rhs) && !(lhs == rhs);
	}

	bool operator<(const char * lhs, const String & rhs)
	{
		return !(lhs > rhs) && !(lhs == rhs);
	}

	bool operator<(const String & lhs, char rhs)
	{
		return !(lhs > rhs) && !(lhs == rhs);
	}

	bool operator<(char lhs, const String & rhs)
	{
		return !(lhs > rhs) && !(lhs == rhs);
	}

	bool operator>=(const String & lhs, const String & rhs)
	{
		return lhs > rhs || lhs == rhs;
	}

	bool operator>=(const String & lhs, const char * rhs)
	{
		return lhs > rhs || lhs == rhs;
	}

	bool operator>=(const char * lhs, const String & rhs)
	{
		return lhs > rhs || lhs == rhs;
	}

	bool operator>=(const String & lhs, char rhs)
	{
		return lhs > rhs || lhs == rhs;
	}

	bool operator>=(char lhs, const String & rhs)
	{
		return lhs > rhs || lhs == rhs;
	}

	bool operator<=(const String & lhs, const String & rhs)
	{
		return !(lhs > rhs);
	}

	bool operator<=(const String & lhs, const char * rhs)
	{
		return !(lhs > rhs);
	}

	bool operator<=(const char * lhs, const String & rhs)
	{
		return !(lhs > rhs);
	}

	bool operator<=(const String & lhs, char rhs)
	{
		return !(lhs > rhs);
	}

	bool operator<=(char lhs, const String & rhs)
	{
		return !(lhs > rhs);
	}

	bool String::equals(const String& other) const
	{
		return *this == other;
	}

	bool String::equals(const char* other) const
	{
		return *this == String(other);
	}

	bool String::equals(char other) const
	{
		return *this == String(other);
	}

	bool String::equalsIgnoreCase(const String & other) const
	{
		return String(*this).toLowerCase() == other.toLowerCase();
	}

	bool String::startsWith(const String & other) const
	{
		unsigned int cap = other.length();
		unsigned int n = 0;
		while (n < cap && m_Buffer[n] == other.m_Buffer[n])
			n++;
		return n == cap;
	}

	bool String::startsWith(const char * other) const
	{
		unsigned int cap = strlen(other);
		unsigned int n = 0;
		while (n < cap && m_Buffer[n] == other[n])
			n++;
		return n == cap;
	}

	bool String::startsWith(char other) const
	{
		return m_Buffer[0] == other;
	}

	bool String::endsWith(const String & other) const
	{
		unsigned int cap = other.length();
		unsigned int n = m_Length;
		while (n > cap && m_Buffer[n] == other.m_Buffer[n])
			n--;
		return n == cap;
	}

	bool String::endsWith(const char * other) const
	{
		unsigned int cap = strlen(other);
		unsigned int n = m_Length;
		while (n > cap && m_Buffer[n] == other[n])
			n--;
		return n == cap;
	}

	bool String::endsWith(char other) const
	{
		return m_Buffer[m_Length - 1] == other;
	}

	void String::empty()
	{
		*this = "";
	}

	void String::clear()
	{
		delete[] m_Buffer;
		m_Buffer = nullptr;
		m_Length = NULL;
	}

	bool String::isEmpty() const
	{
		return m_Length == 0;
	}

	bool String::isNull() const
	{
		return m_Buffer == nullptr && m_Length == NULL;
	}
}