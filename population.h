#pragma once

#include "dna.h"
#include <random>
#include <iostream>

class Population{
public:
    
    std::vector<DNA> population;
    std::vector<DNA> matingPool;
    std::vector<double> targetParams;
    double mutationRate;
    int maxPopulation = 1000;
    bool calledOnce= false;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen{rd()}; //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> equalRandom{0.0, 1.0};
    long double generations= 0;              // Number of generations
    bool finished;
    long double perfectScore;
    long double maxFitness=0;
    
    std::vector<DNA> newPopulation;
    Population(std::vector<double> tp);
    
    void setMutationRate(double mr){
        this->mutationRate= mr;
    }
    double getMutationRate(){
        return this->mutationRate;
    }
    void setMaxPopulation(int mp);
    int getMaxPopulation(){
        
        return this->maxPopulation;
    }
    
    void calcFitness();

    // Compute average fitness for the population
    double getAverageFitness();
    
     // Compute the current "most fit" member of the population
    std::vector<int> getBest();
    
    // Create a new generation
    void generate();

    DNA select(std::vector<double> scores);
    
    bool terminate() {
       return finished;
     }

     int getGenerations() {
       return generations;
     }
    
};