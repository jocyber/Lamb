#ifndef MONOID_HPP
#define MONOID_HPP

#include <concepts>

namespace lamb {
  template<class T>
  T mempty() = delete;

  template<class T>
  auto mappend(T, T) -> T = delete;

  template<typename M>
  concept Monoid = requires(M m) {
    { mempty<M>(); } -> M;
    { mappend(M, M); } -> M;
  };
}

#endif
