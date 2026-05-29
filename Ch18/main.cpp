#include "ConfigReader.h"

#include <iostream>

int main()
{
    try
    {
        ConfigReader config;

        config.load("app.conf");

        std::cout << "all config values:" << std::endl;
        config.print_all();

        std::cout << "app_name = " << config.get("app_name") << std::endl;
        std::cout << "port = " << config.get_int("port") << std::endl;
    }
    catch (const ConfigError& error)
    {
        std::cout << "config error: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}
