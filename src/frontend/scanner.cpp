#include <unordered_set>
#include <cctype>
#include <utility>
#include <ranges>

#include "scanner.hpp"
#include "token.hpp"

static const std::unordered_set<std::string> KEYWORDS = { };

auto lamb::Scanner::get_token() noexcept -> Token {
  switch (src_[0]) {
    case '\n': return Token{consume("\n"), TokenType::Whitespace, row_number_++, 0};
    case ' ':  return Token{consume(" "), TokenType::Whitespace, row_number_++, 0};
    case '=':  return Token{consume("="), TokenType::Assignment, row_number_, column_number_++};
    case '\\': return Token{consume("\\"), TokenType::Lambda, row_number_, column_number_++};
    case '-': {
      auto lookahead = src_[1];
 
      switch (lookahead) {
        case '>': return Token{consume("->"), TokenType::Arrow, row_number_, column_number_++};
        case '-': return Token{consume("--"), TokenType::Comment, row_number_, column_number_++};
        // TODO: make identifier logic here
        default:  return Token{consume("-"), TokenType::Identifier, row_number_, column_number_++};
      }
    }
    case '"': {
      auto literal = src_
        | std::views::take_while([](auto c){ return c != '"' && c != '\n'; });

      return Token{
        consume(literal.data()),
        TokenType::String_Literal,
        row_number_++,
        column_number_ += std::ranges::distance(literal)
      };
    }
    default: {
      // check if the first character is alphaNumeric, otherwise, this is an invalid token
      const auto& lexeme = munch_lexeme();
      const auto column_number = column_number_ += std::ranges::distance(lexeme);

      // advance until we find a whitespace character or end of file
      if (std::isdigit(lexeme[0])) {
        return Token{
          consume(lexeme.data()),
          TokenType::Number_Literal,
          row_number_,
          column_number,
        };
      } else if (KEYWORDS.contains(lexeme.data())) {
        return Token{
          consume(lexeme.data()),
          TokenType::Keyword, 
          row_number_, 
          column_number,
        };
      } else {
        return Token{
          consume(lexeme.data()),
          TokenType::Identifier, 
          row_number_, 
          column_number,
        };
      }
    }
  }
}

auto lamb::Scanner::consume(std::string str) noexcept -> std::string {
  return src_ = &src_[str.size()], str;
}

