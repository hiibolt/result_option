# Option and Result Library
A basic library that allows the incredibly usful Rust types Option and Result.

I can't live without them while developing in C++, so I'd rather write it myself. Just goes to show how cool Rust is, and that you should learn it! 

# class Option 
## Constructors:
    Option()
    Option(T incoming_value)
## Functions
```
/**
 * Check if the option type is Some.
 *
 * @return true if the option type is Some, false otherwise.
 */
bool is_some() const
/**
 * Check if the option is None.
 *
 * @return true if the option is None, false otherwise
 */
bool is_none() const

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
T expect(const char panic_message[]) const
/**
 * Unwraps the value of the object.
 *
 * @return The unwrapped value.
 *
 * @throws ErrorType Called unwrap on an empty value!
 */
T unwrap() const
/**
 * A function that applies a callback function to the value if it is not None.
 *
 * @param callback a function that takes a value of type T and returns a value of type T
 *
 * @return an Option object that contains the result of applying the callback function to the value, or the current Option object if the value is None
 *
 * @throws None
 */
Option and_then(T (*callback)(T))
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
Option or_else(T (*callback)())
```

# class Result
## Constructors
    Result(E incoming_error)
    Result(T incoming_value)
## Functions
```
/**
 * Check if the result type is "Ok".
 *
 * @return true if the result type is "Ok", false otherwise
 */
bool is_ok() const
/**
 * Check if the result is an error.
 *
 * @return true if the result is an error, false otherwise
 */
bool is_err() const

/**
 * Throws a std::runtime_error with the given panic message if the result is in an error state.
 *
 * @param panic_message The panic message to be included in the exception.
 *
 * @return The value of the result if it is not in an error state.
 *
 * @throws std::runtime_error The panic message provided as the exception message.
 */
T expect(const char panic_message[]) const
/**
 * Unwraps the value of type T.
 *
 * @return the unwrapped value
 *
 * @throws ErrorType if called on an empty value
 */
T unwrap() const
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
Result and_then(T (*callback)(T))
/**
 * Executes the provided callback function if the Result is an error.
 *
 * @param callback a pointer to a function that takes no arguments and returns a value of type T.
 *
 * @return Returns the Result object itself if it is not an error, otherwise it returns the value returned by the callback function.
 *
 * @throws None.
 */
Result or_else(T (*callback)()) 
```

Not maintained.
