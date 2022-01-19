return num>n || zeroInit;
});
if(num>n) return;
int zero=0;
printNumber(zero);
_condOddEven.notify_all();
}
​
void odd(function<void(int)> printNumber) {
unique_lock<mutex> lock(_mtx);
_condOddEven.wait(lock, [this](){
return num>n || isOdd;
});
if(num>n) return;
printNumber(num);
++num;
isOdd = false;
_condZero.notify_one();
}
void even(function<void(int)> printNumber) {
unique_lock<mutex> lock(_mtx);
_condOddEven.wait(lock, [this](){
return num>n || !isOdd;
});
if(num>n) return;
printNumber(num);
++num;
isOdd = true;
_condZero.notify_one();
}
};
```