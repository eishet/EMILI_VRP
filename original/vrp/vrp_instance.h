
#ifndef _VRPINSTANCE_H
#define _VRPINSTANCE_H

#include <string>
#include <vector>


struct instance_data_struct {
  std::vector<std::vector<float>> distanceMatrix;
  std::vector<float> distanceWarehouses;
  std::vector<int> demands;
  int nbCustomers;
  int truckCapacity;
};


class VrpInstance{
  private:
    /** Capacity of the trucks */
    int truckCapacity;
    /** Number of customers */
    int nbCustomers;
    /** Distance matrix | distance between customers */
    std::vector<std::vector<float>> distanceMatrix;
    /** Distance to depot distance between customers and the depot */
    std::vector<float> distanceWarehouses;
    /** Demand on each node */
    std::vector<int> demands;

    bool silence;

    float computeDist(int xi, int xj, int yi, int yj);
    //void computeDistanceMatrix(int depotX, int depotY, const std::vector<int>& customersX, const std::vector<int>& customersY);
    std::vector<std::vector<float>> computeDistanceMatrix(int nbCustomers, const std::vector<int>& customersX, const std::vector<int>& customersY);
    std::vector<float> computeDistanceToWarehouse(int nbCustomers, int depotX, int depotY, const std::vector<int>& customersX, const std::vector<int>& customersY);

  public:
    VrpInstance();
    ~VrpInstance(){};

    /**  Read write privates attributes : */
    int getNbCustomers();
    void setNbCustomers(int nbCustomers);

    std::vector<int> getDemands();
    void setDemands(std::vector<int> demands);

    std::vector<std::vector<float>> getDistanceMatrix();
    void setDistanceMatrix(std::vector<std::vector<float>> distanceMatrix);

    std::vector<float> getDistanceWarehouses();
    void setDistanceWarehouses(std::vector<float> distanceWarehouses);

    int getTruckCapacity();
    void setTruckCapacity(int nbCustomers);

    /**  Read Data from a file : */
    bool readDataFromFile(const std::string _fileName);

    void setSilence(bool s);

    float computeSolution(std::vector<std::vector<int>> & solution);
};


#endif
