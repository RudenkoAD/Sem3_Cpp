#include <iostream>
#include <set>
#include <random>

class State{
    protected:
        std::set<int> states;
    public:
        bool contains(int s) const {
            return states.count(s) > 0;
        }
        State(): states(){}
        State(std::set<int> src){
            states = src;
        }
        State operator+ (const State& other) const{
            std::set<int> newstates = states;
            for(auto i = other.states.begin(); i!=other.states.end(); i++){
                if(newstates.count(*i)>0){
                    newstates.insert(*i);
                }
            }
            return State(newstates);
        }
        State operator* (const State& other) const{
            std::set<int> newstates = states;
            for(auto i = newstates.begin(); i!=newstates.end();){
                if(other.states.count(*i)>0){
                    i = newstates.erase(i);
                } else{
                    i++;
                }
            }
            return State(newstates);
        }
};

class DiscreteState: public State {
public:
    DiscreteState(): State(){}
    DiscreteState(int state): State(){
        states.insert(state);
    }
};

class SegmentState: public State {
public:
    SegmentState(): State(){}
    SegmentState(int beg, int end): State() {
        for(int i=beg; i<=end; i++){
            states.insert(i);
        }
    }
};

class SetState: public State {
    SetState():State(){}
    SetState(std::set<int> const &src): State() {
        states=src;
    }
};

class MultSegmentStates: public State {
    MultSegmentStates(): State(){};
    MultSegmentStates(std::set<std::tuple<int, int>> src): State(){

    }
};

class ProbabilityTest {
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;
    
public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count): seed(seed), test_min(test_min),test_max(test_max), test_count(test_count) { }
    
    float operator()(State s) const {
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min,test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng))) ++good;
        
        return static_cast<float>(good)/static_cast<float>(test_count);
    }
};

int main(int argc, const char * argv[]) {
    DiscreteState d(1);
    SegmentState s(0,10);
    //SetState ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});
    ProbabilityTest pt(10,0,100,100000);
    std::cout << pt(d) << std::endl;
    std::cout << pt(s) << std::endl;
    //std::cout << pt(ss) << std::endl;
    return 0;
}
