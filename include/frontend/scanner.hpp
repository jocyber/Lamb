#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "../pch.hpp"
#include "token.hpp"
#include "unordered_set"

namespace lamb {
  std::vector<Token> scan_source(std::string source) noexcept;

  inline const std::unordered_set<std::string> KEYWORDS = { };
}

#endif
