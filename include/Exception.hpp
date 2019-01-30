#pragma once

#include <exception>
#include <string>

/*
 * @Brief:
 *      Class responsible for exceptions.
 */
class Exception
{
public:
    Exception(const std::string & message);
    const std::string& what() const noexcept;

protected:
    const std::string m_message;
};