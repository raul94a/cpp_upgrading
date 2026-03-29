#ifndef H_SERIALIZER
#define H_SERIALIZER
#include <string>
template <class T>
class Serializer {};

template <class T>
class JsonSerializer : public Serializer<T> {
    public:
        virtual std::string toJson() = 0;
        virtual void fromJson(const std::string& string) = 0;

};

#endif