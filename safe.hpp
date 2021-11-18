#ifndef SAFE_HPP
#define SAFE_HPP

#include <mutex>
#include <vector>
#include <functional>
#include <condition_variable>

namespace jenya705 {

    // I wanted to make .cpp file but generics don't support it

    namespace safe {

        template <typename T>
        class Mono {
        public:

            virtual bool set(T value) = 0;

            virtual T get() const = 0;

        };

        template <typename T>
        class JustMono: public Mono<T> {
        private:
            T _value;
            std::vector<std::function<bool(T, T)>>* _conditions;
        public:
            JustMono(T value): _value(value) {}

            JustMono(T value, std::vector<std::function<bool(T, T)>>& conditions) : JustMono<T>(value) {
                _conditions = new std::vector<std::function<bool(T, T)>>(conditions);
            }

            ~JustMono() {
                if (_conditions != NULL)
                    delete _conditions;
            }

            virtual bool set(T value) {
                if (_conditions != NULL) {
                    for (auto iterator = _conditions->begin(); iterator < _conditions->end(); ++iterator) {
                        std::function<bool(T, T)> condition = *iterator;
                        if (!condition(_value, value)) return false;
                    }
                }
                _value = value;
                return true;
            }

            virtual T get() const {
                return _value;
            }

        };

        template <typename T>
        class ConcurrentMono: public JustMono<T>{
        private:
            mutable std::mutex _mutex;
            std::condition_variable* _cv; /// Toggle feature;
            inline JustMono<T> super() {
                return *static_cast<JustMono<T>*>(this);
            }
        protected:
            std::mutex& getMutex() const;
        public:
            ConcurrentMono(T value) : JustMono<T>(value) , _mutex(std::mutex()) {}

            ConcurrentMono(T value, std::vector<std::function<bool(T, T)>>& conditions) :
                JustMono<T>(value, conditions), _mutex(std::mutex()){}

            ConcurrentMono(const ConcurrentMono<T>& toCopy) = delete;

            ~ConcurrentMono() {
                if (_cv != NULL)
                    delete _cv;
            };

            virtual bool set(T value) {
                _mutex.lock();
                bool success = super().set(value);
                if (success && _cv != NULL) {
                    _cv->notify_one();
                }
                _mutex.unlock();
                return success;
            }

            virtual T get() const {
                _mutex.lock();
                T copy = super().get();
                _mutex.unlock();
                return copy;
            }

            virtual void enableConditionVariable() {
                if (_cv != NULL)
                    _cv = new std::condition_variable();
            }

            std::condition_variable* getConditionVariable() const {
                return _cv;
            }

        };

        template<typename T>
        JustMono<T>* just(T value, std::vector<std::function<bool(T, T)>>& conditions) {
            return new JustMono<T>(value, conditions);
        }

        template <typename T>
        JustMono<T>* just(T value) {
            return new JustMono<T>(value);
        }

        template <typename T>
        ConcurrentMono<T>* concurrent(T value, std::vector<std::function<bool(T, T)>>& conditions) {
            return new ConcurrentMono<T>(value, conditions);
        }

        template <typename T>
        ConcurrentMono<T>* concurrent(T value) {
            return new ConcurrentMono<T>(value);
        }

    }

}

#endif
