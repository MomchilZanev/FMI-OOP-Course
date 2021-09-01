#pragma once
#include <cstring>

enum class ErrorType 
{
    None,
    BuildFailed,
    Warning,
    FailedAssertion,
};

class Error 
{
public:
    Error();
    Error(const Error& rhs);
    ~Error();
    Error& operator=(const Error& rhs);

    bool hasMessage() const;
    const char* getMessage() const;
    ErrorType getType() const;

    static Error newNone();
    static Error newBuildFailed(const char* message);
    static Error newWarning(const char* message);
    static Error newFailedAssertion(const char* message);
private:
    static char* copy(const char* original);

    ErrorType type;
    char* message;
};