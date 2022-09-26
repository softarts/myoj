//
// Created by rui.zhou on 3/17/2019.
//
/* 设计一个停车场
 * https://wdxtub.com/interview/14520604446608.html
 *
抽象/建模:一个车库有不同的level,每个level有不同的row,每个row有一系列的slot,车有不同的size，只能停入空余的停车位
停车的过程: gateway-查找空余停车位(size>=vehicle.size)-入库-计时-离开停车场-停止计时-收费-清理停车位

 先抽象出对象/建模
 尺寸， 车， 停车位， 层， 车库， 每个对象都有不同的API

 */

#include <codech/codech_def.h>
#include <ctime>
using namespace std;

namespace {
    enum VehicleSize {
        COMPACT,
        STANDARD,
        LARGE
    };
    // 停车位
    class ParkingSpot {
    protected:
        VehicleSize size_;
        bool isAvai_;
        int level_;
        int mId_;
    public:
        ParkingSpot(VehicleSize sz, int id) {size_ = sz;isAvai_ = true;mId_=id; }
        VehicleSize getSize() {return size_;}
        int getId() {return mId_;}
        bool isAvail() {return isAvai_;}
        void occupy() {isAvai_ = false;}
        void leave() {isAvai_ = true;}
    };

    // 车
    class Vehicle {
    private:
        int licensePlateId_;
        VehicleSize size_;
        bool isParked_;
        float balance_;
        ParkingSpot *spot_;
    public:
        Vehicle(VehicleSize sz, float bal, int lic) {
            size_ = sz;
            isParked_ = false;
            spot_ = nullptr;
            balance_ = bal;
            licensePlateId_ = lic;
        }
        bool isParked() {return isParked_;}
        VehicleSize getVehicleSize() {return size_;}
        int getLicensePlateId() {return licensePlateId_;}
        ParkingSpot* getParkSlot() {
            return spot_;
        }
        bool park(ParkingSpot *spot) {
            if (spot) {
                spot_ = spot;
                spot_->occupy();
                isParked_ = true;
                return true;
            }
            return false;

        }
        bool leave(float fee) {
            if (spot_) {
                spot_->leave();
                isParked_ = false;
                spot_ = nullptr;
                balance_ -=fee;
                return true;
            }
            return false;
        }
    };

    class Motor:public Vehicle{};

    // 为了简化，不给level分配具体的ID了
    class Level {
    protected:
        vector<ParkingSpot> spots_;
    public:
        Level() {
            // init with some parking spots, use index in vector as the spot ID
            int idx = 0;
            for (int i=0;i<10;i++) {
                spots_.emplace_back(ParkingSpot(VehicleSize::COMPACT,idx++));
                spots_.emplace_back(ParkingSpot(VehicleSize::STANDARD,idx++));
                spots_.emplace_back(ParkingSpot(VehicleSize::LARGE,idx++));
            }
        }
        bool findSpot(VehicleSize sz,ParkingSpot *&spot ) {
            for (int i=0;i<spots_.size();i++) {
                if (spots_[i].getSize()==sz && spots_[i].isAvail()) {
                    spot = &spots_[i];
                    return true;
                }
            }
            return false;
        }
    };

    class CarPark {
    protected:
        vector<Level> levels_;
        unordered_map<int, int> bills_;
        const float feepm_ = 1.0;
    protected:
        void startBill(Vehicle &v) {
            bills_[v.getLicensePlateId()] = time(NULL);
        }

        float calculateFee(Vehicle &v) {
            auto end = time(nullptr);
            auto start = bills_[v.getLicensePlateId()];
            return feepm_ * (end-start)/60;
        }
    public:
        CarPark(int num) {
            // 3 levels
            for (int i=0;i<num;i++) {
                levels_.emplace_back(Level());
            }
        }
        bool enter(Vehicle  &v) {
            ParkingSpot *spot = nullptr;
            for (int i=0;i<levels_.size();i++) {
                if (levels_[i].findSpot(v.getVehicleSize(),spot)) {
                    v.park(spot);
                    startBill(v);
                    return true;
                }
            }
            return false;
        }

        bool leave(Vehicle &v) {
            if (v.isParked()) {
                auto fee = calculateFee(v);
                v.leave(fee);
                bills_.erase(v.getLicensePlateId());
                return true;
            } else {
                return false;
            }
        }
    };
}

DEFINE_CODE_TEST(design_carpark)
{
    CarPark carPark(1);

    vector<Vehicle> cars;
    for (int i=0;i<100;i++) {
        cars.emplace_back(VehicleSize::LARGE,100,i);
    }

    // enter
    for (int i=0;i<100;i++) {
        Vehicle &vehicle=cars[i];
        if (carPark.enter(vehicle)) {
            cout << "parked " << vehicle.getLicensePlateId() << " " << vehicle.getParkSlot()->getId()  <<endl;
        } else {
            cout << "no space " <<vehicle.getLicensePlateId()<<endl;
        }
    }
    //leave
    for (int i=0;i<100;i++) {
        Vehicle &vehicle=cars[i];
        if (carPark.leave(vehicle)) {
            cout << "leaving " <<vehicle.getLicensePlateId()<<endl;
        } else {
            cout << "not parking  " <<vehicle.getLicensePlateId()<<endl;
        }
    }
}
