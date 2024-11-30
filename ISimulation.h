#pragma once



class IGrille;

class ISimulation {
public:
    virtual ~ISimulation() {};
    virtual void execute() = 0;
};
