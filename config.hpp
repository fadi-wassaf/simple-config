#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unordered_map>

class Config {
    public:
    Config();
    Config(std::string const& config_path);

    bool foundConfig() { return found_config; }
    void readConfig(std::string const& config_path);
    template<typename T> T getValue(std::string const& key, T def);

    private:
    bool found_config;
    std::unordered_map<std::string, std::string> config_map;
};

Config::Config() { found_config = false; }
Config::Config(std::string const& config_path){ readConfig(config_path); }

/**
 * @brief Read and store the (key, value) pairs located in the config file. 
 * Skips lines that don't have an '=' character.
 * 
 * @param config_path Path to the config file.
 */
void Config::readConfig(std::string const& config_path){
    // Try to open the config file specified by the user.
    std::ifstream config_file(config_path);
    if(config_file.fail()){
        found_config = false;
        return;
    }

    found_config = true;
    std::string line;
    while(getline(config_file, line)){
        // Locate the '=' character in the current line.
        size_t eq_pos = line.find('=');
        if(eq_pos == std::string::npos)
            continue;
        
        // Store the (key, value) pair.
        std::string key = line.substr(0, eq_pos);
        std::string value = line.substr(eq_pos + 1);
        if(key.empty() || value.empty())
            continue;
        config_map[key] = value;
    }
}

/**
 * @brief Returns the value for a given key. If one is not present, pass back the passed in default value.
 * 
 * @tparam T Desired type for the value in the (key, value) pair.
 * @param key Key associated with the desired value.
 * @param def Default value to pass back if the key does not exist.
 * @return T The value desired. Will either be from the config or the default.
 */
template<typename T>
T Config::getValue(std::string const& key, T def) {
    if(config_map.find(key) == config_map.end())
        return def;

    std::istringstream iss(config_map[key]);
    T val;
    iss >> val;
    return val;
}

#endif