#if 1
class TrafficLight {
private:
    int currentGreenRoadId;
    mutex _mtx;
public:
    
    TrafficLight() {
        currentGreenRoadId = 1; // Road A
    }

void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) 
{
        lock_guard<mutex> lock(_mtx);
        if(roadId != currentGreenRoadId) {
            currentGreenRoadId = roadId ;
            turnGreen();
        }
        crossCar();

}
    
};
#endif
