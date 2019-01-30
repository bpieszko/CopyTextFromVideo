#include "Exception.hpp"

Exception::Exception(const char * message)
    : m_message(message)
{

}

const char * Exception::what() const noexcept
{
    return m_message;
}