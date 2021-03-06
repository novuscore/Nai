#pragma once
#include <pch/Build.h>
#include <string>

class Token
{
public:
    enum class Type : uint16_t
    {
        EXCLAMATION_MARK = 33,
        PERCENT = 37,
        AMPERSAND = 38,
        LPAREN = 40,
        RPAREN = 41,
        ASTERISK = 42,
        PLUS = 43,
        COMMA = 44,
        MINUS = 45,
        PERIOD = 46,
        SLASH = 47,
        DECLARATION = 58,
        SEMICOLON = 59,
        LESS_THAN = 60,
        ASSIGN = 61,
        GREATER_THAN = 62,
        QUESTION_MARK = 63,
        LBRACKET = 91,
        BACKSLASH = 92,
        RBRACKET = 93,
        CARET = 94,
        LBRACE = 123,
        PIPE = 124,
        RBRACE = 125,
        TILDE = 126,

        IDENTIFIER = 256,
        NUMERIC_SIGNED,
        NUMERIC_UNSIGNED,
        NUMERIC_FLOAT,
        NUMERIC_DOUBLE,
        NUMERIC_HEX,
        STRING,
        KEYWORD_IMPORT,
        KEYWORD_FUNCTION,
        KEYWORD_STRUCT,
        KEYWORD_ENUM,
        KEYWORD_BREAK,
        KEYWORD_CONTINUE,
        KEYWORD_RETURN,
        KEYWORD_WHILE,
        KEYWORD_IF,
        KEYWORD_ELSEIF,
        KEYWORD_ELSE,
        KEYWORD_FOR,
        KEYWORD_FOREACH,
        KEYWORD_IN,
        KEYWORD_TRUE,
        KEYWORD_FALSE,
        KEYWORD_NULLPTR,

        // Custom Special/Operator Types
        ATTRIBUTE,
        UNINITIALIZED,
        DECLARATION_CONST,
        RETURN_TYPE,
        EQUALS,
        NOT_EQUALS,
        LESS_THAN_EQUALS,
        GREATER_THAN_EQUALS,
        PLUS_EQUALS,
        MINUS_EQUALS,
        MULTIPLY_EQUALS,
        DIVIDE_EQUALS,
        MODULUS_EQUALS,
        POW_EQUALS,
        BITSHIFT_LEFT_EQUALS,
        BITSHIFT_RIGHT_EQUALS,
        BITWISE_AND_EQUALS,
        BITWISE_OR_EQUALS,
        BITSHIFT_LEFT,
        BITSHIFT_RIGHT,
        AND,
        OR,

        // Alias
        PARAM_SEPERATOR = COMMA,
        END_OF_LINE = SEMICOLON,

        NONE = 999
    };

    Type type = Type::NONE;
    uint32_t lineNum = 0;
    uint16_t colNum = 0;

    std::string_view stringview;
    uint32_t hash = 0;
};