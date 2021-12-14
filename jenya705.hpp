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

    #define DEBUG 2
    #define FUTURE 0

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

    template <typename T>
    class VirtualField {
    private:
        vector<vector<T>> field;
    public:
        VirtualField(): field(vector<vector<T>>(DEFAULT_WIDTH, vector<T>(DEFAULT_WIDTH, UNKNOWN))) {}

        void moreField(int need) {
            if (need <= 0) return;
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
            moreField(onField.x - field.size());
            return field[onField.y][onField.x];
        }

        Point find(function<bool(T, T)> func) {
            T current = field[0][0];
            Point currentPosition = {0, 0};
            Point position = {0, 0};
            for (vector<T>& column: field) {
                for (T& row: column) {
                    if (func(row, current)){
                        current = row;
                        currentPosition = position;
                    }
                    position.x++;
                }
                position.y++;
            }
            return currentPosition;
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
    public:
        Position position;
        VirtualMovement(VirtualField<T>* field, Position position): virtualField(field), position(position) {}

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
            //BestMono<int>* bestMono = bestPathMono();
            //vector<direction> dirs = jenya705::getNodeAllDirections(VirtualMovement(&virtualField, position.copy()), vector<Point>(1, position.position), bestMono);
            //delete bestMono;
            return getNodeStarter(DefaultVirtualMovement(&virtualField, position.copy()), position.position);
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

        direction* generateDirections(int x, int y) {
            int sgnX = signum(x);
            int sgnY = signum(y);
            if (sgnY == 0) {
                if (sgnX == 1) return jenya705::getDirectionNearsArray(d);
                else return jenya705::getDirectionNearsArray(a);
            }
            direction right = (sgnY == 1 ? e : x);
            direction left = (sgnY == 1 ? w : z);
            if (sgnX == -1) return jenya705::getDirectionNearsArray(left);
            return jenya705::getDirectionNearsArray(right);
        }

        vector<direction> createNodeTo(Point destination, VirtualMovement<float>* virtualMovement) {

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
                    Point point = virtualField.find([](float a, float b){
                        return a == -1 ? b : (b == -1 ? a : (a > b ? b : a))
                    });

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
                        virtualField.set(position.position, -1);
                    }
                }
            }

        };

    }

};

#endif // JENYA705_HPP

