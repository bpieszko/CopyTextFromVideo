#include "Exception.hpp"

Exception::Exception(const std::string & message)
    : m_message(message)
{
    
}

const std::string& Exception::what() const noexcept
{
    return m_message;
}