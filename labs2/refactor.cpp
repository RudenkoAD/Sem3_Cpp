#include <iostream>
#include <set>
#include <random>
#include <fstream>
#include <string>

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
        friend State operator+ (const State& lha, const State& rha);
        friend State operator- (const State& lha, const State& rha);
        friend State operator* (const State& lha, const State& rha);
        
};

State operator+ (const State& lha, const State& rha){
    std::set<int> newstates = lha.states;
    for(auto i = rha.states.begin(); i!=rha.states.end(); i++){
        if(newstates.count(*i)>0){
            newstates.insert(*i);
        }
    }
    return State(newstates);
}

State operator- (const State& lha, const State& rha){
    std::set<int> newstates = lha.states;
    for(auto i = rha.states.begin(); i!=rha.states.end(); i++){
        if(newstates.count(*i)>0){
            newstates.erase(*i);
        }
    }
    return State(newstates);
}

State operator* (const State& lha, const State& rha){
    std::set<int> newstates = lha.states;
    for(auto i = newstates.begin(); i!=newstates.end();){
        if(rha.states.count(*i)>0){
            i = newstates.erase(i);
        } else{
            i++;
        }
    }
    return State(newstates);
}


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

class ProbabilityTest {
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;
    
public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count): seed(seed), test_min(test_min),test_max(test_max), test_count(test_count) { }
    
    int change_count(int a){
        test_count = a;
        return a;
    }

    float operator()(State s) const {
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min,test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng))) ++good;
        
        return static_cast<float>(good)/static_cast<float>(test_count);
    }
};

int Operator(ProbabilityTest& pt, State& st, std::ostream& out, int const n){
    for(int i=0; i<n; i+=100){
        pt.change_count(i);
        out<<pt(st)<<' ';
    }
    out<<std::endl;
    return 0;
}

int N = 100000;

int main(int argc, const char * argv[]) {
    //int seed;
    //std::cin>>seed;
    std::ofstream out("out.txt");
    out<<"TEST"<<std::endl;
    out.close();
    //SegmentState ss = SegmentState(1, 10);
    //DiscreteState ds = DiscreteState(11);
    //ProbabilityTest pt(seed,0,100,N);
    //State sum = ss + ds;
    //Operator(pt, sum, out, N);
    //out.close(); 
}
