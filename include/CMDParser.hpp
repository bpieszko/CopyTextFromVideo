#pragma once

#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "Exception.hpp"

class CMDParser
{
public:
    CMDParser(const int argc, char ** argv);
    std::string at(const std::string & key);

private:
    std::pair<std::string, std::string> getKeyValue(const int i, char ** argv) const;
    void insertKeyValue(const std::pair<std::string, std::string> & keyvalue);
    const int getArgc() const;

    int m_argc;
    std::map<std::string, std::string> m_args;
    const std::vector<std::string> m_keys;
};

class CMDException : public Exception
{
public:
    CMDException(const std::string &);
};