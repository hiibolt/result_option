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

    /**
     * Check if the option type is Some.
     *
     * @return true if the option type is Some, false otherwise.
     */
    bool is_some() const {
        return (option_type == OptionType::Some);
    }
    /**
     * Check if the option is None.
     *
     * @return true if the option is None, false otherwise
     */
    bool is_none() const {
        return (option_type == OptionType::None);
    }

    /**
     * A function that expects a non-null value and returns it, or throws a runtime error
     * with the provided panic message.
     *
     * @param panic_message the message to be displayed if the value is null
     *
     * @return the non-null value
     *
     * @throws std::runtime_error if the value is null
     */
    T expect(const char panic_message[]) const {
        if (is_none()) throw std::runtime_error(panic_message);
        return value;
    }
    /**
     * Unwraps the value of the object.
     *
     * @return The unwrapped value.
     *
     * @throws ErrorType Called unwrap on an empty value!
     */
    T unwrap() const {
        expect("Called unwrap on an empty value!");
    }
    /**
     * A function that applies a callback function to the value if it is not None.
     *
     * @param callback a function that takes a value of type T and returns a value of type T
     *
     * @return an Option object that contains the result of applying the callback function to the value, or the current Option object if the value is None
     *
     * @throws None
     */
    Option and_then(T (*callback)(T)) {
        if (is_some()) return callback(value);
        return *this;
    }
    /**
     * A function that returns the value of the Option if it is not None,
     * otherwise it calls the provided callback and returns its result.
     *
     * @param callback a function that takes no arguments and returns a value of type T.
     *
     * @return the value of the Option if it is not None, otherwise the result of calling the callback.
     *
     * @throws None
     */
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

    /**
     * Check if the result type is "Ok".
     *
     * @return true if the result type is "Ok", false otherwise
     */
    bool is_ok() const {
        return (result_type == ResultType::Ok);
    }
    /**
     * Check if the result is an error.
     *
     * @return true if the result is an error, false otherwise
     */
    bool is_err() const {
        return (result_type == ResultType::Err);
    }

    /**
     * Throws a std::runtime_error with the given panic message if the result is in an error state.
     *
     * @param panic_message The panic message to be included in the exception.
     *
     * @return The value of the result if it is not in an error state.
     *
     * @throws std::runtime_error The panic message provided as the exception message.
     */
    T expect(const char panic_message[]) const {
        if (is_err()) throw std::runtime_error(panic_message);
        return value;
    }
    /**
     * Unwraps the value of type T.
     *
     * @return the unwrapped value
     *
     * @throws ErrorType if called on an empty value
     */
    T unwrap() const {
        expect("Called unwrap on an empty value!");
    }
    /**
     * Applies a callback function to the value contained in the Result object if it is in a valid state. 
     * If the Result object is in an invalid state, it returns a copy of itself.
     *
     * @param callback A function pointer to a callback function that takes a single parameter of type T and returns a value of type T.
     *
     * @return A new Result object that contains the result of applying the callback function to the value contained in the original Result object, 
     *         or a copy of the original Result object if it is in an invalid state.
     *
     * @throws None
     */
    Result and_then(T (*callback)(T)) {
        if (is_ok()) return callback(value);
        return *this;
    }
    /**
     * Executes the provided callback function if the Result is an error.
     *
     * @param callback a pointer to a function that takes no arguments and returns a value of type T.
     *
     * @return Returns the Result object itself if it is not an error, otherwise it returns the value returned by the callback function.
     *
     * @throws None.
     */
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