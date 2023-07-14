#include <iostream>

enum OptionType { Some, None };
template <typename T> class Option 
{
private: 
    T value;
    OptionType option_type;
public:
    Option() : option_type(OptionType::None) {}
    Option(T incoming_value) : value(incoming_value), option_type(OptionType::Some) {}

    bool is_some() const {
        return (option_type == OptionType::Some);
    }
    bool is_none() const {
        return (option_type == OptionType::None);
    }

    Option operator=(T new_value) {
        value = new_value;
        std::cout << new_value << std::endl;
    }
    T expect(const char panic_message[]) const {
        if (is_none()) throw std::runtime_error(panic_message);
        return value;
    }
    T unwrap() const {
        expect("Called unwrap on an empty value!");
    }
    Option and_then(T (*callback)(T)) {
        if (is_some()) return callback(value);
        return *this;
    }
    Option or_else(T (*callback)()) {
        if (is_none()) return callback();
        return *this;
    }
};


enum ResultType { Ok, Err };
template <typename T, typename E> class Result
{
private:
    T value;
    E error;
    ResultType result_type;
public:
    Result(E incoming_error) : error(incoming_error), result_type(ResultType::Err) {}
    Result(T incoming_value) : value(incoming_value), result_type(ResultType::Ok) {}

    bool is_ok() const {
        return (result_type == ResultType::Ok);
    }
    bool is_err() const {
        return (result_type == ResultType::Err);
    }

    Result operator=(E new_error) {
        
    }
    T expect(const char panic_message[]) const {
        if (is_err()) throw std::runtime_error(panic_message);
        return value;
    }
    T unwrap() const {
        expect("Called unwrap on an empty value!");
    }
    Result and_then(T (*callback)(T)) {
        if (is_ok()) return callback(value);
        return *this;
    }
    Result or_else(T (*callback)()) {
        if (is_err()) return callback();
        return *this;
    }
};



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
    // hi!
    std::cout << "HIIII :3" << std::endl;


    /* Basic Option Usage */
    Option<int> test1_1 = Option<int>(2);

    std::cout << (test1_1.is_some() ? "Yep!" : "Nope...") << std::endl;
    std::cout << test1_1.and_then(mult_by_ten).expect("frick") << std::endl;


    Option<int> test1_2 = Option<int>();

    std::cout << (test1_2.is_some() ? "Yep!" : "Nope...") << std::endl;
    std::cout << test1_2.or_else(return_five).expect("frick") << std::endl;


    

    /* Basic Result Usage */
    Result<int, float> test2_1 = Result<int, float>(2);

    std::cout << (test2_1.is_ok() ? "Yep!" : "Nope...") << std::endl;
    std::cout << test2_1.and_then(mult_by_ten).expect("frick") << std::endl;


    Result<int, float> test2_2 = Result<int, float>(2.0f);

    std::cout << (test2_2.is_err() ? "Nope..." : "Yep!") << std::endl;
    std::cout << test2_2.or_else(return_five).expect("frick") << std::endl;
}