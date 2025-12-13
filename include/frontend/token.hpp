#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "../pch.hpp"

namespace lamb {
  enum class TokenType {
    Whitespace,
    String_Literal,
    Number_Literal,
    Assignment,
    Lambda, // backspace or lambda unicode character
    Keyword,
    Identifier,
    Invalid
  };

  struct Token {
    Token(
      std::string lexeme,
      TokenType type,
      std::uint32_t row_number,
      std::uint32_t column_number
    ) : lexeme_(std::move(lexeme)),
        type_(type),
        row_number_(row_number),
        column_number_(column_number) {}

    [[nodiscard]] const auto& lexeme() const noexcept { return lexeme_; }
    [[nodiscard]] auto type() const noexcept { return type_; }
    [[nodiscard]] auto row_number() const noexcept { return row_number_; }
    [[nodiscard]] auto column_number() const noexcept { return column_number_; }

  private:
    std::string lexeme_;
    TokenType type_;
    std::uint32_t row_number_;
    std::uint32_t column_number_;
  };
}

#endif
