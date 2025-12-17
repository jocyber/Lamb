#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "../pch.hpp"
#include "token.hpp"

namespace lamb {
  auto scan_source(std::string_view source) noexcept -> std::vector<Token>;
}

#endif
