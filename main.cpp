#include <iostream>

enum OptionType { Some, None }
template <typename T> class Option 
{
private: 
    T value;
    OptionType option_type;
public:
    Option() : option_type(OptionType::None) {}
    Option(T incoming_value) : value(incoming_value), option_type(OptionType::Some) {}

    bool is_some() {
        return option_type == OptionType::Some;
    }
    bool is_none() {
        return option_type == OptionType::None;
    }

    Option operator=(T new_value) {
        value = new_value;
        std::cout << new_value << std::endl;
    }
    T expect(char panic_message[]) const {
        if (is_none()) throw std::runtime_error(panic_message);
        return value;
    }
    T unwrap() const {
        expect("Called unwrap on an empty value!");
    }
    Option and_then(T (*callback)(T)) {
        if is_some() return callback(value);
        return *this;
    }
    Option or_else(T (*callback)()) {
        if (empty_value) {
            return callback();
        }
        return *this;
    }
};
int mult_by_ten(int input) {

int mult_by_ten(int input)
{
    return input * 10;
}
int return_five()
{
    return 5;
}
int main()
{
    std::cout << "HIIII :3" << std::endl;

    Option<int> test1 = Option<int>(2);

    std::cout << (test1.is_some() ? "Yep!" : "Nope...") << std::endl;
    std::cout << test1.and_then(mult_by_ten).expect("frick") << std::endl;



    Option<int> test2 = Option<int>();

    std::cout << (test2.is_some() ? "Yep!" : "Nope...") << std::endl;
    std::cout << test2.or_else(return_five).expect("frick") << std::endl;

    //test = 3;
}