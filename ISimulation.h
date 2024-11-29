#pragma once



class IGrille;

class ISimulation {
public:
    virtual ~ISimulation() = default;
    virtual void execute() = 0;
};
