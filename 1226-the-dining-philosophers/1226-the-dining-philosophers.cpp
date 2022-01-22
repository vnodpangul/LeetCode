class DiningPhilosophers {
private:
    mutex _mtx;
    condition_variable _cond;
    vector<int> isValid;
public:
    DiningPhilosophers() {
     isValid.resize(5, 1);   
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        {
            unique_lock<mutex> lock(_mtx);
            _cond.wait(lock, [this, philosopher](){
               return isValid[philosopher] && isValid[(philosopher+1)%5]; 
            });
            isValid[philosopher] = 0;
            isValid[(philosopher+1)%5] = 0;
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        {
            lock_guard<mutex> lock(_mtx);

            isValid[philosopher] = 1;
            isValid[(philosopher+1)%5] = 1;
            _cond.notify_all();
        }
		
    }
};