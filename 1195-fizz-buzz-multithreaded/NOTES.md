```
void number(function<void(int)> printNumber) {
while (true) {
unique_lock<mutex> lock(m);
while (count <= n && (count % 5 == 0 || count % 3 == 0))
cv.wait(lock);
if (count > n) return;
printNumber(count++);
cv.notify_all();
}
}
```