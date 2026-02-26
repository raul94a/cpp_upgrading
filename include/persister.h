#ifndef H_PERSISTER
#define H_PERSISTER
#include <string>

// candidato a usarlo de template
class Persister {
    public:
        Persister();
        ~Persister();
        void write(std::string uri,std::string content);
        void read(std::string uri);
};

class FilePersister : public Persister {
public:
    FilePersister();
    ~FilePersister();
    void write(std::string uri,std::string content);
    void write(std::string uri, std::string content, int flag);
    void read(std::string uri);
};

#endif