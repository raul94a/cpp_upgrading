#include <queue> // Brings in std::queue#include <iostream>
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <string>

using namespace std;

/**
 * All the messages are sent with this struct
 */
struct Message
{
    string message;
    long long timestamp;
    // mutex* m;
} Broker_Message;

mutex mtx;
condition_variable mcond;
queue<Message> q;
bool end_pg = false;
int producer()
{

    while (true)
    {
        if (end_pg)
        {
            return 0;
        }
        unique_lock<mutex> lock(mtx);
        cout << "Type a message: ";
        string msg;
        getline(cin, msg);
        auto now = std::chrono::system_clock::now();
        auto duration_since_epoch = now.time_since_epoch();
        long long timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(duration_since_epoch).count();
        struct Message message = {
            .message = msg,
            .timestamp = timestamp};

        q.push(message);
        lock.unlock();
        mcond.notify_one();
        // if the program does not wait here, the consumer is never reached.
        // of course, if we want to make some kind of signaling, we have to wait
        // more time than nano seconds. There are for sure better mechanisms for stopping
        // the loop when the consumer is done. 
        this_thread::sleep_for(chrono::milliseconds(1));
    }
}

void consumer()
{
    while (true)
    {

        unique_lock<mutex> lock{mtx};

        mcond.wait(lock, []
                   { return !q.empty(); });
        auto m = q.front();
        q.pop();

        // Process the message (Print it out to prove it works)
        cout << "\n[Consumer Processed] Msg: " << m.message
             << " | Timestamp: " << m.timestamp << "\n\n";
        cout << endl;

        // compute answer...

        lock.unlock();

        if (m.message == "end")
        {
            end_pg = true;
            return;
        }

    }
}

int main()
{
    thread producer_thread(producer);
    thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}