#include <unordered_set>
#include <utility>

#include "frontend/scanner.hpp"
#include "frontend/token.hpp"

static const std::unordered_set<std::string> KEYWORDS = { };

std::vector<Token> scan_source(std::string_view source) noexcept {
  auto result = std::vector<Token>(source.length);

  auto column_number = 0u;
  auto row_number = 0u;

  for (const auto& c : source) {
    switch (c) {
      case '\n':
        result.emplace_back("\n", TokenType::Whitespace, ++row_number, ++column_number);
        column_number = 0;
        break;
      case '=': result.emplace_back("=", TokenType::Assignment, row_number, ++column_number); break;
      default: {
        // check if the first character is alphaNumeric, otherwise, this is an invalid token
        const auto& identifier = munch_identifier(); // should return identifier and the rest of the list

        // advance until we find a whitespace character or end of file
        if (KEYWORDS.contains(identifier)) {
          result.emplace_back(
            std::move(identifier), 
            TokenType::Keyword, 
            row_number, 
            column_number += identifier.length
          );
        } else {
          result.emplace_back(
            std::move(identifier), 
            TokenType::Identifier, 
            row_number, 
            column_number += identifier.length
          )
        }
      }
    }
  }

  result.shrink_to_fit();
  return result;
}
