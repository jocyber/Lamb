#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "../pch.hpp"
#include "token.hpp"

namespace lamb {
  std::vector<Token> scan_source(std::string_view source) noexcept;
}

#endif
