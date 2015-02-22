#include "psosolution.h"
#include "psovectorunit.h"

PSOSolution::PSOSolution()
{
}

PSOVectorUnit*  PSOSolution::operator <<(PSOVectorUnit *v)
{
  vectorOfRn << v;
  return v;
}
