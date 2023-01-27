# simple-config

This is a C++ config reader contained in a single header file. Useful when you have a set of primitive variables in a program that you would like to change without recompiling. The way it is implemented allows for you to select default values so that the program can also be run without any config file at all.

## Config File Format

Each line in your config file corresponds to a `(key, value)` pair that will be stored in an `std::unordered_map<std::string, std::string>`. Keys and values should not have spaces. Types **do not** need to be specified in the config file itself as this is done in the reading step in your program. One final restriction is that if you want to set values for `boolean` types, you should write `0` or `1` for `false` and `true` respectively.
```cpp
// Here are some examples of correct ways to set values.
name=Bob
age=20
married=1

// Here are some examples of lines that will not contribute.
test1
test2=
=test3

// If you try to read string1, only 'The' will be found.
string1=The quick brown fox
```

## Example Program Usage
Below is some example code for reading in values from the above config file. You can also see how default values are set.
```cpp
Config cfg("./path/to/config");
std::string name = cfg.getValue<std::string>("name", "");
int age = cfg.getValue<int>("age", 0);
bool isMarried = cfg.getValue<bool>("married", false);
```
