#include "psosolution.h"
#include "psovectorunit.h"

PSOSolution::PSOSolution()
{
}

PSOSolution::~PSOSolution()
{
    while(vectorRn.size()) {
       PSOVectorUnit *e = vectorRn.last();
       vectorRn.removeLast();
       delete e;
    }
}

PSOVectorUnit*  PSOSolution::operator <<(PSOVectorUnit *v)
{
  vectorRn << v;
  return v;
}

int PSOSolution::dimension()
{
    return vectorRn.size();
}

PSOVectorUnit *PSOSolution::getElement(int indx)
{
    return vectorRn[indx];
}

void PSOSolution::removeElement(int indx)
{
    PSOVectorUnit *e = vectorRn[indx];
    vectorRn.removeAt(indx);
    delete e;
}

void PSOSolution::generateRandomSolution(int dimension)
{
    
}
