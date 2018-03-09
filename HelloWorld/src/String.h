#ifndef STRING_H
#define STRING_H

#include <iostream>

namespace bear
{
	typedef class String
	{
	private:
		char* m_Buffer;
		unsigned int m_Length;
	public:

		String();

		String(char);

		String(const char*);

		String(const String&);

		~String();

		unsigned int length() const;
		
		char& front() const;
		
		char& back() const;

		//unsigned int begin() const;

		//unsigned int end() const;
		
		int indexOf(char) const;
		
		int indexOf(char, unsigned int offset) const;
		
		unsigned int countOf(char) const;

		unsigned int countOf(char, unsigned int offset) const;

		String toUpperCase() const;

		String& toUpperCase(unsigned int start, unsigned int end);

		String toLowerCase() const;

		String& toLowerCase(unsigned int start, unsigned int end);

		String toggleCase() const;

		String& toggleCase(unsigned int start, unsigned int end);
		
		String& append(const char* suffix);
	
		String& append(const String& suffix);
		
		String& prepend(const char* prefix);
		
		String& prepend(const String& prefix);
		
		void resize(unsigned int size);
		
		void resize(unsigned int size, char fill);
		
		String& insert(unsigned int index, const char* insertion);

		String& insert(unsigned int index, const String& insertion);

		char operator[] (unsigned int index) const;

		//char& operator[] (unsigned int index);

		friend std::ostream& operator<<(std::ostream&, const String&);

		friend std::istream& operator>>(std::istream&, String&);

		String& operator= (const char*);

		String& operator= (const String&);

		String& operator+= (const char*);

		String& operator+= (const String&);	

		friend String operator+ (const String& lhs, const String& rhs);

		friend String operator+ (const String& lhs, const char* rhs);

		friend String operator+ (const char* lhs, const String& rhs);

		friend String operator+ (const String& lhs, char rhs);

		friend String operator+ (char lhs, const String& rhs);

		friend bool operator== (const String& lhs, const String& rhs);

		friend bool operator== (const String& lhs, const char* rhs);

		friend bool operator== (const char* lhs, const String& rhs);

		friend bool operator== (const String& lhs, char rhs);

		friend bool operator== (char lhs, const String& rhs);

		friend bool operator!= (const String& lhs, const String& rhs);

		friend bool operator!= (const String& lhs, const char* rhs);

		friend bool operator!= (const char* lhs, const String& rhs);

		friend bool operator!= (const String& lhs, char rhs);

		friend bool operator!= (char lhs, const String& rhs);

		friend bool operator> (const String& lhs, const String& rhs);

		friend bool operator> (const String& lhs, const char* rhs);

		friend bool operator> (const char* lhs, const String& rhs);

		friend bool operator> (const String& lhs, char rhs);

		friend bool operator> (char lhs, const String& rhs);

		friend bool operator< (const String& lhs, const String& rhs);

		friend bool operator< (const String& lhs, const char* rhs);

		friend bool operator< (const char* lhs, const String& rhs);

		friend bool operator< (const String& lhs, char rhs);

		friend bool operator< (char lhs, const String& rhs);

		friend bool operator>= (const String& lhs, const String& rhs);

		friend bool operator>= (const String& lhs, const char* rhs);

		friend bool operator>= (const char* lhs, const String& rhs);

		friend bool operator>= (const String& lhs, char rhs);

		friend bool operator>= (char lhs, const String& rhs);

		friend bool operator<= (const String& lhs, const String& rhs);

		friend bool operator<= (const String& lhs, const char* rhs);

		friend bool operator<= (const char* lhs, const String& rhs);

		friend bool operator<= (const String& lhs, char rhs);

		friend bool operator<= (char lhs, const String& rhs);

		bool equals(const String& other) const;

		bool equals(const char* other) const;

		bool equals(char other) const;

		bool equalsIgnoreCase(const String& other) const;

		bool startsWith(const String& other) const;

		bool startsWith(const char* other) const;

		bool startsWith(char other) const;

		bool endsWith(const String& other) const;

		bool endsWith(const char* other) const;

		bool endsWith(char other) const;

		void empty();

		void clear();

		bool isEmpty() const;

		bool isNull() const;

	} string; 
}

#endif // STRING_H