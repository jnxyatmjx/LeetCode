#ifndef OBserver_H
#define OBserver_H

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <thread>
#include <chrono>
#include <list>
#include <iostream>

int curs= 0 ;

class IObserver
{
public:
    virtual ~IObserver() = default;

public:
    virtual void updateState(const std::string&) = 0; // Used for Subject class notify
};

class ISubject
{
public:
    virtual ~ISubject() = default;

public:
    virtual void notify() = 0;
    virtual void addObserver(IObserver *obs) = 0;
    virtual void delObserver(IObserver *obs) = 0;
};

class Observer : public IObserver
{
public:
    Observer(ISubject * su):sub_(su) {
        curs++;
        sub_->addObserver(this);
        nus_ = curs;
    }

    ~Observer() { std::cout << "goodbye Observer Destruct:" << nus_ << std::endl; }

public:
    void updateState(const std::string& ssf) override
    {   
        update_from_subject = ssf;
        std::cout <<" " << nus_ << " " << update_from_subject << std::endl;
    }
private:
    std::string update_from_subject;
    ISubject * sub_;
    int nus_;
};

class Subject : public ISubject
{
public:
    Subject():curnum_(0) {

    }
    ~Subject(){}
public:
    void notify() override {
        std::cout << "have size of lists :" << observer_list_.size() << std::endl;
        for(std::list<IObserver*>::iterator it = observer_list_.begin();
        it != observer_list_.end(); it++){
            (*it)->updateState(messg_);
        }
    }
    void addObserver(IObserver *obs) override {
        observer_list_.push_back(obs);
    }
    void delObserver(IObserver *obs) override {
        observer_list_.remove(obs);
    }

public:
    void createMes(std::string ms = "Good boy default"){
        this->messg_ = ms;
        this->notify();
    }

private:
    std::list<IObserver*> observer_list_;
    std::string messg_;
    int curnum_;
};

int main(int argc, char *argv[])
{

    Subject *ss = new Subject();
    Observer * ob1 = new Observer(ss);
    Observer * ob2 = new Observer(ss);

    ss->createMes("upate dfir first");
    Observer * ob3 = new Observer(ss);
    ss->createMes("update second messga");

    ss->delObserver(ob2);
    ss->createMes("update mess after delete");

    Observer * o4 = new Observer(ss);
    ss->createMes("okokk  ddddd ddfsdf");

    delete ob3;
    delete ob2;
    delete ob1;

    delete ss;
    return 1;
}

#endif
