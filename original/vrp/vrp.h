
#ifndef VEHICULEROUTINGPROBLEM_H
#define VEHICULEROUTINGPROBLEM_H
#include "../emilibase.h"
#include "vrp_instance.h"

/**
 *
 *  Vehicle Routing Problem components for EMILI
 *
*/
namespace emili{
namespace vrp{



/*----------------------------------------------------------------------------------------------------------------*
 *-------------------------------------PROBLEM & VRPPROBLEM TYPE CLASS--------------------------------------------*
 *----------------------------------------------------------------------------------------------------------------*/


class VrpProblem: public emili::Problem{
protected:
  VrpInstance instance;
public:
    // Constructor that uses a VrpInstance implementation
    VrpProblem(VrpInstance& problemInstance):instance(problemInstance) { }
    virtual ~VrpProblem(){};
    //Constructor that loads the instance from file path
    //VrpProblem(char* instance_path):instance(){ if (! instance.readDataFromFile(instance_path) ){exit(-1);}} //ramiro

    virtual double calcObjectiveFunctionValue(Solution& solution);
    virtual double evaluateSolution(Solution & solution);
    virtual int problemSize() {return getNcustomers();} //clients number

    /** Utils methods **/
    virtual double computeObjectiveFunction(std::vector < std::vector<int> > &solution)=0;

    /**  This method returns the number of clients*/
    int getNcustomers();
    /**  This method returns the capacity of the truck*/
    int getTruckCapacity();
    /**  This method returns the demand of each client*/
    std::vector<int> getDemands();
    

    /** This method returns the matrix of distance between customers*/
    std::vector<std::vector<float>> getDistanceMatrix();
    /** This method returns the distance between customers and depot*/
    std::vector<float> getDistanceWarehouses();
};

/**  CLASSIC CVRP*/
class CVRP: public VrpProblem
{
public:
    CVRP(VrpInstance& problemInstance):VrpProblem(problemInstance) { }
    ~CVRP(){};
    //CVRP(char* instance_path):VrpProblem(instance_path) { } //ramiro

    virtual double computeObjectiveFunction(std::vector < std::vector<int> > & solution);
};



/*----------------------------------------------------------------------------------------------------------------------*
 *-------------------------------------SOLUTION & INITIALSOLUTION TYPE CLASS--------------------------------------------*
 *----------------------------------------------------------------------------------------------------------------------*/


class VrpSolution: public emili::Solution
{
protected:
    std::vector< std::vector< int > > solutionRepresentation; //valores solucion vrp
    double solutionValue; //funcion objetivo

    virtual const void* getRawData()const;
    virtual void setRawData(const void* data);
public:
    //VrpSolution(std::vector< std::vector< int > >& solution, double solutionValue):solution(solution), solutionValue(solutionValue){}
    VrpSolution(std::vector< std::vector< int > > & solution, double value):emili::Solution(value),solutionValue(value),solutionRepresentation(solution){}
    virtual ~VrpSolution() {};

    virtual std::vector< std::vector< int > >& getSolution(); //retorna la representacion de la solucion
    virtual void setSolution(std::vector< std::vector< int > > & sol); //set the solution representation
    virtual double getSolutionValue(); //retorna valor de la solucion
    virtual void setSolutionValue(double solutionValue); //setea la solucion

    virtual std::string getSolutionRepresentation(); //imprime la representacion de la solucion
    virtual void printObjetivefunction(); //imprime la funcion objetivo


    virtual Solution* clone();
    virtual bool isFeasible(); //{return true;};

};

//The initial solution generator
class VrpInitialSolution: public emili::InitialSolution
{
protected:
    VrpProblem& pis;  //PROBLEM INSTANCE
    virtual Solution* generate() = 0 ;
public:
    VrpInitialSolution(VrpProblem& problem_instance):emili::InitialSolution(problem_instance),pis(problem_instance){};
    virtual ~VrpInitialSolution() {};

    virtual Solution* generateSolution();
    virtual Solution* generateEmptySolution();

    virtual double calculateInitialSolutionValue(std::vector < std::vector<int> > &solution)=0;
};

class VrpRandomInitialSolution: public emili::vrp::VrpInitialSolution
{
protected:
    virtual Solution* generate();
public:
    VrpRandomInitialSolution(VrpProblem& problem_instance):emili::vrp::VrpInitialSolution(problem_instance){};
    virtual ~VrpRandomInitialSolution() {};

    double calculateInitialSolutionValue(std::vector < std::vector<int> > &solution);
};

class VrpDetInitialSolution: public emili::vrp::VrpInitialSolution
{
protected:
    virtual Solution* generate();
public:
    VrpDetInitialSolution(VrpProblem& problem_instance):emili::vrp::VrpInitialSolution(problem_instance){};
    virtual ~VrpDetInitialSolution() {};

    double calculateInitialSolutionValue(std::vector < std::vector<int> > &solution);
};



/*--------------------------------------------------------------------------------------------------------*
 *-------------------------------------NEIGHBORHOOD TYPE CLASS--------------------------------------------*
 *--------------------------------------------------------------------------------------------------------*/


class VrpNeighborhood: public emili::Neighborhood
{
protected:
    VrpProblem& pis;
    int nClientsToIterate;
    int start_route;
    int start_client;

    virtual Solution* computeStep(Solution* step)=0;
    virtual void reverseLastMove(Solution* step)=0;

public:
    VrpNeighborhood(VrpProblem& problem, int sr, int sc):pis(problem),
    start_route(sr), start_client(sc), nClientsToIterate(problem.getNcustomers()){};
    
    virtual ~VrpNeighborhood() {};

    virtual NeighborhoodIterator begin(emili::Solution* base)=0;
    virtual void reset()=0;
    virtual Solution* random(Solution* currentSolution)=0;
    virtual int size(){return 1;};
};


class Shift_1_0_Neighborhood: public emili::vrp::VrpNeighborhood
{
protected:
    int shift;
    int previous_route;
    int previous_client;
    int actual_route;
    int actual_client;
    int next_route;
    int next_client;

    bool isFirstTime = true;

    Solution* computeStep(Solution* step);
    void reverseLastMove(Solution* step);

public:
    Shift_1_0_Neighborhood(VrpProblem& problem):
    VrpNeighborhood(problem, 0, 0),previous_route(0),previous_client(0),
    actual_route(0),actual_client(0),next_route(0),next_client(0),shift(1){};

    Shift_1_0_Neighborhood(VrpProblem& problem, int startRoute, int startCLient):
    VrpNeighborhood(problem, startRoute, startCLient),previous_route(startRoute),previous_client(startCLient),
    actual_route(startRoute),actual_client(startCLient),
    next_route(startRoute),next_client(startCLient),shift(1){};

    ~Shift_1_0_Neighborhood() {}

    NeighborhoodIterator begin(emili::Solution* base);
    void reset();
    Solution* random(Solution* currentSolution);
    int size(std::vector < std::vector<int> >& solution);

//private:
    void getNextNeighborPos(std::vector < std::vector<int> >& solution);
    bool proposedNextIsFeasible(std::vector < std::vector<int> >& solution);
    void makeShift(std::vector < std::vector<int> >& solution);
    double calculateDeltaSolutionValue(std::vector < std::vector<int> >& solution, double solutionValue);

};



/*-------------------------------------------------------------------------------------------------------*
 *-------------------------------------PERTUBATION TYPE CLASS--------------------------------------------*
 *-------------------------------------------------------------------------------------------------------*/


/** @brief The Perturbation class
* The pertubation phase of the ils.
*/
class VrpPerturbation: public emili::Perturbation
{
  public:
    virtual Solution* perturb(Solution* solution);

    virtual ~VrpPerturbation() { }
};
}
}
#endif // VEHICULEROUTINGPROBLEM_H
