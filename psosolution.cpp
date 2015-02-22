#include "psosolution.h"
#include "psovectorunit.h"

PSOSolution::PSOSolution()
{
}

PSOSolution::~PSOSolution()
{
    while(vectorOfRn.size()) {
       PSOVectorUnit *e = vectorOfRn.last();
       vectorOfRn.removeLast();
       delete e;
    }
}

PSOVectorUnit*  PSOSolution::operator <<(PSOVectorUnit *v)
{
  vectorOfRn << v;
  return v;
}

PSOVectorUnit *PSOSolution::getElement(int indx)
{
    return vectorOfRn[indx];
}

void *PSOSolution::removeElement(int indx)
{
    vectorOfRn.removeAt(indx);
}
