
#include "vrp.h"

#include <cstdlib>
#include <ctime>



void notyet()
{
    std::cout << "Not implemented yet \n";
    //std::exit(-5);
}



/**-------------------------------------------------- PROBLEM -------------------------------------------------------**/

double emili::vrp::VrpProblem::calcObjectiveFunctionValue(emili::Solution &solution)
{
    emili::vrp::VrpSolution& s = dynamic_cast<emili::vrp::VrpSolution&> (solution);
    return computeObjectiveFunction(s.getSolution());
}

double emili::vrp::VrpProblem::evaluateSolution(emili::Solution &solution)
 {
    emili::vrp::VrpSolution& s = dynamic_cast<emili::vrp::VrpSolution&> (solution);
    double p = computeObjectiveFunction(s.getSolution());
    solution.setSolutionValue(p);
    return p;
}

double emili::vrp::VrpProblem::computeObjectiveFunction(std::vector < std::vector<int> > &solution)
{
    return this->computeObjectiveFunction(solution);
}

double emili::vrp::CVRP::computeObjectiveFunction(std::vector < std::vector<int> > &solution)
{
    return instance.computeSolution(solution);
}

int emili::vrp::VrpProblem::getNcustomers(){
    return instance.getNbCustomers();
}

int emili::vrp::VrpProblem::getTruckCapacity(){
    return instance.getTruckCapacity();
}

std::vector<int> emili::vrp::VrpProblem::getDemands(){
    return instance.getDemands();
}




/** INITIAL SOLUTION **/


emili::Solution* emili::vrp::VrpInitialSolution::generateEmptySolution() /*TO DO*/
{
    std::vector< std::vector< int > > empty;
    double maxValue = std::numeric_limits<double>::max();
    emili::vrp::VrpSolution*  em =  new emili::vrp::VrpSolution(empty, maxValue);
    return em;
}

emili::Solution* emili::vrp::VrpInitialSolution::generateSolution()
{
    return generate();
}

//--------------------------------solucion inicial determinista-------------------------------------------------
emili::Solution* emili::vrp::VrpDetInitialSolution::generate()
{
  std::vector < std::vector<int> > solution;
  std::vector<int> used_pos(pis.getNcustomers());
  std::vector<int> demands = pis.getDemands();
  int actualTruckCapacity = pis.getTruckCapacity();
  std::vector<int> actualTruckSolution;

  for(int i=0; i<used_pos.size(); i++){
    used_pos[i] = i;
  }

  while(used_pos.size() > 0){
    int i = 1;
    actualTruckSolution.push_back(i);
    actualTruckCapacity = actualTruckCapacity - demands[i];
    used_pos.erase(used_pos.begin());
    solution.push_back(actualTruckSolution);
    actualTruckSolution.clear();
    i++;
  }
  VrpSolution* s = new VrpSolution(solution, calculateInitialSolutionValue(solution));
  pis.evaluateSolution(*s);
  return s;
}
//--------------------------------------fin solucion determinista----------------------------------------------
//--------------------------------------solucion inicial aleatoria---------------------------------------------
emili::Solution* emili::vrp::VrpRandomInitialSolution::generate()
{
  srand(time(NULL));
	std::vector < std::vector<int> > solution;
	std::vector<int> used_pos(pis.getNcustomers());

  std::vector<int> demands = pis.getDemands();
	int actualTruckCapacity = pis.getTruckCapacity();
	std::vector<int> actualTruckSolution;

	for(int i =0; i<used_pos.size(); i++){	//vector with all the pos. Example  v = [ 0, 1, 2, 3 ..... (nbCustomers -1) ]
		used_pos[i] = i;
	}

	while(used_pos.size() > 0){
		int rand_pos = rand() % used_pos.size();
		int actual_pos = used_pos[rand_pos];

		if(actualTruckCapacity == 0 || demands[actual_pos] > actualTruckCapacity){
    			actualTruckCapacity = pis.getTruckCapacity();
    			solution.push_back(actualTruckSolution);
    			actualTruckSolution.clear();
		}

		actualTruckSolution.push_back(actual_pos);
		actualTruckCapacity = actualTruckCapacity - demands[actual_pos];
  	used_pos.erase(used_pos.begin() + rand_pos);
	}
	solution.push_back(actualTruckSolution);

  VrpSolution* s = new VrpSolution(solution, calculateInitialSolutionValue(solution));
  pis.evaluateSolution(*s);
  return s;
}

double emili::vrp::VrpRandomInitialSolution::calculateInitialSolutionValue(std::vector < std::vector<int> >&solution)
{
  return 0;
}

//----------------------------------------------------------------------------------------------------------------
double emili::vrp::VrpDetInitialSolution::calculateInitialSolutionValue(std::vector < std::vector<int> >&solution)
{
  return 0;
}
//----------------------------------------------------------------------------------------------------------------

/** SOLUTION **/
const void* emili::vrp::VrpSolution::getRawData()const
{
notyet();
return nullptr;
}

void emili::vrp::VrpSolution::setRawData(const void* data)
{
  notyet();

}

std::string emili::vrp::VrpSolution::getSolutionRepresentation()
{

  return std::string("TO implement");
}

emili::Solution* emili::vrp::VrpSolution::clone()
{
  notyet();
  return nullptr;
}

std::vector< std::vector< int > > & emili::vrp::VrpSolution::getSolution()
{
  return solutionRepresentation;
}

void emili::vrp::VrpSolution::setSolution(std::vector< std::vector< int > >& sol)
{
  solutionRepresentation = sol;
}

double emili::vrp::VrpSolution::getSolutionValue()
{
  return solutionValue;
}

void emili::vrp::VrpSolution::setSolutionValue(double solutionValue)
{
  this->solutionValue = solutionValue;
}




/** NEIGHBORHOOD **/

/*Shift_1_0_Neighborhood*/

emili::Solution* emili::vrp::Shift_1_0_Neighborhood::random(Solution* currentSolution)
{
    notyet();
    return nullptr;
}

emili::Neighborhood::NeighborhoodIterator emili::vrp::Shift_1_0_Neighborhood::begin(emili::Solution* base)
{
  return emili::Neighborhood::NeighborhoodIterator(this,base);
}


void emili::vrp::Shift_1_0_Neighborhood::reset()
{
  notyet();
}

emili::Solution* emili::vrp::Shift_1_0_Neighborhood::computeStep(emili::Solution* step)
{
  emili::iteration_increment();

  std::vector<std::vector<int>> solution = ((emili::vrp::VrpSolution*) step)->getSolution();
  double solutionValue = ((emili::vrp::VrpSolution*) step)->getSolutionValue();

  do{
    getNextNeighborPos( solution );
    if( proposedNextIsFeasible( solution ) ){
        //Modify actual Solution for the new one
        makeShift( solution );
        ( (emili::vrp::VrpSolution*) step )->setSolution( solution );
        ( (emili::vrp::VrpSolution*) step )->setSolutionValue( calculateDeltaSolutionValue( solution, solutionValue ) );




        return step;

    }
  }while(nClientsToIterate > 0);

  return nullptr;
}

void emili::vrp::Shift_1_0_Neighborhood::getNextNeighborPos(std::vector < std::vector<int> >& solution){

  /*The first time will never enter*/
  if(!isFirstTime){
    if(actual_route == next_route && actual_client == next_client){
      actual_client++;
      if(actual_client  > solution[actual_route].size()-1){
        actual_route++;
        actual_client  = 0;
        if(actual_route > solution.size()-1){
          actual_route = 0;
        }
      }
      next_route = actual_route;
      next_client = actual_client;
      nClientsToIterate--;
    }
  }
  else{
    isFirstTime = false;
  }

  next_client++;

  /*move if next client is outside*/
  if( next_client  > solution[next_route].size()-1){
    next_route++;
    next_client = 0;
    /*if there are no routes send it to the begining*/
    if(next_route > solution.size()-1){
      next_route = 0;
    }
  }

}


bool emili::vrp::Shift_1_0_Neighborhood::proposedNextIsFeasible(std::vector < std::vector<int> >& solution){

    /*VALIDATING ROUTES*/
    /*validate routes are not the same*/
    if(actual_route == next_route){
      return false;
    }

    /*Validate actual  and next_route exists*/
    if(actual_route > solution.size()-1 || next_route > solution.size()-1){
      return false;
    }

    /*Validate actual route has enough elements for the shift*/
    if(solution[actual_route].size() < shift){
      return false;
    }

    /*VALIDATE ACTUAL CLIENT IN ACTUAL ROUTE CAN MAKE THE SHIFT*/
    if((solution[actual_route].size() - (actual_client + shift) ) < 0 ){
      return false;
    }

    /*VALIDATING CLIENTS*/
    /*VALIDATE ACTUAL CLIENT IN ACTUAL ROUTE IS INSIDEs IT*/
    if(actual_client  > solution[actual_route].size()-1 ){
      return false;
    }

    /*VALIDATE NEXT CLIENT IN NEXT ROUTE IS INSIDE IT*/
    if(next_client  > solution[next_route].size()-1){
      return false;
    }

    return true;
}

void emili::vrp::Shift_1_0_Neighborhood::reverseLastMove(Solution* step)
{
  notyet();

}

void emili::vrp::Shift_1_0_Neighborhood::makeShift(std::vector < std::vector<int> >& solution){
  notyet();
}

double emili::vrp::Shift_1_0_Neighborhood::calculateDeltaSolutionValue(std::vector < std::vector<int> >& solution, double solutionValue){
  return 0;
}



/*int emili::problemX::NeighborhoodProblemX::size()
{
    notyet();
    return 0;
}*/




/** PERTURBATION **/


emili::Solution* emili::vrp::VrpPerturbation::perturb(Solution* solution)
{
    notyet();
    return nullptr;
}
