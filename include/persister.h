#ifndef H_PERSISTER
#define H_PERSISTER
#include <string>

// candidato a usarlo de template
class Persister {
    public:
        Persister();
        ~Persister();
        virtual void write(std::string uri,std::string content) = 0;
        virtual std::string read(std::string uri) = 0;
};

class FilePersister : public Persister {
public:
    FilePersister();
    ~FilePersister();
    void write(std::string uri,std::string content);
    void write(std::string uri, std::string content, int flag);
    std::string read(std::string uri);
};

#endif