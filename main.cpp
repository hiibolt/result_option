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
        if is_none() return callback();
        return *this;
    }
};

enum ResultType { Ok, Err }
template <typename T, typename E> class Result
{
private:
    T value,
    E error,
    ResultType result_type,
public: 
    Result(E incoming_error) : error(incoming_error), result_type(ResultType::None) {}
    Result(T incoming_value) : value(incoming_value), result_type(ResultType::Some) {}

    bool is_some() {
        return result_type == ResultType::Ok;
    }
    bool is_none() {
        return result_type == ResultType::Err;
    }

    Result operator=(T new_value) {
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
    Result and_then(T (*callback)(T)) {
        if is_some() return callback(value);
        return *this;
    }
    Result or_else(T (*callback)()) {
        if is_none() return callback();
        return *this;
    }
}

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

    Option<int> test11 = Option<int>(2);

    std::cout << (test11.is_some() ? "Yep!" : "Nope...") << std::endl;
    std::cout << test11.and_then(mult_by_ten).expect("frick") << std::endl;



    Option<int> test12 = Option<int>();

    std::cout << (test12.is_some() ? "Yep!" : "Nope...") << std::endl;
    std::cout << test12.or_else(return_five).expect("frick") << std::endl;


    std::cout<< "HIIII";


    Result<int> test21 = Result<int, float>(2);

    std::cout << (test21.is_some() ? "Yep!" : "Nope...") << std::endl;
    std::cout << test21.and_then(mult_by_ten).expect("frick") << std::endl;



    Option<int> test2 = Option<int>();

    std::cout << (test22.is_some() ? "Yep!" : "Nope...") << std::endl;
    std::cout << test22.or_else(return_five).expect("frick") << std::endl;

    //test = 3;
}