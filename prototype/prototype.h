#include<iostream>

class Iprototype
{   
    protected:
    virtual std::shared_ptr<Iprototype> clone() = 0;
}


class prototypeA : public Iprototype
{
    public:
    prototypeA(){}
    prototypeA(prototypeA & pr_a);
    private:
    std::shared_ptr<Iprototype> clone() override;
}

class prototypeB : public Iprototype
{
    public:
    prototypeB(){}
    prototypeB(prototypeB & pr_b);
    private:
    std::shared_ptr<Iprototype> clone() override;
}
