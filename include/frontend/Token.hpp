#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "../pch.hpp"

namespace lamb {
  struct Token {
    std::string lexeme_;
    TokenType type_;
    int row_number_;
    int column_number_;
  };

  enum class TokenType {
    Whitespace,
    String_Literal,
    Number_Literal 
  };
}

#endif
