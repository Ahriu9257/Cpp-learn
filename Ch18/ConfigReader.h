#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>

class ConfigError : public std::runtime_error
{
public:
    // 用专门的异常类型表示配置文件读取/解析错误，方便 main 统一捕获。
    explicit ConfigError(const std::string& message);
};

class ConfigReader
{
public:
    // 读取 key = value 格式的配置文件；文件打不开时抛 ConfigError。
    void load(const std::string& filename);

    // 按 key 查询字符串值；当前阶段找不到时返回空字符串。
    std::string get(const std::string& key) const;

    // 按 key 查询整数值；缺少 key 或解析失败时应抛 ConfigError。
    int get_int(const std::string& key) const;

    // 打印当前已经读取到的所有键值，便于学习阶段观察解析结果。
    void print_all() const;

private:
    // 去掉字符串首尾空白字符，保证 "key = value" 两侧空格不影响解析。
    static std::string trim(const std::string& text);

private:
    // 用哈希表保存配置项，key 负责查找，value 保留原始字符串形式。
    std::unordered_map<std::string, std::string> values_;
};
