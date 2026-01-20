#include <bits/stdc++.h>
using namespace std;

class ISubscribe {
public:
    virtual void update() = 0;
    virtual ~ISubscribe() {}
};

class IChannel {
public:
    virtual void subscribe(ISubscribe* sub) = 0;
    virtual void unsubscribe(ISubscribe* sub) = 0;
    virtual void notify() = 0;
    virtual ~IChannel() {}
};

class Channel : public IChannel {
private:
    string videoName;
    string channelName;
    vector<ISubscribe*> subscribers;

public:
    Channel(string name) {
        channelName = name;
    }

    void subscribe(ISubscribe* sub) override {
        if (find(subscribers.begin(), subscribers.end(), sub) == subscribers.end()) {
            subscribers.push_back(sub);
        }
    }

    void unsubscribe(ISubscribe* sub) override {
        auto it = find(subscribers.begin(), subscribers.end(), sub);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notify() override {
        for (auto sub : subscribers) {
            sub->update();
        }
    }

    void upload(string video) {
        videoName = video;
        notify();
    }

    string getVideoName() {
        return videoName;
    }

    string getChannelName() {
        return channelName;
    }
};

class Subscriber : public ISubscribe {
private:
    string name;
    Channel* ch;

public:
    Subscriber(string n, Channel* c) {
        name = n;
        ch = c;
    }

    void update() override {
        cout << "Hey " << name
             << ", new video on "
             << ch->getChannelName()
             << ": " << ch->getVideoName() << endl;
    }
};

int main() {
    Channel* newch = new Channel("Code");

    Subscriber* s1 = new Subscriber("Sub1", newch);
    Subscriber* s2 = new Subscriber("Sub2", newch);

    newch->subscribe(s1);
    newch->subscribe(s2);

    newch->upload("Observer Pattern Explained");

    return 0;
}
