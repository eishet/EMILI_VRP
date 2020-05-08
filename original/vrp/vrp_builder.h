
#ifndef VRPBUILDER_H
#define  VRPBUILDER_H
#include "../generalParser.h"
#include "vrp.h"

namespace prs
{
namespace vrp
{
class VrpBuilder: public Builder
{
public:
    VrpBuilder(GeneralParserE& generalParser,TokenManager& tokenManager):
      Builder(generalParser,tokenManager) {};

    virtual ~VrpBuilder(){};

    virtual bool isCompatibleWith(char* problem_definition);
    virtual bool canOpenInstance(char* problem_definition);
    virtual emili::Problem* openInstance();
    virtual emili::InitialSolution* buildInitialSolution();
    virtual emili::Neighborhood* buildNeighborhood();
    virtual emili::Perturbation* buildPerturbation();
};
}
}
#endif //  VRP_BUILDER_H
