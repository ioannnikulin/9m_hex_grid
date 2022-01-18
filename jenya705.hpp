#ifndef JENYA705_HPP
#define JENYA705_HPP

#include <chrono>
#include <thread>
#include <algorithm>
#include <map>
#include <future>
#include <mutex>
#include <array>
#include <cmath>
#include "base.h"
#include "safe.hpp"

using namespace std;

namespace jenya705 {

    #define ALL_DIRECTIONS {direction::w, direction::e, direction::d, direction::x, direction::z, direction::a}

    #define VS 1

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

    #if VS == 0
    const float infinity = 1.0f / 0.0f;
    #else
    #include <limits>
    const float infinity = std::numeric_limits<float>::infinity();
    #endif

    const direction* generateAllDirections() {
        return new direction[7]{direction::w, direction::e, direction::d, direction::x, direction::z, direction::a, (direction) -1};
    }

    vector<function<bool(int, int)>> bestPathFunctions(1, [](int first, int second){return first > second;});

    safe::JustMono<int>* bestPathMono() {
        return safe::just(0, bestPathFunctions);
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

    bool operator!=(const Point& p1, const Point& p2) {
        return !(p1 == p2);
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

    template <typename T>
    class VirtualField {
    private:
        vector<vector<T>> field;
    public:
        VirtualField(): field(vector<vector<T>>(DEFAULT_WIDTH, vector<T>(DEFAULT_WIDTH, UNKNOWN))) {}

        void moreField(int need) {
            if (need < 0) return;
            int currentWidth = field.size();
            int newWidth = currentWidth + DEFAULT_WIDTH * (need / DEFAULT_WIDTH + 1);
            vector<vector<T>> newField(newWidth, vector<T>(newWidth, UNKNOWN));
            newField.insert(newField.begin() + DEFAULT_WIDTH / 2, field.begin(), field.end());
            field = newField;
        }

        int deltaField() {
            return field.size() / 2;
        }

        Point fieldPoint(Point p) {
            return {p.x + deltaField(), p.y + deltaField()};
        }

        void set(Point point, T c) {
            Point onField = fieldPoint(point);
            moreField(onField.x - field.size());
            field[onField.y][onField.x] = c;
        }

        T at(Point point) {
            Point onField = fieldPoint(point);
            moreField(max(onField.x, onField.y) - field.size());
            onField = fieldPoint(point);
            return field[onField.y][onField.x];
        }

        Point& find(function<bool(T&, T&)> func) {
            return findPositionable([&](Point p1, float& v1, Point p2, float& v2) {
                return func(v1, v2);
            });
        }

        Point realPoint(Point point) {
            return {
                point.x - deltaField(),
                point.y - deltaField()
            };
        }

        Point findPositionable(function<bool(Point, T&, Point, T&)> func) {
            T current = field[0][0];
            Point currentPosition = {0, 0};
            Point position = {0, 0};
            for (vector<T>& column: field) {
                for (T row: column) {
                    if (func(realPoint(position), row, realPoint(currentPosition), current)){
                        current = row;
                        currentPosition = position;
                    }
                    position.x++;
                }
                position.x = 0;
                position.y++;
            }
            return {
                currentPosition.x - deltaField(),
                currentPosition.y - deltaField()
            };
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

    typedef VirtualField<char> DefaultVirtualField;

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

    template <typename T>
    class VirtualMovement {
    private:
        VirtualField<T>* virtualField;
        function<bool(T)> canMove;
    public:
        Position position;
        VirtualMovement(VirtualField<T>* field, Position position) : VirtualMovement<T>(field, position, [](T something) {return something == AIR; }) {}

        VirtualMovement(VirtualField<T>* field, Position position, function<bool(T)> canMove) : virtualField(field), position(position), canMove(canMove) {}

        T move(direction dir) {
            Position positionCopy = position.copy();
            positionCopy.move(dir);
            T c = virtualField->at(positionCopy.position);
            if (!canMove(c)) return c;
            position = positionCopy;
            return c;
        }

        VirtualMovement copy() {
            return VirtualMovement(virtualField, position.copy());
        }

        VirtualField<T>* getVirtualField() {
            return virtualField;
        }

    };

    typedef VirtualMovement<char> DefaultVirtualMovement;

    vector<direction> getNodeAllDirections(DefaultVirtualMovement movement, vector<Point> whereWas, std::shared_ptr<safe::Mono<int>> bestMono);

    vector<direction> getNode(DefaultVirtualMovement movement, vector<Point> whereWas, std::shared_ptr<safe::Mono<int>> bestNodeMono, const direction* dirs) {
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
            DefaultVirtualMovement movementCopy = movement.copy();
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
                    bestNodeMono->set(bestNode.size() + whereWas.size());
                }
            }
            else if (goingTo == UNKNOWN) {
                #if DEBUG == 1
                cout << "unknown! (" << whereWas.size() << ") - " << this_thread::get_id() << endl;
                #endif
                delete[] dirs;
                bestNodeMono->set(1);
                return vector<direction>(1, dir);
            }
        }
        #if DEBUG == 1
        cout << "return! (" << whereWas.size() << ")" << endl << "[ ";
        for (int i = 0; i < bestNode.size(); ++i) cout << bestNode[i] << " ";
        cout << "] - " << this_thread::get_id() << endl;
        #endif
        if (bestNode.empty()) {
            movement.getVirtualField()->set(movement.position.position, WALL);
        }
        delete[] dirs;
        return bestNode;
    }

    vector<direction> getNodeAllDirections(DefaultVirtualMovement movement, vector<Point> whereWas, std::shared_ptr<safe::Mono<int>> bestMono) {
        return getNode(movement, whereWas, bestMono, generateAllDirections());
    }

    vector<direction> getNodeStarter(DefaultVirtualMovement movement, Point start) {
        #if FUTURE == 1
        vector<pair<std::shared_ptr<safe::ConcurrentMono<vector<direction>>>, thread*>> threads;
        std::shared_ptr<safe::Mono<int>> bestMono(bestPathMono());
        for (direction dir: ALL_DIRECTIONS) {
            VirtualMovement movementCopy = movement.copy();
            char c = movementCopy.move(dir);
            if (c == WALL) continue;
            vector<Point> points;
            points.push_back(start);
            points.push_back(movementCopy.position.position);
            std::shared_ptr<safe::ConcurrentMono<vector<direction>>> result(safe::concurrent(vector<direction>(0)));
            thread* thr = new thread([](
                    std::shared_ptr<safe::ConcurrentMono<vector<direction>>> result,
                    VirtualMovement movement,
                    vector<Point> whereWas,
                    std::shared_ptr<safe::Mono<int>> bestMono,
                    const direction* dirs
                    ){
                        result->set(getNode(movement, whereWas, bestMono, dirs));
                    },
                    result,
                    movementCopy,
                    points,
                    bestMono,
                    getDirectionNearsArray(dir)
                );
            threads.push_back(make_pair(result, thr));
        }
        vector<direction> bestNode;
        for (auto& task: threads) {
            task.first->wait();
            vector<direction> node = task.first->get();
            if (bestNode.empty() || node.size() < bestNode.size()) {
                bestNode = node;
            }
            task.second->detach();
            delete task.second;
        }
        return bestNode;
        #elif FUTURE == 0
        std::shared_ptr<safe::Mono<int>> mono(bestPathMono());
        vector<direction> result = getNodeAllDirections(movement, vector<Point>(1, movement.position.position), mono);
        return result;
        #endif // FUTURE

    }

    class Bot {
    private:
        pc* bot;
        DefaultVirtualField virtualField;
        Position position;
    public:
        Bot(pc* bot) : bot(bot), virtualField(DefaultVirtualField()), position(Position({0, 0})) {}

        void ai() {

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
            #if DEBUG > 0
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
            return getNodeStarter(DefaultVirtualMovement(&virtualField, position.copy()), position.position);
        }

    };

    void runVanilla(pc* bot) {
        Bot vanillaBot(bot);
        vanillaBot.ai();
    }

    class jenya705_bot_starter : public pc {
    private:
        int icon_counter;
        string icons;
        function<void(pc*)> starter;
    public:
        jenya705_bot_starter(function<void(pc*)> starter, string icons): pc(NULL, "-"), icons(icons), starter(starter), icon_counter(0) {}

        virtual void ai() {
            starter(this);
        }

        virtual string str() {
            icon_counter++;
            icon_counter %= icons.size();
            return string(&icons[icon_counter], 1);
        }

    };

    namespace A {

        inline bool isWall(float n) {
            return n == -1;
        }

        inline bool isUnknown(float n) {
            return n == 0;
        }

        inline bool canGo(float n) {
            return n > 0;
        }

        template <typename T>
        inline int signum(T val) {
            return (T(0) < val) - (val < T(0));
        }

        direction directionTowards(int deltax, int deltay) {
            int sgnx = signum(deltax);
            int sgny = signum(deltay);
            if (sgny == 0) return sgnx == -1 ? a : d;
            direction r, l;
            if (sgny == 1) {
                r = e; l = w;
            }
            else {
                r = x; l = z;
            }
            return sgnx == -1 ? l : r;
        }

        direction* generateDirections(int x, int y) {
            direction dir = directionTowards(x, y);
            return jenya705::getDirectionNearsArray(dir);
        }

        inline void stepBack(VirtualMovement<int>& stepsVirtualMovement, vector<direction>& result, int& currentDelta) {
            stepsVirtualMovement.move(mirrorDirection(result[result.size() - 1]));
            result.pop_back();
            currentDelta = 0;
        }

        vector<direction> createNodeTo(Point destination, VirtualMovement<float>* virtualMovement) {
            direction* dirs = generateDirections(
                destination.x - virtualMovement->position.position.x,
                destination.y - virtualMovement->position.position.y
            );
            VirtualField<int> stepsVirtualField;
            stepsVirtualField.set(virtualMovement->position.position, -1);
            VirtualMovement<int> stepsVirtualMovement(&stepsVirtualField, virtualMovement->position, canGo);
            VirtualField<float>* distanceVirtualField = virtualMovement->getVirtualField();
            vector<direction> result;
            int currentDelta = 0;
            int steps = 0;
            while (stepsVirtualMovement.position.position != destination) {
                if (currentDelta > 5) {
                    stepBack(stepsVirtualMovement, result, currentDelta);
                }
                Position movedCurrent = stepsVirtualMovement.position.copy();
                movedCurrent.move(dirs[currentDelta]);
                if (!canGo(distanceVirtualField->at(movedCurrent.position))) {
                    currentDelta++;
                    continue;
                }
                int onCellSteps = stepsVirtualField.at(movedCurrent.position);
                if (onCellSteps == 0 || onCellSteps > steps) {
                    stepsVirtualField.set(movedCurrent.position, ++steps);
                    stepsVirtualMovement.position = movedCurrent;
                    result.push_back(dirs[currentDelta]);
                    currentDelta = 0;
                }
                else if (currentDelta == 5){
                    stepBack(stepsVirtualMovement, result, currentDelta);
                }
                else {
                    currentDelta++;
                }
            }
            delete[] dirs;
            return result;
        }

        direction onCircleDirection(VirtualMovement<float>* movement) {
            for (direction dir: ALL_DIRECTIONS) {
                Position currentPosition = movement->position.copy();
                currentPosition.move(dir);
                if (isUnknown(movement->getVirtualField()->at(currentPosition.position))) return dir;
            }
            return (direction) -1;
        }

        class ABot {
        private:
            pc* bot;
            VirtualField<float> virtualField;
            Position position;
        public:
            ABot(pc* bot): bot(bot), virtualField(), position({0, 0}) {}

            void ai() {
                cache();
                while (!bot->won()) {
                    Point point;
                    direction thisPointDir;
                    while (true) {
                        point = virtualField.findPositionable([&](Point ap, float& a, Point bp, float& b){
                            if (a <= 0) return false;
                            a += abs(position.position.x - ap.x) + abs(position.position.y - ap.y);
                            if (virtualField.at(bp) <= 0) return true;
                            return a < b;
                        });
                        VirtualMovement<float> pointVirtualMovement(&virtualField, point, canGo);
                        thisPointDir = onCircleDirection(&pointVirtualMovement);
                        if (thisPointDir == -1) {
                            virtualField.set(point, infinity);
                        }
                        else {
                            break;
                        }
                    }
                    VirtualMovement<float> virtualMovement(&virtualField, position, canGo);
                    if (point != position.position) {
                        vector<direction> way = createNodeTo(point, &virtualMovement);
                        for (direction dir: way) {
                            go(dir);
                            if (bot->won()) return;
                        }
                    }
                    go(thisPointDir);
                }
            }

            void cache() {
                if (virtualField.at(position.position) == 0) {
                    virtualField.set(position.position, bot->dist_to_exit());
                }
                for (direction dir: ALL_DIRECTIONS) {
                    if (!bot->can_go(dir)) {
                        Position positionCopy = position.copy();
                        positionCopy.move(dir);
                        virtualField.set(positionCopy.position, -1);
                    }
                }
            }

            void go(direction dir) {
                position.move(dir);
                bot->go(dir);
                cache();
            }

        };

        void runA(pc* bot) {
            ABot aBot(bot);
            aBot.ai();
        }

    }

};

#endif // JENYA705_HPP

