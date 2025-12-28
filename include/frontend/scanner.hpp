#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "../pch.hpp"
#include "token.hpp"
#include <ranges>

namespace lamb {
  struct Scanner {
    Scanner(std::string_view src)
      : src_{src},
        row_number_{0u},
        column_number_{0u} {}
    
    [[nodiscard]] auto get_token() noexcept -> Token;

  private:
    [[nodiscard]] auto munch_lexeme() const noexcept {
      return src_ | std::views::take_while([](auto c){ return c != ' '; });
    }
    [[nodiscard]] auto consume(std::string str) noexcept -> std::string;

    std::string_view src_;
    std::uint32_t row_number_;
    std::uint32_t column_number_;
  };
}

#endif
