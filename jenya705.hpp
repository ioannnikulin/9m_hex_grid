#ifndef JENYA705_HPP
#define JENYA705_HPP

#include <chrono>
#include <thread>
#include <algorithm>
#include <map>
#include <future>
#include <mutex>
#include "safe.hpp"

using namespace std;

namespace jenya705 {

    #define ALL_DIRECTIONS {direction::w, direction::e, direction::d, direction::x, direction::z, direction::a}

    #define UNKNOWN 0
    #define AIR 1
    #define WALL 2

    #define UNKNOWN_CHAR '?'
    #define AIR_CHAR '.'
    #define WALL_CHAR '#'
    #define PLAYER_CHAR '@'

    #define DEFAULT_WIDTH 100

    #define DEBUG 0
    #define FUTURE 0

    const direction* generateAllDirections() {
        return new direction[7]{direction::w, direction::e, direction::d, direction::x, direction::z, direction::a, (direction) -1};
    }

    template <typename T>
    class Mono {
    protected:
        T value;
        mutex* lock;
    public:

        Mono<T>(T value) : lock(new mutex()), value(value) {}

        T get() {
            T valueCopy;
            lock->lock();
            valueCopy = value;
            lock->unlock();
            return valueCopy;
        }

        void set(T value) {
            lock->lock();
            this->value = value;
            lock->unlock();
        }

    };

    template <typename T>
    class BestMono: public Mono<T> {

    protected:
        /// true if first is better than second
        function<bool(T, T)> bestFunction;

    public:
        BestMono<T>(T value, function<bool(T, T)> bestFunction) : Mono<T>(value), bestFunction(bestFunction) {}

        bool setIfBetter(T value) {
            this->lock->lock();
            if (bestFunction(this->value, value)) {
                this->lock->unlock();
                return false;
            }
            this->value = value;
            this->lock->unlock();
            return true;
        }
    };

    BestMono<int>* bestPathMono() {
        return new BestMono<int>(0, [](int first, int second){return first >= second;});
    }

    char fromFieldToChar(int num) {
        return (num == UNKNOWN ? UNKNOWN_CHAR : (num == WALL ? WALL_CHAR : AIR_CHAR));
    }

    array<direction, 6> getDirectionNears(direction dir) {
        array<direction, 6> dirs;
        dirs[0] = dir;
        dirs[1] = (direction) ((dir + 5) % 6);
        dirs[2] = (direction) ((dir + 1) % 6);
        dirs[3] = (direction) ((dir + 4) % 6);
        dirs[4] = (direction) ((dir + 2) % 6);
        dirs[5] = (direction) ((dir + 3) % 6);
        return dirs;
    }

    direction* getDirectionNearsArray(direction dir) {
        direction* dirs = new direction[7];
        dirs[0] = dir;
        dirs[1] = (direction) ((dir + 5) % 6);
        dirs[2] = (direction) ((dir + 1) % 6);
        dirs[3] = (direction) ((dir + 4) % 6);
        dirs[4] = (direction) ((dir + 2) % 6);
        dirs[5] = (direction) ((dir + 3) % 6);
        dirs[6] = (direction) -1;
        return dirs;
    }

    direction mirrorDirection(direction dir) {
        switch(dir) {
        case w: return x;
        case e: return z;
        case a: return d;
        case d: return a;
        case z: return e;
        case x: return w;
        }
        return a;
    }

    struct Point {
        int x;
        int y;
    };

    bool operator==(const Point& p1, const Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }

    Point dirMovement(int y, direction dir) {
        int even = -(y & 1);
        switch(dir) {
        case d:
            return {1, 0};
        case a:
            return {-1, 0};
        case w:
            return {even, 1};
        case e:
            return {1 + even, 1};
        case z:
            return {even, -1};
        case x:
            return {1 + even, -1};
        }
        return {0, 0};
    }

    class ExpensiveMap {
    private:
        map<direction, int> prices;

    public:
        ExpensiveMap() {
            for (direction dir: ALL_DIRECTIONS) {
                prices[dir] = 0; /// start price
            }
        }

        void addResult(direction dir, int price) {
            prices[dir] = price;
        }

        array<direction, 6> getSortedDirections() {
            array<pair<direction, int>, 6> dirWithPrices;
            for (direction dir: ALL_DIRECTIONS) {
                dirWithPrices[dir] = {dir, prices[dir]};
            }
            array<direction, 6> sortedDirs;
            sort(dirWithPrices.begin(), dirWithPrices.end(), [](
                                                                pair<direction, int> first,
                                                                pair<direction, int> second)
                                                                {return first.second < second.second; }
                 );
            for (int i = 0; i < dirWithPrices.size(); ++i) {
                cout << "(" << dirWithPrices[i].first << ", " << dirWithPrices[i].second << ")" << endl;
                sortedDirs[i] = dirWithPrices[i].first;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            return sortedDirs;
        }

        void updatePrices() {
            for (direction dir: ALL_DIRECTIONS) {
                prices[dir] /= 2;
            }
        }

    };

    class VirtualField {
    private:
        vector<vector<char>> field;
    public:
        VirtualField(): field(vector<vector<char>>(DEFAULT_WIDTH, vector<char>(DEFAULT_WIDTH, UNKNOWN))) {}

        void moreField(int need) {
            if (need <= 0) return;
            int currentWidth = field.size();
            int newWidth = currentWidth + DEFAULT_WIDTH * (need / DEFAULT_WIDTH + 1);
            vector<vector<char>> newField(newWidth, vector<char>(newWidth, UNKNOWN));
            newField.insert(newField.begin() + DEFAULT_WIDTH / 2, field.begin(), field.end());
            field = newField;
        }

        int deltaField() {
            return field.size() / 2;
        }

        Point fieldPoint(Point p) {
            return {p.x + deltaField(), p.y + deltaField()};
        }

        void set(Point point, char c) {
            Point onField = fieldPoint(point);
            moreField(onField.x - field.size());
            field[onField.y][onField.x] = c;
        }

        char at(Point point) {
            Point onField = fieldPoint(point);
            moreField(onField.x - field.size());
            return field[onField.y][onField.x];
        }

        void printAt(Point point) {
            Point onField = fieldPoint(point);
            moreField(onField.x - field.size());
            cout << "Debug: (" << point.x << ", " << point.y << ")" << endl;
            cout << " ";
            for (int i = 0; i < 2; ++i) {
                int num = field[onField.y + 1][onField.x - 1 + i];
                cout << fromFieldToChar(num) << " ";
            }
            cout << endl;
            int num = field[onField.y][onField.x - 1];
            cout << fromFieldToChar(num) << " ";
            cout << PLAYER_CHAR << " ";
            num = field[onField.y][onField.x + 1];
            cout << fromFieldToChar(num) << " ";
            cout << endl << " ";
            for (int i = 0; i < 2; ++i) {
                int num = field[onField.y - 1][onField.x - 1 + i];
                cout << fromFieldToChar(num) << " ";
            }

            cout << endl;
        }

    };

    class Position {
    public:
        Position(Point position): position(position) {}
        Point position;
        void move(direction dir) {
            Point movement = dirMovement(position.y, dir);
            position = {
                position.x + movement.x,
                position.y + movement.y
            };
        }
        Position copy() {
            return Position({position.x, position.y});
        }
    };

    class VirtualMovement {
    private:
        VirtualField* virtualField;
    public:
        Position position;
        VirtualMovement(VirtualField* field, Position position): virtualField(field), position(position) {}

        char move(direction dir) {
            Position positionCopy = position.copy();
            positionCopy.move(dir);
            char c = virtualField->at(positionCopy.position);
            if (c != AIR) return c;
            position = positionCopy;
            return c;
        }

        VirtualMovement copy() {
            return VirtualMovement(virtualField, position.copy());
        }

        VirtualField* getVirtualField() {
            return virtualField;
        }

    };

    vector<direction> getNodeAllDirections(VirtualMovement movement, vector<Point> whereWas, BestMono<int>* bestMono);

    vector<direction> getNode(VirtualMovement movement, vector<Point> whereWas, BestMono<int>* bestNodeMono, const direction* dirs) {
        vector<direction> bestNode;
        int nodeSize = whereWas.size();
        for (int i = 0; ; ++i) {
            direction dir = dirs[i];
            if (dir == -1) break;
            int bestNodeSize = bestNodeMono->get();
            if (bestNodeSize != 0 && bestNodeSize <= whereWas.size()) {
                #if DEBUG == 1
                cout << "was better node so skipping! - " << this_thread::get_id() << endl;
                #endif // DEBUG
                return vector<direction>(0);
            }
            #if DEBUG == 1
            cout << "moved to: " << dir << " (" << whereWas.size() << ") - " << this_thread::get_id() << endl;
            #endif
            VirtualMovement movementCopy = movement.copy();
            char goingTo = movementCopy.move(dir);
            if (goingTo == AIR) {
                bool foundDuplicate = false;
                for (int i = 0; i < whereWas.size(); ++i) {
                    if (whereWas[i] == movementCopy.position.position) {
                        #if DEBUG == 1
                        cout << "found duplicate! (" << whereWas.size() << ") - " << this_thread::get_id() << endl;
                        #endif
                        foundDuplicate = true;
                        break;

                    }
                }
                if (foundDuplicate) continue;
                vector<Point> whereWasCopy = whereWas;
                whereWasCopy.push_back(movementCopy.position.position);
                vector<direction> nextNode = getNode(movementCopy, whereWasCopy, bestNodeMono, getDirectionNearsArray(dir));
                if (nextNode.size() == 0) {
                    #if DEBUG == 1
                    cout << "next node size is 0 (" << whereWas.size() << ") - " << this_thread::get_id() << endl;
                    #endif
                    continue;
                }
                if (bestNode.empty() || bestNode.size() > nextNode.size()){
                    #if DEBUG == 1
                    cout << "found better way! (" << whereWas.size() << ") - " << this_thread::get_id() << endl;
                    #endif
                    bestNode.clear();
                    for (int i = 0; i < nextNode.size(); ++i) bestNode.push_back(nextNode[i]);
                    bestNode.push_back(dir);
                    bestNodeMono->setIfBetter(bestNode.size() + whereWas.size());
                }
            }
            else if (goingTo == UNKNOWN) {
                #if DEBUG == 1
                cout << "unknown! (" << whereWas.size() << ") - " << this_thread::get_id() << endl;
                #endif
                delete[] dirs;
                return vector<direction>(1, dir);
            }
        }
        #if DEBUG == 1
        cout << "return! (" << whereWas.size() << ")" << endl << "[ ";
        for (int i = 0; i < bestNode.size(); ++i) cout << bestNode[i] << " ";
        cout << "] - " << this_thread::get_id() << endl;
        #endif
        delete[] dirs;
        return bestNode;
    }

    vector<direction> getNodeAllDirections(VirtualMovement movement, vector<Point> whereWas, BestMono<int>* bestMono) {
        return getNode(movement, whereWas, bestMono, generateAllDirections());
    }

    typedef packaged_task<vector<direction>(VirtualMovement, vector<Point>,
                        BestMono<int>*, const direction*)> getNodeTask;

    vector<direction> getNodeStarter(VirtualMovement movement, Point start) {
        #if FUTURE == 1
        vector<pair<future<vector<direction>>, thread*>> futures;
        BestMono<int>* mono = bestPathMono();
        for (direction dir: ALL_DIRECTIONS) {
            VirtualMovement movementCopy = movement.copy();
            char c = movementCopy.move(dir);
            if (c == WALL) continue;
            vector<Point> points;
            points.push_back(start);
            points.push_back(movementCopy.position.position);
            getNodeTask packTask(getNode);
            future<vector<direction>> packFuture = packTask.get_future();
            thread* packThread = new thread(move(packTask), movementCopy, points, mono, getDirectionNearsArray(dir));
            futures.push_back(make_pair(packFuture, packThread));
        }
        vector<direction> bestNode;
        for (auto i = futures.begin(); i < futures.end(); ++i) {
            pair<future<vector<direction>>, thread*> packTask = *futures;
            packTask.second->join();
            packTask.first.wait();
            vector<direction> thisNode = packTask.first.get();
            if (bestNode.empty() || bestNode.size() < thisNode.size()) bestNode = thisNode;
            delete packTask.second;
        }
        delete mono;
        return bestNode;
        #elif FUTURE == 0
        BestMono<int>* mono = bestPathMono();
        vector<direction> result = getNodeAllDirections(movement, vector<Point>(1, movement.position.position), mono);
        delete mono;
        return result;
        #endif // FUTURE

    }

    void c(safe::Mono<int>* mono) {
        this_thread::sleep_for(chrono::seconds(1));
        mono->set(1);
    }

    class Bot {
    private:
        pc* bot;
        VirtualField virtualField;
        Position position;
    public:
        Bot(pc* bot) : bot(bot), virtualField(VirtualField()), position(Position({0, 0})) {}

        void ai() {

            safe::ConcurrentMono<int>* mono = safe::concurrent(0);
            mono->enableConditionVariable();
            thread t(c, mono);
            mono->wait();
            cout << mono->get() << endl;
            delete mono;
            t.detach();

            return;

            cache();
            while(!bot->won()) {
                vector<direction> node = getNode();
                for (int i = node.size() - 1; i >= 0; --i) {
                    go(node[i]);
                    if (bot->won()) return;
                }
            }
        }

        void go(direction dir) {
            if (!bot->can_go(dir)) return;
            bot->go(dir);
            position.move(dir);
            cache();
            #if DEBUG == 1
            virtualField.printAt(position.position);
            #endif
        }

        void cache() {
            for (direction dir: ALL_DIRECTIONS) {
                Point movement = dirMovement(position.position.y, dir);
                Point newPosition = {
                    movement.x + position.position.x,
                    movement.y + position.position.y
                };
                bool cango = bot->can_go(dir);
                if (virtualField.at(newPosition) != UNKNOWN) continue;
                if (cango) virtualField.set(newPosition, AIR);
                else virtualField.set(newPosition, WALL);
            }
        }

        vector<direction> getNode() {
            //BestMono<int>* bestMono = bestPathMono();
            //vector<direction> dirs = jenya705::getNodeAllDirections(VirtualMovement(&virtualField, position.copy()), vector<Point>(1, position.position), bestMono);
            //delete bestMono;
            return getNodeStarter(VirtualMovement(&virtualField, position.copy()), position.position);
        }

    };

    #define JENYA705_ICONS string("?^%@\[]")
    #define JENYA705_ICONS_LENGTH JENYA705_ICONS.size()

    class jenya705_bot_starter : public pc {
    private:
        int icon_counter;
    public:
        jenya705_bot_starter(field* p): pc(p, "-"), icon_counter(0) {}

        virtual void ai() {
            jenya705::Bot bot(this);
            bot.ai();
        }

        virtual string str() {
            icon_counter++;
            icon_counter %= JENYA705_ICONS_LENGTH;
            return string(&JENYA705_ICONS[icon_counter], 1);
        }

    };

};

#endif // JENYA705_HPP

