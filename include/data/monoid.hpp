#ifndef MONOID_HPP
#define MONOID_HPP

#include <concepts>
#include <type_traits>

namespace lamb {
  template<typename T>
  auto id() -> T = delete;
  template<typename T>
  auto operator+(T, T) -> T = delete;

  template<typename M>
  concept Monoid = requires(M m1, M m2) {
    { id<M>() } -> std::same_as<M>;
    { m1 + m2 } -> std::same_as<M>;
  };
}

#endif
