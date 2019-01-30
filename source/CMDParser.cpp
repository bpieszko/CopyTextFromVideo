#include "CMDParser.hpp"

CMDParser::CMDParser(const int argc, char ** argv) 
    : m_argc(argc), m_keys({"-v"})
{
    if (argc < 3)
        throw Exception("Missing arguments: -v.");

    for (int i = 1; i < argc; i += 2)
        insertKeyValue(getKeyValue(i, argv));
}

std::pair<std::string, std::string> CMDParser::getKeyValue(const int i, char ** argv) const
{
    if (i + 1 > getArgc())
        throw Exception("Size of argv is not enough to parse.");

    std::string key = argv[i];
    std::string value = argv[i + 1];

    if (key.at(0) != '-')
        throw Exception("Key value at " + std::to_string(i) + " argument is wrong. (should be key)");
       
    if (std::find(m_keys.begin(), m_keys.end(), key) == m_keys.end())
        throw Exception("Unknown key at " + std::to_string(i) + " argument.");

    return {key, value};
}

void CMDParser::insertKeyValue(const std::pair<std::string, std::string> & keyvalue)
{
    if (m_args.find(keyvalue.first) != m_args.end())
        throw Exception("Key " + keyvalue.first + " is duplicated.");

    m_args.insert(keyvalue);
}

std::string& CMDParser::at(const std::string & key)
{
    if (m_args.find(key) == m_args.end())
        throw Exception("Key " + key + " is not available.");

    return m_args.at(key);
}

const int CMDParser::getArgc() const
{
    return m_argc;
}