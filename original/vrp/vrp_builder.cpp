

#include "vrp_builder.h"
#include "vrp.h"
#include "vrp_instance.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <iostream>
#include <sstream>


/* Vehicule Routing Problem */
#define PROBLEM_VRP_CAPACITATED "VRP_CAPACITATED"

/* initial solution heuristics */
#define INITIAL_RANDOM "random"


/*
 *  vehicule routing problem neighborhoods
 */

/* Inter route structures */
#define NEIGHBORHOOD_INTER_ROUTE_SHIFT_1_0 "n_inter_sh_1_0"
#define NEIGHBORHOOD_INTER_ROUTE_SHIFT_2_0 "n_inter_sh_2_0"
#define NEIGHBORHOOD_INTER_ROUTE_SWAP_1_0 "n_inter_sw_1_0"
#define NEIGHBORHOOD_INTER_ROUTE_SWAP_2_0 "n_inter_sw_2_0"
#define NEIGHBORHOOD_INTER_ROUTE_CROSS "n_inter_cr"

/* Intra route structures */
#define NEIGHBORHOOD_INTRA_ROUTE_REINSERTION "n_intra_re"
#define NEIGHBORHOOD_INTRA_ROUTE_OR_OPT_2 "n_intra_or_opt_2"
#define NEIGHBORHOOD_INTRA_ROUTE_OR_OPT_3 "n_intra_or_opt_3"
#define NEIGHBORHOOD_INTRA_ROUTE_REINSERTION "n_intra_re"


/* perturbations types */
#define PERTURBATION_MULTI_SWAP_1_1 "p_ms_w_11"
#define PERTURBATION_MULTI_SHIFT_1_1 "p_ms_h_11"

char* problem_string;
emili::vrp::VrpProblem* loadProblem(char* t, VrpInstance i);

std::string info_vrp()
{
    std::ostringstream oss;
    oss << "Usage:\n\n";
    oss << "PROBLEM               = "<<PROBLEM_VRP_CAPACITATED<<"\n";
    return oss.str();
}


emili::Problem* prs::vrp::VrpBuilder::openInstance()
{

    VrpInstance instance;
    problem_string = tm.nextToken();
    bool ok;

    ok = instance.readDataFromFile(tm.tokenAt(1));

    if(ok)
    {
       emili::vrp::VrpProblem* problem = loadProblem(problem_string, instance);
       return problem;
    }

    std::cout << info_vrp() << std::endl;
    exit(-1);
}


emili::vrp::VrpProblem* loadProblem(char* t, VrpInstance i)
{
  emili::vrp::VrpProblem* prob;
  if(strcmp(t,PROBLEM_VRP_CAPACITATED)==0)
  {
      //prs::printTab("Capacitated Vehicule Routing Problem");
      prob = new emili::vrp::CVRP(i);
  }
  else
  {
      std::cerr<< "'" << t << "' -> ERROR a problem was expected! " << std::endl;
      prs::info();
      exit(-1);
  }
  return prob;

}


emili::InitialSolution* prs::vrp::VrpBuilder::buildInitialSolution()
{
    prs::incrementTabLevel();
    emili::InitialSolution* init = nullptr;
    emili::vrp::VrpProblem* instance =(emili::vrp::VrpProblem*) gp.getInstance();

    if(tm.checkToken(INITIAL_RANDOM))
    {
        printTab( "Random initial solution");
        init = new emili::vrp::VrpRandomInitialSolution(*instance);
    }
    prs::decrementTabLevel();

    return init;
}

emili::Neighborhood* prs::vrp::VrpBuilder::buildNeighborhood()
{
        prs::incrementTabLevel();
        emili::Neighborhood* neigh = nullptr;
        emili::vrp::VrpProblem* instance =(emili::vrp::VrpProblem*) gp.getInstance();

        if(tm.checkToken(NEIGHBORHOOD_INTER_ROUTE_SHIFT_1_0))
        {
            printTab( "Neighborhood: Inter-route Shift(1,0)" );
            neigh = new emili::vrp::Shift_1_0_Neighborhood(*instance);
        }

        prs::decrementTabLevel();
        return neigh;
}

emili::Perturbation* prs::vrp::VrpBuilder::buildPerturbation()
{
     prs::incrementTabLevel();
        emili::Perturbation* per = nullptr;
        /*
        if(tm.checkToken(PERTURBATION_PROBLEMX))
        {
            printTab( "PROBLEMX Perturbation");
            //emili::Neighborhood* n = gp.buildComponent(COMPONENT_NEIGHBORHOOD).get<emili::Neighborhood>();
            per = new emili::problemX::PerturbationProblemX();
        }
        */
        prs::decrementTabLevel();
        return per;
}

bool isParsable(std::string &problem)
{
    if(strcmp(problem.c_str(),PROBLEM_VRP_CAPACITATED)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool prs::vrp::VrpBuilder::isCompatibleWith(char* problem_definition)
{
    std::string s(problem_definition);
    return isParsable(s);
}

bool prs::vrp::VrpBuilder::canOpenInstance(char* problem_definition)
{
    std::string s(problem_definition);
    return isParsable(s);
}
