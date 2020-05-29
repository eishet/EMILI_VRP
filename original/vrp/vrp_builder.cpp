

#include "vrp_builder.h"
#include "vrp.h"
#include "vrp_instance.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <iostream>
#include <sstream>

/*---------------------------------------------------------------------------------------------------------------------*
 *-------------------------------------DEFINICION DE SECCIONES DEL PROBLEMA--------------------------------------------*
 *---------------------------------------------------------------------------------------------------------------------*/

#define EMPTY_LS "vacio"
#define TEST_LS "test"


/* 
 *  Vehicule Routing Problem 
 */

#define PROBLEM_VRP_CAPACITATED "CVRP"

/* 
 *initial solution heuristics 
 */

#define INITIAL_RANDOM "random"
#define INITIAL_DET "det"

/*
 *  vehicule routing problem neighborhoods
 */

/* Inter route structures */
#define NEIGHBORHOOD_INTER_ROUTE_SHIFT_1_0 "nshift10"
#define NEIGHBORHOOD_INTER_ROUTE_SHIFT_2_0 "nshift20"
#define NEIGHBORHOOD_INTER_ROUTE_SWAP_1_0 "nswap10"
#define NEIGHBORHOOD_INTER_ROUTE_SWAP_2_0 "nswap20"
#define NEIGHBORHOOD_INTER_ROUTE_CROSS "ncross"
/* Intra route structures */
#define NEIGHBORHOOD_INTRA_ROUTE_REINSERTION "nrein"
#define NEIGHBORHOOD_INTRA_ROUTE_OR_OPT_2 "nopt2"
#define NEIGHBORHOOD_INTRA_ROUTE_OR_OPT_3 "nopt3"

/* 
 *perturbations types 
 */

#define PERTURBATION_MULTI_SWAP_1_1 "p_ms_w_11"
#define PERTURBATION_MULTI_SHIFT_1_1 "p_ms_h_11"



/*--------------------------------------------------------------------------------------------------------------------*
 *-------------------------------------CARGA DE INSTANCIA E INICIALIZACIÓN--------------------------------------------*
 *--------------------------------------------------------------------------------------------------------------------*/

char* problem_string;
emili::vrp::VrpProblem* loadProblem(char* t, VrpInstance i);


//------------------------------Info de ejecución------------------------------
std::string info_vrp()
{
    std::ostringstream oss;
    oss << "Usage:\n\n";
    oss << "PROBLEM               = "<<PROBLEM_VRP_CAPACITATED<<"\n";
    //oss << "INITIAL_SOLUTION      = random | det" <<"\n";
    return oss.str();
}

/*/------------------------------Creación del algoritmo de búsqueda------------------------------
emili::LocalSearch* prs::vrp::VrpBuilder::buildAlgo()
{
    prs::incrementTabLevel();
    emili::LocalSearch* ls = nullptr;
    if(tm.checkToken(TEST_LS))
    {
        printTab("LOCAL SEARCH");
        emili::vrp::VrpProblem* instance =(emili::vrp::VrpProblem*) gp.getInstance();
        emili::InitialSolution* in = retrieveComponent(COMPONENT_INITIAL_SOLUTION_GENERATOR).get<emili::InitialSolution>();
        emili::Termination* te = retrieveComponent(COMPONENT_TERMINATION_CRITERION).get<emili::Termination>();
        emili::Neighborhood* ne = retrieveComponent(COMPONENT_NEIGHBORHOOD).get<emili::Neighborhood>();
        ls = new emili::vrp::SinLS(*instance,*in);
    }
    prs::decrementTabLevel();
    return ls;
}
*/

//------------------------------lectura y carga de instancia------------------------------
emili::Problem* prs::vrp::VrpBuilder::openInstance()
{

    VrpInstance instance;
    problem_string = tm.nextToken(); //avanza al siguiente token que corresponde a la direccion de la instancia
    bool ok;

    ok = instance.readDataFromFile(tm.tokenAt(1)); //true si existe el token, falso si no

    if(ok) //si existe la instancia llama a loadproblem que carga el problema
    {
       emili::vrp::VrpProblem* problem = loadProblem(problem_string, instance);
       return problem;
    }

    std::cout << info_vrp() << std::endl;
    exit(-1);
}

/*/------------------------------creacion del problema------------------------------
emili::Problem* prs::PfspBuilder::buildProblem()
{
    emili::vrp::VrpProblem* instance =(emili::vrp::VrpProblem*) gp.getInstance();
    return loadProblem(tm.nextToken(),instance->getInstance());
}
*/

//------------------------------lectura del problema VRP------------------------------
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






/*----------------------------------------------------------------------------------------------------------------------*
 *-------------------------------------COMPONENTES DEL ALGORITMO DE BÚSQUEDA--------------------------------------------*
 *----------------------------------------------------------------------------------------------------------------------*/


//------------------------------crea la solucion inicial------------------------------
emili::InitialSolution* prs::vrp::VrpBuilder::buildInitialSolution()
{
    prs::incrementTabLevel();
    emili::InitialSolution* init = nullptr;
    emili::vrp::VrpProblem* instance =(emili::vrp::VrpProblem*) gp.getInstance();
    
    //la solucion inicial varia dependiendo de los parámetros ingresados por consola
    if(tm.checkToken(INITIAL_RANDOM))
    {
        printTab( "Random initial solution");
        init = new emili::vrp::VrpRandomInitialSolution(*instance);
    }
    else if(tm.checkToken(INITIAL_DET))
    {
        printTab( "Determinist initial solution");
        init = new emili::vrp::VrpDetInitialSolution(*instance);
    }
    prs::decrementTabLevel();

    return init;
}

//------------------------------creacion de vecindario------------------------------
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

//------------------------------creacion de la perturbación------------------------------
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


/*--------------------------------------------------------------------------------------------------------*
 *-------------------------------------BOOLEANOS DE ACEPTACION--------------------------------------------*
 *--------------------------------------------------------------------------------------------------------*/

//comprueba que el problema ingresado puede ser usado por el parser
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


/*
 *TO DO:
 *  Buscar porque ambas hacen lo mismo y donde son utilizadas/llamadas 
 */
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
