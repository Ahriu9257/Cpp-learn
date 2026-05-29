#include "ConfigReader.h"

#include <fstream>
#include <iostream>
#include <sstream>

ConfigError::ConfigError(const std::string& message)
    : std::runtime_error(message)
{
}

void ConfigReader::load(const std::string& filename)
{
    // ifstream 是 RAII 对象：打开文件成功后，离开函数会自动关闭文件。
    std::ifstream file(filename);
    if (!file)
    {
        throw ConfigError("failed to open config file: " + filename);
    }

    values_.clear();

    std::string line;
    while (std::getline(file, line))
    {
        // 1. 对整行做 trim，去掉首尾空白。
        line = trim(line);
        // 2. 跳过空行，以及首字符为 '#' 的注释行。
        if(line.empty() || line[0] == '#') continue;
        // 3. 用 find('=') 找到 key 和 value 的分隔位置。
        auto pos = line.find('=');
        if (pos == std::string::npos) continue;
        // 4. 用 substr 切出 key/value，并分别 trim。
        std::string key = trim(line.substr(0, pos));
        std::string value = trim(line.substr(pos + 1));
        // 5. 把合法结果保存到 values_[key] = value。
        if(!key.empty()) values_[key] = value;
    }
}

std::string ConfigReader::get(const std::string& key) const
{
    const auto it = values_.find(key);
    if (it == values_.end())
    {
        return "";
    }
    return it->second;
}

int ConfigReader::get_int(const std::string& key) const
{
    const std::string value = get(key);
    if (value.empty())
    {
        throw ConfigError("missing int config: " + key);
    }

    // stringstream 把字符串当作输入流，适合本章练习字符串转数字。
    std::stringstream ss(value);
    int result = 0;

    if(!(ss >> result))
    {
        throw ConfigError("invalid int config: " + key + " = " + value);
    }

    char extra = '\0';
    if(ss >> extra)
    {
        throw ConfigError("invalid int config: " + key + " = " + value);
    }

    return result;
}

void ConfigReader::print_all() const
{
    for (const auto& item : values_)
    {
        std::cout << item.first << " = " << item.second << std::endl;
    }
}

std::string ConfigReader::trim(const std::string& text)
{
    const std::string whitespace = " \t\r\n";

    // 全是空白字符时，find_first_not_of 会返回 npos。
    const std::size_t first = text.find_first_not_of(whitespace);
    if (first == std::string::npos)
    {
        return "";
    }

    const std::size_t last = text.find_last_not_of(whitespace);
    return text.substr(first, last - first + 1);
}
