#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "Sole" ? 0 : 1;
}
