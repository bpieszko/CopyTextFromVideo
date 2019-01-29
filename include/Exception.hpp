#pragma once

#include <exception>

class Exception : public std::exception
{
public:
    Exception(const char * message);
    const char * what() const noexcept;

protected:
    const char * m_message;
};