#include "CMDParser.hpp"

CMDParser::CMDParser(const int argc, char ** argv) 
    : m_argc(argc), m_keys({"-v"})
{
    for (int i = 0; i < argc; i += 2)
        insertKeyValue(getKeyValue(i, argv));
}

std::pair<std::string, std::string> CMDParser::getKeyValue(const int i, char ** argv) const
{
    if (i + 1 > getArgc())
        throw CMDException("Size of argv is not enough to parse.");

    std::string key = argv[i];
    std::string value = argv[i + 1];

    if (key.at(0) != '-')
        throw CMDException("Key value at " + std::to_string(i) + " argument is wrong. (should be key)");
       
    if (std::find(m_keys.begin(), m_keys.end(), key) == m_keys.end())
        throw CMDException("Unknown key at " + std::to_string(i) + " argument.");

    return {key, value};
}

void CMDParser::insertKeyValue(const std::pair<std::string, std::string> & keyvalue)
{
    if (m_args.find(keyvalue.first) == m_args.end())
        throw CMDException("Key " + keyvalue.first + " is duplicated.");

    m_args.insert(keyvalue);
}

CMDException::CMDException(const std::string & message)
    : Exception(m_message)
{
    
}
