
#include "vrp.h"

#include <cstdlib>
#include <ctime>
//-----------------
#include <climits>
#include <string>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <limits>
//----------------


void notyet()
{
    std::cout << "Not implemented yet \n";
    //std::exit(-5);
}



/*----------------------------------------------------------------------------------------------------------------*
 *--------------------------------------------------PROBLEM-------------------------------------------------------*
 *----------------------------------------------------------------------------------------------------------------*/


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
    return instance.computeSolution(solution);  //ojo aqui
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

std::vector<std::vector<float>> emili::vrp::VrpProblem::getDistanceMatrix(){
    return instance.getDistanceMatrix();
}

std::vector<float> emili::vrp::VrpProblem::getDistanceWarehouses(){
    return instance.getDistanceWarehouses();
}




/*----------------------------------------------------------------------------------------------------------------*
 *----------------------------------------------INITIAL SOLUTION--------------------------------------------------*
 *----------------------------------------------------------------------------------------------------------------*/


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

//solucion inicial determinista
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

  int i = 0;
  while(used_pos.size() > 0){
    actualTruckSolution.push_back(i);
    actualTruckCapacity = actualTruckCapacity - demands[i];
    used_pos.erase(used_pos.begin());
    solution.push_back(actualTruckSolution);
    actualTruckSolution.clear();
    i++;
  }
  VrpSolution* s = new VrpSolution(solution, calculateInitialSolutionValue(solution));
  pis.evaluateSolution(*s);
  s->isFeasible();
  return s;
}

//solucion inicial aleatoria
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
  std::vector < std::vector<int> >& v = dynamic_cast<std::vector < std::vector<int> >&> (solution);
  return pis.computeObjectiveFunction(v);
}

double emili::vrp::VrpDetInitialSolution::calculateInitialSolutionValue(std::vector < std::vector<int> >&solution)
{
  std::vector < std::vector<int> >& v = dynamic_cast<std::vector < std::vector<int> >&> (solution);
  return pis.computeObjectiveFunction(v);
}


/*----------------------------------------------------------------------------------------------------------------*
 *-------------------------------------------------SOLUTION-------------------------------------------------------*
 *----------------------------------------------------------------------------------------------------------------*/


const void* emili::vrp::VrpSolution::getRawData()const
{
  //return &solutionValue;
  return &solutionRepresentation;
}

void emili::vrp::VrpSolution::setRawData(const void* data)
{
  std::vector < std::vector < int > >* data_vector = (std::vector < std::vector< int > >*) data;
  this->solutionRepresentation = *data_vector;
  //double* tdata = (double*) data;
  //this->solutionValue = *tdata;
}

//imprime la representacion de la solucion
std::string emili::vrp::VrpSolution::getSolutionRepresentation()
{
  std::ostringstream oss;
  int size = solutionRepresentation.size();
  std::cout<< " \nrepresentacion de la solucion:" <<std::endl;
  oss << "{ ";
  for(int i=0; i<size; i++){
    std::cout<< "automovil: " << i+1 << " visita a cliente(s):" <<std::endl;
        for(int j=0;j<solutionRepresentation[i].size();j++){
          std::cout << solutionRepresentation[i][j]+1 << ", "; 
          oss << solutionRepresentation[i][j] << " ";
        }
        std::cout<< std::endl;
  }
  oss << " }";

  double f = solutionValue;
  std::cout<< "La funcion objetivo es: " << f << " unidades de distancia" <<std::endl;

  return oss.str();
}

void emili::vrp::VrpSolution::printObjetivefunction()
{
  double f = solutionValue;
  std::cout<< "La funcion objetivo es: " << f << " unidades de distancia" <<std::endl;
}

emili::Solution* emili::vrp::VrpSolution::clone()
{
  return new emili::vrp::VrpSolution(this->solutionRepresentation,this->solutionValue);
}

std::vector< std::vector< int > > & emili::vrp::VrpSolution::getSolution()
{
  return this->solutionRepresentation;
}

void emili::vrp::VrpSolution::setSolution(std::vector< std::vector< int > >& sol)
{
  this->solutionRepresentation = sol;
}

double emili::vrp::VrpSolution::getSolutionValue()
{
  return this->solutionValue;
}

void emili::vrp::VrpSolution::setSolutionValue(double solutionValue)
{
  this->solutionValue = solutionValue;
}

bool emili::vrp::VrpSolution::isFeasible()
{
  int cantclients = 0;
  int aux = 0;
  for(int i=0; i<solutionRepresentation.size(); i++){
    for(int j=0;j<solutionRepresentation[i].size();j++){
      cantclients++;
    }
  }
  std::vector< int > visited;
  visited.resize(cantclients);
  for(int i=0; i<visited.size(); i++){
    visited[i] = i;
  }

  for(int i=0; i<solutionRepresentation.size(); i++)
  {
    for(int j=0;j<solutionRepresentation[i].size();j++)
    {
      for(int k=0; k<visited.size(); k++)
      {
        if(visited[k] == solutionRepresentation[i][j])
        {
          aux++;
        }
        if(visited[k] == solutionRepresentation[i][j] && aux > cantclients){
          std::cout << "Hay cliente(s) visitados mas de una vez!!!" << std::endl;
          return false;
        }
      }
    }
  }
  std::cout << "Todos los clientes son visitados una unica vez" << std::endl;
  return true;
}



/*----------------------------------------------------------------------------------------------------------------*
 *--------------------------------------------------NEIGHBORHOOD--------------------------------------------------*
 *----------------------------------------------------------------------------------------------------------------*/


/*Shift_1_0_Neighborhood*/

//calcula el tamaño del vecindario
int emili::vrp::Shift_1_0_Neighborhood::size(std::vector < std::vector<int> >& solution)
{
  /*int neighbors = 0;
  int rutas = solution.size();//cantidad de rutas
  int ruta = 0;
  for (int i = 0; i < rutas; i++)
  {
    ruta = solution[i].size();//tamaño de la ruta actual
    if(ruta > 1)
    {
      neighbors = neighbors + (ruta * ((nClientsToIterate - ruta) + rutas-1));
    }
  }
  return neighbors;*/
  return 1;
}

emili::Solution* emili::vrp::Shift_1_0_Neighborhood::random(Solution* currentSolution) //DE MOMENTO ESTO NO SIRVE, DEBE ENTREGAR UN VECINO RANDOM
{
  /*std::vector<std::vector<int>> solution = ((emili::vrp::VrpSolution*) currentSolution)->getSolution();
  
  int grandsize = solution.size()-1;
  int rand_route = emili::generateRandomNumber()%grandsize;
  int size = solution[rand_route].size()-1;
  int rand_pos = emili::generateRandomNumber()%size;
  //solution[rand_route].emplace((solution[rand_route].begin() + rand_pos),clientshifted);
  



  double value = pis.computeObjectiveFunction(solution);
  return new emili::vrp::VrpSolution(solution, value);*/
  return computeStep(currentSolution);
}

emili::Neighborhood::NeighborhoodIterator emili::vrp::Shift_1_0_Neighborhood::begin(emili::Solution* base)
{
  return emili::Neighborhood::NeighborhoodIterator(this,base);
}

//resetea a default las variables del vecindario
void emili::vrp::Shift_1_0_Neighborhood::reset()
{
  previous_route=0;
  previous_client=0;
  actual_route=0;
  actual_client=0;
  next_route=0;
  next_client=0;  
  isFirstTime = true;
  nClientsToIterate = pis.getNcustomers();
}

//funcion que setea los nuevos valores de la funcion objetivo y la representacion de la solucion
emili::Solution* emili::vrp::Shift_1_0_Neighborhood::computeStep(emili::Solution* step)  //ARREGLAR ACÁ
{
  emili::iteration_increment();

  std::vector<std::vector<int>> representation = ((emili::vrp::VrpSolution*) step)->getSolution();
  double solutionValue = ((emili::vrp::VrpSolution*) step)->getSolutionValue();
  //int unvisitedneighbors = size( representation ); //vecinos sin visitar (sean o no válidos)

  do{
    getNextNeighborPos( representation );
    //unvisitedneighbors--;
    if( proposedNextIsFeasible( representation ) ){
        //Modify actual solution value for the new one
        ( (emili::vrp::VrpSolution*) step )->setSolutionValue( calculateDeltaSolutionValue( representation, solutionValue ) );
        //Modify actual Solution for the new one
        makeShift( representation );
        ( (emili::vrp::VrpSolution*) step )->setSolution( representation );
        std::cout << "entry" << std::endl;
        return step;
    }
  }while(nClientsToIterate > 0);
  std::cout << "No se encontraron soluciones válidas!!" << std::endl;
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
      //std::cout << nClientsToIterate << std::endl; 
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


bool emili::vrp::Shift_1_0_Neighborhood::proposedNextIsFeasible(std::vector < std::vector<int> >& solution)
{

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
    if(solution[actual_route].size() == shift){                     //<-----------------ojo aqui (antes era '>')
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

    /*VALIDATING CAPACITY*/
    /*VALIDATE NEXT ROUTE DONT SURPASS IT'S CAPACITY*/
    int actualcap = 0;
    int customer = 0;
    std::vector<int> demands = pis.getDemands();
    for(int i = 0; i < solution[next_route].size(); i++)
    {
      customer = solution[next_route][i];
      actualcap = actualcap + demands[customer];
    }
    customer = solution[actual_route][actual_client];
    actualcap = actualcap + demands[customer];
    if(actualcap > pis.getTruckCapacity())
    {
      return false;
    }

    return true;
}

void emili::vrp::Shift_1_0_Neighborhood::reverseLastMove(Solution* step)
{
  std::vector<std::vector<int>> solution = ((emili::vrp::VrpSolution*) step)->getSolution();
  int clientshifted;
  clientshifted = solution[next_route][next_client];
  solution[next_route].erase(solution[next_route].begin() + next_client);
  solution[actual_route].emplace((solution[actual_route].begin() + next_client), clientshifted);

  //Lo que sigue es suponiendo que tambien debe revertir la funcion objetivo

  /*std::vector<std::vector<float>> matrix = pis.getDistanceMatrix();
  std::vector<float> disdep = pis.getDistanceWarehouses();
  
  double newvalue = 0;
  int last = solution[actual_route].size() - 1; //ultima posicion de la ruta actual
  int last2 = solution[next_route].size() - 1;  //ultima posicion de la nueva ruta
  float prev1 = 0;  //distancia entre el nodo movido y su colindante en ruta original
  float prev2 = 0;  //same
  float newprev = 0;//distancia entre ambos colindantes del nodo desplazado en ruta original
  float new1 = 0;   //distancia entre el nodo movido y su colindante en nueva ruta
  float new2 = 0;   //same
  float oldnew = 0; //distancia entre los nodos que estaran colindantes al cliente desplazado en la nueva ruta

  if(actual_client == 0 || actual_client == last)//significa que el cliente cambiado esta unido a 1 cliente y al deposito en su vieja ruta
  {
    prev1 = disdep[clientshifted];
    if(actual_client == 0)
    {
      prev2 = matrix[clientshifted][solution[actual_route][actual_client + 1]];
      newprev = disdep[solution[actual_route][actual_client + 1]];
    }
    else
    {
      prev2 = matrix[clientshifted][solution[actual_route][actual_client - 1]];
      newprev = disdep[solution[actual_route][actual_client - 1]];
    }
  }
  else//ambos nodos colindantes son clientes en su ruta original
  {
    prev1 = matrix[clientshifted][solution[actual_route][actual_client - 1]];
    prev2 = matrix[clientshifted][solution[actual_route][actual_client + 1]];
    newprev = matrix[solution[actual_route][actual_client - 1]][solution[actual_route][actual_client + 1]];
  }


  if(next_client == 0 || next_client == last2)//significa que el cliente cambiado quedará unido a 1 cliente y al deposito en su nueva ruta
  {
    new1 = disdep[clientshifted];
    new2 = matrix[clientshifted][solution[next_route][next_client]]; //como aun no se agrega el cliente a la nueva ruta, la posicion que tomara la tiene uno de sus futuros nodos colindantes
    oldnew = disdep[solution[next_route][next_client]];
  }
  else//ambos nodos colindantes son clientes en su nueva ruta
  {
    new1 = matrix[clientshifted][solution[next_route][next_client - 1]];
    new2 = matrix[clientshifted][solution[next_route][next_client]];
    oldnew = matrix[solution[next_route][next_client - 1]][solution[next_route][next_client]];
  }

  newvalue = solutionValue + (prev1 + prev2 + oldnew) - (new1 + new2 + newprev);
  ((emili::vrp::VrpSolution*) step)->setSolutionValue(newvalue);*/
}

void emili::vrp::Shift_1_0_Neighborhood::makeShift(std::vector < std::vector<int> >& solution)
{
  int clientshifted;
  clientshifted = solution[actual_route][actual_client];
  solution[actual_route].erase(solution[actual_route].begin() + actual_client);
  solution[next_route].emplace((solution[next_route].begin() + next_client),clientshifted);
}

//funcion que calcula el valor de la nueva funcion objetivo de manera "acotada"  (considera las variables ANTES de realizar el makeshift!!)
double emili::vrp::Shift_1_0_Neighborhood::calculateDeltaSolutionValue(std::vector < std::vector<int> >& solution, double solutionValue)
{
  
  int clientshifted; //valor de indice del cliente a cambiar
  clientshifted = solution[actual_route][actual_client];
  std::vector<std::vector<float>> matrix = pis.getDistanceMatrix();
  std::vector<float> disdep = pis.getDistanceWarehouses();
  
  double newvalue = 0;
  int last = solution[actual_route].size() - 1; //ultima posicion de la ruta actual
  int last2 = solution[next_route].size() - 1;  //ultima posicion de la nueva ruta
  float prev1 = 0;  //distancia entre el nodo movido y su colindante en ruta original
  float prev2 = 0;  //same
  float newprev = 0;//distancia entre ambos colindantes del nodo desplazado en ruta original
  float new1 = 0;   //distancia entre el nodo movido y su colindante en nueva ruta
  float new2 = 0;   //same
  float oldnew = 0; //distancia entre los nodos que estaran colindantes al cliente desplazado en la nueva ruta

  if(actual_client == 0 || actual_client == last)//significa que el cliente cambiado esta unido a 1 cliente y al deposito en su vieja ruta
  {
    prev1 = disdep[clientshifted];
    if(actual_client == 0)
    {
      prev2 = matrix[clientshifted][solution[actual_route][actual_client + 1]];
      newprev = disdep[solution[actual_route][actual_client + 1]];
    }
    else
    {
      prev2 = matrix[clientshifted][solution[actual_route][actual_client - 1]];
      newprev = disdep[solution[actual_route][actual_client - 1]];
    }
  }
  else//ambos nodos colindantes son clientes en su ruta original
  {
    prev1 = matrix[clientshifted][solution[actual_route][actual_client - 1]];
    prev2 = matrix[clientshifted][solution[actual_route][actual_client + 1]];
    newprev = matrix[solution[actual_route][actual_client - 1]][solution[actual_route][actual_client + 1]];
  }


  if(next_client == 0 || next_client == last2)//significa que el cliente cambiado quedará unido a 1 cliente y al deposito en su nueva ruta
  {
    new1 = disdep[clientshifted];
    new2 = matrix[clientshifted][solution[next_route][next_client]]; //como aun no se agrega el cliente a la nueva ruta, la posicion que tomara la tiene uno de sus futuros nodos colindantes
    oldnew = disdep[solution[next_route][next_client]];
  }
  else//ambos nodos colindantes son clientes en su nueva ruta
  {
    new1 = matrix[clientshifted][solution[next_route][next_client - 1]];
    new2 = matrix[clientshifted][solution[next_route][next_client]];
    oldnew = matrix[solution[next_route][next_client - 1]][solution[next_route][next_client]];
  }

  newvalue = solutionValue + (new1 + new2 + newprev) - (prev1 + prev2 + oldnew);
  return newvalue;
}




/*----------------------------------------------------------------------------------------------------------------*
 *--------------------------------------------------PERTURBATION--------------------------------------------------*
 *----------------------------------------------------------------------------------------------------------------*/


emili::Solution* emili::vrp::VrpPerturbation::perturb(Solution* solution)
{
    std::cout << "7 \n";
    notyet();
    return nullptr;
}
